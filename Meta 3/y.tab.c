/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "jucompiler.y"

	/*
    Luís Neto -2020215474
    João Moura -2020235800 
	*/  
    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
    #include "functions.h"
    int yylex(void);
    void yyerror(const char *s);
    Node* root;
	Node* aux;
	int flag_erro = 0;

#line 88 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    AND = 258,                     /* AND  */
    ASSIGN = 259,                  /* ASSIGN  */
    STAR = 260,                    /* STAR  */
    COMMA = 261,                   /* COMMA  */
    DIV = 262,                     /* DIV  */
    EQ = 263,                      /* EQ  */
    GE = 264,                      /* GE  */
    GT = 265,                      /* GT  */
    LBRACE = 266,                  /* LBRACE  */
    LE = 267,                      /* LE  */
    LPAR = 268,                    /* LPAR  */
    LSQ = 269,                     /* LSQ  */
    LT = 270,                      /* LT  */
    MINUS = 271,                   /* MINUS  */
    MOD = 272,                     /* MOD  */
    NE = 273,                      /* NE  */
    NOT = 274,                     /* NOT  */
    OR = 275,                      /* OR  */
    PLUS = 276,                    /* PLUS  */
    RBRACE = 277,                  /* RBRACE  */
    RPAR = 278,                    /* RPAR  */
    RSQ = 279,                     /* RSQ  */
    SEMICOLON = 280,               /* SEMICOLON  */
    ARROW = 281,                   /* ARROW  */
    LSHIFT = 282,                  /* LSHIFT  */
    RSHIFT = 283,                  /* RSHIFT  */
    XOR = 284,                     /* XOR  */
    CLASS = 285,                   /* CLASS  */
    DOTLENGTH = 286,               /* DOTLENGTH  */
    ELSE = 287,                    /* ELSE  */
    IF = 288,                      /* IF  */
    PRINT = 289,                   /* PRINT  */
    PARSEINT = 290,                /* PARSEINT  */
    PUBLIC = 291,                  /* PUBLIC  */
    RETURN = 292,                  /* RETURN  */
    STATIC = 293,                  /* STATIC  */
    STRING = 294,                  /* STRING  */
    VOID = 295,                    /* VOID  */
    WHILE = 296,                   /* WHILE  */
    INT = 297,                     /* INT  */
    DOUBLE = 298,                  /* DOUBLE  */
    BOOL = 299,                    /* BOOL  */
    RESERVED = 300,                /* RESERVED  */
    ID = 301,                      /* ID  */
    INTLIT = 302,                  /* INTLIT  */
    REALLIT = 303,                 /* REALLIT  */
    BOOLLIT = 304,                 /* BOOLLIT  */
    STRLIT = 305                   /* STRLIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define AND 258
#define ASSIGN 259
#define STAR 260
#define COMMA 261
#define DIV 262
#define EQ 263
#define GE 264
#define GT 265
#define LBRACE 266
#define LE 267
#define LPAR 268
#define LSQ 269
#define LT 270
#define MINUS 271
#define MOD 272
#define NE 273
#define NOT 274
#define OR 275
#define PLUS 276
#define RBRACE 277
#define RPAR 278
#define RSQ 279
#define SEMICOLON 280
#define ARROW 281
#define LSHIFT 282
#define RSHIFT 283
#define XOR 284
#define CLASS 285
#define DOTLENGTH 286
#define ELSE 287
#define IF 288
#define PRINT 289
#define PARSEINT 290
#define PUBLIC 291
#define RETURN 292
#define STATIC 293
#define STRING 294
#define VOID 295
#define WHILE 296
#define INT 297
#define DOUBLE 298
#define BOOL 299
#define RESERVED 300
#define ID 301
#define INTLIT 302
#define REALLIT 303
#define BOOLLIT 304
#define STRLIT 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "jucompiler.y"

	struct token* value;
	struct Node * node;

#line 246 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_AND = 3,                        /* AND  */
  YYSYMBOL_ASSIGN = 4,                     /* ASSIGN  */
  YYSYMBOL_STAR = 5,                       /* STAR  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_DIV = 7,                        /* DIV  */
  YYSYMBOL_EQ = 8,                         /* EQ  */
  YYSYMBOL_GE = 9,                         /* GE  */
  YYSYMBOL_GT = 10,                        /* GT  */
  YYSYMBOL_LBRACE = 11,                    /* LBRACE  */
  YYSYMBOL_LE = 12,                        /* LE  */
  YYSYMBOL_LPAR = 13,                      /* LPAR  */
  YYSYMBOL_LSQ = 14,                       /* LSQ  */
  YYSYMBOL_LT = 15,                        /* LT  */
  YYSYMBOL_MINUS = 16,                     /* MINUS  */
  YYSYMBOL_MOD = 17,                       /* MOD  */
  YYSYMBOL_NE = 18,                        /* NE  */
  YYSYMBOL_NOT = 19,                       /* NOT  */
  YYSYMBOL_OR = 20,                        /* OR  */
  YYSYMBOL_PLUS = 21,                      /* PLUS  */
  YYSYMBOL_RBRACE = 22,                    /* RBRACE  */
  YYSYMBOL_RPAR = 23,                      /* RPAR  */
  YYSYMBOL_RSQ = 24,                       /* RSQ  */
  YYSYMBOL_SEMICOLON = 25,                 /* SEMICOLON  */
  YYSYMBOL_ARROW = 26,                     /* ARROW  */
  YYSYMBOL_LSHIFT = 27,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 28,                    /* RSHIFT  */
  YYSYMBOL_XOR = 29,                       /* XOR  */
  YYSYMBOL_CLASS = 30,                     /* CLASS  */
  YYSYMBOL_DOTLENGTH = 31,                 /* DOTLENGTH  */
  YYSYMBOL_ELSE = 32,                      /* ELSE  */
  YYSYMBOL_IF = 33,                        /* IF  */
  YYSYMBOL_PRINT = 34,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 35,                  /* PARSEINT  */
  YYSYMBOL_PUBLIC = 36,                    /* PUBLIC  */
  YYSYMBOL_RETURN = 37,                    /* RETURN  */
  YYSYMBOL_STATIC = 38,                    /* STATIC  */
  YYSYMBOL_STRING = 39,                    /* STRING  */
  YYSYMBOL_VOID = 40,                      /* VOID  */
  YYSYMBOL_WHILE = 41,                     /* WHILE  */
  YYSYMBOL_INT = 42,                       /* INT  */
  YYSYMBOL_DOUBLE = 43,                    /* DOUBLE  */
  YYSYMBOL_BOOL = 44,                      /* BOOL  */
  YYSYMBOL_RESERVED = 45,                  /* RESERVED  */
  YYSYMBOL_ID = 46,                        /* ID  */
  YYSYMBOL_INTLIT = 47,                    /* INTLIT  */
  YYSYMBOL_REALLIT = 48,                   /* REALLIT  */
  YYSYMBOL_BOOLLIT = 49,                   /* BOOLLIT  */
  YYSYMBOL_STRLIT = 50,                    /* STRLIT  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_Program = 52,                   /* Program  */
  YYSYMBOL_ProgramScript = 53,             /* ProgramScript  */
  YYSYMBOL_MethodDecl = 54,                /* MethodDecl  */
  YYSYMBOL_FieldDecl = 55,                 /* FieldDecl  */
  YYSYMBOL_FieldDecl2 = 56,                /* FieldDecl2  */
  YYSYMBOL_Type = 57,                      /* Type  */
  YYSYMBOL_MethodHeader = 58,              /* MethodHeader  */
  YYSYMBOL_MethodHeader2 = 59,             /* MethodHeader2  */
  YYSYMBOL_FormalParams = 60,              /* FormalParams  */
  YYSYMBOL_FormalParams2 = 61,             /* FormalParams2  */
  YYSYMBOL_MethodBody = 62,                /* MethodBody  */
  YYSYMBOL_MethodBody2 = 63,               /* MethodBody2  */
  YYSYMBOL_VarDecl = 64,                   /* VarDecl  */
  YYSYMBOL_VarDecl2 = 65,                  /* VarDecl2  */
  YYSYMBOL_Statement = 66,                 /* Statement  */
  YYSYMBOL_Statement2 = 67,                /* Statement2  */
  YYSYMBOL_ExprReturn = 68,                /* ExprReturn  */
  YYSYMBOL_Statement3 = 69,                /* Statement3  */
  YYSYMBOL_StatementPrint = 70,            /* StatementPrint  */
  YYSYMBOL_MethodInvocation = 71,          /* MethodInvocation  */
  YYSYMBOL_MethodInvocation2 = 72,         /* MethodInvocation2  */
  YYSYMBOL_MethodInvocationExpr = 73,      /* MethodInvocationExpr  */
  YYSYMBOL_Assignment = 74,                /* Assignment  */
  YYSYMBOL_ParseArgs = 75,                 /* ParseArgs  */
  YYSYMBOL_Expr = 76,                      /* Expr  */
  YYSYMBOL_ExprOperations = 77,            /* ExprOperations  */
  YYSYMBOL_Expr2 = 78,                     /* Expr2  */
  YYSYMBOL_ExprLit = 79                    /* ExprLit  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  89
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    47,    47,    54,    57,    58,    60,    62,    65,    70,
      89,    92,    93,    97,    98,    99,   102,   108,   118,   119,
     122,   127,   134,   135,   143,   147,   148,   155,   159,   178,
     179,   183,   191,   203,   228,   238,   240,   241,   243,   246,
     247,   256,   257,   260,   261,   262,   263,   266,   267,   271,
     276,   280,   281,   285,   286,   295,   301,   305,   309,   310,
     313,   316,   319,   322,   325,   328,   331,   334,   337,   340,
     343,   346,   349,   352,   355,   358,   361,   363,   365,   367,
     368,   370,   371,   373,   376,   380,   381,   384,   386,   388
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "AND", "ASSIGN",
  "STAR", "COMMA", "DIV", "EQ", "GE", "GT", "LBRACE", "LE", "LPAR", "LSQ",
  "LT", "MINUS", "MOD", "NE", "NOT", "OR", "PLUS", "RBRACE", "RPAR", "RSQ",
  "SEMICOLON", "ARROW", "LSHIFT", "RSHIFT", "XOR", "CLASS", "DOTLENGTH",
  "ELSE", "IF", "PRINT", "PARSEINT", "PUBLIC", "RETURN", "STATIC",
  "STRING", "VOID", "WHILE", "INT", "DOUBLE", "BOOL", "RESERVED", "ID",
  "INTLIT", "REALLIT", "BOOLLIT", "STRLIT", "$accept", "Program",
  "ProgramScript", "MethodDecl", "FieldDecl", "FieldDecl2", "Type",
  "MethodHeader", "MethodHeader2", "FormalParams", "FormalParams2",
  "MethodBody", "MethodBody2", "VarDecl", "VarDecl2", "Statement",
  "Statement2", "ExprReturn", "Statement3", "StatementPrint",
  "MethodInvocation", "MethodInvocation2", "MethodInvocationExpr",
  "Assignment", "ParseArgs", "Expr", "ExprOperations", "Expr2", "ExprLit", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-52)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-52)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       6,   -19,    42,    41,   -52,    50,    21,    50,    38,    58,
      50,    50,   -52,   -52,    54,    44,   -52,   -52,    37,   -52,
     -52,   -52,    46,    71,   -52,    77,    -3,   138,   -52,    35,
      53,    35,    76,    79,   163,    89,   111,   120,    68,   121,
      22,    90,   113,   138,   138,   112,   -52,   -52,   -52,   126,
      95,   119,   -52,   137,   124,   -52,   -52,   163,   129,    68,
     189,     4,   110,   213,   213,   213,     2,   -52,   -52,   -52,
     128,   -52,   -52,   -52,   -52,   237,   -52,   -52,    68,    68,
      72,   148,   -52,   -52,   -52,   -52,   131,   159,   -52,   -52,
     -52,   -52,   -52,   144,   -52,   146,   -52,   147,   154,   153,
     155,     9,   -52,   -52,   -52,   -52,   -52,   213,   213,   213,
     213,   213,   213,   213,   213,   213,   213,   213,   213,   213,
     213,   213,   213,   164,   -52,   166,   167,   171,   140,   169,
     149,    -5,   -52,   182,   174,   -52,    68,   -52,   -52,   289,
     -52,   -52,   338,   351,   351,   351,   351,    36,   -52,   338,
     264,    36,   145,   145,   314,   182,   -52,   -52,    68,   -52,
     148,   -52,   -52,   157,   160,   -52,   177,   -52,   171,   -52,
     159,   182,   168,   -52,   -52,   -52,   -52
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,    10,     7,     0,     0,     5,     6,     0,    14,
      15,    13,     0,     0,     3,     0,    11,     0,     8,    18,
       0,    18,     0,     0,     0,     0,     0,     0,    41,     0,
       0,     0,     0,     0,     0,     0,    44,    45,    46,     0,
       0,     0,    19,    11,     0,     9,    38,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    82,    87,    88,    89,
       0,    85,    58,    86,    42,    59,    81,    84,     0,     0,
       0,    29,    24,    27,    26,    36,     0,    22,    17,    12,
      16,    40,    31,     0,    48,     0,    47,     0,     0,     0,
       0,    82,    77,    78,    76,    83,    35,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    55,     0,     0,    53,     0,     0,
       0,     0,    20,     0,     0,    57,     0,    80,    79,    65,
      62,    63,    70,    71,    72,    73,    74,    61,    64,    75,
      66,    60,    68,    69,    67,     0,    50,    49,     0,    52,
      29,    28,    21,     0,    32,    37,     0,    34,    53,    30,
      22,     0,     0,    54,    23,    33,    56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -52,   -52,   102,   -52,   -52,   158,    -6,   -52,   175,   -52,
      43,   -52,    11,   -52,    52,   -33,   161,   -52,   -52,   -52,
     -27,   -52,    57,   -25,   -23,   -31,   -51,   -52,   -52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    32,    41,    23,    51,    52,
     132,    28,    42,    43,   129,    44,    58,    70,    45,    95,
      71,   126,   159,    72,    73,    74,    75,    76,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    57,    47,    30,    48,    97,    79,    46,    22,    47,
      31,    48,   102,   103,   104,    80,    46,    46,    47,    47,
      48,    48,    80,    50,    57,    50,    79,     3,    93,    96,
      46,   100,    47,   105,    48,    80,     1,    19,    20,    21,
     105,   108,     4,   109,    -2,    24,    12,   123,   124,   127,
      98,     6,     5,   116,    83,    84,   139,   140,   141,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,    -4,   125,    49,     7,    14,    19,    20,    21,
      15,    62,    27,    25,    63,    62,     8,    64,    63,    65,
      29,    64,    26,    65,    18,   -51,    19,    20,    21,    53,
     164,    55,    59,    37,    56,   166,    46,    37,    47,    13,
      48,    99,    16,    17,    66,    67,    68,    69,    66,    67,
      68,    69,   167,    62,    60,   163,    63,   168,    46,    64,
      47,    65,    48,    61,    78,    82,    81,    85,   175,    33,
      86,    87,    88,    30,    46,    37,    47,    90,    48,    34,
     108,    92,   109,   106,   128,   130,    66,    67,    68,    69,
     -25,   115,   116,   -43,    33,   131,   119,   133,   136,   134,
     135,    35,    36,    37,    34,    38,   137,   158,   138,    39,
      19,    20,    21,    33,    40,   -39,   160,   155,   -43,   156,
     157,   176,   171,    34,   161,   162,    35,    36,    37,   165,
      38,   172,    62,   170,    39,    63,    54,   -43,    64,    40,
      65,    89,   169,   174,     0,    35,    36,    37,    91,    38,
       0,     0,     0,    39,    37,   173,    62,     0,    40,    63,
       0,     0,    64,     0,    65,    66,    67,    68,    69,    94,
     107,     0,   108,     0,   109,   110,   111,   112,    37,   113,
       0,     0,   114,   115,   116,   117,     0,   118,   119,   101,
      67,    68,    69,     0,   120,   121,   122,   107,     0,   108,
       0,   109,   110,   111,   112,     0,   113,     0,     0,   114,
     115,   116,   117,     0,     0,   119,     0,     0,     0,     0,
       0,   120,   121,   122,   108,     0,   109,   110,   111,   112,
       0,   113,     0,     0,   114,   115,   116,   117,     0,     0,
     119,     0,     0,     0,     0,     0,   120,   121,   122,   108,
       0,   109,   110,   111,   112,     0,   113,     0,     0,   114,
     115,   116,   117,     0,     0,   119,     0,     0,     0,     0,
       0,   120,   121,   108,     0,   109,     0,   111,   112,     0,
     113,     0,     0,   114,   115,   116,   108,     0,   109,   119,
       0,     0,     0,     0,     0,   120,   121,   115,   116,     0,
       0,     0,   119,     0,     0,     0,     0,     0,   120,   121
};

static const yytype_int16 yycheck[] =
{
      27,    34,    27,     6,    27,     1,     4,    34,    14,    34,
      13,    34,    63,    64,    65,    13,    43,    44,    43,    44,
      43,    44,    13,    29,    57,    31,     4,    46,    59,    60,
      57,    62,    57,    31,    57,    13,    30,    42,    43,    44,
      31,     5,     0,     7,     0,     1,    25,    78,    79,    80,
      46,     1,    11,    17,    43,    44,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,    22,     1,    39,    25,    38,    42,    43,    44,
      22,    13,    11,    46,    16,    13,    36,    19,    16,    21,
      13,    19,    46,    21,    40,    23,    42,    43,    44,    46,
     133,    25,    13,    35,    25,   136,   133,    35,   133,     7,
     133,     1,    10,    11,    46,    47,    48,    49,    46,    47,
      48,    49,   155,    13,    13,   131,    16,   158,   155,    19,
     155,    21,   155,    13,    13,    22,    46,    25,   171,     1,
      14,    46,    23,     6,   171,    35,   171,    23,   171,    11,
       5,    22,     7,    25,     6,    24,    46,    47,    48,    49,
      22,    16,    17,    25,     1,     6,    21,    23,    14,    23,
      23,    33,    34,    35,    11,    37,    23,     6,    23,    41,
      42,    43,    44,     1,    46,    22,    46,    23,    25,    23,
      23,    23,    32,    11,    25,    46,    33,    34,    35,    25,
      37,    24,    13,    46,    41,    16,    31,    25,    19,    46,
      21,    53,   160,   170,    -1,    33,    34,    35,    57,    37,
      -1,    -1,    -1,    41,    35,   168,    13,    -1,    46,    16,
      -1,    -1,    19,    -1,    21,    46,    47,    48,    49,    50,
       3,    -1,     5,    -1,     7,     8,     9,    10,    35,    12,
      -1,    -1,    15,    16,    17,    18,    -1,    20,    21,    46,
      47,    48,    49,    -1,    27,    28,    29,     3,    -1,     5,
      -1,     7,     8,     9,    10,    -1,    12,    -1,    -1,    15,
      16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,    29,     5,    -1,     7,     8,     9,    10,
      -1,    12,    -1,    -1,    15,    16,    17,    18,    -1,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,     5,
      -1,     7,     8,     9,    10,    -1,    12,    -1,    -1,    15,
      16,    17,    18,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      -1,    27,    28,     5,    -1,     7,    -1,     9,    10,    -1,
      12,    -1,    -1,    15,    16,    17,     5,    -1,     7,    21,
      -1,    -1,    -1,    -1,    -1,    27,    28,    16,    17,    -1,
      -1,    -1,    21,    -1,    -1,    -1,    -1,    -1,    27,    28
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    52,    46,     0,    11,     1,    25,    36,    53,
      54,    55,    25,    53,    38,    22,    53,    53,    40,    42,
      43,    44,    57,    58,     1,    46,    46,    11,    62,    13,
       6,    13,    56,     1,    11,    33,    34,    35,    37,    41,
      46,    57,    63,    64,    66,    69,    71,    74,    75,    39,
      57,    59,    60,    46,    59,    25,    25,    66,    67,    13,
      13,    13,    13,    16,    19,    21,    46,    47,    48,    49,
      68,    71,    74,    75,    76,    77,    78,    79,    13,     4,
      13,    46,    22,    63,    63,    25,    14,    46,    23,    56,
      23,    67,    22,    76,    50,    70,    76,     1,    46,     1,
      76,    46,    77,    77,    77,    31,    25,     3,     5,     7,
       8,     9,    10,    12,    15,    16,    17,    18,    20,    21,
      27,    28,    29,    76,    76,     1,    72,    76,     6,    65,
      24,     6,    61,    23,    23,    23,    14,    23,    23,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    23,    23,    23,     6,    73,
      46,    25,    46,    57,    66,    25,    76,    66,    76,    65,
      46,    32,    24,    73,    61,    66,    23
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    52,    53,    53,    53,    53,    54,    55,
      55,    56,    56,    57,    57,    57,    58,    58,    59,    59,
      60,    60,    61,    61,    62,    63,    63,    63,    64,    65,
      65,    66,    66,    66,    66,    66,    66,    66,    66,    67,
      67,    68,    68,    69,    69,    69,    69,    70,    70,    71,
      71,    72,    72,    73,    73,    74,    75,    75,    76,    76,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    78,    78,    79,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     6,     0,     2,     2,     2,     4,     6,
       2,     0,     3,     1,     1,     1,     5,     5,     0,     1,
       3,     4,     0,     4,     3,     0,     2,     2,     4,     0,
       3,     3,     5,     7,     5,     3,     2,     5,     2,     0,
       2,     0,     1,     0,     1,     1,     1,     1,     1,     4,
       4,     0,     2,     0,     3,     3,     7,     4,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     2,     2,     2,     3,
       3,     1,     1,     2,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* Program: CLASS ID LBRACE ProgramScript RBRACE  */
