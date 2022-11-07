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
	#include "functions.h"
	#define false 0
    #define true 1
    int col=1; 
    int line=1;
    int commentBegin[2];
    int strlitBegin[2];
	extern int flag_erro;
	extern Node* root;
	int printLex=false;
    int doYacc=false;
    char *strlit;
    int str=0;
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
<LINE_COMMENT>{NEWLINE}                    {line+=1,col=1,BEGIN 0;}
<LINE_COMMENT>.                            {col+=yyleng;}

"/*"                {BEGIN COMMENT;commentBegin[0]=line;commentBegin[1]=col;col+=yyleng;}
<COMMENT>"*/"       {BEGIN 0;col+=yyleng;}
<COMMENT>{NEWLINE}  {line++;col=1;}
<COMMENT>.          {col+=yyleng;}
<COMMENT><<EOF>>    {BEGIN 0;printf("Line %d, col %d: unterminated comment\n",commentBegin[0],commentBegin[1]);}

\"                                      {BEGIN STRLLIT;strlit=yytext;strlitBegin[0]=line;strlitBegin[1]=col;col+=yyleng;str=1;}
<STRLLIT>{STRLIT}                        {col+=yyleng;}
<STRLLIT>\\(.?)                          {printf("Line %d, col %d: invalid escape sequence (%s)\n",line,col,yytext); col += yyleng;str = 0;}
<STRLLIT>\n|\r|(\r\n)                    {line++; col= 1; printf("Line %d, col %d: unterminated string literal\n",strlitBegin[0],strlitBegin[1]);BEGIN 0;}
<STRLLIT>"\""                            {if(printLex && str==1)printf("STRLIT(%s)\n",strlit);col+=yyleng;BEGIN 0;
                                                                        if(doYacc && str== 1) {
											                                    yylval.id = strdup(strlit);
																				yytext=strlit;
																				return STRLIT;
										}}
<STRLLIT><<EOF>>                         {printf("Line %d, col %d: unterminated string literal\n",strlitBegin[0],strlitBegin[1]); col+=yyleng; BEGIN 0;}


"true"              {if(printLex)printf("BOOLLIT(true)\n"); col+=yyleng;
                                        if(doYacc) {
											yylval.id = strdup(yytext);
											return BOOLLIT;
										}}
"false"             {if(printLex)printf("BOOLLIT(false)\n"); col+=yyleng;
                                        if(doYacc) {
											yylval.id = strdup(yytext);
											return BOOLLIT;
										}}
