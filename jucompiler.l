%{
//Constantes
    int col=1; 
    int line=1; 
%}

ID 				[a-zA-Z]([a-zA-Z]|[0-9]|"$"|"_")*
INTLIT          [0-9]("_"*[0-9])*
REALLIT         {INTLIT}*("."{INTLIT}*)?((e|E)("+"|"-")?{INTLIT}+)?
STRLIT          "\""([^(\n|\r|\")]|\\f|\\n|\\r|\\t|\\\|\\)*"\""
RESERVED        ("++"|"--"|null|Integer|System|abstract|continue|for|new|switch|assert|default|package|synchronized|do|goto|private|this|break|implements|protected|throw|byte|import|throws|case|enum|instanceof|transient|catch|extends|short|try|char|final|interface|finally|long|strictfp|volatile|const|float|native|super)
SPACE           (" "|"\t")
NEWLINE         ("\n"|"\r\n"|"\r")

%%
{SPACE}             col+=yyleng;
{NEWLINE}           line+=1; col=1;
"true"|"false"      {printf("BOOLLIT\n"); col+=yyleng;}
"&&"                {printf("AND\n"); col+=yyleng;}
"="                 {printf("ASSIGN\n"); col+=yyleng;}
"*"                 {printf("STAR\n"); col+=yyleng;}
","                 {printf("COMMA\n"); col+=yyleng;}
"/"                 {printf("DIV\n"); col+=yyleng;}
"=="                {printf("EQ\n"); col+=yyleng;}
">="                {printf("GE\n"); col+=yyleng;}
">"                 {printf("GT\n"); col+=yyleng;}
"{"                 {printf("LBRACE\n"); col+=yyleng;}
"<="                {printf("LE\n"); col+=yyleng;}
"("                 {printf("LPAR\n");col+=yyleng;}
"["                 {printf("LSQ\n");col+=yyleng;}
"<"                 {printf("LT\n");col+=yyleng;}
"-"                 {printf("MINUS\n");col+=yyleng;}
"%"                 {printf("MOD\n"); col+=yyleng;}
"!="                {printf("NE\n"); col+=yyleng;}
"!"                 {printf("NOT\n");col+=yyleng;}
"||"                {printf("OR\n"); col+=yyleng;}
"+"                 {printf("PLUS\n");col+=yyleng;}
"}"                 {printf("RBRACE\n");col+=yyleng;}
")"                 {printf("RPAR\n"); col+=yyleng;}
"]"                 {printf("RSQ\n"); col+=yyleng;}
";"                 {printf("SEMI; ON\n"); col+=yyleng;}
"->"                {printf("ARROW\n"); col+=yyleng;}
"<<"                {printf("LSHIFT\n"); col+=yyleng;}
">>"                {printf("RSHIFT\n"); col+=yyleng;}
"^"                 {printf("XOR\n"); col+=yyleng;}
"boolean"           {printf("BOOL\n"); col+=yyleng;}
"class"             {printf("CLASS\n"); col+=yyleng;}
".length"           {printf("DOTLENGTH\n"); col+=yyleng;}
"double"            {printf("DOUBLE\n"); col+=yyleng;}
"else"              {printf("ELSE\n"); col+=yyleng;}
"if"                {printf("IF\n"); col+=yyleng;}
"int"               {printf("INT\n"); col+=yyleng;}
"System.out.print"  {printf("PRINT\n"); col+=yyleng;}
"Integer.parseInt"  {printf("PARSEINT\n"); col+=yyleng;}
"return"            {printf("RETURN\n"); col+=yyleng;}
"static"            {printf("STATIC\n"); col+=yyleng;}
"String"            {printf("STRING\n"); col+=yyleng;}
"void"              {printf("VOID\n"); col+=yyleng;}
"public"            {printf("PUBLIC\n"); col+=yyleng;}
"while"             {printf("WHILE\n"); col+=yyleng;}
{ID}                {printf("ID(%s)\n",yytext); col+=yyleng;}
{INTLIT}            {printf("INTLIT(%s)\n",yytext); col+=yyleng;}
{REALLIT}           {printf("REALLIT(%s)\n",yytext); col+=yyleng;}
{STRLIT}            {printf("STRLIT(%s)\n",yytext); col+=yyleng;}
{RESERVED}          {printf("RESERVED(%s)\n",yytext); col+=yyleng;}

"\"".*({NEWLINE}||<<EOF>>)     {printf("Line <%d>, col <%d>:  unterminated string literal\n", line,col); col+=yyleng;}
"\\"[^(f|n|r|t|\)]   {printf("Line <%d>, col <%d>: invalid escape sequence (<%s>)\n", line,col,yytext); col+=yyleng;}
.                    {printf("Line <%d>, col <%d>: illegal character (<%s>)\n", line,col,yytext); col+=yyleng;}
%%
int main()
{
    
yylex(); 
return 0; 
}

int yywrap()
{
return 1; 
}
