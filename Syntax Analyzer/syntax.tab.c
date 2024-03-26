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
#line 1 "syntax.y"

    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <errno.h>
    #include <math.h>
    #include "hashtbl.h"

	void yyerror(const char* err);
    int error_counter = 0;

    HASHTBL *hashtbl;

    int scope = 0;
    extern FILE *yyin;
    extern int yylex();
    extern void yyerror(const char *err);
    extern int yylineno;

#line 91 "syntax.tab.c"

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

#include "syntax.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "EOF"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_T_FUNCTION = 3,                 /* "function"  */
  YYSYMBOL_T_SUBROUTINE = 4,               /* "subroutine"  */
  YYSYMBOL_T_END = 5,                      /* "end"  */
  YYSYMBOL_T_INTEGER = 6,                  /* "integer"  */
  YYSYMBOL_T_REAL = 7,                     /* "real"  */
  YYSYMBOL_T_LOGICAL = 8,                  /* "logical"  */
  YYSYMBOL_T_CHARACTER = 9,                /* "character"  */
  YYSYMBOL_T_RECORD = 10,                  /* "record"  */
  YYSYMBOL_T_ENDREC = 11,                  /* "endrec"  */
  YYSYMBOL_T_DATA = 12,                    /* "data"  */
  YYSYMBOL_T_CONTINUE = 13,                /* "continue"  */
  YYSYMBOL_T_GOTO = 14,                    /* "goto"  */
  YYSYMBOL_T_CALL = 15,                    /* "call"  */
  YYSYMBOL_T_READ = 16,                    /* "read"  */
  YYSYMBOL_T_WRITE = 17,                   /* "write"  */
  YYSYMBOL_T_IF = 18,                      /* "if"  */
  YYSYMBOL_T_THEN = 19,                    /* "then"  */
  YYSYMBOL_T_ELSE = 20,                    /* "else"  */
  YYSYMBOL_T_ENDIF = 21,                   /* "endif"  */
  YYSYMBOL_T_DO = 22,                      /* "do"  */
  YYSYMBOL_T_ENDDO = 23,                   /* "enddo"  */
  YYSYMBOL_T_STOP = 24,                    /* "stop"  */
  YYSYMBOL_T_RETURN = 25,                  /* "return"  */
  YYSYMBOL_T_ID = 26,                      /* "identifier"  */
  YYSYMBOL_T_ICONST = 27,                  /* "integer constant"  */
  YYSYMBOL_T_RCONST = 28,                  /* "real constant"  */
  YYSYMBOL_T_LCONST = 29,                  /* "logical constant"  */
  YYSYMBOL_T_CCONST = 30,                  /* "char constant"  */
  YYSYMBOL_T_OROP = 31,                    /* "or"  */
  YYSYMBOL_T_ANDOP = 32,                   /* "and"  */
  YYSYMBOL_T_NOTOP = 33,                   /* "not"  */
  YYSYMBOL_T_RELOP = 34,                   /* "> or >= or < or <= or !="  */
  YYSYMBOL_T_ADDOP = 35,                   /* "+ or -"  */
  YYSYMBOL_T_MULOP = 36,                   /* "*"  */
  YYSYMBOL_T_DIVOP = 37,                   /* "/"  */
  YYSYMBOL_T_POWEROP = 38,                 /* "**"  */
  YYSYMBOL_T_STRING = 39,                  /* "string constant"  */
  YYSYMBOL_T_LPAREN = 40,                  /* "("  */
  YYSYMBOL_T_RPAREN = 41,                  /* ")"  */
  YYSYMBOL_T_COMMA = 42,                   /* ","  */
  YYSYMBOL_T_ASSIGN = 43,                  /* "="  */
  YYSYMBOL_T_COLON = 44,                   /* ":"  */
  YYSYMBOL_YYACCEPT = 45,                  /* $accept  */
  YYSYMBOL_program = 46,                   /* program  */
  YYSYMBOL_body = 47,                      /* body  */
  YYSYMBOL_declarations = 48,              /* declarations  */
  YYSYMBOL_type = 49,                      /* type  */
  YYSYMBOL_vars = 50,                      /* vars  */
  YYSYMBOL_undef_variable = 51,            /* undef_variable  */
  YYSYMBOL_dims = 52,                      /* dims  */
  YYSYMBOL_dim = 53,                       /* dim  */
  YYSYMBOL_fields = 54,                    /* fields  */
  YYSYMBOL_field = 55,                     /* field  */
  YYSYMBOL_vals = 56,                      /* vals  */
  YYSYMBOL_value_list = 57,                /* value_list  */
  YYSYMBOL_values = 58,                    /* values  */
  YYSYMBOL_value = 59,                     /* value  */
  YYSYMBOL_repeat = 60,                    /* repeat  */
  YYSYMBOL_constant = 61,                  /* constant  */
  YYSYMBOL_statements = 62,                /* statements  */
  YYSYMBOL_labeled_statement = 63,         /* labeled_statement  */
  YYSYMBOL_label = 64,                     /* label  */
  YYSYMBOL_statement = 65,                 /* statement  */
  YYSYMBOL_simple_statement = 66,          /* simple_statement  */
  YYSYMBOL_assignment = 67,                /* assignment  */
  YYSYMBOL_variable = 68,                  /* variable  */
  YYSYMBOL_expressions = 69,               /* expressions  */
  YYSYMBOL_expression = 70,                /* expression  */
  YYSYMBOL_goto_statement = 71,            /* goto_statement  */
  YYSYMBOL_labels = 72,                    /* labels  */
  YYSYMBOL_if_statement = 73,              /* if_statement  */
  YYSYMBOL_subroutine_call = 74,           /* subroutine_call  */
  YYSYMBOL_io_statement = 75,              /* io_statement  */
  YYSYMBOL_read_list = 76,                 /* read_list  */
  YYSYMBOL_read_item = 77,                 /* read_item  */
  YYSYMBOL_iter_space = 78,                /* iter_space  */
  YYSYMBOL_step = 79,                      /* step  */
  YYSYMBOL_write_list = 80,                /* write_list  */
  YYSYMBOL_write_item = 81,                /* write_item  */
  YYSYMBOL_compound_statement = 82,        /* compound_statement  */
  YYSYMBOL_branch_statement = 83,          /* branch_statement  */
  YYSYMBOL_84_1 = 84,                      /* $@1  */
  YYSYMBOL_tail = 85,                      /* tail  */
  YYSYMBOL_86_2 = 86,                      /* $@2  */
  YYSYMBOL_loop_statement = 87,            /* loop_statement  */
  YYSYMBOL_88_3 = 88,                      /* $@3  */
  YYSYMBOL_89_4 = 89,                      /* $@4  */
  YYSYMBOL_subprograms = 90,               /* subprograms  */
  YYSYMBOL_subprogram = 91,                /* subprogram  */
  YYSYMBOL_header = 92,                    /* header  */
  YYSYMBOL_93_5 = 93,                      /* $@5  */
  YYSYMBOL_94_6 = 94,                      /* $@6  */
  YYSYMBOL_95_7 = 95,                      /* $@7  */
  YYSYMBOL_96_8 = 96,                      /* $@8  */
  YYSYMBOL_97_9 = 97,                      /* $@9  */
  YYSYMBOL_98_10 = 98,                     /* $@10  */
  YYSYMBOL_formal_parameters = 99          /* formal_parameters  */
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

