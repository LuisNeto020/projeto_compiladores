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
	int yyparse(void);
    int col=1; 
    int line=1;
    int commentBegin[2];
    int strlitBegin[2];
    extern int flag_erro;
    int flag=0;
    char *strlit;
    int str=false;
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
<COMMENT><<EOF>>    {printf("Line %d, col %d: unterminated comment\n",commentBegin[0],commentBegin[1]);BEGIN 0;}

\"                                      {BEGIN STRLLIT;strlit=yytext;strlitBegin[0]=line;strlitBegin[1]=col;col+=yyleng;str=1;}
<STRLLIT>{STRLIT}                        {col+=yyleng;}
<STRLLIT>\\(.?)                          {printf("Line %d, col %d: invalid escape sequence (%s)\n",line,col,yytext); col += yyleng;str = 0;}
<STRLLIT>\n|\r|(\r\n)                    {line++; col= 1; printf("Line %d, col %d: unterminated string literal\n",strlitBegin[0],strlitBegin[1]);BEGIN 0;}
<STRLLIT>"\""                            {if(flag==1 && str==1)printf("STRLIT(%s)\n",strlit);col+=yyleng;BEGIN 0;
                                                                        if(flag!= 1 && str== 0) {
											                                    yylval.id = strdup(strlit);
											                                    
											                                    											                                    return STRLIT;
										}}
<STRLLIT><<EOF>>                         {printf("Line %d, col %d: unterminated string literal\n",strlitBegin[0],strlitBegin[1]); col+=yyleng; BEGIN 0;}


"true"              {if(flag==1)printf("BOOLLIT(true)\n"); col+=yyleng;
                                        if(flag != 1) {
											yylval.id = strdup(yytext);
											return BOOLLIT;
										}}
"false"             {if(flag==1)printf("BOOLLIT(false)\n"); col+=yyleng;
                                        if(flag!= 1) {
											yylval.id = strdup(yytext);
											return BOOLLIT;
										}}
