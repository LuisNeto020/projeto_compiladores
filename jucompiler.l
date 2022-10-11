%{
    

    int commentBegin[2];
%}

ID 				[a-zA-Z]([a-zA-Z]|[0-9]|"$"|"_")*
INTLIT          (0|[1-9]("_"*[0-9])*)
REALLIT         ([0-9]("_"*[0-9])*)*("."([1-9]("_"*[0-9])*)*)?((e|E)("+"|"-")?([1-9]("_"*[0-9])*)+)?
STRLIT          "\""([^(\n|\r|\")]|\\f|\\n|\\r|\\t|\\\|\\)*"\""
RESERVED        ("|+"|"--"|abstract|continue|for|new|switch|assert|default|package|synchronized|do|goto|private|this|break|implements|protected|throw|byte|import|throws|case|enum|instanceof|transient|catch|extends|short|try|char|final|interface|finally|long|strictfp|volatile|const|float|native|super|System|Integer|null)
SPACE           (" "|"\t")
NEWLINE         ("\n"|"\r\n"|"\r")

%X              COMMENT
%%
"/*"                {BEGIN COMMENT;commentBegin[0]=line;commentBegin[1]=col;col+=yyleng;}
<COMMENT>.*         {col+=yyleng;}
<COMMENT>{NEWLINE}  {line++;col=1;}
<COMMENT><<EOF>>    {BEGIN 0;printf("Line %i, col %i: unterminated comment\n",commentBegin[0],commentBegin[1]);}
<COMMENT>"*/"       {BEGIN 0;col+=yyleng;}



{SPACE}             ;
{NEWLINE}           ;
"true"|"false"      {printf("BOOLLIT\n");}
"&&"                {printf("AND\n");}
"="                 {printf("ASSIGN\n");}
"*"                 {printf("STAR\n");}
","                 {printf("COMMA\n");}
"/"                 {printf("DIV\n");}
"=="                {printf("EQ\n");}
">="                {printf("GE\n");}
">"                 {printf("GT\n");}
"{"                 {printf("LBRACE\n");}
"<="                {printf("LE\n");}
"("                 {printf("LPAR\n");}
"["                 {printf("LSQ\n");}
"<"                 {printf("LT\n");}
"-"                 {printf("MINUS\n");}
"%"                 {printf("MOD\n");}
"!="                {printf("NE\n");}
"!"                 {printf("NOT\n");}
"||"                {printf("OR\n");}
"+"                 {printf("PLUS\n");}
"}"                 {printf("RBRACE\n");}
")"                 {printf("RPAR\n");}
"]"                 {printf("RSQ\n");}
";"                 {printf("SEMICOLON\n");}
"->"                {printf("ARROW\n");}
"<<"                {printf("LSHIFT\n");}
">>"                {printf("RSHIFT\n");}
"^"                 {printf("XOR\n");}
"boolean"           {printf("BOOL\n");}
"class"             {printf("CLASS\n");}
".length"           {printf("DOTLENGTH\n");}
"double"            {printf("DOUBLE\n");}
"else"              {printf("ELSE\n");}
"if"                {printf("IF\n");}
"int"               {printf("INT\n");}
"System.out.print"  {printf("PRINT\n");}
"Integer.parseInt"  {printf("PARSEINT\n");}
"return"            {printf("RETURN\n");}
"static"            {printf("STATIC\n");}
"String"            {printf("STRING\n");}
"void"              {printf("VOID\n");}
"public"            {printf("PUBLIC\n");}
"while"             {printf("WHILE\n");}
{ID}                {printf("ID(%s)\n",yytext);}
{INTLIT}            {printf("INTLIT(%s)\n",yytext);}
{REALLIT}           {printf("REALLIT(%s)\n",yytext);}
{STRLIT}            {printf("STRLIT(%s)\n",yytext);}
{RESERVED}          {printf("RESERVED(%s)\n",yytext);}

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