"&&"                {if(printLex)printf("AND\n"); col+=yyleng;if(doYacc)return AND;}
"="                 {if(printLex)printf("ASSIGN\n"); col+=yyleng; if(doYacc)return ASSIGN;}
"*"                 {if(printLex)printf("STAR\n"); col+=yyleng; if(doYacc)return STAR;}
","                 {if(printLex)printf("COMMA\n"); col+=yyleng; if(doYacc)return COMMA;}
"/"                 {if(printLex)printf("DIV\n"); col+=yyleng; if(doYacc)return DIV;}
"=="                {if(printLex)printf("EQ\n"); col+=yyleng; if(doYacc)return EQ;}
">="                {if(printLex)printf("GE\n"); col+=yyleng; if(doYacc)return GE;}
">"                 {if(printLex)printf("GT\n"); col+=yyleng; if(doYacc)return GT;}
"{"                 {if(printLex)printf("LBRACE\n"); col+=yyleng; if(doYacc)return LBRACE;}
"<="                {if(printLex)printf("LE\n"); col+=yyleng; if(doYacc)return LE;}
"("                 {if(printLex)printf("LPAR\n");col+=yyleng; if(doYacc)return LPAR;}
"["                 {if(printLex)printf("LSQ\n");col+=yyleng; if(doYacc)return LSQ;}
"<"                 {if(printLex)printf("LT\n");col+=yyleng; if(doYacc)return LT;}
"-"                 {if(printLex)printf("MINUS\n");col+=yyleng; if(doYacc)return MINUS;}
"%"                 {if(printLex)printf("MOD\n"); col+=yyleng; if(doYacc)return MOD;}
"!="                {if(printLex)printf("NE\n"); col+=yyleng; if(doYacc)return NE;}
"!"                 {if(printLex)printf("NOT\n");col+=yyleng; if(doYacc)return NOT;}
"||"                {if(printLex)printf("OR\n"); col+=yyleng; if(doYacc)return OR;}
"+"                 {if(printLex)printf("PLUS\n");col+=yyleng; if(doYacc)return PLUS;}
"}"                 {if(printLex)printf("RBRACE\n");col+=yyleng; if(doYacc)return RBRACE;}
")"                 {if(printLex)printf("RPAR\n"); col+=yyleng; if(doYacc)return RPAR;}
"]"                 {if(printLex)printf("RSQ\n"); col+=yyleng; if(doYacc)return RSQ;}
";"                 {if(printLex)printf("SEMICOLON\n"); col+=yyleng; if(doYacc)return SEMICOLON;}
"->"                {if(printLex)printf("ARROW\n"); col+=yyleng; if(doYacc)return ARROW;}
"<<"                {if(printLex)printf("LSHIFT\n"); col+=yyleng; if(doYacc)return LSHIFT;}
">>"                {if(printLex)printf("RSHIFT\n"); col+=yyleng; if(doYacc)return RSHIFT;}
"^"                 {if(printLex)printf("XOR\n"); col+=yyleng; if(doYacc)return XOR;}
"boolean"           {if(printLex)printf("BOOL\n"); col+=yyleng;if(doYacc)return BOOL;}
"class"             {if(printLex)printf("CLASS\n"); col+=yyleng;if(doYacc)return CLASS;}
".length"           {if(printLex)printf("DOTLENGTH\n"); col+=yyleng;if(doYacc)return DOTLENGTH;}
"double"            {if(printLex)printf("DOUBLE\n"); col+=yyleng;if(doYacc)return DOUBLE;}
"else"              {if(printLex)printf("ELSE\n"); col+=yyleng; if(doYacc)return ELSE;}
"if"                {if(printLex)printf("IF\n"); col+=yyleng;if(doYacc)return IF;}
"int"               {if(printLex)printf("INT\n"); col+=yyleng;if(doYacc)return INT;}
"System.out.print"  {if(printLex)printf("PRINT\n"); col+=yyleng;if(doYacc)return PRINT;}
"Integer.parseInt"  {if(printLex)printf("PARSEINT\n"); col+=yyleng;if(doYacc) return PARSEINT;}
"return"            {if(printLex)printf("RETURN\n"); col+=yyleng;if(doYacc) return RETURN;}
"static"            {if(printLex)printf("STATIC\n"); col+=yyleng;if(doYacc)return STATIC;}
"String"            {if(printLex)printf("STRING\n"); col+=yyleng;if(doYacc)return STRING;}
"void"              {if(printLex)printf("VOID\n"); col+=yyleng;if(doYacc) return VOID;}
"public"            {if(printLex)printf("PUBLIC\n"); col+=yyleng;if(doYacc)return PUBLIC;}
"while"             {if(printLex)printf("WHILE\n"); col+=yyleng;if(doYacc) return WHILE;}
{RESERVED}          {if(printLex)printf("RESERVED(%s)\n",yytext); col+=yyleng;if(doYacc) return RESERVED;}
{SPACE}             {col+=yyleng;}
"\f"                {col+=yyleng;}
{NEWLINE}           {line+=1; col=1;}
{ID}                {if(printLex)printf("ID(%s)\n",yytext); col+=yyleng;
                                        if(doYacc) {
											yylval.id = strdup(yytext);
											return ID;
										}}
{INTLIT}            {if(printLex)printf("INTLIT(%s)\n",yytext); col+=yyleng;
                                     if(doYacc) {
											yylval.id = strdup(yytext);
											 return INTLIT;
										}}
{REALLIT}           {if(printLex)printf("REALLIT(%s)\n",yytext); col+=yyleng;
                                            if(doYacc) {
											yylval.id = strdup(yytext);
											return REALLIT;
										}}

.                   {printf("Line %d, col %d: illegal character (%s)\n", line,col,yytext); col+=yyleng;}


%%

void yyerror(const char *s) { 
     printf ("Line %d, col %d: %s: %s\n", line, (int)(col-strlen(yytext)), s, yytext);
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
	}
    else {
		printLex=false;
        doYacc=true;
		yyparse();
		freeTree(root);
		
	}
	return 0;
}