"&&"                {if(flag==1)printf("AND\n"); col+=yyleng;if(flag!=1)return AND;}
"="                 {if(flag==1)printf("ASSIGN\n"); col+=yyleng; if(flag!=1)return ASSIGN;}
"*"                 {if(flag==1)printf("STAR\n"); col+=yyleng; if(flag!=1)return STAR;}
","                 {if(flag==1)printf("COMMA\n"); col+=yyleng; if(flag!=1)return COMMA;}
"/"                 {if(flag==1)printf("DIV\n"); col+=yyleng; if(flag!=1)return DIV;}
"=="                {if(flag==1)printf("EQ\n"); col+=yyleng; if(flag!=1)return EQ;}
">="                {if(flag==1)printf("GE\n"); col+=yyleng; if(flag!=1)return GE;}
">"                 {if(flag==1)printf("GT\n"); col+=yyleng; if(flag!=1)return GT;}
"{"                 {if(flag==1)printf("LBRACE\n"); col+=yyleng; if(flag!=1)return LBRACE;}
"<="                {if(flag==1)printf("LE\n"); col+=yyleng; if(flag!=1)return LE;}
"("                 {if(flag==1)printf("LPAR\n");col+=yyleng; if(flag!=1)return LPAR;}
"["                 {if(flag==1)printf("LSQ\n");col+=yyleng; if(flag!=1)return LSQ;}
"<"                 {if(flag==1)printf("LT\n");col+=yyleng; if(flag!=1)return LT;}
"-"                 {if(flag==1)printf("MINUS\n");col+=yyleng; if(flag!=1)return MINUS;}
"%"                 {if(flag==1)printf("MOD\n"); col+=yyleng; if(flag!=1)return MOD;}
"!="                {if(flag==1)printf("NE\n"); col+=yyleng; if(flag!=1)return NE;}
"!"                 {if(flag==1)printf("NOT\n");col+=yyleng; if(flag!=1)return NOT;}
"||"                {if(flag==1)printf("OR\n"); col+=yyleng; if(flag!=1)return OR;}
"+"                 {if(flag==1)printf("PLUS\n");col+=yyleng; if(flag!=1)return PLUS;}
"}"                 {if(flag==1)printf("RBRACE\n");col+=yyleng; if(flag!=1)return RBRACE;}
")"                 {if(flag==1)printf("RPAR\n"); col+=yyleng; if(flag!=1)return RPAR;}
"]"                 {if(flag==1)printf("RSQ\n"); col+=yyleng; if(flag!=1)return RSQ;}
";"                 {if(flag==1)printf("SEMICOLON\n"); col+=yyleng; if(flag!=1)return SEMICOLON;}
"->"                {if(flag==1)printf("ARROW\n"); col+=yyleng; if(flag!=1)return ARROW;}
"<<"                {if(flag==1)printf("LSHIFT\n"); col+=yyleng; if(flag!=1)return LSHIFT;}
">>"                {if(flag==1)printf("RSHIFT\n"); col+=yyleng; if(flag!=1)return RSHIFT;}
"^"                 {if(flag==1)printf("XOR\n"); col+=yyleng; if(flag!=1)return XOR;}
"boolean"           {if(flag==1)printf("BOOL\n"); col+=yyleng;if(flag!=1)return BOOL;}
"class"             {if(flag==1)printf("CLASS\n"); col+=yyleng;if(flag!=1)return CLASS;}
".length"           {if(flag==1)printf("DOTLENGTH\n"); col+=yyleng;if(flag!=1)return DOTLENGTH;}
"double"            {if(flag==1)printf("DOUBLE\n"); col+=yyleng;if(flag!=1)return DOUBLE;}
"else"              {if(flag==1)printf("ELSE\n"); col+=yyleng; if(flag!=1)return ELSE;}
"if"                {if(flag==1)printf("IF\n"); col+=yyleng;if(flag!=1)return IF;}
"int"               {if(flag==1)printf("INT\n"); col+=yyleng;if(flag!=1)return INT;}
"System.out.print"  {if(flag==1)printf("PRINT\n"); col+=yyleng;if(flag!=1)return PRINT;}
"Integer.parseInt"  {if(flag==1)printf("PARSEINT\n"); col+=yyleng;if(flag!=1) return PARSEINT;}
"return"            {if(flag==1)printf("RETURN\n"); col+=yyleng;if(flag!=1) return RETURN;}
"static"            {if(flag==1)printf("STATIC\n"); col+=yyleng;if(flag!=1)return STATIC;}
"String"            {if(flag==1)printf("STRING\n"); col+=yyleng;if(flag!=1)return STRING;}
"void"              {if(flag==1)printf("VOID\n"); col+=yyleng;if(flag!=1) return VOID;}
"public"            {if(flag==1)printf("PUBLIC\n"); col+=yyleng;if(flag!=1)return PUBLIC;}
"while"             {if(flag==1)printf("WHILE\n"); col+=yyleng;if(flag!=1) return WHILE;}
{RESERVED}          {if(flag==1)printf("RESERVED(%s)\n",yytext); col+=yyleng;if(flag!=1) return RESERVED;}
{SPACE}             {col+=yyleng;}
"\f"                {col+=yyleng;}
{NEWLINE}           {line+=1; col=1;}
{ID}                {if(flag==1)printf("ID(%s)\n",yytext); col+=yyleng;
                                        if(flag != 1) {
											yylval.id = strdup(yytext);
											return ID;
										}}
{INTLIT}            {if(flag==1)printf("INTLIT(%s)\n",yytext); col+=yyleng;
                                     if(flag != 1) {
											yylval.id = strdup(yytext);
											 return INTLIT;
										}}
{REALLIT}           {if(flag==1)printf("REALLIT(%s)\n",yytext); col+=yyleng;
                                            if(flag != 1) {
											yylval.id = strdup(yytext);
											return REALLIT;
										}}

.                   {printf("Line %d, col %d: illegal character (%s)\n", line,col,yytext); col+=yyleng;}
<<EOF>>             {col=1;exit (0);}

%%

int yywrap() {
	return 1;
}

void yyerror(const char *s) { 
     printf ("Line %d, col %d: %s: %s\n", line, (int)(col-strlen(yytext)), s, yytext);
}

int main(int argc,char* argv[]){
    if (argc > 1){
        if (strcmp(argv[1], "-l") == 0){
            flag=1;
            yylex();}
        else if(strcmp(argv[1], "-t") == 0){
            flag=2;
            yyparse();
        }
        else if (strcmp(argv[1], "-e1") == 0) {
			flag = 0;
         }
        else if (strcmp(argv[1], "-e2") == 0) {
			flag = 0;
			flag_erro = 1;
			yyparse();
			yylex();
		}
	}
    else {
		flag = 0;
		flag_erro = 1;
		yyparse();
		yylex();
	}
}
