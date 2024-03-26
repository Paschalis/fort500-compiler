%{
    #include "lexer.h"
    #include <stdlib.h>
    #include <stdio.h>
    #include <string.h>
    #include <errno.h>
    #include <math.h>


    char str_buf[256]; /* Στατικός πίνακας 256 χαρακτήρων για την αποθήκευση των string αργότερα*/
    char str_esc[256];

    int strtoint(const char *str);
    char strtochar(const char *str);
    float strtoreal(const char *str);
    void stresc(char *original_string, char *final_string);
    void yyerror(const char *err);
%}

/* Instructs flex to generate a case-insensitive scanner. The case of letters given in the flex input patterns will be ignored, and tokens in the input will be matched regardless of case.*/
/* Αναγνώριση των λέξεων κλειδιών και με κεφαλαία (e.g. 'INT') και με πεζά (e.g. 'int')*/
%option case-insensitive

/* The 'yywrap' if unset (i.e., `%option noyywrap'), makes the scanner not call `yywrap()' upon an end-of-file, but simply assume that there are no more files to scan  */
/* Για την ανάγνωση ΜΟΝΟ ενός αρχείου κάθε φορά*/
%option noyywrap

/* Directs flex to generate a scanner that maintains the number of the current line read from its input in the global variable yylineno */
/* Μεταβλητή τύπου int ενσωματωμένη στο Flex. Κάθε φορά που συναντά το Flex τον χαρακτήρα νέας γραμμής ('\n'), η μεταβλητή αυξάνεται αυτόματα κατά 1*/
%option yylineno
%x STRING


LETTER      [a-z]
DIGIT       [0-9]
CHARACTER   {LETTER}|{DIGIT}
NZNUMBER    [1-9]{DIGIT}*|0

/* ALTERNATIVE WAY*/ 
/*                  (_[LETTER](({CHARACTER}|_{CHARACTER})+)?_)|{LETTER}({CHARACTER}+)?  */
ID                  (_[a-z](([a-z]|[0-9]|_([a-z]|[0-9]))+)?_)|[a-z](([a-z]|[0-9])+)?  

/* ALTERNATIVE WAY*/
/*                  {NZNUMBER}?\.({NZNUMBER}*{NZNUMBER})([E][-+]?{NZNUMBER})?|{NZNUMBER}[E][-+]?({NZNUMBER}[^\.]|0H([1-9A-F][0-9A-F]*|0)?\.([1-9A-F][0-9A-F]*|0*[1-9A-F][0-9A-F]*|0)?|0B(1[01]*|0)?\.(1[01]*|0*1[0-1]*|0)*    */
RCONST              ([1-9][0-9]*|0)?\.([1-9][0-9]*|0*[1-9][0-9]|0)([Ee][-+]?([1-9][0-9]*|0))?|([1-9][0-9]*|0)[Ee][-+]?([1-9][0-9]*|0)[^\.]|0H([1-9A-F][0-9A-F]*|0)?\.([1-9A-F][0-9A-F]*|0*[1-9A-F][0-9A-F]*|0)?|0B(1[01]*|0)?\.(1[01]*|0*1[0-1]*|0)

/* ALTERNATIVE WAY*/ 
/*                  0H[1-9A-F][0-9A-F]*|0B1[01]*|{NZNUMBER} */
ICONST              0H[1-9A-F][0-9A-F]*|0B1[01]*|[1-9][0-9]*|0
 
LCONST              ".TRUE."|".FALSE."
CCONST              '(.|\\[nftrbv])'
RELOP               ".GT."|".GE."|".LT."|".LE."|".EQ."|".NE."

%%