#line 47 "jucompiler.y"
                                                                                        {root = newNode( NULL, "Program",0,0);
																	aux = newNode( (yyvsp[-3].value)->value, "Id",(yyvsp[-3].value)->line,(yyvsp[-3].value)->column);
																	add_child(root, aux);
																	addBrother(aux, (yyvsp[-1].node));
																	freeToken((yyvsp[-3].value));
																	(yyval.node) = root;
																	}
#line 1465 "y.tab.c"
    break;

  case 3: /* Program: CLASS ID LBRACE ProgramScript RBRACE error  */
#line 54 "jucompiler.y"
                                                                                        {(yyval.node) = NULL; flag_erro = 1;}
#line 1471 "y.tab.c"
    break;

  case 4: /* ProgramScript: %empty  */
#line 57 "jucompiler.y"
                                                                                                                {(yyval.node) = NULL;}
#line 1477 "y.tab.c"
    break;

  case 5: /* ProgramScript: MethodDecl ProgramScript  */
#line 58 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[-1].node);
																	addBrother((yyval.node), (yyvsp[0].node));}
#line 1484 "y.tab.c"
    break;

  case 6: /* ProgramScript: FieldDecl ProgramScript  */
#line 60 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[-1].node);
																	addBrother((yyval.node), (yyvsp[0].node));}