#if 1

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
#endif /* 1 */

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
#define YYLAST   403

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  55
/* YYNRULES -- Number of rules.  */
#define YYNRULES  124
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  235

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    99,    99,   100,   101,   103,   104,   105,   106,   106,
     106,   106,   107,   108,   109,   110,   112,   113,   114,   115,
     116,   117,   118,   119,   120,   121,   122,   123,   124,   125,
     126,   127,   128,   129,   130,   131,   131,   132,   132,   132,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   164,   165,   166,   167,   168,   169,   170,   171,
     172,   173,   174,   175,   176,   177,   178,   179,   180,   181,
     182,   183,   184,   185,   186,   187,   188,   189,   190,   191,
     192,   192,   193,   193,   194,   195,   195,   195,   196,   197,
     198,   199,   199,   199,   200,   200,   200,   201,   202,   203,
     204,   204,   204,   205,   206
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"EOF\"", "error", "\"invalid token\"", "\"function\"",
  "\"subroutine\"", "\"end\"", "\"integer\"", "\"real\"", "\"logical\"",
  "\"character\"", "\"record\"", "\"endrec\"", "\"data\"", "\"continue\"",
  "\"goto\"", "\"call\"", "\"read\"", "\"write\"", "\"if\"", "\"then\"",
  "\"else\"", "\"endif\"", "\"do\"", "\"enddo\"", "\"stop\"", "\"return\"",
  "\"identifier\"", "\"integer constant\"", "\"real constant\"",
  "\"logical constant\"", "\"char constant\"", "\"or\"", "\"and\"",
  "\"not\"", "\"> or >= or < or <= or !=\"", "\"+ or -\"", "\"*\"",
  "\"/\"", "\"**\"", "\"string constant\"", "\"(\"", "\")\"", "\",\"",
  "\"=\"", "\":\"", "$accept", "program", "body", "declarations", "type",
  "vars", "undef_variable", "dims", "dim", "fields", "field", "vals",
  "value_list", "values", "value", "repeat", "constant", "statements",
  "labeled_statement", "label", "statement", "simple_statement",
  "assignment", "variable", "expressions", "expression", "goto_statement",
  "labels", "if_statement", "subroutine_call", "io_statement", "read_list",
  "read_item", "iter_space", "step", "write_list", "write_item",
  "compound_statement", "branch_statement", "$@1", "tail", "$@2",
  "loop_statement", "$@3", "$@4", "subprograms", "subprogram", "header",
  "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "formal_parameters", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-147)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-84)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -147,    26,    27,   210,  -147,  -147,  -147,  -147,  -147,  -147,
     105,     2,  -147,    23,    17,    -7,    64,    34,  -147,  -147,
    -147,  -147,  -147,    35,   187,  -147,   285,  -147,  -147,  -147,
      -5,  -147,  -147,  -147,  -147,  -147,  -147,  -147,   362,   105,
      35,   381,  -147,    50,    54,    58,  -147,    45,    -7,    45,
      63,  -147,  -147,  -147,  -147,  -147,   257,   257,  -147,    64,
    -147,    45,   341,   141,  -147,   257,    99,    88,   103,  -147,
    -147,  -147,   257,   242,   145,   152,    14,   178,  -147,  -147,
     387,   103,    35,  -147,   286,  -147,   158,   150,   151,    -7,
     257,   162,   365,    41,     9,   257,   257,   257,   257,   257,
     257,   257,    64,    94,   138,   154,    37,    35,    66,   341,
    -147,   341,  -147,   167,   168,   181,   203,   226,    35,   103,
     194,   218,  -147,    -1,  -147,   197,  -147,    50,   236,    -6,
    -147,    41,  -147,   159,   348,   101,   239,   365,   157,   157,
     157,  -147,  -147,  -147,   225,   257,  -147,  -147,    77,  -147,
    -147,  -147,   257,   253,   253,   253,  -147,   234,  -147,   103,
    -147,  -147,   286,   299,  -147,  -147,    89,   233,   235,   248,
    -147,   237,  -147,   305,  -147,  -147,    37,   341,    35,   250,
     252,     5,  -147,   253,  -147,   218,  -147,  -147,  -147,   236,
     257,   257,   257,  -147,   236,   257,   266,  -147,   238,  -147,
    -147,  -147,  -147,   254,  -147,  -147,   255,   263,   323,   123,
     264,   314,  -147,    62,  -147,  -147,  -147,  -147,   240,  -147,
    -147,  -147,   236,   257,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,   341,  -147,   273,  -147
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     0,     0,     1,   109,     8,     9,    10,    11,
       0,     0,    53,     0,     0,     0,     0,     0,   105,    55,
      54,    60,    45,     0,     3,    42,     0,    44,    46,    48,
       0,    49,    50,    51,    52,    47,    98,    99,     0,     0,
       0,     0,    21,     0,     6,     0,    75,    81,     0,    86,
      82,    85,    37,    38,    39,    40,     0,     0,    97,     0,
      73,    72,    95,     0,    94,     0,     0,    15,     4,    13,
      41,    43,     0,     0,     0,     0,     0,     0,   108,     7,
       0,    22,     0,    20,    36,    25,     0,     0,     0,     0,
       0,    70,    71,    95,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    62,
      57,    56,    58,     0,     0,   120,     0,     0,     0,     5,
      37,     0,    34,     0,    28,     0,    33,     0,     0,     0,
      84,     0,    74,     0,    63,    64,    65,    66,    67,    68,
      69,    93,    92,    91,     0,     0,    19,    18,     0,    17,
      12,    59,     0,     0,     0,     0,   121,     0,   110,    23,
      32,    26,    36,     0,    24,    78,     0,    60,    60,     0,
     100,     0,    80,     0,     7,    14,     0,    61,     0,     0,
       0,     0,   122,     0,    27,     0,    31,    30,    76,     0,
       0,     0,     0,     7,     0,     0,     0,    16,   124,   119,
     117,   118,   114,     0,    29,    77,     0,     0,     0,     0,
       0,    90,   106,     0,   115,   111,    87,    96,     0,   102,
     104,   101,     0,     0,    88,   107,   123,   116,   112,     7,
      79,    89,   113,     0,   103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -147,  -147,   -76,  -147,    21,   -38,  -103,  -147,   129,   269,
     -14,  -147,   185,  -147,   155,  -147,   -79,  -147,   294,   -12,
     293,  -137,  -147,    -3,  -147,   -43,  -147,  -147,  -147,  -147,
    -147,   272,   -64,   -40,  -147,   265,   -85,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,  -147,
    -147,  -147,  -147,  -147,  -146
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,     3,   178,    68,    69,   148,   149,    41,
      42,    44,    85,   123,   124,   125,    60,    24,    25,    26,
      27,    28,    29,    61,   108,    62,    31,   166,    32,    33,
      34,    50,    51,   174,   224,    63,    64,    35,    36,   193,
     221,   229,    37,    66,   225,    38,    78,    79,   228,   232,
     214,   227,   156,   182,   179
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      30,    46,    81,   117,   150,   126,   201,   172,   180,   181,
     102,    47,    49,    91,    92,   114,    93,   141,   143,    21,
     167,    30,   104,    30,    23,   130,     4,    83,    43,   109,
     111,    40,     5,    48,    48,    72,   161,   203,    73,    74,
     115,   162,   160,    21,   119,    49,   202,   131,   143,    45,
      22,   133,   134,   135,   136,   137,   138,   139,   140,    77,
      40,    67,    40,   146,   147,   130,    83,   226,     6,     7,
       8,     9,    95,    96,    65,    97,    98,    99,   100,   101,
     159,   172,   132,   126,   187,    72,    49,    84,    67,    74,
      21,    52,    53,    54,    55,   142,    86,    56,   196,    57,
      87,    40,   173,    58,    59,    89,   204,   151,   152,   177,
     150,     6,     7,     8,     9,    39,   165,   209,   175,   176,
      21,    52,    53,    54,    55,   105,    49,    56,   106,    57,
     188,   189,   171,    58,    59,    97,    98,    99,   100,   101,
     198,    30,   102,   219,   220,   107,   -83,   173,   173,   208,
     206,   207,   211,   233,   -83,   -83,   -83,   -83,   -83,   -83,
     142,   -83,   -83,   -83,   -83,   -83,   -83,   -83,   -83,    95,
      96,   112,    97,    98,    99,   100,   101,   205,   113,   144,
     231,   116,   210,   103,   127,   168,    52,    53,    54,    55,
     128,    97,    56,   129,    57,   101,    97,   145,    58,    59,
      12,    13,    14,    15,    16,    17,   171,   153,   154,    18,
     230,    19,    20,    21,    22,    30,     6,     7,     8,     9,
      10,   155,    11,    12,    13,    14,    15,    16,    17,   157,
     -35,   158,    18,   163,    19,    20,    21,    22,    12,    13,
      14,    15,    16,   169,   170,    52,    53,    54,    55,    19,
      20,    21,    22,    12,    13,    14,    15,    16,   169,     6,
       7,     8,     9,    22,    19,    20,    21,    22,    21,    52,
      53,    54,    55,   -84,   183,    56,   190,    57,   191,   194,
     213,   110,    90,    21,    52,    53,    54,    55,   192,   212,
      56,   199,    57,   200,   234,   215,   216,    90,    12,    13,
      14,    15,    16,    17,   217,   197,   222,    18,    80,    19,
      20,    21,   164,   120,    53,    54,    55,   184,    70,    71,
      88,   121,     0,     0,    94,   122,    52,    53,    54,    55,
       0,     0,     0,     0,   185,     0,    95,    96,   186,    97,
      98,    99,   100,   101,     0,    95,    96,   195,    97,    98,
      99,   100,   101,     0,    95,    96,   223,    97,    98,    99,
     100,   101,    -2,    75,   218,     0,    76,     0,     6,     7,
       8,     9,    95,    96,     0,    97,    98,    99,   100,   101,
      96,     0,    97,    98,    99,   100,   101,     6,     7,     8,
       9,    39,    82,     6,     7,     8,     9,    39,   118,    97,
       0,    99,   100,   101
};

