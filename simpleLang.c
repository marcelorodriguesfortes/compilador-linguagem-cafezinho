/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "simpleLang.y" /* yacc.c:339  */

/* Secao prologo*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipos.h"

extern char * yytext;
extern char * yylex();
extern int numLinha;
extern FILE* yyin;
extern int erroOrigem;
void yyerror( char const *s);




typedef struct noArvorePilha
{
  struct dir *esq;
  struct dir *dir;
  char tipo[40];
  char id[40];
  int  escopo;
  int  pos;
  	
}noArvorePilha;

typedef struct pilha
{
    struct arvore   * pontArvore;
    struct pilha    * proximo;
}pilha;




void pesquisaPreOrdemPilha(noArvorePilha *raiz);
void inserirNoArvorePilha(noArvorePilha **raiz,char identificador[],char tipo[]);
void listar (pilha *top);
void inserir (pilha **top, char lexema[], char tipo[]);
Toperador* CriaOperador(TespecieOperador tipoOperador,  int linha, Toperador* filho1, Toperador* filho2, Toperador* filho3, Toperador* filho4, Toperador* filho5, char* lexema);

void percorreArvore(Toperador* raiz);
void obtemEspecieNoEnumLin(Toperador* no, char* nomeOperador);

pilha * topo = NULL;
Toperador* raiz;
char nomeOperador[200];
char a[34] =  {'l','e','x','P','r','o','g','r','a','m','a'};
char b[34] =  {'T','i','p','o'};
char c[34] =  {'l','e','x','I','D'};
char d[34] =  { 'D','e','c','l','V','a','r'};
char declFuncvar[34] =  {'N','o','D','e','c','l','F','u','n','c','V','a','r'};
char tipo[10];
char lex[80];	
int tok;
char inteiro[4] = {'i','n','t'};
char charr[5] = {'c','a','r'};
int escopo = 0;




#line 131 "simpleLang.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "simpleLang.h".  */
#ifndef YY_YY_SIMPLELANG_H_INCLUDED
# define YY_YY_SIMPLELANG_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    id = 258,
    programa = 259,
    intconst = 260,
    carconst = 261,
    in = 262,
    car = 263,
    retorne = 264,
    leia = 265,
    escreva = 266,
    novalinha = 267,
    enquanto = 268,
    execute = 269,
    cadeiaCaracteres = 270,
    entao = 271,
    ou = 272,
    se = 273,
    senao = 274,
    igual = 275,
    diferente = 276,
    menorigual = 277,
    maiorigual = 278,
    e = 279
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 69 "simpleLang.y" /* yacc.c:355  */

    int nlinha;
    Toperador* Tpont;
    char * lexemaId;

#line 202 "simpleLang.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SIMPLELANG_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 217 "simpleLang.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   189

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  162

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   279

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,     2,     2,    43,     2,     2,
      29,    30,    41,    39,    28,    40,     2,    42,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    35,    25,
      37,    33,    38,    34,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    26,     2,    27,     2,     2,     2,     2,     2,     2,
       2,    36,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    31,     2,    32,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    89,    89,    92,    94,    95,    97,   100,   104,   106,
     107,   110,   113,   114,   117,   119,   121,   123,   128,   129,
     132,   133,   135,   138,   139,   142,   143,   146,   147,   148,
     149,   150,   151,   152,   153,   154,   156,   157,   160,   164,
     165,   168,   169,   172,   173,   176,   177,   180,   181,   182,
     185,   186,   187,   188,   189,   192,   193,   194,   197,   198,
     199,   200,   203,   204,   205,   208,   209,   212,   213,   214,
     215,   216,   217,   218,   221,   222
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "id", "programa", "intconst", "carconst",
  "in", "car", "retorne", "leia", "escreva", "novalinha", "enquanto",
  "execute", "cadeiaCaracteres", "entao", "ou", "se", "senao", "igual",
  "diferente", "menorigual", "maiorigual", "e", "';'", "'['", "']'", "','",
  "'('", "')'", "'{'", "'}'", "'='", "'?'", "':'", "'e'", "'<'", "'>'",
  "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "$accept", "Programa",
  "DeclFuncVar", "DeclProg", "DeclVar", "DeclFunc", "ListaParametros",
  "ListaParametrosCont", "Bloco", "ListaDeclVar", "Tipo", "ListaComando",
  "Comando", "Expr", "AssignExpr", "CondExpr", "OrExpr", "AndExpr",
  "EqExpr", "DesigExpr", "AddExpr", "MulExpr", "UnExpr", "LValueExpr",
  "PrimExpr", "ListExpr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,    59,    91,    93,    44,    40,
      41,   123,   125,    61,    63,    58,   101,    60,    62,    43,
      45,    42,    47,    37,    33
};
# endif

