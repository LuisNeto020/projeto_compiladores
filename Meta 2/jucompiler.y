%{
	/*
    Luís Neto -2020215474
    João Moura -2020235800 
	*/  
    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
    #include "functions.h"
    char* yytext;
    int yylex(void);
    void yyerror(const char *s);
    Node* root;
	Node* aux;
	int flag_erro = 0;
%}
%union {
	char * id;
	struct Node * node;
}

%token AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR CLASS DOTLENGTH ELSE IF PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE INT DOUBLE BOOL RESERVED

%token <id> ID
%token <id> INTLIT
%token <id> REALLIT
%token <id> BOOLLIT
%token <id> STRLIT

%type <node> Program ProgramScript MethodDecl FieldDecl FieldDecl2 Type MethodHeader MethodHeader2 FormalParams FormalParams2 MethodBody MethodBody2 VarDecl VarDecl2 Statement Statement2 ExprReturn Statement3 StatementPrint MethodInvocation MethodInvocation2 MethodInvocationExpr Assignment ParseArgs Expr ExprOperations Expr2 ExprLit

%right ASSIGN
%left OR
%left AND
%left XOR
%left EQ NE
%left GE GT LE LT
%left LSHIFT RSHIFT
%left PLUS MINUS
%left STAR DIV MOD
%right NOT
%left LPAR RPAR LSQ RSQ
%right ELSE

%%

Program:	CLASS ID LBRACE ProgramScript RBRACE					{root = newNode( "", "Program");
																	aux = newNode( $2, "Id");
																	add_child(root, aux);
																	addBrother(aux, $4);
																	$$ = root;
																	}
		| CLASS ID LBRACE ProgramScript RBRACE error				{$$ = NULL; flag_erro = 1;}
		;

ProgramScript: 	/* empty */											{$$ = NULL;}
			|	MethodDecl ProgramScript							{$$ = $1;
																	addBrother($$, $2);}
			|	FieldDecl ProgramScript								{$$ = $1;
																	addBrother($$, $2);}
			|	SEMICOLON ProgramScript								{$$ = $2;}
			;

MethodDecl:	PUBLIC STATIC MethodHeader MethodBody					{$$ = newNode( "", "MethodDecl");
																	add_child($$, $3);
																	addBrother($3, $4);}
		;

FieldDecl:	PUBLIC STATIC Type ID FieldDecl2 SEMICOLON				{$$ = newNode( "", "FieldDecl");
																	add_child($$, $3);
																	addBrother($3, newNode( $4, "Id"));
																	if ($5 != NULL){
																		aux = $5;
																		while (aux != NULL) {
																			Node* aux1 = newNode( "", "FieldDecl");
																			Node* aux2 = newNode( $3->valor, $3->s_type);
																			add_child(aux1, aux2);
																			addBrother(aux2, newNode( aux->valor, "Id"));
																			addBrother($$, aux1);
																			aux = aux->brother;
																		}
																		free(aux);
																	}}
		|	error SEMICOLON											{$$ = NULL; flag_erro = 1;}
		;

FieldDecl2:	/* empty */												{$$ = NULL;}
		|	COMMA ID FieldDecl2										{$$ = newNode( $2, "Id");
																	addBrother($$, $3);}
		;

Type:	BOOL														{$$ = newNode( "", "Bool");}
	|	INT															{$$ = newNode( "", "Int");}
	|	DOUBLE														{$$ = newNode( "", "Double");}
	;

MethodHeader:	Type ID LPAR MethodHeader2 RPAR						{$$ = newNode( "", "MethodHeader");
																	add_child($$,$1);
																	addBrother($1, newNode( $2, "Id"));
																	aux = newNode( "", "MethodParams");
																	addBrother($1, aux);
																	add_child(aux, $4);}
			|	VOID ID LPAR MethodHeader2 RPAR						{$$ = newNode( "", "MethodHeader");
																	aux = newNode( "", "Void");
																	add_child($$, aux);
																	addBrother(aux, newNode( $2, "Id"));
																	Node* aux2 = newNode( "", "MethodParams");
																	addBrother(aux, aux2);
																	add_child(aux2, $4);}
			;

MethodHeader2:	/* empty */											{$$ = NULL;}
			|	FormalParams										{$$ = $1;}
			;