#line 1491 "y.tab.c"
    break;

  case 7: /* ProgramScript: SEMICOLON ProgramScript  */
#line 62 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1497 "y.tab.c"
    break;

  case 8: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 65 "jucompiler.y"
                                                                                        {(yyval.node) = newNode(NULL , "MethodDecl",0,0);
																	add_child((yyval.node), (yyvsp[-1].node));
																	addBrother((yyvsp[-1].node), (yyvsp[0].node));}
#line 1505 "y.tab.c"
    break;

  case 9: /* FieldDecl: PUBLIC STATIC Type ID FieldDecl2 SEMICOLON  */
#line 70 "jucompiler.y"
                                                                                        {(yyval.node) = newNode( NULL, "FieldDecl",0,0);
																	add_child((yyval.node), (yyvsp[-3].node));
																	addBrother((yyvsp[-3].node), newNode( (yyvsp[-2].value)->value, "Id",(yyvsp[-2].value)->line,(yyvsp[-2].value)->column));
																	freeToken((yyvsp[-2].value));
																	if ((yyvsp[-1].node) != NULL){
																		aux = (yyvsp[-1].node);
																		while (aux != NULL) {
																			Node* aux1 = newNode( NULL, "FieldDecl",0,0);
																			Node* aux2 = newNode( (yyvsp[-2].value)->value, "Id", (yyvsp[-2].value)->line, (yyvsp[-2].value)->column);
																			add_child(aux1, aux2);
																			addBrother(aux2, newNode(aux->value,"Id",aux->line,aux->column));
																			addBrother((yyval.node), aux1);
																			aux = aux->brother;
																		}
																		
																		free(aux);
																		
																	}
																	freeToken((yyvsp[-2].value));}