#define YYPACT_NINF -120

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-120)))

#define YYTABLE_NINF -67

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      17,  -120,  -120,    34,    44,    77,  -120,    80,  -120,    23,
      17,  -120,    95,   100,    17,    93,    17,    10,   124,   108,
      60,   111,  -120,   141,    17,  -120,   -15,  -120,  -120,    90,
     142,    72,   121,   118,   122,  -120,    90,  -120,    24,    24,
    -120,   123,    54,   125,  -120,  -120,    -8,   116,    53,    69,
       4,    67,  -120,   126,  -120,    71,   128,   148,  -120,    80,
     110,  -120,    90,    99,   129,   131,   133,   136,   137,  -120,
      90,    90,   135,    55,  -120,  -120,  -120,  -120,  -120,   120,
      90,   120,   120,   120,   120,   120,   120,   120,   120,   120,
     120,   120,   120,    90,   158,   143,   144,   139,  -120,   140,
      17,   145,  -120,  -120,   112,  -120,    90,  -120,  -120,  -120,
     146,   147,  -120,    90,   116,   138,    53,    69,    69,     4,
       4,     4,     4,    67,    67,  -120,  -120,  -120,  -120,   151,
      17,    17,   128,   152,  -120,   149,    90,  -120,   154,   156,
     155,   157,   120,   128,  -120,  -120,  -120,    17,  -120,  -120,
      54,    54,  -120,  -120,   150,  -120,  -120,   160,    17,    54,
    -120,  -120
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,    23,    24,     0,     0,     0,     1,     0,     2,    10,
      20,     7,     0,     0,    12,     0,     6,     0,     0,     0,
      10,     0,    13,     0,     6,     5,    70,    72,    71,     0,
       0,     0,     0,     0,     0,    27,     0,    19,     0,     0,
      37,     0,    25,     0,    38,    39,    41,    44,    46,    49,
      54,    57,    61,     0,    64,    10,    10,     0,     8,     0,
      14,     3,     0,     0,     0,    66,     0,     0,     0,    33,
       0,     0,     0,    70,    62,    63,    18,    26,    28,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,    68,    74,     0,    29,     0,    30,    32,    31,
       0,     0,    73,     0,    43,     0,    45,    47,    48,    53,
      52,    50,    51,    55,    56,    58,    59,    60,    40,     0,
      20,     6,    10,    15,    16,    69,     0,    67,     0,     0,
       0,     0,     0,    10,    21,     4,     9,     0,    75,    65,
       0,     0,    69,    42,     0,    17,    36,    34,    20,     0,
      22,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -120,  -120,   -14,  -120,   -19,  -120,  -120,   -92,    -1,  -113,
     -10,   132,  -119,   -24,   -60,    43,  -120,   104,   105,   -21,
     -16,    26,    41,   159,    83,  -120
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     8,    15,    16,    21,    22,    40,    17,
       5,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,   104
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      18,    58,    25,   103,    23,    64,    11,    68,   134,    79,
      61,    62,    72,    26,    63,    27,    28,   144,   -66,    29,
      30,    31,    32,    33,     1,     2,    80,    73,    34,    27,
      28,   156,   157,   128,     6,    35,    95,    96,   101,    36,
     161,    10,    37,    88,    89,   160,   110,   111,     7,    12,
      38,    13,    14,    36,    39,   155,   115,    26,    98,    27,
      28,   117,   118,    29,    30,    31,    32,    33,   119,   120,
     121,   122,    34,    82,    83,    26,   148,    27,    28,    35,
       9,   113,   138,    36,    63,    10,    57,    67,    13,   141,
      23,    84,    85,    26,    38,    27,    28,    94,    39,    13,
      19,    36,    26,    20,    27,    28,    86,    87,    90,    91,
      92,    10,    38,   146,   123,   124,    39,   145,    24,    36,
      18,    74,    75,    73,   154,    27,    28,    55,    36,   102,
      38,   125,   126,   127,    39,    56,    99,    23,   100,    38,
     136,    59,   137,    39,    60,    65,    69,    70,    18,    36,
      78,    71,    81,    97,   105,    76,    13,   106,   107,    93,
      38,   108,   109,   129,    39,   112,   132,   133,   130,   131,
     150,   151,   135,   142,    77,   158,   139,   140,   143,   159,
     147,   149,   -65,   114,   152,   153,   116,     0,     0,    66
};

