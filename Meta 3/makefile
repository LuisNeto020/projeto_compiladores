all:
	flex  jucompiler.l
	yacc -d jucompiler.y
	cc -o jucompiler *.c 
	zip jucompiler.zip jucompiler.l jucompiler.y lex.yy.c y.tab.c y.tab.h functions.c functions.h