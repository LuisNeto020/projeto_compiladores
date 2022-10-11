ID 				[a-zA-Z]([a-zA-Z]|[0-9]|"$"|"_")*
INTLIT          [0-9]("_"*[0-9])*
REALLIT         {INTLIT}*("."{INTLIT}*)?((e|E)("+"|"-")?{INTLIT}+)?
STRLIT          "\""([^(\n|\r|\")]|\\f|\\n|\\r|\\t|\\\|\\)*"\""
RESERVED        ("++"|"--"|null|Integer|System)
SPACE           (" "|"\t")
NEWLINE         ("\n"|"\r\n"|"\r")

%%
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
