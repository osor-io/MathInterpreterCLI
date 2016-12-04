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
short isVector(variableContent *vc);
short isInBounds(int x, int y,variableContent *vc);
short isSingleNumber(variableValue vc);
short sameSize(variableValue vc1, variableValue vc2);

void defOneNumberMatrix(variableValue *vv, double number);
void copyMatrix (variableValue *dest, variableContent *vc);
void copyExpression (variableValue *dest, variableValue *src);
void copyExpressionWFree(variableValue *dest, variableValue *src);
void freeMatrix(variableValue *vv);
void generateMatrix (variableValue *dest, int rows, int columns);


%}

%error-verbose


%union {
        variableValue matrixVal;
        double val;
        symbolData *pts;
}

 /*%destructor  { printf("Discarding pointer to symbolData"); }*/


%token<val> NUMBER_LITERAL
%token<pts> VARIABLE ONE_OPERATOR_FUNCTION
%token END_OF_FILE
%token '+' '-' '*' '/' '(' ')' OPE_SLASH_EQ   OPE_AND_AND OPE_VERT_VERT OPE_MINUS_EQ OPE_MINUS_MINUS OPE_PLUS_EQ OPE_PLUS_PLUS '<' OPE_LESSTHAN_EQ   '>' OPE_MORETHAN_EQ   '!' OPE_EXCL_EQ OPE_EQ_EQ OPE_TIMES_EQ OPE_PERC_EQ  '[' ']' ';' '%'
%token NEW_LINE QUIT HELP DECLARE EXISTS_VARIABLE CLEAR_VARIABLES LIST_VARIABLES


%right OPE_PLUS_EQ OPE_MINUS_EQ
%right '=' OPE_SLASH_EQ  OPE_TIMES_EQ  OPE_PERC_EQ
%left OPE_VERT_VERT
%left OPE_AND_AND
%left OPE_EXCL_EQ OPE_EQ_EQ
%left '<' '>' OPE_LESSTHAN_EQ OPE_MORETHAN_EQ
%left '+' '-'
%left '*' '/' '%'
%right '!'
%left OPE_MINUS_MINUS OPE_PLUS_PLUS '[' ']' '(' ')'

%left NEGATE

%type<matrixVal> EXPRESSION

%start calculation

%%



calculation:
	   | calculation line
;