FormalParams:	Type ID FormalParams2								{$$ = newNode( "", "ParamDecl");
																	add_child($$, $1);
																	aux = newNode( $2, "Id");
																	addBrother($1, aux);
																	addBrother($$, $3);}
			|	STRING LSQ RSQ ID									{$$ = newNode( "", "ParamDecl");
																	aux = newNode( "", "StringArray");
																	add_child($$, aux);
																	addBrother(aux, newNode( $4, "Id"));}
			;

FormalParams2:	/* empty */											{$$ = NULL;}
			|	COMMA Type ID FormalParams2 						{$$ = newNode( "", "ParamDecl");
																	aux = newNode( $3, "Id");
																	add_child($$, $2);
																	addBrother($2, aux);
																	addBrother($$, $4);}
			;

MethodBody:	LBRACE MethodBody2 RBRACE								{$$ = newNode( "", "MethodBody");
																	add_child($$, $2);}
		;

MethodBody2: 	/* empty */											{$$ = NULL;}
			|	Statement MethodBody2								{if ($1 != NULL){
																		$$ = $1;
																		addBrother($$, $2);
																		}
																	else {
																		$$ = $2;
																	}}
			|	VarDecl MethodBody2									{$$ = $1;
																	addBrother($$, $2);}
			;

VarDecl:	Type ID VarDecl2 SEMICOLON								{$$ = newNode( "", "VarDecl");
																	add_child($$, $1);
																	addBrother($1, newNode( $2, "Id"));
																	if ($3 != NULL){
																		aux = $3;
																		while (aux != NULL) {
																			Node* aux1 = newNode( "", "VarDecl");
																			Node* aux2 = newNode( $1->valor, $1->s_type);
																			add_child(aux1, aux2);
																			addBrother(aux2, newNode( aux->valor, "Id"));
																			addBrother($$, aux1);
																			aux = aux->brother;
																		}
																		free(aux);
																	}}
		;

VarDecl2:	/* empty */												{$$ = NULL;}
		|	COMMA ID VarDecl2										{$$ = newNode( $2, "Id");
																	addBrother($$, $3);}
		;

Statement:	LBRACE Statement2 RBRACE								{if (countBrother($2) > 1) {
																		aux = newNode( "", "Block");
																		$$ = aux;
																		add_child(aux, $2);
																	}
																	else {
																		$$ = $2;
																	}}
		|	IF LPAR Expr RPAR Statement %prec ELSE					{$$ = newNode( "", "If");
																	add_child($$,$3);
																	aux = newNode( "", "Block");
																	if (countBrother($5) == 1 && $5 != NULL) {
																		addBrother($3, $5);
																		addBrother($5, aux);
																	}
																	else {
																		addBrother($3, aux);
																		add_child(aux, $5);
																		addBrother(aux, newNode( "", "Block"));
																	}}
		|	IF LPAR Expr RPAR Statement ELSE Statement				{$$ = newNode( "", "If");
																	add_child($$,$3);
																	aux = newNode( "", "Block");
																	if (countBrother($5) == 1 && $5 != NULL) {
																		addBrother($3, $5);
																		if (countBrother($7) == 1 && $7 != NULL) {
																			addBrother($5, $7);
																		}
																		else {
																			addBrother($5, aux);
																			add_child(aux, $7);
																		}
																	}
																	else {
																		addBrother($3, aux);
																		add_child(aux, $5);
																		if (countBrother($7) == 1 && $7 != NULL) {
																			addBrother(aux, $7);
																		}
																		else {
																			Node* aux2 = newNode( "", "Block");
																			addBrother(aux, aux2);
																			add_child(aux2, $7);
																		}
																	}}
		|	WHILE LPAR Expr RPAR Statement							{$$ = newNode( "", "While");
																	add_child($$, $3);
																	if (countBrother($5) == 1 && $5 != NULL) {
																		addBrother($3, $5);
																	}
																	else {
																		aux = newNode( "", "Block");
																		addBrother($3, aux);
																		add_child(aux, $5);
																	}}
		|	RETURN ExprReturn SEMICOLON								{$$ = newNode( "", "Return");
																	add_child($$, $2);}
		|	Statement3 SEMICOLON									{$$ = $1;}
		|	PRINT LPAR StatementPrint RPAR SEMICOLON				{$$ = newNode( "", "Print");
																	add_child($$, $3);}
		|	error SEMICOLON											{$$ = NULL;flag_erro = 1;}
		;

Statement2:	/* empty */												{$$ = NULL;}
		|	Statement Statement2									{if ($1 != NULL) {
																		$$ = $1;
																		addBrother($$, $2);
																	}
																	else {
																		$$ = $2;
																	}}
		;

