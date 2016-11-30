#include <stdio.h>
#include <stdlib.h>

int main() {
        printf("done");
        return 0;
}

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
