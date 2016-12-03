%{
#include <math.h>
#include "../symbolTable/symbolTable.h"
#include <stdio.h>
#include <string.h>
#include "../utils/colours.h"
#include "./CLIHelp.h"
#include "../errorManager/errorManager.h"
/*#include "../MICLI/LANG_WORDS.h"*/

/*
Reference to the global symbol table
*/
extern symbolTable *global_st;
extern int yylex();
extern int yyparse();
void yyerror(char* s);
void showWarning(char *s);
short defined(variableContent *vc,unsigned short assign);
short isMatrix(variableContent *vc);
short isInBounds(int x, int y,variableContent *vc);

void copyMatrix (void * destmat, variableContent *vc) {
  memcpy(destmat,vc->value.values, vc->value.rows*vc->value.columns*sizeof(double));
}


%}

/*%define parse.lac full*/
%error-verbose


%union {
        variableValue matrixVal;
        double val;
        symbolData *pts;
}

 /*%destructor  { printf("Discarding pointer to symbolData"); }*/


%token<val> FLOAT_VALUE
%token<pts> VARIABLE ONE_OPERATOR_FUNCTION
%token END_OF_FILE
%token '+' '-' '*' '/' '(' ')' OPE_SLASH_EQ '&'  OPE_AND_AND '|' OPE_VERT_VERT OPE_MINUS_EQ OPE_MINUS_MINUS OPE_PLUS_EQ OPE_PLUS_PLUS '<' OPE_LESSTHAN_EQ OPE_LESSTHAN_LESSTHAN OPE_LESSTHAN_LESSTHAN_EQ '>' OPE_MORETHAN_EQ OPE_MORETHAN_MORETHAN_EQ OPE_MORETHAN_MORETHAN '!' OPE_EXCL_EQ OPE_EQ_EQ OPE_TIMES_EQ OPE_PERC_EQ OPE_HAT_EQ '[' ']' ';' '%' '~'
%token NEWLINE QUIT HELP DECLARE EXISTS_VARIABLE CLEAR_VARIABLES LIST_VARIABLES


%right '=' OPE_SLASH_EQ OPE_MINUS_EQ OPE_PLUS_EQ OPE_TIMES_EQ  OPE_PERC_EQ '!' '~'
%left '+' '-'
%left OPE_AND_AND OPE_VERT_VERT OPE_MINUS_MINUS OPE_PLUS_PLUS '<' '>' OPE_LESSTHAN_EQ OPE_LESSTHAN_LESSTHAN OPE_MORETHAN_EQ OPE_MORETHAN_MORETHAN OPE_EXCL_EQ OPE_EQ_EQ
%left '*' '/' '%'
%left NEGATE

 /*%type<matrixVal> MATRIXEXPRESSION*/
%type<val> EXPRESSION

%start calculation

%%



calculation:
	   | calculation line
;

line: NEWLINE
    | declaration NEWLINE         { printf( BLU "\tMatrix/Vector declared\n" RESET);}
    | declaration ';' NEWLINE     { }
    | EXPRESSION ';' NEWLINE      { }
    | EXPRESSION NEWLINE          { printf( BLU "\t%g\n" RESET, $1);}
    | error NEWLINE               { yyerrok; }
    | HELP NEWLINE                { printfHelp(); }
    | QUIT NEWLINE                { YYACCEPT; }
    | END_OF_FILE                 { YYACCEPT; }
;

/*-----------------------------*/
/*---------DECLARATIONS--------*/
/*-----------------------------*/

declaration: DECLARE VARIABLE '[' EXPRESSION ']' '[' EXPRESSION ']' {
                                  variableContent *vc= (variableContent*) $2->content;
                                  if(defined(vc,0)){
                                    yyerror("Matrix already declared");
                                    YYERROR;
                                  }

                                  int rows=(int)$4;
                                  int columns=(int)$7;
                                  vc->value.rows=rows;
                                  vc->value.columns=columns;
                                  vc->value.defAsMatrix=1;
                                  vc->value.values = malloc(rows * sizeof(double*));
                                  for (int i = 0; i < rows; i++) {
                                        vc->value.values[i] = malloc(columns * sizeof(double));
                                        for(int j=0;j < columns; j++){
                                          vc->value.values[i][j]=0;
                                        }
                                  }
                                  vc->defined=1;
                                }

