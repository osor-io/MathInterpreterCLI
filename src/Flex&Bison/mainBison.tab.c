/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER_LITERAL = 258,
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
     OPE_MORETHAN_EQ = 270,
     OPE_EXCL_EQ = 271,
     OPE_EQ_EQ = 272,
     OPE_TIMES_EQ = 273,
     OPE_PERC_EQ = 274,
     NEW_LINE = 275,
     QUIT = 276,
     HELP = 277,
     DECLARE = 278,
     NEGATE = 279
   };
#endif
/* Tokens.  */
#define NUMBER_LITERAL 258
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
#define OPE_MORETHAN_EQ 270
#define OPE_EXCL_EQ 271
#define OPE_EQ_EQ 272
#define OPE_TIMES_EQ 273
#define OPE_PERC_EQ 274
#define NEW_LINE 275
#define QUIT 276
#define HELP 277
#define DECLARE 278
#define NEGATE 279




/* Copy the first part of user declarations.  */
#line 1 "mainBison.y"

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




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 44 "mainBison.y"
{
        variableValue matrixVal;
        double val;
        symbolData *pts;
}
/* Line 193 of yacc.c.  */
#line 190 "mainBison.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 203 "mainBison.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   349

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  5
/* YYNRULES -- Number of rules.  */
#define YYNRULES  47
/* YYNRULES -- Number of states.  */
#define YYNSTATES  93

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    23,     2,     2,     2,    32,     2,     2,
      11,    12,     9,     7,     2,     8,     2,    10,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
      19,    37,    21,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    28,     2,    30,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,    13,    14,    15,    16,    17,    18,    20,    22,
      24,    25,    26,    27,    29,    33,    34,    35,    36,    38
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     4,     7,     9,    12,    16,    20,    23,
      26,    29,    32,    34,    43,    49,    52,    54,    56,    60,
      70,    77,    81,    85,    89,    93,    97,   101,   105,   109,
     113,   117,   121,   125,   129,   133,   137,   141,   145,   149,
     152,   155,   158,   166,   171,   176,   179,   182
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      40,     0,    -1,    -1,    40,    41,    -1,    33,    -1,    42,
      33,    -1,    42,    31,    33,    -1,    43,    31,    33,    -1,
      43,    33,    -1,     1,    33,    -1,    35,    33,    -1,    34,
      33,    -1,     6,    -1,    36,     4,    28,    43,    30,    28,
      43,    30,    -1,    36,     4,    28,    43,    30,    -1,    36,
       4,    -1,     3,    -1,     4,    -1,     4,    37,    43,    -1,
       4,    28,    43,    30,    28,    43,    30,    37,    43,    -1,
       4,    28,    43,    30,    37,    43,    -1,     4,    13,    43,
      -1,     4,    16,    43,    -1,     4,    18,    43,    -1,     4,
      27,    43,    -1,     4,    29,    43,    -1,    43,    15,    43,
      -1,    43,    14,    43,    -1,    43,    26,    43,    -1,    43,
      25,    43,    -1,    43,    21,    43,    -1,    43,    24,    43,
      -1,    43,    19,    43,    -1,    43,    22,    43,    -1,    43,
       7,    43,    -1,    43,     8,    43,    -1,    43,     9,    43,
      -1,    43,    10,    43,    -1,    43,    32,    43,    -1,    23,
      43,    -1,     8,    43,    -1,     7,    43,    -1,     4,    28,
      43,    30,    28,    43,    30,    -1,     4,    28,    43,    30,
      -1,     5,    11,    43,    12,    -1,     4,    20,    -1,     4,
      17,    -1,    11,    43,    12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    78,    78,    79,    82,    83,    84,    85,    86,    90,
      91,    92,    93,   100,   138,   168,   182,   186,   197,   212,
     243,   264,   291,   323,   356,   393,   416,   440,   464,   484,
     505,   525,   546,   566,   589,   609,   632,   663,   683,   703,
     716,   727,   741,   767,   792,   805,   818,   834
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER_LITERAL", "VARIABLE",
  "ONE_OPERATOR_FUNCTION", "END_OF_FILE", "'+'", "'-'", "'*'", "'/'",
  "'('", "')'", "OPE_SLASH_EQ", "OPE_AND_AND", "OPE_VERT_VERT",
  "OPE_MINUS_EQ", "OPE_MINUS_MINUS", "OPE_PLUS_EQ", "'<'", "OPE_PLUS_PLUS",
  "'>'", "OPE_LESSTHAN_EQ", "'!'", "OPE_MORETHAN_EQ", "OPE_EXCL_EQ",
  "OPE_EQ_EQ", "OPE_TIMES_EQ", "'['", "OPE_PERC_EQ", "']'", "';'", "'%'",
  "NEW_LINE", "QUIT", "HELP", "DECLARE", "'='", "NEGATE", "$accept",
  "calculation", "line", "declaration", "EXPRESSION", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,    43,    45,    42,
      47,    40,    41,   262,   263,   264,   265,   266,   267,    60,
     268,    62,   269,    33,   270,   271,   272,   273,    91,   274,
      93,    59,    37,   275,   276,   277,   278,    61,   279
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    39,    40,    40,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    42,    42,    42,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    43
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     2,     3,     3,     2,     2,
       2,     2,     1,     8,     5,     2,     1,     1,     3,     9,
       6,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     7,     4,     4,     2,     2,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     1,     0,    16,    17,     0,    12,     0,     0,
       0,     0,     4,     0,     0,     0,     3,     0,     0,     9,
       0,     0,    46,     0,    45,     0,     0,     0,     0,     0,
      41,    40,     0,    39,    11,    10,    15,     0,     5,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     8,    21,    22,    23,    24,     0,    25,
      18,     0,    47,     0,     6,    34,    35,    36,    37,    27,
      26,    32,    30,    33,    31,    29,    28,     7,    38,    43,
      44,     0,     0,     0,    14,     0,    20,     0,    42,     0,
       0,    13,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    16,    17,    18
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -25
static const yytype_int16 yypact[] =
{
     -25,    53,   -25,   -24,   -25,   312,     0,   -25,    62,    62,
      62,    62,   -25,   -19,    -9,    22,   -25,   -23,    83,   -25,
      62,    62,   -25,    62,   -25,    62,    62,    62,    62,    62,
      13,   -25,   110,   -25,   -25,   -25,    -1,    -5,   -25,    62,
      62,    62,    62,    62,    62,    62,    62,    62,    62,    62,
      62,    10,    62,   -25,   254,   254,   254,   254,   130,   254,
     254,   156,   -25,    62,   -25,    13,    13,   -25,   -25,   294,
     274,    -3,    -3,    -3,    -3,   314,   314,   -25,   -25,   -12,
     -25,   176,    62,    62,     2,   202,   254,    62,     9,   228,
      62,   -25,   254
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -25,   -25,   -25,   -25,    -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      30,    31,    32,    33,    39,    40,    41,    42,    37,    19,
      38,    29,    54,    55,    34,    56,    82,    57,    58,    59,
      60,    61,    41,    42,    35,    83,    36,    63,    64,    52,
      87,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    52,    90,     0,     0,     0,
       0,     0,     0,     2,     3,    81,     4,     5,     6,     7,
       8,     9,     0,     0,    10,     4,     5,     6,     0,     8,
       9,     0,     0,    10,    85,    86,    11,     0,     0,    89,
       0,     0,    92,     0,     0,    11,    12,    13,    14,    15,
      39,    40,    41,    42,     0,     0,     0,    43,    44,     0,
       0,     0,    45,     0,    46,    47,     0,    48,    49,    50,
       0,     0,     0,     0,    51,    52,    53,    39,    40,    41,
      42,     0,    62,     0,    43,    44,     0,     0,     0,    45,
       0,    46,    47,     0,    48,    49,    50,    39,    40,    41,
      42,     0,    52,     0,    43,    44,     0,     0,     0,    45,
       0,    46,    47,     0,    48,    49,    50,     0,     0,     0,
      79,     0,    52,    39,    40,    41,    42,     0,    80,     0,
      43,    44,     0,     0,     0,    45,     0,    46,    47,     0,
      48,    49,    50,    39,    40,    41,    42,     0,    52,     0,
      43,    44,     0,     0,     0,    45,     0,    46,    47,     0,
      48,    49,    50,     0,     0,     0,    84,     0,    52,    39,
      40,    41,    42,     0,     0,     0,    43,    44,     0,     0,
       0,    45,     0,    46,    47,     0,    48,    49,    50,     0,
       0,     0,    88,     0,    52,    39,    40,    41,    42,     0,
       0,     0,    43,    44,     0,     0,     0,    45,     0,    46,
      47,     0,    48,    49,    50,     0,     0,     0,    91,     0,
      52,    39,    40,    41,    42,     0,     0,     0,    43,    44,
       0,     0,     0,    45,     0,    46,    47,     0,    48,    49,
      50,    39,    40,    41,    42,     0,    52,     0,    43,     0,
       0,     0,     0,    45,     0,    46,    47,     0,    48,    49,
      50,    39,    40,    41,    42,     0,    52,     0,     0,     0,
       0,     0,     0,    45,     0,    46,    47,     0,    48,    49,
      50,    39,    40,    41,    42,    20,    52,     0,    21,    22,
      23,     0,    24,    45,     0,    46,    47,     0,    48,    25,
      26,    27,     0,     0,     0,     0,    52,     0,     0,    28
};