#line 1529 "y.tab.c"
    break;

  case 10: /* FieldDecl: error SEMICOLON  */
#line 89 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL; flag_erro = 1;}
#line 1535 "y.tab.c"
    break;

  case 11: /* FieldDecl2: %empty  */
#line 92 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1541 "y.tab.c"
    break;

  case 12: /* FieldDecl2: COMMA ID FieldDecl2  */
#line 93 "jucompiler.y"
                                                                                                                        {(yyval.node) = newNode( (yyvsp[-1].value)->value, "Id",(yyvsp[-1].value)->line,(yyvsp[-1].value)->column);
																	addBrother((yyval.node), (yyvsp[0].node));}
#line 1548 "y.tab.c"
    break;

  case 13: /* Type: BOOL  */
#line 97 "jucompiler.y"
                                                                                                                        {(yyval.node) = newNode( NULL, "Bool",0,0);}
#line 1554 "y.tab.c"
    break;

  case 14: /* Type: INT  */
#line 98 "jucompiler.y"
                                                                                                                                        {(yyval.node) = newNode( NULL, "Int",0,0);}
#line 1560 "y.tab.c"
    break;

  case 15: /* Type: DOUBLE  */
#line 99 "jucompiler.y"
                                                                                                                                {(yyval.node) = newNode( NULL, "Double",0,0);}