line: NEW_LINE
    | declaration NEW_LINE         { printf( BLU "\tSuccesfull declaration\n" RESET); }
    | declaration ';' NEW_LINE     { }
    | EXPRESSION ';' NEW_LINE      { }
    | EXPRESSION NEW_LINE          { printf(BLU);
                                    printMatrix($1);
                                    printf(RESET);
                                  }
    | error NEW_LINE               { yyerrok; }
    | HELP NEW_LINE                { printfHelp(); }
    | QUIT NEW_LINE                { YYACCEPT; }
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

                                  if(!isSingleNumber($4)){
                                    yyerror("Row number is a matrix");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber($7)){
                                    yyerror("Column number is a matrix");
                                    YYERROR;
                                  }


                                  free(vc->value.values[0]);
                                  free(vc->value.values);

                                  int rows=(int)$4.values[0][0];
                                  int columns=(int)$7.values[0][0];

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
                                  freeMatrix(&$4);
                                  freeMatrix(&$7);
                                }

 | DECLARE VARIABLE '[' EXPRESSION ']'{
                                  variableContent *vc= (variableContent*) $2->content;
                                  if(defined(vc,0)){
                                    yyerror("Matrix already declared");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber($4)){
                                    yyerror("Vector size is a matrix");
                                    YYERROR;
                                  }

                                  free(vc->value.values[0]);
                                  free(vc->value.values);

                                  int rows=(int)$4.values[0][0];
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
                                  freeMatrix(&$4);

                                }
 | DECLARE VARIABLE   {
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

EXPRESSION: NUMBER_LITERAL          {
                                  defOneNumberMatrix(&$$,$1);

                                }
    | VARIABLE                   {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,0)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  copyMatrix(&$$,vc);
                                  //printMatrix($$);
                                 }

    /*-----------BEG OF ASSIGNING OPERATORS-----------*/
    | VARIABLE '=' EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,0)){
                                    showWarning("Implicit declaration with assignment");
                                  }
                                  if(!sameSize(vc->value,$3)){
                                    yyerror("Variable is not the same size (rows and columns) as the expresion.");
                                    YYERROR;
                                  }
                                  freeMatrix(&vc->value);
                                  copyExpression(&(vc->value),&($3));
                                  vc->defined=1;
                                  copyExpression(&$$,&($3));
                                  freeMatrix(&$3);
                                  }
    | VARIABLE '[' EXPRESSION ']' '[' EXPRESSION ']' '=' EXPRESSION {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,0)){
                                    yyerror("Matrix not declared");
                                    YYERROR;
                                  }
                                  if(!isMatrix(vc)){
                                    yyerror("That element is not a matrix");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber($3)){
                                    yyerror("First expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber($6)){
                                    yyerror("Second expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber($9)){
                                    yyerror("Number assigned expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isInBounds($3.values[0][0],$6.values[0][0],vc)){
                                    yyerror("Index outside the matrix");
                                    YYERROR;
                                  }
                                  vc->value.values[(int)$3.values[0][0]][(int)$6.values[0][0]]=$9.values[0][0];
                                  double aux= vc->value.values[(int)$3.values[0][0]][(int)$6.values[0][0]];
                                  defOneNumberMatrix(&$$,aux);
                                  }

    | VARIABLE '[' EXPRESSION ']' '=' EXPRESSION{
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,0)){
                                    yyerror("Vector not declared");
                                    YYERROR;
                                  }
                                  if(!isVector(vc)){
                                    yyerror("That element is not a vector");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber($3)){
                                    yyerror("First expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isInBounds($3.values[0][0],0,vc)){
                                    yyerror("Index outside the matrix");
                                    YYERROR;
                                  }
                                  double aux= vc->value.values[(int)$3.values[0][0]][0];
                                  defOneNumberMatrix(&$$,aux);
                                  }
    | VARIABLE  OPE_SLASH_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber(vc->value)){
                                    showWarning("Doing operation to all elements in the matrix");
                                  }
                                  if(!isSingleNumber($3)){
                                    yyerror("Expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if($3.values[0][0]==0){
                                    yyerror("You cannot divide by zero");
                                    YYERROR;
                                  }
                                  int i,j;
                                  for (i=0;i<vc->value.rows;i++){
                                        for (j=0;j<vc->value.columns;j++)
                                        {
                                        vc->value.values[i][j] /= $3.values[0][0];
                                        }
                                  }
                                  copyMatrix(&$$,vc);
                                  freeMatrix(&$3);
                                  }
    | VARIABLE OPE_MINUS_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(isSingleNumber($3)){
                                        int i,j;
                                        for (i=0;i<vc->value.rows;i++){
                                              for (j=0;j<vc->value.columns;j++)
                                              {
                                              vc->value.values[i][j] -= $3.values[0][0];
                                              }
                                        }
                                        copyMatrix(&$$,vc);
                                        freeMatrix(&$3);
                                  }else{
                                        if(!sameSize(vc->value,$3)){
                                          yyerror("Expresion does not match required size (rows and columns)");
                                          YYERROR;
                                        }
                                        int i,j;
                                        for (i=0;i<vc->value.rows;i++){
                                              for (j=0;j<vc->value.columns;j++)
                                              {
                                              vc->value.values[i][j] -= $3.values[i][j];
                                              }
                                        }
                                        copyMatrix(&$$,vc);
                                        freeMatrix(&$3);
                                  }
                                  }
    | VARIABLE OPE_PLUS_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }

                                  if(isSingleNumber($3)){
                                        int i,j;
                                        for (i=0;i<vc->value.rows;i++){
                                              for (j=0;j<vc->value.columns;j++)
                                              {
                                              vc->value.values[i][j] += $3.values[0][0];
                                              }
                                        }
                                        copyMatrix(&$$,vc);
                                        freeMatrix(&$3);
                                  }else{
                                        if(!sameSize(vc->value,$3)){
                                          yyerror("Expresion does not match required size (rows and columns)");
                                          YYERROR;
                                        }
                                        int i,j;
                                        for (i=0;i<vc->value.rows;i++){
                                              for (j=0;j<vc->value.columns;j++)
                                              {
                                              vc->value.values[i][j] += $3.values[i][j];
                                              }
                                        }
                                        copyMatrix(&$$,vc);
                                        freeMatrix(&$3);
                                  }
                                  }
    | VARIABLE OPE_TIMES_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  variableValue vv = vc->value;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(isSingleNumber($3)){

                                          int i,j;
                                          for (i=0;i<vc->value.rows;i++){
                                                for (j=0;j<vc->value.columns;j++)
                                                {
                                                vc->value.values[i][j] *= $3.values[0][0];
                                                }
                                          }
                                          copyMatrix(&$$,vc);
                                          freeMatrix(&$3);
                                  }else{
                                          if((vv.columns != $3.rows) || ((vv.rows != $3.columns))){
                                            yyerror("Matrices must be the same size");
                                            YYERROR;
                                          }
                                          int i,j,k;
                                          generateMatrix(&$$,vv.rows,$3.columns);
                                          for (i=0;i<$$.rows;i++){
                                                for (j=0;j<$$.columns;j++){
                                                    $$.values[i][j]=0;
                                                    for(k=0;k<vv.columns;k++){
                                                        $$.values[i][j]+=vv.values[i][k]*$3.values[k][j];
                                                    }
                                                }
                                          }
                                          copyExpression(&(vc->value),&$$);
                                          freeMatrix(&$3);
                                  }
                                  }
    | VARIABLE OPE_PERC_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber($3)){
                                    yyerror("Expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  int i,j;
                                  for (i=0;i<vc->value.rows;i++){
                                        for (j=0;j<vc->value.columns;j++)
                                        {
                                        vc->value.values[i][j] = fmod(vc->value.values[i][j],$3.values[0][0]);
                                        }
                                  }
                                  copyMatrix(&$$,vc);
                                  freeMatrix(&$3);
                                  }
    /*-----------END OF ASSIGNING OPERATORS-----------*/

      /* LOGICAL OR */
    | EXPRESSION OPE_VERT_VERT EXPRESSION    {

                                  if(!sameSize($1,$3) && (!isSingleNumber($3))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$1.rows;i++){
                                        for (j=0;j<$1.columns;j++)
                                        {
                                          if(isSingleNumber($3)){
                                            $$.values[i][j] = ($1.values[i][j]) || ($3.values[0][0]);
                                          }else{
                                            $$.values[i][j] = ($1.values[i][j]) || ($3.values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                  }


      /* LOGICAL AND */
    | EXPRESSION OPE_AND_AND EXPRESSION    {
                                  if(!sameSize($1,$3) && (!isSingleNumber($3))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$1.rows;i++){
                                        for (j=0;j<$1.columns;j++)
                                        {
                                          if(isSingleNumber($3)){
                                            $$.values[i][j] = ($1.values[i][j]) && ($3.values[0][0]);
                                          }else{
                                            $$.values[i][j] = ($1.values[i][j]) && ($3.values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                  }



    /*-----------BEG OF COMPARISON OPERATORS-----------*/
    | EXPRESSION OPE_EQ_EQ EXPRESSION     {
                                  if(!sameSize($1,$3) && (!isSingleNumber($3))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$1.rows;i++){
                                        for (j=0;j<$1.columns;j++)
                                        {
                                          if(isSingleNumber($3)){
                                            $$.values[i][j] = ($1.values[i][j]) == ($3.values[0][0]);
                                          }else{
                                            $$.values[i][j] = ($1.values[i][j]) == ($3.values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                  }
    | EXPRESSION OPE_EXCL_EQ EXPRESSION     {
                                  if(!sameSize($1,$3) && (!isSingleNumber($3))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$1.rows;i++){
                                        for (j=0;j<$1.columns;j++)
                                        {
                                          if(isSingleNumber($3)){
                                            $$.values[i][j] = ($1.values[i][j]) != ($3.values[0][0]);
                                          }else{
                                            $$.values[i][j] = ($1.values[i][j]) != ($3.values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                  }

    | EXPRESSION '>' EXPRESSION     {
                                  if(!sameSize($1,$3) && (!isSingleNumber($3))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$1.rows;i++){
                                        for (j=0;j<$1.columns;j++)
                                        {
                                          if(isSingleNumber($3)){
                                            $$.values[i][j] = ($1.values[i][j]) > ($3.values[0][0]);
                                          }else{
                                            $$.values[i][j] = ($1.values[i][j]) > ($3.values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                  }
    | EXPRESSION OPE_MORETHAN_EQ EXPRESSION    {
                                  if(!sameSize($1,$3) && (!isSingleNumber($3))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$1.rows;i++){
                                        for (j=0;j<$1.columns;j++)
                                        {
                                          if(isSingleNumber($3)){
                                            $$.values[i][j] = ($1.values[i][j]) >= ($3.values[0][0]);
                                          }else{
                                            $$.values[i][j] = ($1.values[i][j]) >= ($3.values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                  }

    | EXPRESSION '<' EXPRESSION    {
                                  if(!sameSize($1,$3) && (!isSingleNumber($3))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$1.rows;i++){
                                        for (j=0;j<$1.columns;j++)
                                        {
                                          if(isSingleNumber($3)){
                                            $$.values[i][j] = ($1.values[i][j]) < ($3.values[0][0]);
                                          }else{
                                            $$.values[i][j] = ($1.values[i][j]) < ($3.values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                  }
    | EXPRESSION OPE_LESSTHAN_EQ EXPRESSION   {
                                  if(!sameSize($1,$3) && (!isSingleNumber($3))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$1.rows;i++){
                                        for (j=0;j<$1.columns;j++)
                                        {
                                          if(isSingleNumber($3)){
                                            $$.values[i][j] = ($1.values[i][j]) <= ($3.values[0][0]);
                                          }else{
                                            $$.values[i][j] = ($1.values[i][j]) <= ($3.values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                  }
    /*-----------END OF COMPARISON OPERATORS-----------*/

    /*-----------BEG OF SUM OPERATORS-----------*/
	  | EXPRESSION '+' EXPRESSION	 {
                                  if(!sameSize($1,$3) && (!isSingleNumber($3))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$1.rows;i++){
                                        for (j=0;j<$1.columns;j++)
                                        {
                                          if(isSingleNumber($3)){
                                            $$.values[i][j] = ($1.values[i][j]) + ($3.values[0][0]);
                                          }else{
                                            $$.values[i][j] = ($1.values[i][j]) + ($3.values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                  }
	  | EXPRESSION '-' EXPRESSION	 {
                                  if(!sameSize($1,$3) && (!isSingleNumber($3))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$1.rows;i++){
                                        for (j=0;j<$1.columns;j++)
                                        {
                                          if(isSingleNumber($3)){
                                            $$.values[i][j] = ($1.values[i][j]) - ($3.values[0][0]);
                                          }else{
                                            $$.values[i][j] = ($1.values[i][j]) - ($3.values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                  }
    /*-----------END OF SUM OPERATORS-----------*/

    /*-----------BEG OF PLUS OPERATORS-----------*/
  | EXPRESSION '*' EXPRESSION  {
                                if(isSingleNumber($3)){
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$1.rows;i++){
                                        for (j=0;j<$1.columns;j++)
                                        {
                                            $$.values[i][j] = ($1.values[i][j]) * ($3.values[0][0]);
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                }else{
                                      if($1.columns != $3.rows){
                                        yyerror("Rows of the first matrix must match columns of the second one");
                                        YYERROR;
                                      }
                                      int i,j,k;
                                      generateMatrix(&$$,$1.rows,$3.columns);
                                      for (i=0;i<$$.rows;i++){
                                            for (j=0;j<$$.columns;j++){
                                                $$.values[i][j]=0;
                                                for(k=0;k<$1.columns;k++){
                                                    $$.values[i][j]+=$1.values[i][k]*$3.values[k][j];
                                                }
                                            }
                                      }
                                      freeMatrix(&$1);
                                      freeMatrix(&$3);
                                      }
                              }
	  | EXPRESSION '/' EXPRESSION	 {
                                  if(!isSingleNumber($3)){
                                    yyerror("Second expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if($3.values[0][0]==0){
                                    yyerror("You cannot divide by zero");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$1.rows;i++){
                                        for (j=0;j<$1.columns;j++)
                                        {
                                            $$.values[i][j] = ($1.values[i][j]) / ($3.values[0][0]);
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                  }
    | EXPRESSION '%' EXPRESSION	 {
                                  if(!isSingleNumber($3)){
                                    yyerror("Second expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&$$,&$1);
                                  for (i=0;i<$$.rows;i++){
                                        for (j=0;j<$$.columns;j++)
                                        {
                                        $$.values[i][j] = fmod($1.values[i][j],$3.values[0][0]);
                                        }
                                  }
                                  freeMatrix(&$1);
                                  freeMatrix(&$3);
                                  }
    /*-----------END OF PLUS OPERATORS-----------*/


    /* LOGICAL NOT */
    | '!' EXPRESSION  {
                      int i,j;
                      copyExpression(&$$,&$2);
                      for (i=0;i<$$.rows;i++){
                            for (j=0;j<$$.columns;j++)
                            {
                            $$.values[i][j] = !($2.values[i][j]);
                            }
                      }
                      freeMatrix(&$2);
                      }

    /*-----------BEG OF UNARY PLUS AND MINUS OPERATORS-----------*/
    | '-' EXPRESSION %prec NEGATE  {
                                  int i,j;
                                  copyExpression(&$$,&$2);
                                  for (i=0;i<$$.rows;i++){
                                        for (j=0;j<$$.columns;j++)
                                        {
                                        $$.values[i][j] = -($2.values[i][j]);
                                        }
                                  }
                                  freeMatrix(&$2);
                                  }
    | '+' EXPRESSION  {
                      int i,j;
                      copyExpression(&$$,&$2);
                      for (i=0;i<$$.rows;i++){
                            for (j=0;j<$$.columns;j++)
                            {
                            $$.values[i][j] = +($2.values[i][j]);
                            }
                      }
                      freeMatrix(&$2);
                      }
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
                                  if(!isSingleNumber($3)){
                                    yyerror("First expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber($6)){
                                    yyerror("First expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isInBounds($3.values[0][0],$6.values[0][0],vc)){
                                    yyerror("Index outside the matrix");
                                    YYERROR;
                                  }
                                  double aux= vc->value.values[(int)$3.values[0][0]][(int)$6.values[0][0]];
                                  defOneNumberMatrix(&$$,aux);
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
                                  if(!isSingleNumber($3)){
                                    yyerror("First expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isInBounds($3.values[0][0],0,vc)){
                                    yyerror("Index outside the matrix");
                                    YYERROR;
                                  }
                                  double aux= vc->value.values[(int)$3.values[0][0]][0];
                                  defOneNumberMatrix(&$$,aux);
                                  }
    /*-----------END OF MATRIX ACCESS OPERATORS-----------*/


    /*-----------BEG OF FUNCTION CALLS-----------*/
    | ONE_OPERATOR_FUNCTION '(' EXPRESSION ')' {
                                  functionContent *fc= (functionContent*) $1->content;
                                  if(!isSingleNumber($3)){
                                    yyerror("Functions only applyable to single numbers");
                                    YYERROR;
                                  }
                                  double aux = (*(fc->funcPointer))($3.values[0][0]);
                                  defOneNumberMatrix(&$$,aux);
                                  }
    /*-----------END OF FUNCTION CALLS-----------*/


    /*-----------BEG OF POSTFIX INCREMENT AND DECREMENT-----------*/
    | VARIABLE OPE_PLUS_PLUS    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber(vc->value)){
                                    yyerror("Trying to use '++' operator on matrix, use 'matrix += 1' instead");
                                    YYERROR;
                                  }
                                  vc->value.values[0][0]++;
                                  copyMatrix(&$$,vc);
                                }
    | VARIABLE OPE_MINUS_MINUS  {
                                  variableContent *vc= (variableContent*) $1->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber(vc->value)){
                                    yyerror("Trying to use '++' operator on matrix, use 'matrix = matrix.+ 1' instead");
                                    YYERROR;
                                  }
                                  vc->value.values[0][0]--;
                                  copyMatrix(&$$,vc);
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

short isSingleNumber(variableValue vv){
  return ((vv.rows==1) && (vv.columns==1));
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

short isVector(variableContent *vc){
  //return vc->value.defAsMatrix;
  return ((vc->value.rows>0) && (vc->value.columns==1) && vc->value.defAsMatrix);
}

short isInBounds(int x, int y,variableContent *vc){
  /*if(vc->value.rows>x && vc->value.columns>y){
    return 1;
  }else{
    return 0;
  }*/
  return ((vc->value.rows>x) && (vc->value.columns>y) && x>=0 && y>=0 );
}

void copyMatrix (variableValue *dest, variableContent *vc) {
  int i;
  dest->rows=vc->value.rows;
  dest->columns=vc->value.columns;
  dest->defAsMatrix=vc->value.defAsMatrix;
  dest->values = malloc(sizeof(double*)* vc->value.rows);
  memcpy(dest->values,vc->value.values,vc->value.rows*sizeof(double*));
  for(i = 0; i < vc->value.rows ; ++ i){
    dest->values[i]=malloc(vc->value.columns * sizeof(double));
    memcpy(dest->values[i], vc->value.values[i], vc->value.columns * sizeof(double));
  }
}

void freeMatrix(variableValue *vv){
  if(vv){
    int i;
    for(i=0;i<vv->rows;i++){
      free(vv->values[i]);
    }
    free(vv->values);
  }
}


short sameSize(variableValue vc1, variableValue vc2){
  return ((vc1.rows==vc2.rows) && (vc1.columns==vc2.columns));
}

void defOneNumberMatrix(variableValue *vv, double number){
  vv->rows = 1;
  vv->columns = 1;
  vv->values=malloc(sizeof(double*));
  vv->values[0] = malloc(sizeof(double));
  vv->values[0][0] = number;
  vv->defAsMatrix=0;
}

void copyExpression (variableValue *dest, variableValue *src){
  int i;
  dest->rows=src->rows;
  dest->columns=src->columns;
  dest->defAsMatrix=src->defAsMatrix;
  dest->values = malloc(sizeof(double*)*src->rows);
  memcpy(dest->values,src->values,src->rows*sizeof(double*));
  for(i = 0; i < src->rows ; ++ i){
    dest->values[i]=malloc(src->columns * sizeof(double));
    memcpy(dest->values[i], src->values[i], src->columns * sizeof(double));
  }
}

void generateMatrix (variableValue *dest, int rows, int columns){
  int i;
  dest->rows=rows;
  dest->columns=columns;
  dest->defAsMatrix=1;
  dest->values = malloc(sizeof(double*)*rows);
  for(i = 0; i < rows ; ++ i){
    dest->values[i]=malloc(columns * sizeof(double));
  }
}

void copyExpressionWFree(variableValue *dest, variableValue *src){
  int i;
  dest->rows=src->rows;
  dest->columns=src->columns;
  dest->defAsMatrix=src->defAsMatrix;

  for(i = 0; i < src->rows ; ++ i){
    free(dest->values[i]);
  }
  free(dest->values);

  dest->values = malloc(sizeof(double*) * (src->rows));
  memcpy(dest->values,src->values,(src->rows) * sizeof(double*));
  for(i = 0; i < src->rows ; ++ i){
    dest->values[i]=malloc(src->columns * sizeof(double));
    memcpy(dest->values[i], src->values[i], src->columns * sizeof(double));
  }


}
