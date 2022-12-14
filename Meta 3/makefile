all:
	flex  jucompiler.l
	yacc -d jucompiler.y
	cc -o  jucompiler *.c -g
	zip jucompiler.zip jucompiler.l jucompiler.y lex.yy.c y.tab.c y.tab.h AstTree.c AstTree.h  semantics.h  semantics.c