#line 1566 "y.tab.c"
    break;

  case 16: /* MethodHeader: Type ID LPAR MethodHeader2 RPAR  */
#line 102 "jucompiler.y"
                                                                                        {(yyval.node) = newNode( NULL, "MethodHeader",0,0);
																	add_child((yyval.node),(yyvsp[-4].node));
																	addBrother((yyvsp[-4].node), newNode( (yyvsp[-3].value)->value, "Id",(yyvsp[-3].value)->line,(yyvsp[-3].value)->column));
																	aux = newNode( NULL, "MethodParams",0,0);
																	addBrother((yyvsp[-4].node), aux);
																	add_child(aux, (yyvsp[-1].node));}
#line 1577 "y.tab.c"
    break;

  case 17: /* MethodHeader: VOID ID LPAR MethodHeader2 RPAR  */
#line 108 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "MethodHeader",0,0);
																	aux = newNode( NULL, "Void",0,0);
																	add_child((yyval.node), aux);
																	addBrother(aux, newNode( (yyvsp[-3].value)->value, "Id",(yyvsp[-3].value)->line,(yyvsp[-3].value)->column));
																	Node* aux2 = newNode( NULL, "MethodParams",0,0);
																	addBrother(aux, aux2);
																	add_child(aux2, (yyvsp[-1].node));
																	freeToken((yyvsp[-3].value));}
#line 1590 "y.tab.c"
    break;

  case 18: /* MethodHeader2: %empty  */
#line 118 "jucompiler.y"
                                                                                                                {(yyval.node) = NULL;}
#line 1596 "y.tab.c"
    break;

  case 19: /* MethodHeader2: FormalParams  */
#line 119 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1602 "y.tab.c"
    break;

  case 20: /* FormalParams: Type ID FormalParams2  */
#line 122 "jucompiler.y"
                                                                                                {(yyval.node) = newNode( NULL, "ParamDecl",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	aux = newNode( (yyvsp[-1].value)->value, "Id",(yyvsp[-1].value)->line,(yyvsp[-1].value)->column);
																	addBrother((yyvsp[-2].node), aux);
																	addBrother((yyval.node), (yyvsp[0].node));}
#line 1612 "y.tab.c"
    break;

  case 21: /* FormalParams: STRING LSQ RSQ ID  */
#line 127 "jucompiler.y"
                                                                                                                        {(yyval.node) = newNode( NULL, "ParamDecl",0,0);
																	aux = newNode( NULL, "StringArray",0,0);
																	add_child((yyval.node), aux);
																	addBrother(aux, newNode( (yyvsp[0].value)->value, "Id",(yyvsp[0].value)->line,(yyvsp[0].value)->column));
																	freeToken((yyvsp[0].value));}
#line 1622 "y.tab.c"
    break;

  case 22: /* FormalParams2: %empty  */
#line 134 "jucompiler.y"
                                                                                                                {(yyval.node) = NULL;}
#line 1628 "y.tab.c"
    break;

  case 23: /* FormalParams2: COMMA Type ID FormalParams2  */
#line 135 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "ParamDecl",0,0);
																	aux = newNode( (yyvsp[-1].value)->value, "Id",(yyvsp[-1].value)->line,(yyvsp[-1].value)->column);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), aux);
																	addBrother((yyval.node), (yyvsp[0].node));
																	freeToken((yyvsp[-1].value));}
