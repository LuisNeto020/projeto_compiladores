%{
/*
    Luís Neto -2020215474
    João Moura -2020235800 
*/        
//Constantes
    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdbool.h>
    #include <stdarg.h>
	#include "y.tab.h"
	#include "symbol_table.h"
	#define false 0
    #define true 1
    int column=1; 
    int line=1;
    int commentBegin[2];
    int strlitBegin[2];
	extern int flag_erro;
	extern Node* root;
	int printLex=false;
    int doYacc=false;
    char *strlit;
    int str=0;
	sym_table *global_table,*local_table;
	int nErrorsSemantic;
	
	
	
%}

ID 				([a-zA-Z]|"$"|"_")+([a-zA-Z]|[0-9]|"$"|"_")*
INTLIT          0|[1-9]("_"*[0-9])*
REAL            ([0-9]("_"*[0-9])*)"."(([0-9]("_"*[0-9])*))?((e|E)("+"|"-")?([0-9]("_"*[0-9])*))?
INTEXP          ([0-9]("_"*[0-9])*)((e|E)("+"|"-")?([0-9]("_"*[0-9])*))
REALEXP         "."(([0-9]("_"*[0-9])*))((e|E)("+"|"-")?([0-9]("_"*[0-9])*))?
REALLIT         {INTEXP}|{REAL}|{REALEXP}
STRLIT          ([^\n\r\\"]|\\n|\\f|\\r|\\\\|\\\"|\\t)*
RESERVED        "++"|"--"|null|Integer|System|abstract|continue|for|new|switch|assert|default|package|synchronized|do|goto|private|this|break|implements|protected|throw|byte|import|throws|case|enum|instanceof|transient|catch|extends|short|try|char|final|interface|finally|long|strictfp|volatile|const|float|native|super
SPACE           " "|\t
NEWLINE         \n|\r\n|\r


%X              STRLLIT LINE_COMMENT COMMENT               

%%

"//"                                       {BEGIN LINE_COMMENT;}
<LINE_COMMENT>{NEWLINE}                    {line+=1,column=1,BEGIN 0;}
<LINE_COMMENT>.                            {column+=yyleng;}

"/*"                {BEGIN COMMENT;commentBegin[0]=line;commentBegin[1]=column;column+=yyleng;}
<COMMENT>"*/"       {BEGIN 0;column+=yyleng;}
<COMMENT>{NEWLINE}  {line++;column=1;}
<COMMENT>.          {column+=yyleng;}
<COMMENT><<EOF>>    {BEGIN 0;printf("Line %d, column %d: unterminated comment\n",commentBegin[0],commentBegin[1]);}

\"                                      {BEGIN STRLLIT;strlit=yytext;strlitBegin[0]=line;strlitBegin[1]=column;column+=yyleng;str=1;}
<STRLLIT>{STRLIT}                        {column+=yyleng;}
<STRLLIT>\\(.?)                          {printf("Line %d, column %d: invalid escape sequence (%s)\n",line,column,yytext); column += yyleng;str = 0;}
<STRLLIT>\n|\r|(\r\n)                    {line++; column= 1; printf("Line %d, column %d: unterminated string literal\n",strlitBegin[0],strlitBegin[1]);BEGIN 0;}
<STRLLIT>"\""                            {if(printLex && str==1)printf("STRLIT(%s)\n",strlit);column+=yyleng;BEGIN 0;
                                                                        if(doYacc && str== 1) {
																				yylval.value = createToken(strlit, line, column);
																				return STRLIT;
										}}
<STRLLIT><<EOF>>                         {printf("Line %d, column %d: unterminated string literal\n",strlitBegin[0],strlitBegin[1]); column+=yyleng; BEGIN 0;}


"true"              {if(printLex)printf("BOOLLIT(true)\n"); column+=yyleng;
                                        if(doYacc) {
										
											yylval.value = createToken(yytext, line, column-strlen(yytext));
											return BOOLLIT;
										}}
"false"             {if(printLex)printf("BOOLLIT(false)\n"); column+=yyleng;
                                        if(doYacc) {
											
											yylval.value = createToken(yytext, line, column-strlen(yytext));
											return BOOLLIT;
										}}
"&&"                {if(printLex)printf("AND\n"); column+=yyleng;if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return AND;}}
"="                 {if(printLex)printf("ASSIGN\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return ASSIGN;}}
"*"                 {if(printLex)printf("STAR\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return STAR;}}
","                 {if(printLex)printf("COMMA\n"); column+=yyleng; if(doYacc)return COMMA;}
"/"                 {if(printLex)printf("DIV\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return DIV;}}
"=="                {if(printLex)printf("EQ\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return EQ;}}
">="                {if(printLex)printf("GE\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return GE;}}
">"                 {if(printLex)printf("GT\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return GT;}}
"{"                 {if(printLex)printf("LBRACE\n"); column+=yyleng; if(doYacc)return LBRACE;}
"<="                {if(printLex)printf("LE\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return LE;}}
"("                 {if(printLex)printf("LPAR\n");column+=yyleng; if(doYacc)return LPAR;}
"["                 {if(printLex)printf("LSQ\n");column+=yyleng; if(doYacc)return LSQ;}
"<"                 {if(printLex)printf("LT\n");column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return LT;}}
"-"                 {if(printLex)printf("MINUS\n");column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return MINUS;}}
"%"                 {if(printLex)printf("MOD\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return MOD;}}
"!="                {if(printLex)printf("NE\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return NE;}}
"!"                 {if(printLex)printf("NOT\n");column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return NOT;}}
"||"                {if(printLex)printf("OR\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return OR;}}
"+"                 {if(printLex)printf("PLUS\n");column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return PLUS;}}
"}"                 {if(printLex)printf("RBRACE\n");column+=yyleng; if(doYacc)return RBRACE;}
")"                 {if(printLex)printf("RPAR\n"); column+=yyleng; if(doYacc)return RPAR;}
"]"                 {if(printLex)printf("RSQ\n"); column+=yyleng; if(doYacc)return RSQ;}
";"                 {if(printLex)printf("SEMICOLON\n"); column+=yyleng; if(doYacc)return SEMICOLON;}
"->"                {if(printLex)printf("ARROW\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return ARROW;}}
"<<"                {if(printLex)printf("LSHIFT\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return LSHIFT;}}
">>"                {if(printLex)printf("RSHIFT\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return RSHIFT;}}
"^"                 {if(printLex)printf("XOR\n"); column+=yyleng; if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return XOR;}}
"boolean"           {if(printLex)printf("BOOL\n"); column+=yyleng;if(doYacc)return BOOL;}
"class"             {if(printLex)printf("CLASS\n"); column+=yyleng;if(doYacc)return CLASS;}
".length"           {if(printLex)printf("DOTLENGTH\n"); column+=yyleng;if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return DOTLENGTH;}}
"double"            {if(printLex)printf("DOUBLE\n"); column+=yyleng;if(doYacc)return DOUBLE;}
"else"              {if(printLex)printf("ELSE\n"); column+=yyleng; if(doYacc)return ELSE;}
"if"                {if(printLex)printf("IF\n"); column+=yyleng;if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return IF;}}
"int"               {if(printLex)printf("INT\n"); column+=yyleng;if(doYacc)return INT;}
"System.out.print"  {if(printLex)printf("PRINT\n"); column+=yyleng;if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return PRINT;}}
"Integer.parseInt"  {if(printLex)printf("PARSEINT\n"); column+=yyleng;if(doYacc){yylval.value = createToken(yytext, line, column-strlen(yytext)); return PARSEINT;}}
"return"            {if(printLex)printf("RETURN\n"); column+=yyleng;if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext)); return RETURN;}}
"static"            {if(printLex)printf("STATIC\n"); column+=yyleng;if(doYacc)return STATIC;}
"String"            {if(printLex)printf("STRING\n"); column+=yyleng;if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext));return STRING;}}
"void"              {if(printLex)printf("VOID\n"); column+=yyleng;if(doYacc){yylval.value = createToken(yytext, line, column-strlen(yytext)); return VOID;}}
"public"            {if(printLex)printf("PUBLIC\n"); column+=yyleng;if(doYacc)return PUBLIC;}
"while"             {if(printLex)printf("WHILE\n"); column+=yyleng;if(doYacc){yylval.value = createToken(NULL, line, column-strlen(yytext)); return WHILE;}}
{RESERVED}          {if(printLex)printf("RESERVED(%s)\n",yytext); column+=yyleng;if(doYacc){yylval.value = createToken(yytext, line, column-strlen(yytext)); return RESERVED;}}
{SPACE}             {column+=yyleng;}
"\f"                {column+=yyleng;}
{NEWLINE}           {line+=1; column=1;}
{ID}                {if(printLex)printf("ID(%s)\n",yytext); column+=yyleng;
                                        if(doYacc) {
											yylval.value = createToken(yytext, line, column-strlen(yytext));
											return ID;
										}}
{INTLIT}            {if(printLex)printf("INTLIT(%s)\n",yytext); column+=yyleng;
                                     if(doYacc) {
											yylval.value = createToken(yytext, line, column-strlen(yytext));
											 return INTLIT;
										}}
{REALLIT}           {if(printLex)printf("REALLIT(%s)\n",yytext); column+=yyleng;
                                            if(doYacc) {
											yylval.value = createToken(yytext, line, column-strlen(yytext));
											return REALLIT;
										}}

.                   {printf("Line %d, column %d: illegal character (%s)\n", line,column,yytext); column+=yyleng;}


%%

void yyerror(const char *s) { 
     printf ("Line %d, column %d: %s: %s\n", line, (int)(column-strlen(yytext)), s, yytext);
}

int yywrap() {
	return 1;
}

int main(int argc,char* argv[]){
    if (argc > 1){
        if (strcmp(argv[1], "-l") == 0){
            printLex=true;
            doYacc=false;
            yylex();}
        else if(strcmp(argv[1], "-t") == 0){
            doYacc=true;
			printLex=false;
            yyparse();
			if (flag_erro == 0) {
				printTree(root, 0);
			}else{
				freeTree(root);
			}  
        }
        else if (strcmp(argv[1], "-e1") == 0) {
			printLex=false;
            doYacc=false;
			yylex() ;
         }
        else if (strcmp(argv[1], "-e2") == 0) {
			printLex=false;
            doYacc=true;
			yyparse();
			freeTree(root);
		}
		else if(strcmp(argv[1],"-s")==0){
			doYacc=true;
			printLex=false;
			global_table = NULL;
			local_table = NULL;
			yyparse();

			if(flag_erro == 0){
				create_semantic_table(root);
				print_table_global(global_table);
				print_tables_local(local_table);
				printAnotedAST(root,0);
				clearTables(global_table, local_table);
			}
			freeTree(root);
		}

			

		}
	
    else {
		printLex=false;
        doYacc=true;
		yyparse();
		freeTree(root);
		
	}
	return 0;
}