static const yytype_int16 yycheck[] =
{
      10,    20,    16,    63,    14,    29,     7,    31,   100,    17,
      24,    26,    36,     3,    29,     5,     6,   130,    33,     9,
      10,    11,    12,    13,     7,     8,    34,     3,    18,     5,
       6,   150,   151,    93,     0,    25,    55,    56,    62,    29,
     159,    31,    32,    39,    40,   158,    70,    71,     4,    26,
      40,    28,    29,    29,    44,   147,    80,     3,    59,     5,
       6,    82,    83,     9,    10,    11,    12,    13,    84,    85,
      86,    87,    18,    20,    21,     3,   136,     5,     6,    25,
       3,    26,   106,    29,    29,    31,    26,    15,    28,   113,
     100,    22,    23,     3,    40,     5,     6,    26,    44,    28,
       5,    29,     3,     3,     5,     6,    37,    38,    41,    42,
      43,    31,    40,   132,    88,    89,    44,   131,    25,    29,
     130,    38,    39,     3,   143,     5,     6,     3,    29,    30,
      40,    90,    91,    92,    44,    27,    26,   147,    28,    40,
      28,    30,    30,    44,     3,     3,    25,    29,   158,    29,
      25,    29,    36,     5,    25,    32,    28,    26,    25,    33,
      40,    25,    25,     5,    44,    30,    27,    27,    25,    25,
      14,    16,    27,    35,    42,    25,    30,    30,    27,    19,
      28,    27,    33,    79,    27,   142,    81,    -1,    -1,    30
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,    46,    47,    55,     0,     4,    48,     3,
      31,    53,    26,    28,    29,    49,    50,    54,    55,     5,
       3,    51,    52,    55,    25,    47,     3,     5,     6,     9,
      10,    11,    12,    13,    18,    25,    29,    32,    40,    44,
      53,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     3,    27,    26,    49,    30,
       3,    47,    26,    29,    58,     3,    68,    15,    58,    25,
      29,    29,    58,     3,    69,    69,    32,    56,    25,    17,
      34,    36,    20,    21,    22,    23,    37,    38,    39,    40,
      41,    42,    43,    33,    26,    49,    49,     5,    53,    26,
      28,    58,    30,    59,    70,    25,    26,    25,    25,    25,
      58,    58,    30,    26,    62,    58,    63,    64,    64,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    59,     5,
      25,    25,    27,    27,    52,    27,    28,    30,    58,    30,
      30,    58,    35,    27,    54,    47,    49,    28,    59,    27,
      14,    16,    27,    60,    49,    52,    57,    57,    25,    19,
      54,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    47,    47,    48,    49,    49,
      49,    50,    51,    51,    52,    52,    52,    52,    53,    53,
      54,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    58,    59,
      59,    60,    60,    61,    61,    62,    62,    63,    63,    63,
      64,    64,    64,    64,    64,    65,    65,    65,    66,    66,
      66,    66,    67,    67,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    69,    70,    70
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     5,     8,     4,     0,     2,     3,     6,
       0,     4,     0,     1,     2,     4,     4,     6,     4,     3,
       0,     5,     8,     1,     1,     1,     2,     1,     2,     3,
       3,     3,     3,     2,     6,     8,     6,     1,     1,     1,
       3,     1,     5,     3,     1,     3,     1,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     3,
       3,     1,     2,     2,     1,     4,     1,     4,     3,     4,
       1,     1,     1,     3,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 89 "simpleLang.y" /* yacc.c:1646  */
    {raiz=CriaOperador(Prog ,numLinha,(yyvsp[-1].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1406 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 3:
#line 92 "simpleLang.y" /* yacc.c:1646  */
    {Toperador * aux1 = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, (yyvsp[-3].Tpont));
										 (yyval.Tpont)=CriaOperador(NoDeclFuncVar, numLinha, (yyvsp[-4].Tpont),aux1,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL);}
#line 1413 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 4:
#line 94 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(NoDeclFuncVar, numLinha, (yyvsp[-7].Tpont),NULL,NULL,(yyvsp[-2].Tpont),(yyvsp[0].Tpont), NULL);}
#line 1419 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 5:
#line 95 "simpleLang.y" /* yacc.c:1646  */
    {Toperador * aux2 = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, (yyvsp[-2].Tpont));
										 (yyval.Tpont)=CriaOperador(NoDeclFuncVar, numLinha, (yyvsp[-3].Tpont),aux2,(yyvsp[-1].Tpont),(yyvsp[0].Tpont),NULL, NULL);}
#line 1426 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 6:
#line 97 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=NULL;}
#line 1432 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 7:
#line 100 "simpleLang.y" /* yacc.c:1646  */
    {Toperador * aux5 = CriaOperador(lexPrograma, numLinha, NULL,NULL,NULL,NULL,NULL, (yyvsp[0].Tpont));
										  (yyval.Tpont)=CriaOperador(DeclProg, numLinha,aux5 ,(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1439 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 8:
#line 104 "simpleLang.y" /* yacc.c:1646  */
    {Toperador * aux = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, (yyvsp[-1].Tpont));
										 (yyval.Tpont)=CriaOperador(DeclVar ,numLinha,(yyvsp[0].Tpont),aux,NULL,NULL,NULL, NULL);}
#line 1446 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 9:
#line 106 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(DeclVar ,numLinha,(yyvsp[0].Tpont),NULL,NULL,NULL,NULL, NULL);}
#line 1452 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 10:
#line 107 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=NULL;}
#line 1458 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 11:
#line 110 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(DeclFunc ,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1464 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 12:
#line 113 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=NULL;}
#line 1470 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 13:
#line 114 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1476 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 14:
#line 117 "simpleLang.y" /* yacc.c:1646  */
    {Toperador * aux7 = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, (yyvsp[0].Tpont));
										 (yyval.Tpont)=CriaOperador(ListaParametrosCont ,numLinha,(yyvsp[-1].Tpont),aux7,NULL,NULL,NULL, NULL);}
#line 1483 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 15:
#line 119 "simpleLang.y" /* yacc.c:1646  */
    {Toperador * aux8 = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, (yyvsp[-2].Tpont));
										(yyval.Tpont)=CriaOperador(ListaParametrosCont ,numLinha,(yyvsp[-3].Tpont),aux8,NULL,NULL,NULL, NULL);}
#line 1490 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 16:
#line 121 "simpleLang.y" /* yacc.c:1646  */
    {Toperador * aux9 = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, (yyvsp[-2].Tpont));
										(yyval.Tpont)=CriaOperador(ListaParametrosCont,numLinha,(yyvsp[-3].Tpont),aux9,(yyvsp[0].Tpont),NULL,NULL, NULL);}
#line 1497 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 17:
#line 123 "simpleLang.y" /* yacc.c:1646  */
    {Toperador * aux10 = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, (yyvsp[-4].Tpont));
										(yyval.Tpont)=CriaOperador(ListaParametrosCont ,numLinha,(yyvsp[-5].Tpont),aux10,(yyvsp[0].Tpont),NULL,NULL, NULL);}