#line 1639 "y.tab.c"
    break;

  case 24: /* MethodBody: LBRACE MethodBody2 RBRACE  */
#line 143 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "MethodBody",0,0);
																	add_child((yyval.node), (yyvsp[-1].node));}
#line 1646 "y.tab.c"
    break;

  case 25: /* MethodBody2: %empty  */
#line 147 "jucompiler.y"
                                                                                                                {(yyval.node) = NULL;}
#line 1652 "y.tab.c"
    break;

  case 26: /* MethodBody2: Statement MethodBody2  */
#line 148 "jucompiler.y"
                                                                                                                {if ((yyvsp[-1].node) != NULL){
																		(yyval.node) = (yyvsp[-1].node);
																		addBrother((yyval.node), (yyvsp[0].node));
																		}
																	else {
																		(yyval.node) = (yyvsp[0].node);
																	}}
#line 1664 "y.tab.c"
    break;

  case 27: /* MethodBody2: VarDecl MethodBody2  */
#line 155 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-1].node);
																	addBrother((yyval.node), (yyvsp[0].node));}
#line 1671 "y.tab.c"
    break;

  case 28: /* VarDecl: Type ID VarDecl2 SEMICOLON  */
#line 159 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "VarDecl",0,0);
																	add_child((yyval.node), (yyvsp[-3].node));
																	addBrother((yyvsp[-3].node), newNode( (yyvsp[-2].value)->value, "Id",(yyvsp[-2].value)->line,(yyvsp[-2].value)->column));
																	freeToken((yyvsp[-2].value));
																	if ((yyvsp[-1].node) != NULL){
																		aux = (yyvsp[-1].node);
																		while (aux != NULL) {
																			Node* aux1 = newNode( NULL, "VarDecl",0,0);
																			Node* aux2 = newNode((yyvsp[-3].node)->value,(yyvsp[-3].node)->s_type, (yyvsp[-3].node)->line,(yyvsp[-3].node)->column);
																			add_child(aux1, aux2);
																			addBrother(aux2, newNode(aux->value ,"Id",aux->line,aux->column));
																			addBrother((yyval.node), aux1);
																			aux = aux->brother;
																		}
																		free(aux);
																		
																	}}
#line 1693 "y.tab.c"
    break;

  case 29: /* VarDecl2: %empty  */
#line 178 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1699 "y.tab.c"
    break;

  case 30: /* VarDecl2: COMMA ID VarDecl2  */
#line 179 "jucompiler.y"
                                                                                                                        {(yyval.node) = newNode( (yyvsp[-1].value)->value, "Id",(yyvsp[-1].value)->line,(yyvsp[-1].value)->column);
																	addBrother((yyval.node), (yyvsp[0].node));}
#line 1706 "y.tab.c"
    break;

  case 31: /* Statement: LBRACE Statement2 RBRACE  */
#line 183 "jucompiler.y"
                                                                                                        {if (countBrother((yyvsp[-1].node)) > 1) {
																		aux = newNode( NULL, "Block",0,0);
																		(yyval.node) = aux;
																		add_child(aux, (yyvsp[-1].node));
																	}
																	else {
																		(yyval.node) = (yyvsp[-1].node);
																	}}
