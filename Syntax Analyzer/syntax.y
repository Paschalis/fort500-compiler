%{
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
%}

%define parse.error verbose


%union {
    int intval;
    float floatval;
    char charval;
    char *strval;
    char *id;
}

// Keywords
%token T_FUNCTION           "function"
%token T_SUBROUTINE         "subroutine"
%token T_END                "end"
%token T_INTEGER            "integer"
%token T_REAL               "real"
%token T_LOGICAL            "logical"
%token T_CHARACTER          "character"
%token T_RECORD             "record"
%token T_ENDREC             "endrec"
%token T_DATA               "data"
%token T_CONTINUE           "continue"
%token T_GOTO               "goto"
%token T_CALL               "call"
%token T_READ               "read"
%token T_WRITE              "write"
%token T_IF                 "if"
%token T_THEN               "then"
%token T_ELSE               "else"
%token T_ENDIF              "endif"
%token T_DO                 "do"
%token T_ENDDO              "enddo"
%token T_STOP               "stop"
%token T_RETURN             "return"

// Identifiers
%token <id>             T_ID                 "identifier"

// Constants
%token <intval>             T_ICONST             "integer constant"
%token <floatval>           T_RCONST             "real constant"
%token <charval>            T_LCONST             "logical constant"
%token <strval>             T_CCONST             "char constant"

// Operators
%token T_OROP               "or"
%token T_ANDOP              "and"
%token T_NOTOP              "not"
%token T_RELOP              "> or >= or < or <= or !="
%token T_ADDOP              "+ or -"
%token T_MULOP              "*"
%token T_DIVOP              "/"
%token T_POWEROP            "**"

%token T_STRING             "string constant"

// Language-specific symbols
%token T_LPAREN             "("
%token T_RPAREN             ")"
%token T_COMMA              ","
%token T_ASSIGN             "="
%token T_COLON              ":"

// End Of File
%token T_EOF         0      "EOF"

%left T_OROP
%left T_ANDOP
%left T_ADDOP
%left T_MULOP T_DIVOP
%left T_LPAREN T_RPAREN T_COLON
%right T_POWEROP
%nonassoc T_NOTOP
%nonassoc T_RELOP

%%

program:                         body T_END subprograms;
body:                            declarations statements;
declarations:                    declarations type vars

                                | declarations T_RECORD fields T_ENDREC vars
                                | declarations T_DATA vals
                                | %empty;
type:                            T_INTEGER | T_REAL | T_LOGICAL | T_CHARACTER;
vars:                            vars T_COMMA undef_variable
                                | undef_variable;
undef_variable:                   T_ID T_LPAREN dims T_RPAREN { hashtbl_insert(hashtbl, $1, NULL, scope); }
                                | T_ID { hashtbl_insert(hashtbl, $1, NULL, scope); }
                                ;
dims:                            dims T_COMMA dim
                                | dim;
dim:                             T_ICONST 
                                | T_ID { hashtbl_insert(hashtbl, $1, NULL, scope); };
fields:                          fields field
                                | field;
field:                           type vars
                                | T_RECORD fields T_ENDREC vars;
vals:                            vals T_COMMA T_ID value_list { hashtbl_insert(hashtbl, $3, NULL, scope); }
                                | T_ID value_list { hashtbl_insert(hashtbl, $1, NULL, scope); }; 
value_list:                      T_DIVOP values T_DIVOP;
values:                          values T_COMMA value
                                | value;
value:                           repeat T_MULOP T_ADDOP constant
                                | repeat T_MULOP constant
                                | repeat T_MULOP T_STRING
                                | T_ADDOP constant
                                | constant
                                | T_STRING;
repeat:                          T_ICONST | %empty;
constant:                        T_ICONST | T_RCONST | T_LCONST | T_CCONST;
statements:                      statements labeled_statement
                                | labeled_statement;
labeled_statement:               label statement
                                | statement;
label:                           T_ICONST;
statement:                       simple_statement
                                | compound_statement;
simple_statement:               assignment
                                | goto_statement
                                | if_statement
                                | subroutine_call
                                | io_statement
                                | T_CONTINUE
                                | T_RETURN { hashtbl_get(hashtbl, scope); scope--;}
                                | T_STOP;
