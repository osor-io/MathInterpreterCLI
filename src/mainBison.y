%{
#include <math.h>
#include "calc.h"
%}
%union {
        double val;
        symrec *tptr;
}
%token <val> NUM
%token <tptr> VAR FNCT
%type <val> exp
%right ’=’
%left ’-’ ’+’
%left ’*’ ’/’
%left NEG
%right ’^’

%%

input:
        | input line
;

line:
        ’\n’
        | exp ’\n’ { printf ("\t%.10g\n", $1); }
        | error ’\n’ { yyerrok; }
;

exp:     NUM { $$ = $1; }
        | VAR { $$ = $1->value.var; }
        | VAR ’=’ exp { $$ = $3; $1->value.var = $3; }
        | FNCT ’(’ exp ’)’ { $$ = (*($1->value.fnctptr))($3); }
        | exp ’+’ exp { $$ = $1 + $3; }
        | exp ’-’ exp { $$ = $1 - $3; }
        | exp ’*’ exp { $$ = $1 * $3; }
        | exp ’/’ exp { $$ = $1 / $3; }
        | ’-’ exp %prec NEG { $$ = -$2; }
        | exp ’^’ exp { $$ = pow ($1, $3); }
        | ’(’ exp ’)’ { $$ = $2; }
;

%%

#include <stdio.h>
main ()
{
        init_table ();
        yyparse ();
}
yyerror (s) /* Llamada por yyparse ante un error */
char *s;
{
        printf ("%s\n", s);
}
struct init
{
        char *fname;
        double (*fnct)();
};

struct init arith_fncts[]
        = {
        "sin", sin,
        "cos", cos,
        "atan", atan,
        "ln", log,
        "exp", exp,
        "sqrt", sqrt,
        0, 0
        };
/* La tabla de s´ımbolos: una cadena de ‘struct symrec’. */
symrec *sym_table = (symrec *)0;
init_table () /* pone las funciones aritm´eticas en una tabla. */
{
        int i;
        symrec *ptr;
        for (i = 0; arith_fncts[i].fname != 0; i++)
        {
                ptr = putsym (arith_fncts[i].fname, FNCT);
                ptr->value.fnctptr = arith_fncts[i].fnct;
        }
}
