all: compiler

syntax.tab.c syntax.tab.h: syntax.y hashtbl.h
	bison -v -d syntax.y

lex.yy.c: lexer.l syntax.tab.h
	flex lexer.l

compiler: lex.yy.c syntax.tab.c syntax.tab.h hashtbl.c hashtbl.h
	gcc -o fort500 hashtbl.c syntax.tab.c lex.yy.c -lm 

clean:
	rm fort500 syntax.tab.c syntax.tab.h lex.yy.c 
	rm syntax.output
