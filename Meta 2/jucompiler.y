%{
    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>

    int yylex(void);
    void yyerror(const char *s);
%}

%union {
	char * id;
}

%token AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR CLASS DOTLENGTH ELSE IF PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE INT DOUBLE BOOL RESERVED

%token <id> ID
%token <id> INTLIT
%token <id> REALLIT
%token <id> BOOLLIT
%token <id> STRLIT

%%

Program:    CLASS ID LBRACE ProgramBody RBRACE
            ;
ProgramBody: /* empty */
            | MethodDecl ProgramBody
            | FielDecl ProgramBody
            | SEMICOLON ProgramBody
            ;

MethodDecl: PUBLIC STATIC MethodHeader MethodBody
            ;
FielDecl: PUBLIC STATIC Type ID FielDecl2 SEMICOLON
            ;
FielDecl2:  /* empty */
            |COMMA ID FielDecl2        
            ;
Type: INT
        |BOOL
        |DOUBLE
        ;
MethodHeader: Type ID LPAR MethodHeaderOpc RPAR
            | VOID ID LPAR MethodHeaderOpc RPAR
            ;
MethodHeaderOpc: /* empty */
                |FormalParams
                ;
FormalParams: Type ID FormalParams1
            | STRING LSQ RSQ ID
            ;
FormalParams1: /* empty */ 
            |COMMA Type ID
            ;
MethodBody: LBRACE MethodBody1 RBRACE
            ;
MethodBody1: /* empty */
            |Statement MethodBody1
            |VarDecl MethodBody1
            ;
VarDecl: Type ID VarDecl1 SEMICOLON
        ;
VarDecl1: /* empty */
            | COMMA ID VarDecl1
            ;
Statement: LBRACE Statement1 RBRACE
            | IF LPAR Expr RPAR Statement Statement2
            | WHILE LPAR Expr RPAR Statement
            | RETURN Statement3 SEMICOLON
            | Statement4 SEMICOLON
            | PRINT LPAR StatementPrint RPAR SEMICOLON
            ;
Statement1: /* empty */
            | Statement Statement1
            ;  
Statement2: /* empty */
            | ELSE Statement
            ;
Statement3: /* empty */
            | Expr
            ;
Statement4: /* empty */
            | MethodInvocation
            | Assignment
            | ParseArgs
            ;
StatementPrint: Expr
                | STRLIT
                ;
MethodInvocation: ID LPAR MethodInvocation1 RPAR
                ;
MethodInvocation1: /* empty */
                | Expr MethodInvocation2
                ;
MethodInvocation2: /* empty */
                | COMMA Expr MethodInvocation2
                ;
Assignment: ID ASSIGN Expr
            ;
ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR
            ;
Expr: Expr PLUS Expr
    | Expr MINUS Expr
    | Expr STAR Expr
    | Expr DIV Expr
    | Expr MOD Expr
    | Expr AND Expr
    | Expr OR Expr
    | Expr XOR Expr
    | Expr LSHIFT Expr
    | Expr RSHIFT Expr
    | Expr EQ Expr
    | Expr GE Expr
    | Expr GT Expr
    | Expr LE Expr
    | Expr LT Expr
    | Expr NE Expr
    | MINUS Expr
    | NOT Expr
    | PLUS Expr
    | LPAR Expr RPAR
    | MethodInvocation
    | Assignment
    | ParseArgs
    | ID
    | ID DOTLENGTH
    | INTLIT
    | REALLIT
    | BOOLLIT
    ;

%%