/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    T_EOF = 0,                     /* "EOF"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    T_FUNCTION = 258,              /* "function"  */
    T_SUBROUTINE = 259,            /* "subroutine"  */
    T_END = 260,                   /* "end"  */
    T_INTEGER = 261,               /* "integer"  */
    T_REAL = 262,                  /* "real"  */
    T_LOGICAL = 263,               /* "logical"  */
    T_CHARACTER = 264,             /* "character"  */
    T_RECORD = 265,                /* "record"  */
    T_ENDREC = 266,                /* "endrec"  */
    T_DATA = 267,                  /* "data"  */
    T_CONTINUE = 268,              /* "continue"  */
    T_GOTO = 269,                  /* "goto"  */
    T_CALL = 270,                  /* "call"  */
    T_READ = 271,                  /* "read"  */
    T_WRITE = 272,                 /* "write"  */
    T_IF = 273,                    /* "if"  */
    T_THEN = 274,                  /* "then"  */
    T_ELSE = 275,                  /* "else"  */
    T_ENDIF = 276,                 /* "endif"  */
    T_DO = 277,                    /* "do"  */
    T_ENDDO = 278,                 /* "enddo"  */
    T_STOP = 279,                  /* "stop"  */
    T_RETURN = 280,                /* "return"  */
    T_ID = 281,                    /* "identifier"  */
    T_ICONST = 282,                /* "integer constant"  */
    T_RCONST = 283,                /* "real constant"  */
    T_LCONST = 284,                /* "logical constant"  */
    T_CCONST = 285,                /* "char constant"  */
    T_OROP = 286,                  /* "or"  */
    T_ANDOP = 287,                 /* "and"  */
    T_NOTOP = 288,                 /* "not"  */
    T_RELOP = 289,                 /* "> or >= or < or <= or !="  */
    T_ADDOP = 290,                 /* "+ or -"  */
    T_MULOP = 291,                 /* "*"  */
    T_DIVOP = 292,                 /* "/"  */
    T_POWEROP = 293,               /* "**"  */
    T_STRING = 294,                /* "string constant"  */
    T_LPAREN = 295,                /* "("  */
    T_RPAREN = 296,                /* ")"  */
    T_COMMA = 297,                 /* ","  */
    T_ASSIGN = 298,                /* "="  */
    T_COLON = 299                  /* ":"  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "syntax.y"

    int intval;
    float floatval;
    char charval;
    char *strval;
    char *id;

#line 116 "syntax.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */
