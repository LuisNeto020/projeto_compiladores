%{
/********************************
************AUTORES**************
*********************************
* Dylan Perdigão   -   2018233092
* Bruno Faria      -   2018295474
*********************************/
/*****************************
************CONSTANTES********
******************************/
#define false 0
#define true 1
/*****************************
************VARIAVEIS*********
******************************/
int isPrinted=false;
int line=1;
int col=1;
int commentBegin[2];
 /*****************************
 ************TOKENS************
 ******************************/
%}
ID          		[a-zA-Z_][a-zA-Z0-9_]*
INTLIT      		[0-9]+
CHRLIT              ([^\n\'\\]|\\n|\\t|\\\\|\\\'|\\\"|\\([0-7]{1,3}))
REALLIT     		[0-9]+"."[0-9]*([eE][+-]?([0-9]+))?|"."[0-9]+([eE][+-]?([0-9]+))?|[0-9]+"."?[0-9]*([eE][+-]?([0-9]+))?
CHAR			    char
ELSE			    else
WHILE			    while
IF			        if
INT			        int
SHORT		        short
DOUBLE		  	    double
RETURN		  	    return
VOID			    void
BITWISEAND		    "&"
BITWISEOR		    "|"
BITWISEXOR		    "^"
AND			        "&&"
ASSIGN		  	    "="
MUL			        "*"
COMMA		   	    ","
DIV			        "/"
EQ			        "=="
GE			        ">="
GT			        ">"
LBRACE		  	    "{"
LE			        "<="
LPAR			    "("
LT			        "<"
MINUS		    	"-"
MOD			        "%"
NE			        "!="
NOT			        "!"
OR			        "||"
PLUS			    "+"
RBRACE		  	    "}"
RPAR			    ")"
SEMI			    ";"
RESERVED            ("["|"]"|"++"|"--"|auto|break|case|const|continue|default|do|enum|extern|float|for|goto|inline|long|register|restrict|signed|sizeof|static|struct|switch|typedef|union|unsigned|volatile|_Bool|_Complex|_Imaginary)
LINE_COMMENT        "//".*
SPACE       (" "|"\t")
NEWLINE             ("\n"|"\r\n"|"\r")


%X                  COMMENT
/******************************
 *************RULES************
 ******************************/
%%
"/*"                    {BEGIN COMMENT;commentBegin[0]=line;commentBegin[1]=col;col+=yyleng;}
<COMMENT>{NEWLINE}      {line++;col=1;}
<COMMENT>.              {col+=yyleng;}
<COMMENT><<EOF>>        {BEGIN 0;printf("Line %i, col %i: unterminated comment\n",commentBegin[0],commentBegin[1]);}
<COMMENT>"*/"           {BEGIN 0;col+=yyleng;}

{LINE_COMMENT}          {col=1;}

{SPACE}                 {col+=yyleng;}
{NEWLINE}               {line++;col=1;}

{CHAR}				{if(isPrinted)printf("CHAR\n");col+=yyleng;}
{ELSE}				{if(isPrinted)printf("ELSE\n");col+=yyleng;}
{WHILE}				{if(isPrinted)printf("WHILE\n");col+=yyleng;}
{IF}				{if(isPrinted)printf("IF\n");col+=yyleng;}
{INT}				{if(isPrinted)printf("INT\n");col+=yyleng;}
{SHORT}			  	{if(isPrinted)printf("SHORT\n");col+=yyleng;}
{DOUBLE}			{if(isPrinted)printf("DOUBLE\n");col+=yyleng;}
{RETURN}			{if(isPrinted)printf("RETURN\n");col+=yyleng;}
{VOID}				{if(isPrinted)printf("VOID\n");col+=yyleng;}
{RESERVED}          {if(isPrinted)printf("RESERVED(%s)\n",yytext);col+=yyleng;}

{BITWISEAND}	    {if(isPrinted)printf("BITWISEAND\n");col+=yyleng;}
{BITWISEOR}			{if(isPrinted)printf("BITWISEOR\n");col+=yyleng;}
{BITWISEXOR}	    {if(isPrinted)printf("BITWISEXOR\n");col+=yyleng;}
{AND}				{if(isPrinted)printf("AND\n");col+=yyleng;}
{ASSIGN}			{if(isPrinted)printf("ASSIGN\n");col+=yyleng;}
{MUL}				{if(isPrinted)printf("MUL\n");col+=yyleng;}
{COMMA}			  	{if(isPrinted)printf("COMMA\n");col+=yyleng;}
{DIV}				{if(isPrinted)printf("DIV\n");col+=yyleng;}
{EQ}				{if(isPrinted)printf("EQ\n");col+=yyleng;}
{GE}				{if(isPrinted)printf("GE\n");col+=yyleng;}
{GT}				{if(isPrinted)printf("GT\n");col+=yyleng;}
{LBRACE}			{if(isPrinted)printf("LBRACE\n");col+=yyleng;}
{LE}				{if(isPrinted)printf("LE\n");col+=yyleng;}
{LPAR}			  	{if(isPrinted)printf("LPAR\n");col+=yyleng;}
{LT}				{if(isPrinted)printf("LT\n");col+=yyleng;}
{MINUS}			  	{if(isPrinted)printf("MINUS\n");col+=yyleng;}
{MOD}				{if(isPrinted)printf("MOD\n");col+=yyleng;}
{NE}			 	{if(isPrinted)printf("NE\n");col+=yyleng;}
{NOT}				{if(isPrinted)printf("NOT\n");col+=yyleng;}
{OR}				{if(isPrinted)printf("OR\n");col+=yyleng;}
{PLUS}			  	{if(isPrinted)printf("PLUS\n");col+=yyleng;}
{RBRACE}			{if(isPrinted)printf("RBRACE\n");col+=yyleng;}
{RPAR}			 	{if(isPrinted)printf("RPAR\n");col+=yyleng;}
{SEMI}				{if(isPrinted)printf("SEMI\n");col+=yyleng;}

'{CHRLIT}'                   {if(isPrinted)printf("CHRLIT(%s)\n",yytext);col+=yyleng;}
'([^\n\'\\]|\\.)*\\?{NEWLINE}        {printf("Line %i, col %i: unterminated char constant\n",line,col);col=1;line++;}
'([^\n\'\\]|\\.)*'                   {printf("Line %i, col %i: invalid char constant (%s)\n",line,col,yytext);col+=yyleng;}

{ID}				        {if(isPrinted)printf("ID(%s)\n",yytext);col+=yyleng;}
{INTLIT}			        {if(isPrinted)printf("INTLIT(%s)\n",yytext);col+=yyleng;}
{REALLIT}                   {if(isPrinted)printf("REALLIT(%s)\n",yytext);col+=yyleng;}

.                           {printf("Line %i, col %i: illegal character (%s)\n",line,col,yytext);col+=yyleng;}
%%

int main(int argc,char* argv[]){
    if (argc == 2){
        if (strcmp(argv[1], "-l") == 0){
            isPrinted=true;
        }else if(strcmp(argv[1], "-e1") == 0){
            isPrinted=false;
        }
    }
    yylex();
    return 0;
}

int yywrap(){
    return 1;
}
