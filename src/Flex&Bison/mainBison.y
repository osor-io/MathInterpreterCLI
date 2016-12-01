%{
#include <math.h>
#include "../symbolTable/symbolTable.h"
#include "../MICLI/LANG_WORDS.h"


extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);

%}


%union {
        double val;
        symbolData *pts;
}

%token<val> FLOAT_VALUE
%token '+' '-' '*' '/' '(' ')'
%token NEWLINE QUIT
%left '+' '-'
%left '*' '/'

%type<val> mixed_expression

%start calculation

%%

calculation:
	   | calculation line
;

line: NEWLINE
    | mixed_expression NEWLINE { printf("\tResult: %f\n", $1);}
    | QUIT NEWLINE { printf("bye!\n"); exit(0); }
;

mixed_expression: FLOAT_VALUE                 		 { $$ = $1; }
	  | mixed_expression '+' mixed_expression	 { $$ = $1 + $3; }
	  | mixed_expression '-' mixed_expression	 { $$ = $1 - $3; }
	  | mixed_expression '*' mixed_expression { $$ = $1 * $3; }
	  | mixed_expression '/' mixed_expression	 { $$ = $1 / $3; }
	  | '(' mixed_expression ')'		 { $$ = $2; }
;


%%

void yyerror (const char *s){
        printf ("ERROR: %s\n", s);
}