#line 1504 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 18:
#line 128 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Bloco,numLinha,(yyvsp[-2].Tpont),(yyvsp[-1].Tpont),NULL,NULL,NULL, NULL);}
#line 1510 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 19:
#line 129 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[-1].Tpont);}
#line 1516 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 20:
#line 132 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=NULL;}
#line 1522 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 21:
#line 133 "simpleLang.y" /* yacc.c:1646  */
    {Toperador * aux = CriaOperador(lexID, numLinha, NULL,NULL,NULL,NULL,NULL, (yyvsp[-3].Tpont));
										 (yyval.Tpont)=CriaOperador(ListaDeclVar ,numLinha,(yyvsp[-4].Tpont),aux,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL, NULL);}
#line 1529 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 22:
#line 135 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(ListaDeclVar ,numLinha,(yyvsp[-7].Tpont),NULL,NULL,(yyvsp[-2].Tpont),(yyvsp[0].Tpont), NULL);}
#line 1535 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 23:
#line 138 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Tipo, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}
#line 1541 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 24:
#line 139 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Tipo, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}
#line 1547 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 25:
#line 142 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1553 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 26:
#line 143 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(ListaComando,numLinha,(yyvsp[-1].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1559 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 27:
#line 146 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=NULL;}
#line 1565 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 28:
#line 147 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[-1].Tpont);}
#line 1571 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 29:
#line 148 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Retorne,numLinha,(yyvsp[-1].Tpont),NULL,NULL,NULL,NULL, NULL);}
#line 1577 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 30:
#line 149 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Leia,numLinha,(yyvsp[-1].Tpont),NULL,NULL,NULL,NULL, NULL);}
#line 1583 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 31:
#line 150 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Escreva,numLinha,(yyvsp[-1].Tpont),NULL,NULL,NULL,NULL, NULL);}
#line 1589 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 32:
#line 151 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Escreva,numLinha,NULL,NULL,NULL,NULL,NULL, yytext);}
#line 1595 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 33:
#line 152 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(NovaLinha,numLinha,NULL,NULL,NULL,NULL,NULL, yytext);}
#line 1601 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 34:
#line 153 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Se,numLinha,(yyvsp[-3].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1607 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 35:
#line 154 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Se,numLinha,(yyvsp[-5].Tpont),(yyvsp[-2].Tpont),NULL,NULL,NULL, NULL);
										(yyval.Tpont)=CriaOperador(Senao,numLinha,(yyvsp[0].Tpont),NULL,NULL,NULL,NULL, NULL);}