ExprReturn:	/* empty */												{$$ = NULL;}
		|	Expr													{$$ = $1;}
		;

Statement3:	/* empty */												{$$ = NULL;}
		|	MethodInvocation										{$$ = $1;}
		|	Assignment												{$$ = $1;}
		|	ParseArgs												{$$ = $1;}
		;

StatementPrint:	Expr												{$$ = $1;}
			|	STRLIT												{$$ = newNode( $1, "StrLit");}
			;

MethodInvocation:	ID LPAR MethodInvocation2 RPAR					{$$ = newNode( "", "Call");
																	aux = newNode( $1, "Id");
																	add_child($$, aux);
																	addBrother(aux, $3);}
				|	ID LPAR error RPAR								{$$ = NULL;
																	flag_erro = 1;}
				;

MethodInvocation2:	/* empty */										{$$ = NULL;}
				|	Expr MethodInvocationExpr						{$$ = $1;
																	addBrother($$, $2);}
				;

MethodInvocationExpr:	/* empty */									{$$ = NULL;}
					|	COMMA Expr MethodInvocationExpr				{if($2!=NULL) {
																		$$=$2;
																		addBrother($$, $3);
																	}
																	else {
																		$$=$2;
																	}}
					;

Assignment:	ID ASSIGN Expr											{$$ = newNode( "", "Assign");
																	aux = newNode( $1, "Id");
																	add_child($$, aux);
																	addBrother(aux, $3);}
		;

ParseArgs:	PARSEINT LPAR ID LSQ Expr RSQ RPAR						{$$ = newNode( "", "ParseArgs");
																	aux = newNode( $3, "Id");
																	add_child($$, aux);
																	addBrother(aux, $5);}
		|	PARSEINT LPAR error RPAR								{$$ = NULL;
																	flag_erro = 1;}
		;

Expr:	Assignment													{$$ = $1;}
	|	ExprOperations												{$$ = $1;}
	;

ExprOperations:	ExprOperations PLUS ExprOperations					{$$ = newNode("", "Add");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations MINUS ExprOperations					{$$ = newNode( "", "Sub");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations STAR ExprOperations					{$$ = newNode( "", "Mul");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations DIV ExprOperations					{$$ = newNode( "", "Div");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations MOD ExprOperations					{$$ = newNode( "", "Mod");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations AND ExprOperations					{$$ = newNode( "", "And");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations OR ExprOperations					{$$ = newNode( "", "Or");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations XOR ExprOperations					{$$ = newNode( "", "Xor");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations LSHIFT ExprOperations				{$$ = newNode( "", "Lshift");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations RSHIFT ExprOperations				{$$ = newNode( "", "Rshift");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations EQ ExprOperations					{$$ = newNode( "", "Eq");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations GE ExprOperations					{$$ = newNode( "", "Ge");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations GT ExprOperations					{$$ = newNode( "", "Gt");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations LE ExprOperations					{$$ = newNode( "", "Le");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations LT ExprOperations					{$$ = newNode( "", "Lt");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	ExprOperations NE ExprOperations					{$$ = newNode( "", "Ne");
																	add_child($$, $1);
																	addBrother($1, $3);}
			|	PLUS ExprOperations %prec NOT						{$$ = newNode( "", "Plus");
																	add_child($$, $2);}
			|	MINUS ExprOperations %prec NOT						{$$ = newNode( "", "Minus");
																	add_child($$, $2);}
			|	NOT ExprOperations									{$$ = newNode( "", "Not");
																	add_child($$, $2);}
			|	LPAR Expr RPAR										{$$ = $2;}
			|	LPAR error RPAR										{$$ = NULL;
																	flag_erro = 1;}
			|	Expr2												{$$ = $1;}
			|	ID													{$$ = newNode( $1, "Id");}
			|	ID DOTLENGTH										{$$ = newNode( "", "Length");
																	add_child($$, newNode( $1, "Id"));}
			|	ExprLit												{$$ = $1;}
	;


Expr2:	MethodInvocation											{$$ = $1;}
	|	ParseArgs													{$$ = $1;}
	;

ExprLit:	INTLIT													{$$ = newNode( $1, "DecLit");}
		|	REALLIT													{$$ = newNode( $1, "RealLit");}
		|	BOOLLIT													{$$ = newNode( $1, "BoolLit");}
		;

%%
