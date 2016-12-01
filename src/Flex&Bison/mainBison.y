%{
#include <math.h>
#include "../symbolTable/symbolTable.h"
#include <stdio.h>
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
void checkDefined(variableContent *vc,unsigned short assign);

%}

/*%define parse.lac full*/
%error-verbose

%union {
        double val;
        symbolData *pts;
}

%token<val> FLOAT_VALUE
%token<pts> VARIABLE ONE_OPERATOR_FUNCTION
%token END_OF_FILE
%token '+' '-' '*' '/' '(' ')' OPE_SLASH_EQ '&'  OPE_AND_AND '|' OPE_VERT_VERT OPE_MINUS_EQ OPE_MINUS_MINUS OPE_PLUS_EQ OPE_PLUS_PLUS '<' OPE_LESSTHAN_EQ OPE_LESSTHAN_LESSTHAN OPE_LESSTHAN_LESSTHAN_EQ '>' OPE_MORETHAN_EQ OPE_MORETHAN_MORETHAN_EQ OPE_MORETHAN_MORETHAN '!' OPE_EXCL_EQ OPE_EQ_EQ OPE_TIMES_EQ OPE_PERC_EQ OPE_HAT_EQ '[' ']' ';' '%' '~'
%token NEWLINE QUIT HELP


%right '=' OPE_SLASH_EQ OPE_MINUS_EQ OPE_PLUS_EQ OPE_TIMES_EQ  OPE_PERC_EQ '!' '~'
%left '+' '-'
%left OPE_AND_AND OPE_VERT_VERT OPE_MINUS_MINUS OPE_PLUS_PLUS '<' '>' OPE_LESSTHAN_EQ OPE_LESSTHAN_LESSTHAN OPE_MORETHAN_EQ OPE_MORETHAN_MORETHAN OPE_EXCL_EQ OPE_EQ_EQ
%left '*' '/' '%'
%left NEGATE


%type<val> EXPRESSION

%start calculation

%%

calculation:
	   | calculation line
;

line: NEWLINE
    | EXPRESSION ';' NEWLINE      { printf( BLU "\t%f\n" RESET, $1);}
    | EXPRESSION NEWLINE          { printf( BLU "\tOK\n" RESET );}
    | error NEWLINE               { yyerrok; }
    | HELP NEWLINE                { printfHelp(); }
    | QUIT NEWLINE                { YYACCEPT; }
    | END_OF_FILE                 { YYACCEPT; }
;

EXPRESSION: FLOAT_VALUE          { $$ = $1; }
    | VARIABLE                   {
                                  variableContent *vc= (variableContent*) $1->content;
                                  checkDefined(vc,0);
                                  $$ = vc->value;
                                 }

    /*-----------BEG OF ASSIGNING OPERATORS-----------*/
    | VARIABLE '=' EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  vc->value=$3;
                                  vc->defined=1;
                                  $$=$3;
                                  }
    | VARIABLE OPE_SLASH_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  vc->value/=$3;
                                  checkDefined(vc,1);
                                  $$=vc->value;
                                  }
    | VARIABLE OPE_MINUS_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  vc->value-=$3;
                                  checkDefined(vc,1);
                                  $$=vc->value;
                                  }
    | VARIABLE OPE_PLUS_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  vc->value+=$3;
                                  checkDefined(vc,1);
                                  $$=vc->value;
                                  }
    | VARIABLE OPE_TIMES_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  vc->value*=$3;
                                  checkDefined(vc,1);
                                  $$=vc->value;
                                  }
    | VARIABLE OPE_PERC_EQ EXPRESSION    {
                                  variableContent *vc= (variableContent*) $1->content;
                                  vc->value=fmod(vc->value,$3);
                                  checkDefined(vc,1);
                                  $$=vc->value;
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
    /*TODO*/
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
                                  vc->value++;
                                  checkDefined(vc,1);
                                  $$=vc->value;
                                }
    | VARIABLE OPE_MINUS_MINUS  {
                                  variableContent *vc= (variableContent*) $1->content;
                                  vc->value--;
                                  checkDefined(vc,1);
                                  $$=vc->value;
                                }
    /*-----------END OF POSTFIX INCREMENT AND DECREMENT-----------*/

    /*PARENTHESES*/
	  | '(' EXPRESSION ')'		     { $$ = $2; }

;


%%

void yyerror (char *s){
        manageNonFatalError(ERR_BISON, s);
}
void checkDefined(variableContent *vc,unsigned short assign){
  if(!vc->defined){
    //We could not allow the operation by uncommenting the next line:
    //YYERROR;
    if(assign){
    printf( YEL "Variable %s not defined by user, value of 0.0f assumed and obtained value assigned.\n" RESET,vc->name);
    }else{
    printf( YEL "Variable %s not defined by user, value of 0.0f assumed.\n" RESET,vc->name);
    }
  }
}
