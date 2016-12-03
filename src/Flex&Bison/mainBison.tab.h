/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     FLOAT_VALUE = 258,
     VARIABLE = 259,
     ONE_OPERATOR_FUNCTION = 260,
     END_OF_FILE = 261,
     OPE_SLASH_EQ = 262,
     OPE_AND_AND = 263,
     OPE_VERT_VERT = 264,
     OPE_MINUS_EQ = 265,
     OPE_MINUS_MINUS = 266,
     OPE_PLUS_EQ = 267,
     OPE_PLUS_PLUS = 268,
     OPE_LESSTHAN_EQ = 269,
     OPE_LESSTHAN_LESSTHAN = 270,
     OPE_LESSTHAN_LESSTHAN_EQ = 271,
     OPE_MORETHAN_EQ = 272,
     OPE_MORETHAN_MORETHAN_EQ = 273,
     OPE_MORETHAN_MORETHAN = 274,
     OPE_EXCL_EQ = 275,
     OPE_EQ_EQ = 276,
     OPE_TIMES_EQ = 277,
     OPE_PERC_EQ = 278,
     OPE_HAT_EQ = 279,
     NEWLINE = 280,
     QUIT = 281,
     HELP = 282,
     DECLARE = 283,
     EXISTS_VARIABLE = 284,
     CLEAR_VARIABLES = 285,
     LIST_VARIABLES = 286,
     NEGATE = 287
   };
#endif
/* Tokens.  */
#define FLOAT_VALUE 258
#define VARIABLE 259
#define ONE_OPERATOR_FUNCTION 260
#define END_OF_FILE 261
#define OPE_SLASH_EQ 262
#define OPE_AND_AND 263
#define OPE_VERT_VERT 264
#define OPE_MINUS_EQ 265
#define OPE_MINUS_MINUS 266
#define OPE_PLUS_EQ 267
#define OPE_PLUS_PLUS 268
#define OPE_LESSTHAN_EQ 269
#define OPE_LESSTHAN_LESSTHAN 270
#define OPE_LESSTHAN_LESSTHAN_EQ 271
#define OPE_MORETHAN_EQ 272
#define OPE_MORETHAN_MORETHAN_EQ 273
#define OPE_MORETHAN_MORETHAN 274
#define OPE_EXCL_EQ 275
#define OPE_EQ_EQ 276
#define OPE_TIMES_EQ 277
#define OPE_PERC_EQ 278
#define OPE_HAT_EQ 279
#define NEWLINE 280
#define QUIT 281
#define HELP 282
#define DECLARE 283
#define EXISTS_VARIABLE 284
#define CLEAR_VARIABLES 285
#define LIST_VARIABLES 286
#define NEGATE 287




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 34 "mainBison.y"
{
        variableValue matrixVal;
        double val;
        symbolData *pts;
}
/* Line 1529 of yacc.c.  */
#line 119 "mainBison.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