DECLARE VARIABLE '[' EXPRESSION ']'{
                                  variableContent *vc= (variableContent*) $2->content;
                                  if(defined(vc,0)){
                                    yyerror("Matrix already declared");
                                    YYERROR;
                                  }
                                  int rows=(int)$4;
                                  int columns=1;
                                  vc->value.rows=rows;
                                  vc->value.columns=columns;
                                  vc->value.defAsMatrix=1;
                                  vc->value.values = malloc(rows * sizeof(double*));
                                  for (int i = 0; i < rows; i++) {
                                        vc->value.values[i] = malloc(columns * sizeof(double));
                                        for(int j=0;j < 1; j++){
                                          vc->value.values[i][j]=0;
                                        }
                                  }
                                  vc->defined=1;
                                }
DECLARE VARIABLE   {
                                  variableContent *vc= (variableContent*) $2->content;
                                  if(defined(vc,0)){
                                    yyerror("Variable already declared");
                                    YYERROR;
                                  }
                                  vc->value.values[0][0]=0;
                                  vc->defined=1;
                                }
;
        /*-----------------------------*/
        /*---------EXPRESSIONS---------*/
        /*-----------------------------*/

EXPRESSION: FLOAT_VALUE          { $$ = $1; }
    | VARIABLE                   {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,0)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(isMatrix(vc)){
                                    showWarning("Accesing first element of matrix without [][] notation");
                                  }
                                  $$=vc->value.values[0][0];
                                 }

    /*-----------BEG OF ASSIGNING OPERATORS-----------*/
    | VARIABLE '=' EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(isMatrix(vc)){
                                    showWarning("Accesing first element of matrix without [][] notation");
                                  }
                                  if(!defined(vc,0)){
                                    showWarning("Implicit declaration with assignment");
                                  }
                                  vc->value.values[0][0]=$3;
                                  vc->defined=1;
                                  $$=$3;
                                  }
    | VARIABLE OPE_SLASH_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(isMatrix(vc)){
                                    showWarning("Accesing first element of matrix without [][] notation");
                                  }
                                  vc->value.values[0][0]/=$3;
                                  $$=vc->value.values[0][0];
                                  }
    | VARIABLE OPE_MINUS_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(isMatrix(vc)){
                                    showWarning("Accesing first element of matrix without [][] notation");
                                  }
                                  vc->value.values[0][0]-=$3;
                                  $$=vc->value.values[0][0];
                                  }
    | VARIABLE OPE_PLUS_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(isMatrix(vc)){
                                    showWarning("Accesing first element of matrix without [][] notation");
                                  }
                                  vc->value.values[0][0]+=$3;
                                  $$=vc->value.values[0][0];
                                  }
    | VARIABLE OPE_TIMES_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(isMatrix(vc)){
                                    showWarning(YEL "Accesing first element of matrix without [][] notation" RESET);
                                  }
                                  vc->value.values[0][0]*=$3;
                                  $$=vc->value.values[0][0];
                                  }
    | VARIABLE OPE_PERC_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(isMatrix(vc)){
                                    showWarning("Accesing first element of matrix without [][] notation");
                                  }
                                  vc->value.values[0][0]=fmod(vc->value.values[0][0],$3);
                                  $$=vc->value.values[0][0];
                                  }
    /*-----------END OF ASSIGNING OPERATORS-----------*/

      /* LOGICAL OR */
    | EXPRESSION OPE_VERT_VERT EXPRESSION   { $$ = ($1 || $3)}

      /* LOGICAL AND */
    | EXPRESSION OPE_AND_AND EXPRESSION   { $$ = ($1 && $3)}



    /*-----------BEG OF COMPARISON OPERATORS-----------*/
    | EXPRESSION OPE_EQ_EQ EXPRESSION   { $$ = ($1 == $3)}
    | EXPRESSION OPE_EXCL_EQ EXPRESSION   { $$ = ($1 != $3)}

    | EXPRESSION '>' EXPRESSION   { $$ = ($1 > $3)}
    | EXPRESSION OPE_MORETHAN_EQ EXPRESSION   { $$ = ($1 >= $3)}

    | EXPRESSION '<' EXPRESSION   { $$ = ($1 < $3)}
    | EXPRESSION OPE_LESSTHAN_EQ EXPRESSION   { $$ = ($1 <= $3)}
    /*-----------END OF COMPARISON OPERATORS-----------*/

    /*-----------BEG OF SUM OPERATORS-----------*/
	  | EXPRESSION '+' EXPRESSION	 { $$ = $1 + $3; }
	  | EXPRESSION '-' EXPRESSION	 { $$ = $1 - $3; }
    /*-----------END OF SUM OPERATORS-----------*/

    /*-----------BEG OF PLUS OPERATORS-----------*/
	  | EXPRESSION '*' EXPRESSION  { $$ = $1 * $3; }
	  | EXPRESSION '/' EXPRESSION	 { $$ = $1 / $3; }
    | EXPRESSION '%' EXPRESSION	 { $$ = fmod($1,$3); }
    /*-----------END OF PLUS OPERATORS-----------*/


    /* LOGICAL NOT */
    | '!' EXPRESSION                { $$ = !($2); }

    /*-----------BEG OF UNARY PLUS AND MINUS OPERATORS-----------*/
    | '-' EXPRESSION %prec NEGATE   { $$ = -$2;}
    | '+' EXPRESSION                { $$ = $2;}
    /*-----------END OF UNARY PLUS AND MINUS OPERATORS-----------*/

    /*-----------BEG OF MATRIX ACCESS OPERATORS-----------*/
    | VARIABLE '[' EXPRESSION ']' '[' EXPRESSION ']'  {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,0)){
                                    yyerror("Matrix not declared");
                                    YYERROR;
                                  }
                                  if(!isMatrix(vc)){
                                    yyerror("That element is not a matrix");
                                    YYERROR;
                                  }
                                  if( ($3<0) || ($6<0)){
                                    yyerror("Negative index not allowed");
                                    YYERROR;
                                  }
                                  if(!isInBounds($3,$6,vc)){
                                    yyerror("Index outside the matrix");
                                    YYERROR;
                                  }
                                  double aux= vc->value.values[(int)$3][(int)$6];
                                  $$=aux;
                                  }

    | VARIABLE '[' EXPRESSION ']' {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,0)){
                                    yyerror("Vector not declared");
                                    YYERROR;
                                  }
                                  if(!isMatrix(vc)){
                                    yyerror("That element is not a vector");
                                    YYERROR;
                                  }
                                  if($3<0){
                                    yyerror("Negative index not allowed");
                                    YYERROR;
                                  }
                                  if(!isInBounds($3,0,vc)){
                                    yyerror("Index outside the matrix");
                                    YYERROR;
                                  }
                                  double aux= vc->value.values[(int)$3][0];
                                  $$=aux;
                                  }
    /*-----------END OF MATRIX ACCESS OPERATORS-----------*/


    /*-----------BEG OF FUNCTION CALLS-----------*/
    | ONE_OPERATOR_FUNCTION '(' EXPRESSION ')' {
                                  functionContent *fc= (functionContent*) $1->content;
                                  $$ = (*(fc->funcPointer))($3);
                                  }
    /*-----------END OF FUNCTION CALLS-----------*/


    /*-----------BEG OF POSTFIX INCREMENT AND DECREMENT-----------*/
    | VARIABLE OPE_PLUS_PLUS    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(isMatrix(vc)){
                                    showWarning("Accesing first element of matrix without [][] notation");
                                  }
                                  vc->value.values[0][0]++;
                                  $$=vc->value.values[0][0];
                                }
    | VARIABLE OPE_MINUS_MINUS  {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(isMatrix(vc)){
                                    showWarning("Accesing first element of matrix without [][] notation");
                                  }
                                  vc->value.values[0][0]--;
                                  $$=vc->value.values[0][0];
                                }
    /*-----------END OF POSTFIX INCREMENT AND DECREMENT-----------*/

    /*PARENTHESES*/
	  | '(' EXPRESSION ')'		     { $$ = $2; }

;


%%

void yyerror (char *s){
        manageNonFatalError(ERR_BISON, s);
}

void showWarning(char *s){
        manageWarning(WAR_BISON,s);
}


short defined(variableContent *vc,unsigned short assign){

return vc->defined;

  //if(!vc->defined){
    //We could not allow the operation by uncommenting the next line:
    //printf( RED "Variable %s not defined by user.\n" RESET,vc->name);
    /*if(assign){
    printf( YEL "Variable %s not defined by user, value of 0.0f assumed and obtained value assigned.\n" RESET,vc->name);
    }else{
    printf( YEL "Variable %s not defined by user, value of 0.0f assumed.\n" RESET,vc->name);
    }*/
  //  return 0;
//  }
//return 1;*/


}

short isMatrix(variableContent *vc){
  /*if(vc->value.rows==1 && vc->value.columns==1){
    return 0;
  }else{
    return 1;
  }*/
  return vc->value.defAsMatrix;
  //return ((vc->value.rows>1) || (vc->value.columns>1));
}

short isInBounds(int x, int y,variableContent *vc){
  /*if(vc->value.rows>x && vc->value.columns>y){
    return 1;
  }else{
    return 0;
  }*/
  return ((vc->value.rows>x) && (vc->value.columns>y));
}