#line 1614 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 36:
#line 156 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Enquanto,numLinha,(yyvsp[-3].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1620 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 37:
#line 157 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=NULL;}
#line 1626 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 38:
#line 160 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1632 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 39:
#line 164 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1638 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 40:
#line 165 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Igual,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1644 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 41:
#line 168 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1650 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 42:
#line 169 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Cond,numLinha,(yyvsp[-4].Tpont),(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL, NULL);}
#line 1656 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 43:
#line 172 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Ou,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1662 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 44:
#line 173 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1668 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 45:
#line 176 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(E,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1674 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 46:
#line 177 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1680 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 47:
#line 180 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Igual,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1686 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 48:
#line 181 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Diferente,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1692 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 49:
#line 182 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1698 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 50:
#line 185 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(MenorQue,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1704 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 51:
#line 186 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(MaiorQue,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1710 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 52:
#line 187 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(MaiorIgual,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1716 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 53:
#line 188 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(MenorIgual,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1722 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 54:
#line 189 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1728 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 55:
#line 192 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Soma,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1734 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 56:
#line 193 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Sub,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1740 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 57:
#line 194 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1746 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 58:
#line 197 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Multi,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1752 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 59:
#line 198 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Div,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1758 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 60:
#line 199 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Resto,numLinha,(yyvsp[-2].Tpont),(yyvsp[0].Tpont),NULL,NULL,NULL, NULL);}
#line 1764 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 61:
#line 200 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1770 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 62:
#line 203 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Menos,numLinha,(yyvsp[0].Tpont),NULL,NULL,NULL,NULL, NULL);}
#line 1776 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 63:
#line 204 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Dif,numLinha,(yyvsp[0].Tpont),NULL,NULL,NULL,NULL, NULL);}
#line 1782 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 64:
#line 205 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1788 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 65:
#line 208 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(LValueExpr,numLinha,(yyvsp[-3].Tpont),(yyvsp[-1].Tpont),NULL,NULL,NULL, NULL);}
#line 1794 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 66:
#line 209 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(ID, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}
#line 1800 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 67:
#line 212 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(PrimExpr,numLinha,NULL,(yyvsp[-1].Tpont),NULL,NULL,NULL, yytext);}
#line 1806 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 68:
#line 213 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(ID, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}
#line 1812 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 69:
#line 214 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(PrimExpr,numLinha,NULL,(yyvsp[-1].Tpont),NULL,NULL,NULL, yytext);}
#line 1818 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 70:
#line 215 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(ID, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}
#line 1824 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 71:
#line 216 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Carconst, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}
#line 1830 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 72:
#line 217 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(Intconst, numLinha , NULL , NULL,NULL,NULL,NULL,  yytext);}
#line 1836 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 73:
#line 218 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[-1].Tpont);}
#line 1842 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 74:
#line 221 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=(yyvsp[0].Tpont);}
#line 1848 "simpleLang.c" /* yacc.c:1646  */
    break;

  case 75:
#line 222 "simpleLang.y" /* yacc.c:1646  */
    {(yyval.Tpont)=CriaOperador(ListExpr, numLinha , (yyvsp[-2].Tpont) , (yyvsp[0].Tpont),NULL,NULL,NULL,  yytext);}
#line 1854 "simpleLang.c" /* yacc.c:1646  */
    break;


#line 1858 "simpleLang.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 229 "simpleLang.y" /* yacc.c:1906  */
 /* Secao Epilogo*/	



int main(int argc, char** argv){
   if(argc!=2)
        yyerror("Uso correto: ./simpleLang nome_arq_entrada");
   yyin=fopen(argv[1], "r");
   if(!yyin)
        yyerror("arquivo não pode ser aberto\n");
  
    yyparse();
    printf("\n---- Árvore abstrata ---- \n");
    percorreArvore(raiz);
    printf("\n---- Tabela de simbolos ---- \n");	
    pesquisaPreOrdemPilha(topo);
    printf("\n");
}

void yyerror( char const *s) {
    if(erroOrigem==0) /*Erro lexico*/
    {
        printf("%s na linha %d - token: %s\n", s, numLinha, yytext);
    }
    else
    {
        printf("Erro sintatico proximo a %s \n", yytext);
        printf(" - linha: %d \n", numLinha);
        erroOrigem=1;
    }
    exit(1);
}

void percorreArvore(Toperador * raiz){
    if(raiz){
        obtemEspecieNoEnumLin(raiz, nomeOperador);
	
        if (strcmp(nomeOperador,a) == 0){
	      inserir(&topo, NULL,NULL);
        }

	if (strcmp(nomeOperador,declFuncvar) == 0){
	      inserir(&topo, NULL,NULL);
        }  

	if (strcmp(nomeOperador,b) == 0){
	    strcpy (tipo,raiz->lexema);   	
        }

        if (strcmp(nomeOperador,c) == 0){
	    inserir(&topo,raiz->lexema,tipo);
        } 
	
	printf("nome do operador: %s  \n", nomeOperador);                                        
        
	percorreArvore(raiz->filho1);
        percorreArvore(raiz->filho2);
	percorreArvore(raiz->filho3);
        percorreArvore(raiz->filho4);
	percorreArvore(raiz->filho5);
    }
  
}