assignment:                      variable T_ASSIGN expression
                                | variable T_ASSIGN T_STRING;
variable:                        variable T_COLON T_ID { hashtbl_insert(hashtbl, $3, NULL, scope); }
                                | variable T_LPAREN expressions T_RPAREN
                                | T_ID { hashtbl_insert(hashtbl, $1, NULL, scope); };
expressions:                     expressions T_COMMA expression
                                | expression;
expression:                      expression T_OROP expression
                                | expression T_ANDOP expression
                                | expression T_RELOP expression
                                | expression T_ADDOP expression
                                | expression T_MULOP expression
                                | expression T_DIVOP expression
                                | expression T_POWEROP expression
                                | T_NOTOP expression
                                | T_ADDOP expression
                                | variable
                                | constant
                                | T_LPAREN expression T_RPAREN;
goto_statement:                  T_GOTO label
                                | T_GOTO T_ID T_COMMA T_LPAREN labels T_RPAREN { hashtbl_insert(hashtbl, $2, NULL, scope); };
labels:                          labels T_COMMA label
                                | label;
if_statement:                    T_IF T_LPAREN expression T_RPAREN label T_COMMA label T_COMMA label
                                | T_IF T_LPAREN expression T_RPAREN simple_statement;
subroutine_call:                 T_CALL variable;
io_statement:                    T_READ read_list
                                | T_WRITE write_list;
read_list:                       read_list T_COMMA read_item
                                | read_item;
read_item:                       variable
                                | T_LPAREN read_list T_COMMA T_ID T_ASSIGN iter_space T_RPAREN { hashtbl_insert(hashtbl, $4, NULL, scope); }; 
iter_space:                      expression T_COMMA expression step;
step:                            T_COMMA expression
                                | %empty;
write_list:                      write_list T_COMMA write_item
                                | write_list T_COMMA error {yyerrok;}
                                | write_list error write_item {yyerrok;}
                                | write_item;
write_item:                      expression
                                | T_LPAREN write_list T_COMMA T_ID T_ASSIGN iter_space T_RPAREN { hashtbl_insert(hashtbl, $4, NULL, scope); }
                                | T_STRING;
compound_statement:              branch_statement
                                | loop_statement;
branch_statement:                T_IF T_LPAREN expression T_RPAREN T_THEN {scope++;} body tail { hashtbl_get(hashtbl, scope); scope--;} ;
tail:                            T_ELSE {scope++;} body T_ENDIF { hashtbl_get(hashtbl, scope); scope--;}
                                | T_ENDIF { hashtbl_get(hashtbl, scope); scope--;} ;
loop_statement:                  T_DO {scope++;} T_ID T_ASSIGN iter_space body T_ENDDO { hashtbl_get(hashtbl, scope); scope--;} { hashtbl_insert(hashtbl, $3, NULL, scope); } ;
subprograms:                     subprograms subprogram
                                | %empty;
subprogram:                      header body T_END;
header:                          type T_FUNCTION T_ID T_LPAREN formal_parameters T_RPAREN {scope++;} { hashtbl_get(hashtbl, scope); scope--;} { hashtbl_insert(hashtbl, $3, NULL, scope); }
                                | T_SUBROUTINE T_ID T_LPAREN formal_parameters T_RPAREN {scope++;} { hashtbl_get(hashtbl, scope); scope--;} { hashtbl_insert(hashtbl, $2, NULL, scope); }
                                | T_SUBROUTINE error T_LPAREN formal_parameters T_RPAREN {yyerrok;}
                                | T_SUBROUTINE T_ID T_LPAREN formal_parameters error {yyerrok;}
                                | error T_ID T_LPAREN formal_parameters T_RPAREN {yyerrok;}
                                | T_SUBROUTINE T_ID {scope++;} { hashtbl_get(hashtbl, scope); scope--;} { hashtbl_insert(hashtbl, $2, NULL, scope); };
formal_parameters:               type vars T_COMMA formal_parameters
                                | type vars;



%%


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