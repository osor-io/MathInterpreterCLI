/*We make yywrap return 1 in order to finish everytime we find the end of the file.*/
%option noyywrap

%{
#include <stdio.h>
#include "../symbolTable/symbolTable.h"
#include "./mainBison.tab.h"
//#include "../MICLI/LANG_WORDS.h"


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

HexDigit [0-9A-F]

SciNo [Ee][+-]?{Digit}+

%%

  /*-----------------RULES-----------------*/

  /*RESERVED WORDS*/

("true"|"TRUE")   {yylval.val = 1;
                return(FLOAT_VALUE);}
("false"|"FALSE") {yylval.val = 0;
                return(FLOAT_VALUE);}

"exist"   {return EXISTS_VARIABLE;}
"clear"   {return CLEAR_VARIABLES;}
"who"     {return LIST_VARIABLES;}
"dec"     {return DECLARE;}
"help"		{/*Please*/return HELP;/*We are running out of food, water and lexical components*/}
"exit"		{return QUIT;}
"quit"		{return QUIT;}

  /*IDENTIFIERS OR FUNCTIONS*/

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

        /*((variableContent*)(sd->content))->value;*/

        ((variableContent*)(sd->content))->value.rows=1;
        ((variableContent*)(sd->content))->value.columns=1;


        ((variableContent*)(sd->content))->value.values = malloc(1 * sizeof(double*));
        for (int i = 0; i < 1; i++) {
              ((variableContent*)(sd->content))->value.values[i] = malloc(1 * sizeof(double));
        }

        ((variableContent*)(sd->content))->value.defAsMatrix=0;


        ((variableContent*)(sd->content))->defined=0;
        ((variableContent*)(sd->content))->name=lexeme;
        yylval.pts=sd;
        /*So we add it*/
        addLex(&global_st, lexeme, sd);
        return(VARIABLE);
      }else{
        if (sd->type == TYPE_VARIABLE) {
        /*It is an identifier but it is on the table already*/
          yylval.pts = sd;
          return(VARIABLE);
        }else{
        /*It is a reserved word so we return that it is a one operator function*/
          yylval.pts=sd;
          return(ONE_OPERATOR_FUNCTION);
        }
      }
  }

  /*INTEGER LITERALS*/

{Digit}({Digit})* 	{
                  yylval.val = atof(yytext);
                  return(FLOAT_VALUE);
						          }

  /*HEXADECIMAL LITERALS*/

("0x"|"0X"){HexDigit}({HexDigit})* 	{
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
"&&"		{ return(OPE_AND_AND);}
"||"		{ return(OPE_VERT_VERT);}
"-"		  { return('-');}
"-="		{ return(OPE_MINUS_EQ);}
"--"		{ return(OPE_MINUS_MINUS);}
"+"		  { return('+');}
"+="		{ return(OPE_PLUS_EQ);}
"++"		{ return(OPE_PLUS_PLUS);}
"<"		  { return('<');}
"<="		{ return(OPE_LESSTHAN_EQ);}
">"		  { return('>');}
">="		{ return(OPE_MORETHAN_EQ);}
"!"		  { return('!');}
"!="		{ return(OPE_EXCL_EQ);}
"("		{ return('(');}
")"		{ return(')');}
"["		{ return('[');}
"]"		{ return(']');}
";"		{ return(';');}
":"		{ return(':');}
"="		{ return('=');}
"=="	{ return(OPE_EQ_EQ);}
"*"		{ return('*');}
"*="	{ return(OPE_TIMES_EQ);}
"%"		{ return('%');}
"%="	{ return(OPE_PERC_EQ);}
"~"		{ return('~');}

    /*SPACES*/

{WhiteSpace}

\n		        {return NEWLINE;}

    /*END OF FILE*/

<<EOF>> {return(END_OF_FILE);}