"FUNCTION"          { printf("\nKEYWORD: FUNCTION"); return T_FUNCTION; }
"END"               { printf("\nKEYWORD: END"); return T_END; }
"REAL"              { printf("\nKEYWORD: REAL"); return T_REAL; }
"SUBROUTINE"        { printf("\nKEYWORD: SUBROUTINE"); return T_SUBROUTINE; }
"LOGICAL"           { printf("\nKEYWORD: LOGICAL"); return T_LOGICAL; }
"CHARACTER"         { printf("\nKEYWORD: CHARACTER"); return T_CHARACTER; }
"INTEGER"           { printf("\nKEYWORD: INTEGER"); return T_INTEGER; }
"RECORD"            { printf("\nKEYWORD: RECORD"); return T_RECORD; }
"ENDREC"            { printf("\nKEYWORD: ENDREC"); return T_ENDREC; }
"DATA"              { printf("\nKEYWORD: DATA"); return T_DATA; }
"CONTINUE"          { printf("\nKEYWORD: CONTINUE"); return T_CONTINUE; }
"GOTO"              { printf("\nKEYWORD: GOTO"); return T_GOTO; }
"CALL"              { printf("\nKEYWORD: CALL"); return T_CALL; }
"READ"              { printf("\nKEYWORD: READ"); return T_READ; }
"WRITE"             { printf("\nKEYWORD: WRITE"); return T_WRITE; }
"IF"                { printf("\nKEYWORD: IF"); return T_IF; }
"THEN"              { printf("\nKEYWORD: THEN"); return T_THEN; }
"ELSE"              { printf("\nKEYWORD: ELSE"); return T_ELSE; }
"ENDIF"             { printf("\nKEYWORD: ENDIF"); return T_ENDIF; }
"DO"                { printf("\nKEYWORD: DO"); return T_DO; }
"ENDDO"             { printf("\nKEYWORD: ENDDO"); return T_ENDDO; }
"STOP"              { printf("\nKEYWORD: STOP"); return T_STOP; }
"RETURN"            { printf("\nKEYWORD: RETURN"); return T_RETURN; }

{RCONST}            { printf("\nT_RCONST: %s (%d)", yytext, strtoreal(yytext)); return T_RCONST; }
{ID}                { printf("\nT_ID: %s", yytext); return T_ID; }
{ICONST}            { printf("\nT_ICONST: %s (%d)", yytext, strtoint(yytext)); return T_ICONST; }
{LCONST}            { printf("\nT_LCONST: %s", yytext); return T_LCONST; }
{CCONST}            { printf("\nT_CCONST: %s (%c)", yytext, strtochar(yytext)); return T_CCONST; }
{RELOP}             { printf("\nT_RELOP: %s", yytext); return T_RELOP; }


".OR."              { printf("\nT_OROP: %s", yytext); return T_OROP;  }
".AND."             { printf("\nT_ANDOP: %s", yytext); return T_ANDOP; }
".NOT."             { printf("\nT_NOTOP: %s", yytext); return T_NOTOP; }
"+"|"-"             { printf("\nT_ADDOP: %s", yytext); return T_ADDOP; }
"*"                 { printf("\nT_MULOP: %s", yytext); return T_MULOP; }
"/"                 { printf("\nT_DIVOP: %s", yytext); return T_DIVOP; }
"**"                { printf("\nT_T_POWEROP: %s", yytext); return T_POWEROP;}


"("                 { printf("\nLPAREN: %s", yytext); return T_LPAREN; }
")"                 { printf("\nRPAREN: %s", yytext); return T_RPAREN; }
","                 { printf("\nCOMMA: %s", yytext); return T_COMMA; }
"="                 { printf("\nASSIGN: %s", yytext); return T_ASSIGN; }
":"                 { printf("\nASSIGN: %s", yytext); return T_COLON; }