static const yytype_int8 yycheck[] =
{
       8,     9,    10,    11,     7,     8,     9,    10,    31,    33,
      33,    11,    20,    21,    33,    23,    28,    25,    26,    27,
      28,    29,     9,    10,    33,    37,     4,    28,    33,    32,
      28,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    33,    52,    32,    37,    -1,    -1,    -1,
      -1,    -1,    -1,     0,     1,    63,     3,     4,     5,     6,
       7,     8,    -1,    -1,    11,     3,     4,     5,    -1,     7,
       8,    -1,    -1,    11,    82,    83,    23,    -1,    -1,    87,
      -1,    -1,    90,    -1,    -1,    23,    33,    34,    35,    36,
       7,     8,     9,    10,    -1,    -1,    -1,    14,    15,    -1,
      -1,    -1,    19,    -1,    21,    22,    -1,    24,    25,    26,
      -1,    -1,    -1,    -1,    31,    32,    33,     7,     8,     9,
      10,    -1,    12,    -1,    14,    15,    -1,    -1,    -1,    19,
      -1,    21,    22,    -1,    24,    25,    26,     7,     8,     9,
      10,    -1,    32,    -1,    14,    15,    -1,    -1,    -1,    19,
      -1,    21,    22,    -1,    24,    25,    26,    -1,    -1,    -1,
      30,    -1,    32,     7,     8,     9,    10,    -1,    12,    -1,
      14,    15,    -1,    -1,    -1,    19,    -1,    21,    22,    -1,
      24,    25,    26,     7,     8,     9,    10,    -1,    32,    -1,
      14,    15,    -1,    -1,    -1,    19,    -1,    21,    22,    -1,
      24,    25,    26,    -1,    -1,    -1,    30,    -1,    32,     7,
       8,     9,    10,    -1,    -1,    -1,    14,    15,    -1,    -1,
      -1,    19,    -1,    21,    22,    -1,    24,    25,    26,    -1,
      -1,    -1,    30,    -1,    32,     7,     8,     9,    10,    -1,
      -1,    -1,    14,    15,    -1,    -1,    -1,    19,    -1,    21,
      22,    -1,    24,    25,    26,    -1,    -1,    -1,    30,    -1,
      32,     7,     8,     9,    10,    -1,    -1,    -1,    14,    15,
      -1,    -1,    -1,    19,    -1,    21,    22,    -1,    24,    25,
      26,     7,     8,     9,    10,    -1,    32,    -1,    14,    -1,
      -1,    -1,    -1,    19,    -1,    21,    22,    -1,    24,    25,
      26,     7,     8,     9,    10,    -1,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    21,    22,    -1,    24,    25,
      26,     7,     8,     9,    10,    13,    32,    -1,    16,    17,
      18,    -1,    20,    19,    -1,    21,    22,    -1,    24,    27,
      28,    29,    -1,    -1,    -1,    -1,    32,    -1,    -1,    37
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    40,     0,     1,     3,     4,     5,     6,     7,     8,
      11,    23,    33,    34,    35,    36,    41,    42,    43,    33,
      13,    16,    17,    18,    20,    27,    28,    29,    37,    11,
      43,    43,    43,    43,    33,    33,     4,    31,    33,     7,
       8,     9,    10,    14,    15,    19,    21,    22,    24,    25,
      26,    31,    32,    33,    43,    43,    43,    43,    43,    43,
      43,    43,    12,    28,    33,    43,    43,    43,    43,    43,
      43,    43,    43,    43,    43,    43,    43,    33,    43,    30,
      12,    43,    28,    37,    30,    43,    43,    28,    30,    43,
      37,    30,    43
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 83 "mainBison.y"
    { printf( BLU "\tSuccesfull declaration\n" RESET); ;}
    break;

  case 6:
#line 84 "mainBison.y"
    { ;}
    break;

  case 7:
#line 85 "mainBison.y"
    { ;}
    break;

  case 8:
#line 86 "mainBison.y"
    { printf(BLU);
                                    printMatrix((yyvsp[(1) - (2)].matrixVal));
                                    printf(RESET);
                                  ;}
    break;

  case 9:
#line 90 "mainBison.y"
    { yyerrok; ;}
    break;

  case 10:
#line 91 "mainBison.y"
    { printfHelp(); ;}
    break;

  case 11:
#line 92 "mainBison.y"
    { YYACCEPT; ;}
    break;

  case 12:
#line 93 "mainBison.y"
    { YYACCEPT; ;}
    break;

  case 13:
#line 100 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(2) - (8)].pts)->content;
                                  if(defined(vc,0)){
                                    yyerror("Matrix already declared");
                                    YYERROR;
                                  }

                                  if(!isSingleNumber((yyvsp[(4) - (8)].matrixVal))){
                                    yyerror("Row number is a matrix");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber((yyvsp[(7) - (8)].matrixVal))){
                                    yyerror("Column number is a matrix");
                                    YYERROR;
                                  }


                                  free(vc->value.values[0]);
                                  free(vc->value.values);

                                  int rows=(int)(yyvsp[(4) - (8)].matrixVal).values[0][0];
                                  int columns=(int)(yyvsp[(7) - (8)].matrixVal).values[0][0];

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
                                  freeMatrix(&(yyvsp[(4) - (8)].matrixVal));
                                  freeMatrix(&(yyvsp[(7) - (8)].matrixVal));
                                ;}
    break;

  case 14:
#line 138 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(2) - (5)].pts)->content;
                                  if(defined(vc,0)){
                                    yyerror("Matrix already declared");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber((yyvsp[(4) - (5)].matrixVal))){
                                    yyerror("Vector size is a matrix");
                                    YYERROR;
                                  }

                                  free(vc->value.values[0]);
                                  free(vc->value.values);

                                  int rows=(int)(yyvsp[(4) - (5)].matrixVal).values[0][0];
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
                                  freeMatrix(&(yyvsp[(4) - (5)].matrixVal));

                                ;}
    break;

  case 15:
#line 168 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(2) - (2)].pts)->content;
                                  if(defined(vc,0)){
                                    yyerror("Variable already declared");
                                    YYERROR;
                                  }
                                  vc->value.values[0][0]=0;
                                  vc->defined=1;
                                ;}
    break;

  case 16:
#line 182 "mainBison.y"
    {
                                  defOneNumberMatrix(&(yyval.matrixVal),(yyvsp[(1) - (1)].val));

                                ;}
    break;

  case 17:
#line 186 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (1)].pts)->content;
                                  if(!defined(vc,0)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  copyMatrix(&(yyval.matrixVal),vc);
                                  //printMatrix($$);
                                 ;}
    break;

  case 18:
#line 197 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (3)].pts)->content;
                                  if(!defined(vc,0)){
                                    showWarning("Implicit declaration with assignment");
                                  }
                                  if(!sameSize(vc->value,(yyvsp[(3) - (3)].matrixVal))){
                                    yyerror("Variable is not the same size (rows and columns) as the expresion.");
                                    YYERROR;
                                  }
                                  freeMatrix(&vc->value);
                                  copyExpression(&(vc->value),&((yyvsp[(3) - (3)].matrixVal)));
                                  vc->defined=1;
                                  copyExpression(&(yyval.matrixVal),&((yyvsp[(3) - (3)].matrixVal)));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 19:
#line 212 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (9)].pts)->content;
                                  if(!defined(vc,0)){
                                    yyerror("Matrix not declared");
                                    YYERROR;
                                  }
                                  if(!isMatrix(vc)){
                                    yyerror("That element is not a matrix");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber((yyvsp[(3) - (9)].matrixVal))){
                                    yyerror("First expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber((yyvsp[(6) - (9)].matrixVal))){
                                    yyerror("Second expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber((yyvsp[(9) - (9)].matrixVal))){
                                    yyerror("Number assigned expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isInBounds((yyvsp[(3) - (9)].matrixVal).values[0][0],(yyvsp[(6) - (9)].matrixVal).values[0][0],vc)){
                                    yyerror("Index outside the matrix");
                                    YYERROR;
                                  }
                                  vc->value.values[(int)(yyvsp[(3) - (9)].matrixVal).values[0][0]][(int)(yyvsp[(6) - (9)].matrixVal).values[0][0]]=(yyvsp[(9) - (9)].matrixVal).values[0][0];
                                  double aux= vc->value.values[(int)(yyvsp[(3) - (9)].matrixVal).values[0][0]][(int)(yyvsp[(6) - (9)].matrixVal).values[0][0]];
                                  defOneNumberMatrix(&(yyval.matrixVal),aux);
                                  ;}
    break;

  case 20:
#line 243 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (6)].pts)->content;
                                  if(!defined(vc,0)){
                                    yyerror("Vector not declared");
                                    YYERROR;
                                  }
                                  if(!isVector(vc)){
                                    yyerror("That element is not a vector");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber((yyvsp[(3) - (6)].matrixVal))){
                                    yyerror("First expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isInBounds((yyvsp[(3) - (6)].matrixVal).values[0][0],0,vc)){
                                    yyerror("Index outside the matrix");
                                    YYERROR;
                                  }
                                  double aux= vc->value.values[(int)(yyvsp[(3) - (6)].matrixVal).values[0][0]][0];
                                  defOneNumberMatrix(&(yyval.matrixVal),aux);
                                  ;}
    break;

  case 21:
#line 264 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (3)].pts)->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber(vc->value)){
                                    showWarning("Doing operation to all elements in the matrix");
                                  }
                                  if(!isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                    yyerror("Expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if((yyvsp[(3) - (3)].matrixVal).values[0][0]==0){
                                    yyerror("You cannot divide by zero");
                                    YYERROR;
                                  }
                                  int i,j;
                                  for (i=0;i<vc->value.rows;i++){
                                        for (j=0;j<vc->value.columns;j++)
                                        {
                                        vc->value.values[i][j] /= (yyvsp[(3) - (3)].matrixVal).values[0][0];
                                        }
                                  }
                                  copyMatrix(&(yyval.matrixVal),vc);
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 22:
#line 291 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (3)].pts)->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                        int i,j;
                                        for (i=0;i<vc->value.rows;i++){
                                              for (j=0;j<vc->value.columns;j++)
                                              {
                                              vc->value.values[i][j] -= (yyvsp[(3) - (3)].matrixVal).values[0][0];
                                              }
                                        }
                                        copyMatrix(&(yyval.matrixVal),vc);
                                        freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  }else{
                                        if(!sameSize(vc->value,(yyvsp[(3) - (3)].matrixVal))){
                                          yyerror("Expresion does not match required size (rows and columns)");
                                          YYERROR;
                                        }
                                        int i,j;
                                        for (i=0;i<vc->value.rows;i++){
                                              for (j=0;j<vc->value.columns;j++)
                                              {
                                              vc->value.values[i][j] -= (yyvsp[(3) - (3)].matrixVal).values[i][j];
                                              }
                                        }
                                        copyMatrix(&(yyval.matrixVal),vc);
                                        freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  }
                                  ;}
    break;

  case 23:
#line 323 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (3)].pts)->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }

                                  if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                        int i,j;
                                        for (i=0;i<vc->value.rows;i++){
                                              for (j=0;j<vc->value.columns;j++)
                                              {
                                              vc->value.values[i][j] += (yyvsp[(3) - (3)].matrixVal).values[0][0];
                                              }
                                        }
                                        copyMatrix(&(yyval.matrixVal),vc);
                                        freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  }else{
                                        if(!sameSize(vc->value,(yyvsp[(3) - (3)].matrixVal))){
                                          yyerror("Expresion does not match required size (rows and columns)");
                                          YYERROR;
                                        }
                                        int i,j;
                                        for (i=0;i<vc->value.rows;i++){
                                              for (j=0;j<vc->value.columns;j++)
                                              {
                                              vc->value.values[i][j] += (yyvsp[(3) - (3)].matrixVal).values[i][j];
                                              }
                                        }
                                        copyMatrix(&(yyval.matrixVal),vc);
                                        freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  }
                                  ;}
    break;

  case 24:
#line 356 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (3)].pts)->content;
                                  variableValue vv = vc->value;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){

                                          int i,j;
                                          for (i=0;i<vc->value.rows;i++){
                                                for (j=0;j<vc->value.columns;j++)
                                                {
                                                vc->value.values[i][j] *= (yyvsp[(3) - (3)].matrixVal).values[0][0];
                                                }
                                          }
                                          copyMatrix(&(yyval.matrixVal),vc);
                                          freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  }else{
                                          if((vv.columns != (yyvsp[(3) - (3)].matrixVal).rows) || ((vv.rows != (yyvsp[(3) - (3)].matrixVal).columns))){
                                            yyerror("Matrices must be the same size");
                                            YYERROR;
                                          }
                                          int i,j,k;
                                          generateMatrix(&(yyval.matrixVal),vv.rows,(yyvsp[(3) - (3)].matrixVal).columns);
                                          for (i=0;i<(yyval.matrixVal).rows;i++){
                                                for (j=0;j<(yyval.matrixVal).columns;j++){
                                                    (yyval.matrixVal).values[i][j]=0;
                                                    for(k=0;k<vv.columns;k++){
                                                        (yyval.matrixVal).values[i][j]+=vv.values[i][k]*(yyvsp[(3) - (3)].matrixVal).values[k][j];
                                                    }
                                                }
                                          }
                                          copyExpression(&(vc->value),&(yyval.matrixVal));
                                          freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  }
                                  ;}
    break;

  case 25:
#line 393 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (3)].pts)->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                    yyerror("Expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  int i,j;
                                  for (i=0;i<vc->value.rows;i++){
                                        for (j=0;j<vc->value.columns;j++)
                                        {
                                        vc->value.values[i][j] = fmod(vc->value.values[i][j],(yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                        }
                                  }
                                  copyMatrix(&(yyval.matrixVal),vc);
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 26:
#line 416 "mainBison.y"
    {

                                  if(!sameSize((yyvsp[(1) - (3)].matrixVal),(yyvsp[(3) - (3)].matrixVal)) && (!isSingleNumber((yyvsp[(3) - (3)].matrixVal)))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyvsp[(1) - (3)].matrixVal).rows;i++){
                                        for (j=0;j<(yyvsp[(1) - (3)].matrixVal).columns;j++)
                                        {
                                          if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) || ((yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                          }else{
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) || ((yyvsp[(3) - (3)].matrixVal).values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 27:
#line 440 "mainBison.y"
    {
                                  if(!sameSize((yyvsp[(1) - (3)].matrixVal),(yyvsp[(3) - (3)].matrixVal)) && (!isSingleNumber((yyvsp[(3) - (3)].matrixVal)))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyvsp[(1) - (3)].matrixVal).rows;i++){
                                        for (j=0;j<(yyvsp[(1) - (3)].matrixVal).columns;j++)
                                        {
                                          if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) && ((yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                          }else{
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) && ((yyvsp[(3) - (3)].matrixVal).values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 28:
#line 464 "mainBison.y"
    {
                                  if(!sameSize((yyvsp[(1) - (3)].matrixVal),(yyvsp[(3) - (3)].matrixVal)) && (!isSingleNumber((yyvsp[(3) - (3)].matrixVal)))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyvsp[(1) - (3)].matrixVal).rows;i++){
                                        for (j=0;j<(yyvsp[(1) - (3)].matrixVal).columns;j++)
                                        {
                                          if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) == ((yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                          }else{
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) == ((yyvsp[(3) - (3)].matrixVal).values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 29:
#line 484 "mainBison.y"
    {
                                  if(!sameSize((yyvsp[(1) - (3)].matrixVal),(yyvsp[(3) - (3)].matrixVal)) && (!isSingleNumber((yyvsp[(3) - (3)].matrixVal)))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyvsp[(1) - (3)].matrixVal).rows;i++){
                                        for (j=0;j<(yyvsp[(1) - (3)].matrixVal).columns;j++)
                                        {
                                          if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) != ((yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                          }else{
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) != ((yyvsp[(3) - (3)].matrixVal).values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 30:
#line 505 "mainBison.y"
    {
                                  if(!sameSize((yyvsp[(1) - (3)].matrixVal),(yyvsp[(3) - (3)].matrixVal)) && (!isSingleNumber((yyvsp[(3) - (3)].matrixVal)))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyvsp[(1) - (3)].matrixVal).rows;i++){
                                        for (j=0;j<(yyvsp[(1) - (3)].matrixVal).columns;j++)
                                        {
                                          if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) > ((yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                          }else{
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) > ((yyvsp[(3) - (3)].matrixVal).values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 31:
#line 525 "mainBison.y"
    {
                                  if(!sameSize((yyvsp[(1) - (3)].matrixVal),(yyvsp[(3) - (3)].matrixVal)) && (!isSingleNumber((yyvsp[(3) - (3)].matrixVal)))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyvsp[(1) - (3)].matrixVal).rows;i++){
                                        for (j=0;j<(yyvsp[(1) - (3)].matrixVal).columns;j++)
                                        {
                                          if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) >= ((yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                          }else{
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) >= ((yyvsp[(3) - (3)].matrixVal).values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 32:
#line 546 "mainBison.y"
    {
                                  if(!sameSize((yyvsp[(1) - (3)].matrixVal),(yyvsp[(3) - (3)].matrixVal)) && (!isSingleNumber((yyvsp[(3) - (3)].matrixVal)))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyvsp[(1) - (3)].matrixVal).rows;i++){
                                        for (j=0;j<(yyvsp[(1) - (3)].matrixVal).columns;j++)
                                        {
                                          if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) < ((yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                          }else{
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) < ((yyvsp[(3) - (3)].matrixVal).values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 33:
#line 566 "mainBison.y"
    {
                                  if(!sameSize((yyvsp[(1) - (3)].matrixVal),(yyvsp[(3) - (3)].matrixVal)) && (!isSingleNumber((yyvsp[(3) - (3)].matrixVal)))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyvsp[(1) - (3)].matrixVal).rows;i++){
                                        for (j=0;j<(yyvsp[(1) - (3)].matrixVal).columns;j++)
                                        {
                                          if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) <= ((yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                          }else{
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) <= ((yyvsp[(3) - (3)].matrixVal).values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 34:
#line 589 "mainBison.y"
    {
                                  if(!sameSize((yyvsp[(1) - (3)].matrixVal),(yyvsp[(3) - (3)].matrixVal)) && (!isSingleNumber((yyvsp[(3) - (3)].matrixVal)))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyvsp[(1) - (3)].matrixVal).rows;i++){
                                        for (j=0;j<(yyvsp[(1) - (3)].matrixVal).columns;j++)
                                        {
                                          if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) + ((yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                          }else{
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) + ((yyvsp[(3) - (3)].matrixVal).values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 35:
#line 609 "mainBison.y"
    {
                                  if(!sameSize((yyvsp[(1) - (3)].matrixVal),(yyvsp[(3) - (3)].matrixVal)) && (!isSingleNumber((yyvsp[(3) - (3)].matrixVal)))){
                                    yyerror("Matrix have different size or second parameter is not only an element");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyvsp[(1) - (3)].matrixVal).rows;i++){
                                        for (j=0;j<(yyvsp[(1) - (3)].matrixVal).columns;j++)
                                        {
                                          if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) - ((yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                          }else{
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) - ((yyvsp[(3) - (3)].matrixVal).values[i][j]);
                                          }
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 36:
#line 632 "mainBison.y"
    {
                                if(isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyvsp[(1) - (3)].matrixVal).rows;i++){
                                        for (j=0;j<(yyvsp[(1) - (3)].matrixVal).columns;j++)
                                        {
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) * ((yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                }else{
                                      if((yyvsp[(1) - (3)].matrixVal).columns != (yyvsp[(3) - (3)].matrixVal).rows){
                                        yyerror("Columns of the first matrix must match rows of the second one");
                                        YYERROR;
                                      }
                                      int i,j,k;
                                      generateMatrix(&(yyval.matrixVal),(yyvsp[(1) - (3)].matrixVal).rows,(yyvsp[(3) - (3)].matrixVal).columns);
                                      for (i=0;i<(yyval.matrixVal).rows;i++){
                                            for (j=0;j<(yyval.matrixVal).columns;j++){
                                                (yyval.matrixVal).values[i][j]=0;
                                                for(k=0;k<(yyvsp[(1) - (3)].matrixVal).columns;k++){
                                                    (yyval.matrixVal).values[i][j]+=(yyvsp[(1) - (3)].matrixVal).values[i][k]*(yyvsp[(3) - (3)].matrixVal).values[k][j];
                                                }
                                            }
                                      }
                                      freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                      freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                      }
                              ;}
    break;

  case 37:
#line 663 "mainBison.y"
    {
                                  if(!isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                    yyerror("Second expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if((yyvsp[(3) - (3)].matrixVal).values[0][0]==0){
                                    yyerror("You cannot divide by zero");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyvsp[(1) - (3)].matrixVal).rows;i++){
                                        for (j=0;j<(yyvsp[(1) - (3)].matrixVal).columns;j++)
                                        {
                                            (yyval.matrixVal).values[i][j] = ((yyvsp[(1) - (3)].matrixVal).values[i][j]) / ((yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 38:
#line 683 "mainBison.y"
    {
                                  if(!isSingleNumber((yyvsp[(3) - (3)].matrixVal))){
                                    yyerror("Second expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(1) - (3)].matrixVal));
                                  for (i=0;i<(yyval.matrixVal).rows;i++){
                                        for (j=0;j<(yyval.matrixVal).columns;j++)
                                        {
                                        (yyval.matrixVal).values[i][j] = fmod((yyvsp[(1) - (3)].matrixVal).values[i][j],(yyvsp[(3) - (3)].matrixVal).values[0][0]);
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(1) - (3)].matrixVal));
                                  freeMatrix(&(yyvsp[(3) - (3)].matrixVal));
                                  ;}
    break;

  case 39:
#line 703 "mainBison.y"
    {
                      int i,j;
                      copyExpression(&(yyval.matrixVal),&(yyvsp[(2) - (2)].matrixVal));
                      for (i=0;i<(yyval.matrixVal).rows;i++){
                            for (j=0;j<(yyval.matrixVal).columns;j++)
                            {
                            (yyval.matrixVal).values[i][j] = !((yyvsp[(2) - (2)].matrixVal).values[i][j]);
                            }
                      }
                      freeMatrix(&(yyvsp[(2) - (2)].matrixVal));
                      ;}
    break;

  case 40:
#line 716 "mainBison.y"
    {
                                  int i,j;
                                  copyExpression(&(yyval.matrixVal),&(yyvsp[(2) - (2)].matrixVal));
                                  for (i=0;i<(yyval.matrixVal).rows;i++){
                                        for (j=0;j<(yyval.matrixVal).columns;j++)
                                        {
                                        (yyval.matrixVal).values[i][j] = -((yyvsp[(2) - (2)].matrixVal).values[i][j]);
                                        }
                                  }
                                  freeMatrix(&(yyvsp[(2) - (2)].matrixVal));
                                  ;}
    break;

  case 41:
#line 727 "mainBison.y"
    {
                      int i,j;
                      copyExpression(&(yyval.matrixVal),&(yyvsp[(2) - (2)].matrixVal));
                      for (i=0;i<(yyval.matrixVal).rows;i++){
                            for (j=0;j<(yyval.matrixVal).columns;j++)
                            {
                            (yyval.matrixVal).values[i][j] = +((yyvsp[(2) - (2)].matrixVal).values[i][j]);
                            }
                      }
                      freeMatrix(&(yyvsp[(2) - (2)].matrixVal));
                      ;}
    break;

  case 42:
#line 741 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (7)].pts)->content;
                                  if(!defined(vc,0)){
                                    yyerror("Matrix not declared");
                                    YYERROR;
                                  }
                                  if(!isMatrix(vc)){
                                    yyerror("That element is not a matrix");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber((yyvsp[(3) - (7)].matrixVal))){
                                    yyerror("First expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber((yyvsp[(6) - (7)].matrixVal))){
                                    yyerror("First expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isInBounds((yyvsp[(3) - (7)].matrixVal).values[0][0],(yyvsp[(6) - (7)].matrixVal).values[0][0],vc)){
                                    yyerror("Index outside the matrix");
                                    YYERROR;
                                  }
                                  double aux= vc->value.values[(int)(yyvsp[(3) - (7)].matrixVal).values[0][0]][(int)(yyvsp[(6) - (7)].matrixVal).values[0][0]];
                                  defOneNumberMatrix(&(yyval.matrixVal),aux);
                                  ;}
    break;

  case 43:
#line 767 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (4)].pts)->content;
                                  if(!defined(vc,0)){
                                    yyerror("Vector not declared");
                                    YYERROR;
                                  }
                                  if(!isVector(vc)){
                                    yyerror("That element is not a vector");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber((yyvsp[(3) - (4)].matrixVal))){
                                    yyerror("First expression cannot be a matrix");
                                    YYERROR;
                                  }
                                  if(!isInBounds((yyvsp[(3) - (4)].matrixVal).values[0][0],0,vc)){
                                    yyerror("Index outside the matrix");
                                    YYERROR;
                                  }
                                  double aux= vc->value.values[(int)(yyvsp[(3) - (4)].matrixVal).values[0][0]][0];
                                  defOneNumberMatrix(&(yyval.matrixVal),aux);
                                  ;}
    break;

  case 44:
#line 792 "mainBison.y"
    {
                                  functionContent *fc= (functionContent*) (yyvsp[(1) - (4)].pts)->content;
                                  if(!isSingleNumber((yyvsp[(3) - (4)].matrixVal))){
                                    yyerror("Functions only applyable to single numbers");
                                    YYERROR;
                                  }
                                  double aux = (*(fc->funcPointer))((yyvsp[(3) - (4)].matrixVal).values[0][0]);
                                  defOneNumberMatrix(&(yyval.matrixVal),aux);
                                  ;}
    break;

  case 45:
#line 805 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (2)].pts)->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber(vc->value)){
                                    yyerror("Trying to use '++' operator on matrix, use 'matrix += 1' instead");
                                    YYERROR;
                                  }
                                  vc->value.values[0][0]++;
                                  copyMatrix(&(yyval.matrixVal),vc);
                                ;}
    break;

  case 46:
#line 818 "mainBison.y"
    {
                                  variableContent *vc= (variableContent*) (yyvsp[(1) - (2)].pts)->content;
                                  if(!defined(vc,1)){
                                    yyerror("Variable not declared");
                                    YYERROR;
                                  }
                                  if(!isSingleNumber(vc->value)){
                                    yyerror("Trying to use '++' operator on matrix, use 'matrix = matrix.+ 1' instead");
                                    YYERROR;
                                  }
                                  vc->value.values[0][0]--;
                                  copyMatrix(&(yyval.matrixVal),vc);
                                ;}
    break;

  case 47:
#line 834 "mainBison.y"
    { (yyval.matrixVal) = (yyvsp[(2) - (3)].matrixVal); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2392 "mainBison.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 839 "mainBison.y"


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