///Inserção na pilha de árvores
void inserir (pilha **top, char lexema[], char tipo[])
{
   
     if(lexema == NULL ){
	     pilha * novo;
	     noArvorePilha *raiz = NULL;
	     novo = (pilha *) malloc (sizeof(pilha));
             
	     if(novo == NULL){
		printf("Não tenho memória");
		exit(1);
	     }else {
		
	       if(*top == NULL){
		 novo->proximo = NULL;
	       }else{
		 novo->proximo = *top;
	       }
	       *top = novo;
	     }
	(*top)->pontArvore = raiz;	
        
	
     }
     if(lexema != NULL)
     inserirNoArvorePilha(&(*top)->pontArvore, lexema, tipo);
        
}


///Inserção de um nó de uma árvore da pilha
void inserirNoArvorePilha(noArvorePilha **raiz,char identificador[],char tipo[])
{

  if (identificador != NULL && tipo != NULL){
	  if(*raiz == NULL)
	    {
		noArvorePilha *aux = (noArvorePilha *) malloc (sizeof(noArvorePilha));
                if(tipo != NULL && identificador != NULL){		
			strcpy (aux->tipo, tipo);
			strcpy (aux->id, identificador);
		}
		aux->dir = aux->esq = NULL;
		*raiz = aux;
		//printf("Elemento %s do tipo %s foi inserido com sucesso! \n", identificador, tipo);
		return;
	    }
	    if (identificador > (*raiz)-> id){
		inserirNoArvorePilha(&(*raiz)->dir,identificador, tipo);
		return;
	    }
	    if (identificador < (*raiz)-> id){
		inserirNoArvorePilha(&(*raiz)->esq, identificador , tipo);
		return;
	    }

            
	    printf("Elemento %s ja existe na arvore. \n", identificador);
  }
}

Toperador* CriaOperador(TespecieOperador tipoOperador,  int linha, Toperador* filho1, Toperador* filho2, Toperador* filho3, Toperador* filho4, Toperador* filho5, char* lexema){
    
    Toperador* aux = (Toperador*) malloc(sizeof(Toperador));
    if (aux){
        aux->tipoOperador=tipoOperador;
        aux->linha=linha;
        aux->filho1=filho1;
        aux->filho2=filho2;
	aux->filho3=filho3;
	aux->filho4=filho4;
	aux->filho5=filho5;
	
        if(lexema){ 
	    aux->lexema= (char*)malloc(strlen(lexema)+1);
            strcpy(aux->lexema, lexema);
        }
        return(aux);
    }
    return(NULL);
}

