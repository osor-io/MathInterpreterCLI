/*We make yywrap return 1 in order to finish everytime we find the end of the file.*/
%option noyywrap

%{
#include <stdio.h>
#include "../symbolTable/symbolTable.h"
#include "../MICLI/LANG_WORDS.h"


/*
Reference to the global symbol table
*/
extern symbolTable *global_st;


%}

/*--------------DEFINITIONS--------------*/

Character .

WhiteSpace [ \t\v\f]

BegOfLineComment "//"

IdentifierStart [[:alpha:]_]

IdentifierChar [[:digit:][:alpha:]_]

Identifier {IdentifierStart}{IdentifierChar}*

Digit [0-9]

SciNo [Ee][+-]?{Digit}+

%%

  /*-----------------RULES-----------------*/

"exit"		{return QUIT;}
"quit"		{return QUIT;}

  /*IDENTIFIERS OR RESERVED WORDS*/

{Identifier}    {
      /*
      Here we check if our alphanumeric string is in the symbol table and
      if it is a reserved word or an identifier.
      */
      symbolData *sd = searchLex(global_st, yytext);
      if (sd == NULL) {
        /*It is an identifier and it is not on the table*/
        char * lexeme;
        sd = (symbolData *) malloc(sizeof(symbolData));
        sd->type = TYPE_VARIABLE;
        lexeme = (char *) malloc((strlen(yytext) + 1) * sizeof(char));
        strcpy(lexeme,yytext);
        sd->content=malloc(sizeof(variableContent));

        /*So we add it*/
        addLex(&global_st, lexeme, sd);
                        return(IDENTIFIER);
      }else{
        if (sd->type == TYPE_VARIABLE) {
        /*It is an identifier but it is on the table already*/
          yylval.val = sd->content->value;
          return(IDENTIFIER);
        }else{
        /*It is a reserved word so we return that it is a one operator function*/
          yylval.pts=sd;
          return(ONE_OPERATOR_FUNCTION);
        }
      }
  }

  /*INTEGER LITERALS*/

{Digit}({Digit}|_)* 	{
                  yylval.val = atof(yytext);
                  return(FLOAT_VALUE);
						          }


	/*FLOATING LITERALS*/

{Digit}*"."{Digit}+({SciNo})?		|
{Digit}+("."{Digit}*)?({SciNo})?	{
                  yylval.val = atof(yytext);
									return(FLOAT_VALUE);
									}

                 /*OPERATORS*/


"/"		  { return('/');}
"/="	  { return(OPE_SLASH_EQ);}
"."		  { return('.');}
".."		{ return(OPE_TWO_POINTS);}
"..."		{ return(OPE_THREE_POINTS);}
"&"	  	{ return('&');}
"&="		{ return(OPE_AND_EQ);}
"&&"		{ return(OPE_AND_AND);}
"|"		  { return('|');}
"|="		{ return(OPE_VERT_EQ);}
"||"		{ return(OPE_VERT_VERT);}
"-"		  { return('-');}
"-="		{ return(OPE_MINUS_EQ);}
"--"		{ return(OPE_MINUS_MINUS);}
"+"		  { return('+');}
"+="		{ return(OPE_PLUS_EQ);}
"++"		{ return(OPE_PLUS_PLUS);}
"<"		  { return('<');}
"<="		{ return(OPE_LESSTHAN_EQ);}
"<<"		{ return(OPE_LESSTHAN_LESSTHAN);}
"<<="		{ return(OPE_LESSTHAN_LESSTHAN_EQ);}
"<>"		{ return(OPE_LESSTHAN_MORETHAN);}
"<>="		{ return(OPE_LESSTHAN_MORETHAN_EQ);}
">"		  { return('>');}
">="		{ return(OPE_MORETHAN_EQ);}
">>="		{ return(OPE_MORETHAN_MORETHAN_EQ);}
">>>="	{ return(OPE_MORETHAN_MORETHAN_MORETHAN_EQ);}
">>"		{ return(OPE_MORETHAN_MORETHAN);}
">>>"		{ return(OPE_MORETHAN_MORETHAN_MORETHAN);}
"!"		  { return('!');}
"!="		{ return(OPE_EXCL_EQ);}
"!<>"		{ return(OPE_EXCL_LESSTHAN_MORETHAN);}
"!<>="	{ return(OPE_EXCL_LESSTHAN_MORETHAN_EQ);}
"!<"		{ return(OPE_EXCL_LESSTHAN);}
"!<="		{ return(OPE_EXCL_LESSTHAN_MORETHAN_EQ);}
"!>"		{ return(OPE_EXCL_MORETHAN);}
"!>="		{ return(OPE_EXCL_MORETHAN_EQ);}
"("		{ return('(');}
")"		{ return(')');}
"["		{ return('[');}
"]"		{ return(']');}
"{"		{ return('{');}      /*{*/
"}"		{ return('}');}      /*}*/
"?"		{ return('?');}
","		{ return(',');}
";"		{ return(';');}
":"		{ return(':');}
"$"		{ return('$');}
"="		{ return('=');}
"=="	{ return(OPE_EQ_EQ);}
"*"		{ return('*');}
"*="	{ return(OPE_TIMES_EQ);}
"%"		{ return('%');}
"%="	{ return(OPE_PERC_EQ);}
"^"		{ return('^');}
"^="	{ return(OPE_HAT_EQ);}
"^^"	{ return(OPE_HAT_HAT);}
"^^="	{ return(OPE_HAT_HAT_EQ);}
"~"		{ return('~');}
"~="	{ return(OPE_VIRG_EQ);}
"@"		{ return('@');}
"=>"	{ return(OPE_EQ_MORE);}
"#"		{ return('#');}

    /*SPACES*/

{WhiteSpace}

\n		        {return NEWLINE;}

    /*END OF FILE*/

<<EOF>>       {return(END_OF_FILE);}