static const yytype_int16 yycheck[] =
{
       3,    13,    40,    79,   107,    84,     1,   144,   154,   155,
       1,    14,    15,    56,    57,     1,    59,   102,   103,    26,
      26,    24,    65,    26,     3,    89,     0,    41,    26,    72,
      73,    10,     5,    40,    40,    40,    37,   183,    43,    44,
      26,    42,   121,    26,    82,    48,    41,    90,   133,    26,
      27,    42,    95,    96,    97,    98,    99,   100,   101,    38,
      39,    26,    41,    26,    27,   129,    80,   213,     6,     7,
       8,     9,    31,    32,    40,    34,    35,    36,    37,    38,
     118,   218,    41,   162,   163,    40,    89,    37,    26,    44,
      26,    27,    28,    29,    30,     1,    42,    33,   174,    35,
      42,    80,   145,    39,    40,    42,   185,    41,    42,   152,
     213,     6,     7,     8,     9,    10,   128,   193,    41,    42,
      26,    27,    28,    29,    30,    26,   129,    33,    40,    35,
      41,    42,   144,    39,    40,    34,    35,    36,    37,    38,
     178,   144,     1,    20,    21,    42,     5,   190,   191,   192,
     190,   191,   195,   229,    13,    14,    15,    16,    17,    18,
       1,    20,    21,    22,    23,    24,    25,    26,    27,    31,
      32,    26,    34,    35,    36,    37,    38,   189,    26,    41,
     223,     3,   194,    42,    26,    26,    27,    28,    29,    30,
      40,    34,    33,    42,    35,    38,    34,    43,    39,    40,
      13,    14,    15,    16,    17,    18,   218,    40,    40,    22,
     222,    24,    25,    26,    27,   218,     6,     7,     8,     9,
      10,    40,    12,    13,    14,    15,    16,    17,    18,    26,
      36,     5,    22,    36,    24,    25,    26,    27,    13,    14,
      15,    16,    17,    18,    19,    27,    28,    29,    30,    24,
      25,    26,    27,    13,    14,    15,    16,    17,    18,     6,
       7,     8,     9,    27,    24,    25,    26,    27,    26,    27,
      28,    29,    30,    34,    40,    33,    43,    35,    43,    42,
      42,    39,    40,    26,    27,    28,    29,    30,    40,    23,
      33,    41,    35,    41,    21,    41,    41,    40,    13,    14,
      15,    16,    17,    18,    41,   176,    42,    22,    39,    24,
      25,    26,   127,    27,    28,    29,    30,   162,    24,    26,
      48,    35,    -1,    -1,    59,    39,    27,    28,    29,    30,
      -1,    -1,    -1,    -1,    35,    -1,    31,    32,    39,    34,
      35,    36,    37,    38,    -1,    31,    32,    42,    34,    35,
      36,    37,    38,    -1,    31,    32,    42,    34,    35,    36,
      37,    38,     0,     1,    41,    -1,     4,    -1,     6,     7,
       8,     9,    31,    32,    -1,    34,    35,    36,    37,    38,
      32,    -1,    34,    35,    36,    37,    38,     6,     7,     8,
       9,    10,    11,     6,     7,     8,     9,    10,    11,    34,
      -1,    36,    37,    38
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    46,    47,    48,     0,     5,     6,     7,     8,     9,
      10,    12,    13,    14,    15,    16,    17,    18,    22,    24,
      25,    26,    27,    49,    62,    63,    64,    65,    66,    67,
      68,    71,    73,    74,    75,    82,    83,    87,    90,    10,
      49,    54,    55,    26,    56,    26,    64,    68,    40,    68,
      76,    77,    27,    28,    29,    30,    33,    35,    39,    40,
      61,    68,    70,    80,    81,    40,    88,    26,    50,    51,
      63,    65,    40,    43,    44,     1,     4,    49,    91,    92,
      54,    50,    11,    55,    37,    57,    42,    42,    76,    42,
      40,    70,    70,    70,    80,    31,    32,    34,    35,    36,
      37,    38,     1,    42,    70,    26,    40,    42,    69,    70,
      39,    70,    26,    26,     1,    26,     3,    47,    11,    50,
      27,    35,    39,    58,    59,    60,    61,    26,    40,    42,
      77,    70,    41,    42,    70,    70,    70,    70,    70,    70,
      70,    81,     1,    81,    41,    43,    26,    27,    52,    53,
      51,    41,    42,    40,    40,    40,    97,    26,     5,    50,
      61,    37,    42,    36,    57,    64,    72,    26,    26,    18,
      19,    64,    66,    70,    78,    41,    42,    70,    49,    99,
      99,    99,    98,    40,    59,    35,    39,    61,    41,    42,
      43,    43,    40,    84,    42,    42,    47,    53,    50,    41,
      41,     1,    41,    99,    61,    64,    78,    78,    70,    47,
      64,    70,    23,    42,    95,    41,    41,    41,    41,    20,
      21,    85,    42,    42,    79,    89,    99,    96,    93,    86,
      64,    70,    94,    47,    21
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    45,    46,    47,    48,    48,    48,    48,    49,    49,
      49,    49,    50,    50,    51,    51,    52,    52,    53,    53,
      54,    54,    55,    55,    56,    56,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    60,    60,    61,    61,    61,
      61,    62,    62,    63,    63,    64,    65,    65,    66,    66,
      66,    66,    66,    66,    66,    66,    67,    67,    68,    68,
      68,    69,    69,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    71,    71,    72,    72,    73,
      73,    74,    75,    75,    76,    76,    77,    77,    78,    79,
      79,    80,    80,    80,    80,    81,    81,    81,    82,    82,
      84,    83,    86,    85,    85,    88,    89,    87,    90,    90,
      91,    93,    94,    92,    95,    96,    92,    92,    92,    92,
      97,    98,    92,    99,    99
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     3,     5,     3,     0,     1,     1,
       1,     1,     3,     1,     4,     1,     3,     1,     1,     1,
       2,     1,     2,     4,     4,     2,     3,     3,     1,     4,
       3,     3,     2,     1,     1,     1,     0,     1,     1,     1,
       1,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     3,     4,
       1,     3,     1,     3,     3,     3,     3,     3,     3,     3,
       2,     2,     1,     1,     3,     2,     6,     3,     1,     9,
       5,     2,     2,     2,     3,     1,     1,     7,     4,     2,
       0,     3,     3,     3,     1,     1,     7,     1,     1,     1,
       0,     8,     0,     4,     1,     0,     0,     8,     2,     0,
       3,     0,     0,     8,     0,     0,     7,     5,     5,     5,
       0,     0,     4,     4,     2
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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

  if (yychar <= T_EOF)
    {
      yychar = T_EOF;
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
  case 14: /* undef_variable: "identifier" "(" dims ")"  */
#line 109 "syntax.y"
                                                              { hashtbl_insert(hashtbl, (yyvsp[-3].id), NULL, scope); }
#line 1649 "syntax.tab.c"
    break;

  case 15: /* undef_variable: "identifier"  */
#line 110 "syntax.y"
                                       { hashtbl_insert(hashtbl, (yyvsp[0].id), NULL, scope); }
#line 1655 "syntax.tab.c"
    break;

  case 19: /* dim: "identifier"  */
#line 115 "syntax.y"
                                       { hashtbl_insert(hashtbl, (yyvsp[0].id), NULL, scope); }
#line 1661 "syntax.tab.c"
    break;

  case 24: /* vals: vals "," "identifier" value_list  */
#line 120 "syntax.y"
                                                              { hashtbl_insert(hashtbl, (yyvsp[-1].id), NULL, scope); }
#line 1667 "syntax.tab.c"
    break;

  case 25: /* vals: "identifier" value_list  */
#line 121 "syntax.y"
                                                  { hashtbl_insert(hashtbl, (yyvsp[-1].id), NULL, scope); }
#line 1673 "syntax.tab.c"
    break;

  case 54: /* simple_statement: "return"  */
#line 146 "syntax.y"
                                           { hashtbl_get(hashtbl, scope); scope--;}
#line 1679 "syntax.tab.c"
    break;

  case 58: /* variable: variable ":" "identifier"  */
#line 150 "syntax.y"
                                                       { hashtbl_insert(hashtbl, (yyvsp[0].id), NULL, scope); }
#line 1685 "syntax.tab.c"
    break;

  case 60: /* variable: "identifier"  */
#line 152 "syntax.y"
                                       { hashtbl_insert(hashtbl, (yyvsp[0].id), NULL, scope); }
#line 1691 "syntax.tab.c"
    break;

  case 76: /* goto_statement: "goto" "identifier" "," "(" labels ")"  */
#line 168 "syntax.y"
                                                                               { hashtbl_insert(hashtbl, (yyvsp[-4].id), NULL, scope); }
#line 1697 "syntax.tab.c"
    break;

  case 87: /* read_item: "(" read_list "," "identifier" "=" iter_space ")"  */
#line 179 "syntax.y"
                                                                                               { hashtbl_insert(hashtbl, (yyvsp[-3].id), NULL, scope); }
#line 1703 "syntax.tab.c"
    break;

  case 92: /* write_list: write_list "," error  */
#line 184 "syntax.y"
                                                           {yyerrok;}
#line 1709 "syntax.tab.c"
    break;

  case 93: /* write_list: write_list error write_item  */
#line 185 "syntax.y"
                                                              {yyerrok;}
#line 1715 "syntax.tab.c"
    break;

  case 96: /* write_item: "(" write_list "," "identifier" "=" iter_space ")"  */
#line 188 "syntax.y"
                                                                                                { hashtbl_insert(hashtbl, (yyvsp[-3].id), NULL, scope); }
#line 1721 "syntax.tab.c"
    break;

  case 100: /* $@1: %empty  */
#line 192 "syntax.y"
                                                                          {scope++;}
#line 1727 "syntax.tab.c"
    break;

  case 101: /* branch_statement: "if" "(" expression ")" "then" $@1 body tail  */
#line 192 "syntax.y"
                                                                                               { hashtbl_get(hashtbl, scope); scope--;}
#line 1733 "syntax.tab.c"
    break;

  case 102: /* $@2: %empty  */
#line 193 "syntax.y"
                                        {scope++;}
#line 1739 "syntax.tab.c"
    break;

  case 103: /* tail: "else" $@2 body "endif"  */
#line 193 "syntax.y"
                                                                { hashtbl_get(hashtbl, scope); scope--;}
#line 1745 "syntax.tab.c"
    break;

  case 104: /* tail: "endif"  */
#line 194 "syntax.y"
                                          { hashtbl_get(hashtbl, scope); scope--;}
#line 1751 "syntax.tab.c"
    break;

  case 105: /* $@3: %empty  */
#line 195 "syntax.y"
                                      {scope++;}
#line 1757 "syntax.tab.c"
    break;

  case 106: /* $@4: %empty  */
#line 195 "syntax.y"
                                                                                       { hashtbl_get(hashtbl, scope); scope--;}
#line 1763 "syntax.tab.c"
    break;

  case 107: /* loop_statement: "do" $@3 "identifier" "=" iter_space body "enddo" $@4  */
#line 195 "syntax.y"
                                                                                                                                { hashtbl_insert(hashtbl, (yyvsp[-5].id), NULL, scope); }
#line 1769 "syntax.tab.c"
    break;

  case 111: /* $@5: %empty  */
#line 199 "syntax.y"
                                                                                          {scope++;}
#line 1775 "syntax.tab.c"
    break;

  case 112: /* $@6: %empty  */
#line 199 "syntax.y"
                                                                                                     { hashtbl_get(hashtbl, scope); scope--;}
#line 1781 "syntax.tab.c"
    break;

  case 113: /* header: type "function" "identifier" "(" formal_parameters ")" $@5 $@6  */
#line 199 "syntax.y"
                                                                                                                                              { hashtbl_insert(hashtbl, (yyvsp[-5].id), NULL, scope); }
#line 1787 "syntax.tab.c"
    break;

  case 114: /* $@7: %empty  */
#line 200 "syntax.y"
                                                                                        {scope++;}
#line 1793 "syntax.tab.c"
    break;

  case 115: /* $@8: %empty  */
#line 200 "syntax.y"
                                                                                                   { hashtbl_get(hashtbl, scope); scope--;}
#line 1799 "syntax.tab.c"
    break;

  case 116: /* header: "subroutine" "identifier" "(" formal_parameters ")" $@7 $@8  */
#line 200 "syntax.y"
                                                                                                                                            { hashtbl_insert(hashtbl, (yyvsp[-5].id), NULL, scope); }
#line 1805 "syntax.tab.c"
    break;

  case 117: /* header: "subroutine" error "(" formal_parameters ")"  */
#line 201 "syntax.y"
                                                                                         {yyerrok;}
#line 1811 "syntax.tab.c"
    break;

  case 118: /* header: "subroutine" "identifier" "(" formal_parameters error  */
#line 202 "syntax.y"
                                                                                     {yyerrok;}
#line 1817 "syntax.tab.c"
    break;

  case 119: /* header: error "identifier" "(" formal_parameters ")"  */
#line 203 "syntax.y"
                                                                                 {yyerrok;}
#line 1823 "syntax.tab.c"
    break;

  case 120: /* $@9: %empty  */
#line 204 "syntax.y"
                                                    {scope++;}
#line 1829 "syntax.tab.c"
    break;

  case 121: /* $@10: %empty  */
#line 204 "syntax.y"
                                                               { hashtbl_get(hashtbl, scope); scope--;}
#line 1835 "syntax.tab.c"
    break;

  case 122: /* header: "subroutine" "identifier" $@9 $@10  */
#line 204 "syntax.y"
                                                                                                        { hashtbl_insert(hashtbl, (yyvsp[-2].id), NULL, scope); }
#line 1841 "syntax.tab.c"
    break;


#line 1845 "syntax.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= T_EOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == T_EOF)
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 210 "syntax.y"



int main(int argc, char* argv[]) {

    int token;

    if(argc>1){
        yyin = fopen(argv[1], "r");
        if (yyin == NULL) {
            printf("File not found: %s\n", argv[1]);
            perror("Error opening file");
            return 1;
        }
    }
    hashtbl = hashtbl_create(23, NULL);
    
    yyparse();

    fclose(yyin);
    hashtbl_get(hashtbl, scope);
    hashtbl_destroy(hashtbl);

    return 0;    
}

void yyerror(const char* err)
{
    error_counter++;
    printf("\n[Error - Line %d] %s\n", yylineno, err);

    if(error_counter == 5)
    {
        printf("MAXIMUM ERRORS FOUND\n");
        exit(EXIT_FAILURE);
    }
}
