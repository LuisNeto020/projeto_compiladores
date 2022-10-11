%{
//Constantes
    #define false 0;
    #define true 1;
    int col=1; 
    int line=1;
    int commentBegin[2];
    int flag=false;
%}

ID 				[a-zA-Z]([a-zA-Z]|[0-9]|"$"|"_")*
INTLIT          (0|[1-9]("_"*[0-9])*)
REALLIT         ([0-9]("_"*[0-9])*)*("."([1-9]("_"*[0-9])*)*)?((e|E)("+"|"-")?([1-9]("_"*[0-9])*)+)?
STRLIT          "\""([^(\n|\r|\")]|\\f|\\n|\\r|\\t|\\\|\\)*"\""
RESERVED        ("++"|"--"|null|Integer|System|abstract|continue|for|new|switch|assert|default|package|synchronized|do|goto|private|this|break|implements|protected|throw|byte|import|throws|case|enum|instanceof|transient|catch|extends|short|try|char|final|interface|finally|long|strictfp|volatile|const|float|native|super)
SPACE       (" "|"\t")
NEWLINE             ("\n"|"\r\n"|"\r")
LINE_COMMENT        "//".*

%X                <COMMENT> 

%%


"/*"                {BEGIN COMMENT;commentBegin[0]=line;commentBegin[1]=col;col+=yyleng;}
<COMMENT>.*[^("*/"|{NEWLINE})]         {col+=yyleng;}
<COMMENT>{NEWLINE}  {line++;col=1;}
<COMMENT><<EOF>>    {BEGIN 0;printf("Line %i, col %i: unterminated comment\n",commentBegin[0],commentBegin[1]);}
<COMMENT>"*/"       {BEGIN 0;col+=yyleng;}

{LINE_COMMENT}          {col=1;}


{NEWLINE}           {line+=1; col=1;}
{SPACE}             {col+=yyleng;}

"true"|"false"      {if(flag)printf("BOOLLIT\n"); col+=yyleng;}
"&&"                {if(flag)printf("AND\n"); col+=yyleng;}
"="                 {if(flag)printf("ASSIGN\n"); col+=yyleng;}
"*"                 {if(flag)printf("STAR\n"); col+=yyleng;}
","                 {if(flag)printf("COMMA\n"); col+=yyleng;}
"/"                 {if(flag)printf("DIV\n"); col+=yyleng;}
"=="                {if(flag)printf("EQ\n"); col+=yyleng;}
">="                {if(flag)printf("GE\n"); col+=yyleng;}
">"                 {if(flag)printf("GT\n"); col+=yyleng;}
"{"                 {if(flag)printf("LBRACE\n"); col+=yyleng;}
"<="                {if(flag)printf("LE\n"); col+=yyleng;}
"("                 {if(flag)printf("LPAR\n");col+=yyleng;}
"["                 {if(flag)printf("LSQ\n");col+=yyleng;}
"<"                 {if(flag)printf("LT\n");col+=yyleng;}
"-"                 {if(flag)printf("MINUS\n");col+=yyleng;}
"%"                 {if(flag)printf("MOD\n"); col+=yyleng;}
"!="                {if(flag)printf("NE\n"); col+=yyleng;}
"!"                 {if(flag)printf("NOT\n");col+=yyleng;}
"||"                {if(flag)printf("OR\n"); col+=yyleng;}
"+"                 {if(flag)printf("PLUS\n");col+=yyleng;}
"}"                 {if(flag)printf("RBRACE\n");col+=yyleng;}
")"                 {if(flag)printf("RPAR\n"); col+=yyleng;}
"]"                 {if(flag)printf("RSQ\n"); col+=yyleng;}
";"                 {if(flag)printf("SEMI; ON\n"); col+=yyleng;}
"->"                {if(flag)printf("ARROW\n"); col+=yyleng;}
"<<"                {if(flag)printf("LSHIFT\n"); col+=yyleng;}
">>"                {if(flag)printf("RSHIFT\n"); col+=yyleng;}
"^"                 {if(flag)printf("XOR\n"); col+=yyleng;}
"boolean"           {if(flag)printf("BOOL\n"); col+=yyleng;}
"class"             {if(flag)printf("CLASS\n"); col+=yyleng;}
".length"           {if(flag)printf("DOTLENGTH\n"); col+=yyleng;}
"double"            {if(flag)printf("DOUBLE\n"); col+=yyleng;}
"else"              {if(flag)printf("ELSE\n"); col+=yyleng;}
"if"                {if(flag)printf("IF\n"); col+=yyleng;}
"int"               {if(flag)printf("INT\n"); col+=yyleng;}
"System.out.print"  {if(flag)printf("PRINT\n"); col+=yyleng;}
"Integer.parseInt"  {if(flag)printf("PARSEINT\n"); col+=yyleng;}
"return"            {if(flag)printf("RETURN\n"); col+=yyleng;}
"static"            {if(flag)printf("STATIC\n"); col+=yyleng;}
"String"            {if(flag)printf("STRING\n"); col+=yyleng;}
"void"              {if(flag)printf("VOID\n"); col+=yyleng;}
"public"            {if(flag)printf("PUBLIC\n"); col+=yyleng;}
"while"             {if(flag)printf("WHILE\n"); col+=yyleng;}
{ID}                {if(flag)printf("ID(%s)\n",yytext); col+=yyleng;}
{INTLIT}            {if(flag)printf("INTLIT(%s)\n",yytext); col+=yyleng;}
{REALLIT}           {if(flag)printf("REALLIT(%s)\n",yytext); col+=yyleng;}
{STRLIT}            {if(flag)printf("STRLIT(%s)\n",yytext); col+=yyleng;}
{RESERVED}          {if(flag)printf("RESERVED(%s)\n",yytext); col+=yyleng;}

"\"".*[{NEWLINE}|<<EOF>>]     {printf("Line <%i>, col <%i>:  unterminated string literal\n", line,col); col+=yyleng;}
"\\"[^(f|n|r|t|\)]   {printf("Line <%i>, col <%i>: invalid escape sequence (<%s>)\n", line,col,yytext); col+=yyleng;}
.                    {printf("Line <%i>, col <%i>: illegal character (<%s>)\n", line,col,yytext); col+=yyleng;}

%%


int main(int argc,char* argv[]){
    if (argc == 2){
        if (strcmp(argv[1], "-l") == 0){
            flag=true;}
        else if(strcmp(argv[1], "-e1") == 0){
            flag=false;
        }
    }
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}