#line 1719 "y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement  */
#line 191 "jucompiler.y"
                                                                                                {(yyval.node) = newNode( NULL, "If",0,0);
																	add_child((yyval.node),(yyvsp[-2].node));
																	aux = newNode( NULL, "Block",0,0);
																	if (countBrother((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
																		addBrother((yyvsp[-2].node), (yyvsp[0].node));
																		addBrother((yyvsp[0].node), aux);
																	}
																	else {
																		addBrother((yyvsp[-2].node), aux);
																		add_child(aux, (yyvsp[0].node));
																		addBrother(aux, newNode( NULL, "Block",0,0));
																	}}
#line 1736 "y.tab.c"
    break;

  case 33: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 203 "jucompiler.y"
                                                                                                {(yyval.node) = newNode( NULL, "If",0,0);
																	add_child((yyval.node),(yyvsp[-4].node));
																	aux = newNode( NULL, "Block",0,0);
																	if (countBrother((yyvsp[-2].node)) == 1 && (yyvsp[-2].node) != NULL) {
																		addBrother((yyvsp[-4].node), (yyvsp[-2].node));
																		if (countBrother((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
																			addBrother((yyvsp[-2].node), (yyvsp[0].node));
																		}
																		else {
																			addBrother((yyvsp[-2].node), aux);
																			add_child(aux, (yyvsp[0].node));
																		}
																	}
																	else {
																		addBrother((yyvsp[-4].node), aux);
																		add_child(aux, (yyvsp[-2].node));
																		if (countBrother((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
																			addBrother(aux, (yyvsp[0].node));
																		}
																		else {
																			Node* aux2 = newNode( NULL, "Block",0,0);
																			addBrother(aux, aux2);
																			add_child(aux2, (yyvsp[0].node));
																		}
																	}}
#line 1766 "y.tab.c"
    break;

  case 34: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 228 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "While",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	if (countBrother((yyvsp[0].node)) == 1 && (yyvsp[0].node) != NULL) {
																		addBrother((yyvsp[-2].node), (yyvsp[0].node));
																	}
																	else {
																		aux = newNode( NULL, "Block",0,0);
																		addBrother((yyvsp[-2].node), aux);
																		add_child(aux, (yyvsp[0].node));
																	}}
#line 1781 "y.tab.c"
    break;

  case 35: /* Statement: RETURN ExprReturn SEMICOLON  */
#line 238 "jucompiler.y"
                                                                                                                {(yyval.node) = newNode( NULL, "Return",0,0);
																	add_child((yyval.node), (yyvsp[-1].node));}
#line 1788 "y.tab.c"
    break;

  case 36: /* Statement: Statement3 SEMICOLON  */
#line 240 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[-1].node);}
#line 1794 "y.tab.c"
    break;

  case 37: /* Statement: PRINT LPAR StatementPrint RPAR SEMICOLON  */
#line 241 "jucompiler.y"
                                                                                                {(yyval.node) = newNode( NULL, "Print",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));}
#line 1801 "y.tab.c"
    break;

  case 38: /* Statement: error SEMICOLON  */
#line 243 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;flag_erro = 1;}
#line 1807 "y.tab.c"
    break;

  case 39: /* Statement2: %empty  */
#line 246 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1813 "y.tab.c"
    break;

  case 40: /* Statement2: Statement Statement2  */
#line 247 "jucompiler.y"
                                                                                                                {if ((yyvsp[-1].node) != NULL) {
																		(yyval.node) = (yyvsp[-1].node);
																		addBrother((yyval.node), (yyvsp[0].node));
																	}
																	else {
																		(yyval.node) = (yyvsp[0].node);
																	}}
#line 1825 "y.tab.c"
    break;

  case 41: /* ExprReturn: %empty  */
#line 256 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1831 "y.tab.c"
    break;

  case 42: /* ExprReturn: Expr  */
#line 257 "jucompiler.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1837 "y.tab.c"
    break;

  case 43: /* Statement3: %empty  */
#line 260 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;}
#line 1843 "y.tab.c"
    break;

  case 44: /* Statement3: MethodInvocation  */
#line 261 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1849 "y.tab.c"
    break;

  case 45: /* Statement3: Assignment  */
#line 262 "jucompiler.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1855 "y.tab.c"
    break;

  case 46: /* Statement3: ParseArgs  */
#line 263 "jucompiler.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1861 "y.tab.c"
    break;

  case 47: /* StatementPrint: Expr  */
#line 266 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 1867 "y.tab.c"
    break;

  case 48: /* StatementPrint: STRLIT  */
#line 267 "jucompiler.y"
                                                                                                                                {(yyval.node) = newNode( (yyvsp[0].value)->value, "StrLit",(yyvsp[0].value)->line,(yyvsp[0].value)->column);
																											freeToken((yyvsp[0].value));}
#line 1874 "y.tab.c"
    break;

  case 49: /* MethodInvocation: ID LPAR MethodInvocation2 RPAR  */
#line 271 "jucompiler.y"
                                                                                        {(yyval.node) = newNode( NULL, "Call",0,0);
																	aux = newNode( (yyvsp[-3].value)->value, "Id",(yyvsp[-3].value)->line,(yyvsp[-3].value)->column);
																	add_child((yyval.node), aux);
																	addBrother(aux, (yyvsp[-1].node));
																	freeToken((yyvsp[-3].value));}
#line 1884 "y.tab.c"
    break;

  case 50: /* MethodInvocation: ID LPAR error RPAR  */
#line 276 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;
																	flag_erro = 1;}
#line 1891 "y.tab.c"
    break;

  case 51: /* MethodInvocation2: %empty  */
#line 280 "jucompiler.y"
                                                                                                                {(yyval.node) = NULL;}
#line 1897 "y.tab.c"
    break;

  case 52: /* MethodInvocation2: Expr MethodInvocationExpr  */
#line 281 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[-1].node);
																	addBrother((yyval.node), (yyvsp[0].node));}
#line 1904 "y.tab.c"
    break;

  case 53: /* MethodInvocationExpr: %empty  */
#line 285 "jucompiler.y"
                                                                                                        {(yyval.node) = NULL;}
#line 1910 "y.tab.c"
    break;

  case 54: /* MethodInvocationExpr: COMMA Expr MethodInvocationExpr  */
#line 286 "jucompiler.y"
                                                                                                        {if((yyvsp[-1].node)!=NULL) {
																		(yyval.node)=(yyvsp[-1].node);
																		addBrother((yyval.node), (yyvsp[0].node));
																	}
																	else {
																		(yyval.node)=(yyvsp[-1].node);
																	}}
#line 1922 "y.tab.c"
    break;

  case 55: /* Assignment: ID ASSIGN Expr  */
#line 295 "jucompiler.y"
                                                                                                                {(yyval.node) = newNode( NULL, "Assign",0,0);
																	aux = newNode( (yyvsp[-2].value)->value, "Id",(yyvsp[-2].value)->line,(yyvsp[-2].value)->column);
																	add_child((yyval.node), aux);
																	addBrother(aux, (yyvsp[0].node));}
#line 1931 "y.tab.c"
    break;

  case 56: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 301 "jucompiler.y"
                                                                                                {(yyval.node) = newNode( NULL, "ParseArgs",0,0);
																	aux = newNode( (yyvsp[-4].value)->value, "Id",(yyvsp[-4].value)->line,(yyvsp[-4].value)->column);
																	add_child((yyval.node), aux);
																	addBrother(aux, (yyvsp[-2].node));}
#line 1940 "y.tab.c"
    break;

  case 57: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 305 "jucompiler.y"
                                                                                                                {(yyval.node) = NULL;
																	flag_erro = 1;}
#line 1947 "y.tab.c"
    break;

  case 58: /* Expr: Assignment  */
#line 309 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1953 "y.tab.c"
    break;

  case 59: /* Expr: ExprOperations  */
#line 310 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[0].node);}
#line 1959 "y.tab.c"
    break;

  case 60: /* ExprOperations: ExprOperations PLUS ExprOperations  */
#line 313 "jucompiler.y"
                                                                                        {(yyval.node) = newNode(NULL, "Add",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1967 "y.tab.c"
    break;

  case 61: /* ExprOperations: ExprOperations MINUS ExprOperations  */
#line 316 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Sub",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1975 "y.tab.c"
    break;

  case 62: /* ExprOperations: ExprOperations STAR ExprOperations  */
#line 319 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Mul",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1983 "y.tab.c"
    break;

  case 63: /* ExprOperations: ExprOperations DIV ExprOperations  */
#line 322 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Div",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1991 "y.tab.c"
    break;

  case 64: /* ExprOperations: ExprOperations MOD ExprOperations  */
#line 325 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Mod",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 1999 "y.tab.c"
    break;

  case 65: /* ExprOperations: ExprOperations AND ExprOperations  */
#line 328 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "And",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2007 "y.tab.c"
    break;

  case 66: /* ExprOperations: ExprOperations OR ExprOperations  */
#line 331 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Or",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2015 "y.tab.c"
    break;

  case 67: /* ExprOperations: ExprOperations XOR ExprOperations  */
#line 334 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Xor",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2023 "y.tab.c"
    break;

  case 68: /* ExprOperations: ExprOperations LSHIFT ExprOperations  */
#line 337 "jucompiler.y"
                                                                                                {(yyval.node) = newNode( NULL, "Lshift",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2031 "y.tab.c"
    break;

  case 69: /* ExprOperations: ExprOperations RSHIFT ExprOperations  */
#line 340 "jucompiler.y"
                                                                                                {(yyval.node) = newNode( NULL, "Rshift",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2039 "y.tab.c"
    break;

  case 70: /* ExprOperations: ExprOperations EQ ExprOperations  */
#line 343 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Eq",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2047 "y.tab.c"
    break;

  case 71: /* ExprOperations: ExprOperations GE ExprOperations  */
#line 346 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Ge",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2055 "y.tab.c"
    break;

  case 72: /* ExprOperations: ExprOperations GT ExprOperations  */
#line 349 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Gt",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2063 "y.tab.c"
    break;

  case 73: /* ExprOperations: ExprOperations LE ExprOperations  */
#line 352 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Le",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2071 "y.tab.c"
    break;

  case 74: /* ExprOperations: ExprOperations LT ExprOperations  */
#line 355 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Lt",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2079 "y.tab.c"
    break;

  case 75: /* ExprOperations: ExprOperations NE ExprOperations  */
#line 358 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Ne",0,0);
																	add_child((yyval.node), (yyvsp[-2].node));
																	addBrother((yyvsp[-2].node), (yyvsp[0].node));}
#line 2087 "y.tab.c"
    break;

  case 76: /* ExprOperations: PLUS ExprOperations  */
#line 361 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Plus",0,0);
																	add_child((yyval.node), (yyvsp[0].node));}
#line 2094 "y.tab.c"
    break;

  case 77: /* ExprOperations: MINUS ExprOperations  */
#line 363 "jucompiler.y"
                                                                                                        {(yyval.node) = newNode( NULL, "Minus",0,0);
																	add_child((yyval.node), (yyvsp[0].node));}
#line 2101 "y.tab.c"
    break;

  case 78: /* ExprOperations: NOT ExprOperations  */
#line 365 "jucompiler.y"
                                                                                                                        {(yyval.node) = newNode( NULL, "Not",0,0);
																	add_child((yyval.node), (yyvsp[0].node));}
#line 2108 "y.tab.c"
    break;

  case 79: /* ExprOperations: LPAR Expr RPAR  */
#line 367 "jucompiler.y"
                                                                                                                        {(yyval.node) = (yyvsp[-1].node);}
#line 2114 "y.tab.c"
    break;

  case 80: /* ExprOperations: LPAR error RPAR  */
#line 368 "jucompiler.y"
                                                                                                                        {(yyval.node) = NULL;
																	flag_erro = 1;}
#line 2121 "y.tab.c"
    break;

  case 81: /* ExprOperations: Expr2  */
#line 370 "jucompiler.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2127 "y.tab.c"
    break;

  case 82: /* ExprOperations: ID  */
#line 371 "jucompiler.y"
                                                                                                                                        {(yyval.node) = newNode( (yyvsp[0].value)->value, "Id",(yyvsp[0].value)->line,(yyvsp[0].value)->column);
			                                                        freeToken((yyvsp[0].value));}
#line 2134 "y.tab.c"
    break;

  case 83: /* ExprOperations: ID DOTLENGTH  */
#line 373 "jucompiler.y"
                                                                                                                        {(yyval.node) = newNode( NULL, "Length",0,0);
																	add_child((yyval.node), newNode( (yyvsp[-1].value)->value, "Id",(yyvsp[-1].value)->line,(yyvsp[-1].value)->column));
																	freeToken((yyvsp[-1].value));}
#line 2142 "y.tab.c"
    break;

  case 84: /* ExprOperations: ExprLit  */
#line 376 "jucompiler.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2148 "y.tab.c"
    break;

  case 85: /* Expr2: MethodInvocation  */
#line 380 "jucompiler.y"
                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2154 "y.tab.c"
    break;

  case 86: /* Expr2: ParseArgs  */
#line 381 "jucompiler.y"
                                                                                                                                {(yyval.node) = (yyvsp[0].node);}
#line 2160 "y.tab.c"
    break;

  case 87: /* ExprLit: INTLIT  */
#line 384 "jucompiler.y"
                                                                                                                        {(yyval.node) = newNode( (yyvsp[0].value)->value, "DecLit",(yyvsp[0].value)->line,(yyvsp[0].value)->column);
																	freeToken((yyvsp[0].value));}
#line 2167 "y.tab.c"
    break;

  case 88: /* ExprLit: REALLIT  */
#line 386 "jucompiler.y"
                                                                                                                                {(yyval.node) = newNode( (yyvsp[0].value)->value, "RealLit",(yyvsp[0].value)->line,(yyvsp[0].value)->column);
																	freeToken((yyvsp[0].value));}
#line 2174 "y.tab.c"
    break;

  case 89: /* ExprLit: BOOLLIT  */
#line 388 "jucompiler.y"
                                                                                                                                {(yyval.node) = newNode( (yyvsp[0].value)->value, "BoolLit",(yyvsp[0].value)->line,(yyvsp[0].value)->column);
																	freeToken((yyvsp[0].value));}
#line 2181 "y.tab.c"
    break;


#line 2185 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 392 "jucompiler.y"