void obtemEspecieNoEnumLin(Toperador* no, char* nomeOperador){
    switch(no->tipoOperador){
		
		case lexPrograma:
		     sprintf(nomeOperador,"lexPrograma");
		     break;
		case lexID:
		     sprintf(nomeOperador,"lexID");
		     break;		
		case Prog:
		     sprintf(nomeOperador,"Prog - Lin: %d", no->linha);
		     break;
		case DeclProg:
		     sprintf(nomeOperador,"DeclProg - Lin: %d", no->linha);
 		     break;	
		case NoDeclFuncVar:
		     sprintf(nomeOperador,"NoDeclFuncVar");
		     break;
		case DeclVar:
		     sprintf(nomeOperador,"DeclVar");
		     break;
		case DeclFunc:
		     sprintf(nomeOperador,"DeclFunc - Lin: %d", no->linha);
		     break;
		case ListaParametrosCont:
		     sprintf(nomeOperador,"ListaParametrosCont - Lin: %d", no->linha);
		     break;
		case Bloco:
		     sprintf(nomeOperador,"Bloco");
		     break;
		case ListaDeclVar:
		     sprintf(nomeOperador,"ListaDeclVar");
		     break;
		case Enquanto:
		     sprintf(nomeOperador,"Enquanto - Lin: %d", no->linha);
		     break;
		case Tipo:
		     sprintf(nomeOperador,"Tipo");
		     break;
		case ListaComando:
		     sprintf(nomeOperador,"ListaComando - Lin: %d", no->linha);
		     break;
		case Retorne:
		     sprintf(nomeOperador,"Retorne - Lin: %d", no->linha);
		     break;
		case Leia:
		     sprintf(nomeOperador,"Leia - Lin: %d", no->linha);
		     break;
		case Se:
		     sprintf(nomeOperador,"Se");
		     break;
		case Senao:
		     sprintf(nomeOperador,"Senao - Lin: %d", no->linha);
		     break;
		case Cond:
		     sprintf(nomeOperador,"Cond - Lin: %d", no->linha);
		     break;
		case Ou:
		     sprintf(nomeOperador,"Ou - Lin: %d", no->linha);
		     break;
		case  E:
		     sprintf(nomeOperador,"E - Lin: %d", no->linha);
		     break;
		case Igual:
		     sprintf(nomeOperador,"Igual - Lin: %d", no->linha);
		     break;
		case Diferente:
		     sprintf(nomeOperador,"Diferente - Lin: %d", no->linha);
		     break;
		case MenorQue:
		     sprintf(nomeOperador,"MenorQue - Lin: %d", no->linha);
		     break;
		case MaiorIgual:
		     sprintf(nomeOperador,"MaiorIgual - Lin: %d", no->linha);
		     break;
		case MenorIgual:
		     sprintf(nomeOperador,"MenorIgual - Lin: %d", no->linha);
		     break;
		case Soma:
		     sprintf(nomeOperador,"Soma - Lin: %d", no->linha);
		     break;
		case Sub:
		     sprintf(nomeOperador,"Sub - Lin: %d", no->linha);
		     break;
		case Div:
		     sprintf(nomeOperador,"Div - Lin: %d", no->linha);
		     break;
		case Resto:
		     sprintf(nomeOperador,"Resto - Lin: %d", no->linha);
		     break;
		case LValueExpr:
		     sprintf(nomeOperador,"LValueExpr - Lin: %d", no->linha);
		     break;
		case ID:
		     sprintf(nomeOperador,"ID");
		     break;
		case PrimExpr:
		     sprintf(nomeOperador,"PrimExpr - Lin: %d", no->linha);
		     break;
		case Carconst:
		     sprintf(nomeOperador,"Carconst - Lin: %d", no->linha);
		     break;
		case Intconst:
		     sprintf(nomeOperador,"Intconst - Lin: %d", no->linha);
		     break;
		case ListExpr:
		     sprintf(nomeOperador,"ListExpr - Lin: %d", no->linha);
		     break;

    }
}



///Listar conteúdo da pilha!
void listar (pilha *top)
{
    pilha * aux ;
    if(top == NULL)
        printf("pilha vazia!\n");
    else{
        aux = top;
        while(aux!= NULL){
            pesquisaPreOrdemPilha(aux->pontArvore);
            aux = aux -> proximo;	
        }
    }


}


void pesquisaPreOrdemPilha(noArvorePilha *raiz)
{
    if(raiz == NULL){
         printf("\n");
         return;
    }
    else{
	if(strcmp(raiz->tipo,inteiro) == 0 || strcmp(raiz->tipo,charr) == 0)	
	   printf("%s %s\n",raiz->id,raiz->tipo);	
	else if((strlen(raiz->tipo) > 0))
	  printf("Erro semântico \n");             

  
           pesquisaPreOrdemPilha(raiz->esq);
	   pesquisaPreOrdemPilha(raiz->dir);				
          
   }
}