\"                  { strcpy(str_buf,  ""); memset(str_esc, 0, sizeof(str_esc)); BEGIN(STRING); }
<STRING>\"          { stresc(str_buf, str_esc); printf("\nSTRING: %s", str_buf); printf("\nFINAL SCONST: %s", str_esc); BEGIN(INITIAL); return T_STRING; }
<STRING>\n          { printf("\n[ERROR] New line without \\"); }
<STRING>\\\n[ ]*    { /* Δεν θέλουμε να αποθηκεύσουμε την αλλαγή γραμμής ως περιεχόμενο του string, όπως και τα space που πιθανώς υπάρχουν στην αρχή της επόμενης γραμμής. */ }
<STRING>\\[ ]       { printf("\n[ERROR] \\ in string, not at the end of the line."); }
<STRING>\\[^ ]      { strcat(str_buf, yytext); }
<STRING>[^\\"]      { strcat(str_buf, yytext); }
<STRING><<EOF>>     { printf("\n[ERROR] EOF in string."); }
<STRING>.           { printf("\n[ERROR] Unrecognised character in string: %s", yytext); }


$.*                 {printf("COMMENT \n");}

[ \t]               { /* Κενά (space) μέσα στο αρχείο - απλά τα αγνοούμε */ }
\n                  { printf("\n\n[Line %d]", yylineno); }
<<EOF>>             { printf("\nEOF\n"); return T_EOF; }
.                   { yyerror("Unrecognised character"); }


%%


int strtoint(const char *str) {
    if (strncmp(str, "0B", 2) == 0 || strncmp(str, "0b", 2) == 0) {
        return (int) strtol(&str[2], NULL, 2);  // Βάση 2
    }
    else if (strncmp(str, "0H", 2) == 0 || strncmp(str, "0H", 2) == 0){
        return (int) strtol(&str[2], NULL, 16);  // Βάση 16
    }
    else {
        return (int) strtol(str, NULL, 10);     // Βάση 10
    }
}

float strtoreal(const char *str) {

    int i, base;
    float res;
    char *integer, *fractional; // part

    if (!strncmp(str, "0B", 2) || !strncmp(str, "0b", 2)) { base = 2; res = strtol(&str[2], &integer, 2); }
    else if (!strncmp(str, "0H", 2) || !strncmp(str, "0h", 2)) { base = 16; res = strtol(&str[2], &integer, 16); }
    else { base = 10; }

    if (base != 10) {
        for (i = 1; i < strlen(integer); ++i) {
            res += (integer[i] <= '9') ? (integer[i] - '0') * (1 / pow(base, i)) : (integer[i] - 'A' + 10) * (1 / pow(base, i));
        }
    } else {
        if (strchr(str, '.')) {
            res = strtol(str, &integer, 10);
            strtol(&integer[1], &fractional, 10);

            for (i = 1; i < strlen(integer) - strlen(fractional); ++i) res += (integer[i] - '0') * (1 / pow(base, i));

            if (strchr(fractional, '+')) res *= pow(10, strtol(&fractional[2], NULL, 10));
            else if (strchr(fractional, '-')) res *= pow(10, strtol(&fractional[2], NULL, 10) * -1);
            else res *= pow(10, strtol(&fractional[1], NULL, 10));
        } else {
            res = strtol(str, &fractional, 10);

            if (strchr(fractional, '+')) res *= pow(10, strtol(&fractional[2], NULL, 10));
            else if (strchr(fractional, '-')) res *= pow(10, strtol(&fractional[2], NULL, 10) * -1);
            else res *= pow(10, strtol(&fractional[1], NULL, 10));
        }
    }

    return res;

}


char strtochar(const char *str) {
    if (str[1] == '\\') {
        switch (str[2]) {
            case 'n': return '\n';
            case 'f': return '\f';
            case 't': return '\t';
            case 'r': return '\r';
            case 'b': return '\b';
            case 'v': return '\v';
            default:
                printf("\n[ERROR] Unknown escaped character: \\%c", str[2]);
                return '\0';
        }
    } else {
        return str[1];
    }
}

void stresc(char *original_string, char *final_string) {
    int i, j;

    for (i = 0, j = 0; i < strlen(original_string); i++, j++) {
        if (original_string[i] == '\\') {
            switch (original_string[i + 1]) {
                case 'n': final_string[j] = '\n'; break;
                case 'f': final_string[j] = '\f'; break;
                case 't': final_string[j] = '\t'; break;
                case 'r': final_string[j] = '\r'; break;
                case 'b': final_string[j] = '\b'; break;
                case 'v': final_string[j] = '\v'; break;
                case '\\': final_string[j] = '\\'; break;
                case '\'': final_string[j] = '\''; break;
                case '"': final_string[j] = '"'; break;
                default:
                    printf("\n[ERROR] Unknown escaped character: \\%c", original_string[i + 1]);
                    return;
            }

            i++;
        } else {
            final_string[j] = original_string[i];
        }
    }
}

void yyerror(const char* err){
    printf("[Error - Line %d] %s\n", yylineno, err);
}

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
    
    printf("[Line %d]\n", yylineno);
    
    do {
        token = yylex();
    } while (token != T_EOF);
    
    fclose(yyin);
    yyterminate();

    return 0;    
}
