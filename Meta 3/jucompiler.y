%{
	/*
    Luís Neto -2020215474
    João Moura -2020235800 
	*/  
    #include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <stdarg.h>
    #include "AstTree.h"
    int yylex(void);
    void yyerror(const char *s);
    Node* root;
	Node* aux;
	int flag_erro = 0;
%}
%union {
	struct token* value;
	struct Node * node;
}

%token <value> AND ASSIGN STAR COMMA DIV EQ GE GT LBRACE LE LPAR LSQ LT MINUS MOD NE NOT OR PLUS RBRACE RPAR RSQ SEMICOLON ARROW LSHIFT RSHIFT XOR CLASS DOTLENGTH ELSE IF PRINT PARSEINT PUBLIC RETURN STATIC STRING VOID WHILE INT DOUBLE BOOL RESERVED  ID INTLIT REALLIT BOOLLIT STRLIT

 

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

Program:	CLASS ID LBRACE ProgramScript RBRACE					{root = newNode( NULL, "Program",0,0);
																	aux = newNode( $2->value, "Id", $2->line, $2->column);
																	add_child(root, aux);
																	addBrother(aux, $4);
																	$$ = root;
																	freeToken($2);}
		| CLASS ID LBRACE ProgramScript RBRACE error				{$$ = NULL; flag_erro = 1;}
		;

ProgramScript: 	/* empty */											{$$ = NULL;}
			|	MethodDecl ProgramScript							{$$ = $1;
																	addBrother($$, $2);}
			|	FieldDecl ProgramScript								{$$ = $1;
																	addBrother($$, $2);}
			|	SEMICOLON ProgramScript								{$$ = $2;}
			;

MethodDecl:	PUBLIC STATIC MethodHeader MethodBody					{$$ = newNode( NULL, "MethodDecl",0,0);
																	add_child($$, $3);
																	addBrother($3, $4);}
		;

FieldDecl:	PUBLIC STATIC Type ID FieldDecl2 SEMICOLON				{$$ = newNode( NULL, "FieldDecl",0,0);
																	add_child($$, $3);
																	addBrother($3, newNode( $4->value, "Id", $4->line, $4->column));
																	freeToken($4);
																	if ($5 != NULL){
																		aux = $5;
																		while (aux != NULL) {
																			Node* aux1 = newNode( NULL, "FieldDecl",0,0);
																			Node* aux2 = newNode($3->valor, $3->s_type, $3->l,$3->column);
																			add_child(aux1, aux2);
																			addBrother(aux2, newNode( aux->valor, "Id", aux->l,aux->column));
																			addBrother($$, aux1);
																			aux = aux->brother;
																		}
																		free(aux);
																		
																	}}
		|	error SEMICOLON											{$$ = NULL; flag_erro = 1;}
		;

FieldDecl2:	/* empty */												{$$ = NULL;}
		|	COMMA ID FieldDecl2										{$$ = newNode( $2->value, "Id", $2->line, $2->column);
																	addBrother($$, $3);
																	freeToken($2);}
		;

Type:	BOOL														{$$ = newNode( NULL, "Bool",0,0);}
	|	INT															{$$ = newNode( NULL, "Int",0,0);}
	|	DOUBLE														{$$ = newNode( NULL, "Double",0,0);}
	;

MethodHeader:	Type ID LPAR MethodHeader2 RPAR						{$$ = newNode( NULL, "MethodHeader",0,0);
																	add_child($$,$1);
																	addBrother($1, newNode( $2->value, "Id", $2->line, $2->column));
																	aux = newNode( NULL, "MethodParams",0,0);
																	addBrother($1, aux);
																	add_child(aux, $4);
																	freeToken($2);}
			|	VOID ID LPAR MethodHeader2 RPAR						{$$ = newNode( NULL, "MethodHeader",0,0);
																	aux = newNode( NULL, "Void", $1->line, $1->column );
																	add_child($$, aux);
																	addBrother(aux, newNode( $2->value, "Id", $2->line, $2->column));
																	Node* aux2 = newNode( NULL, "MethodParams",0,0);
																	addBrother(aux, aux2);
																	add_child(aux2, $4);
																	freeToken($1);
																	freeToken($2);}
			;

MethodHeader2:	/* empty */											{$$ = NULL;}
			|	FormalParams										{$$ = $1;}
			;

FormalParams:	Type ID FormalParams2								{$$ = newNode( NULL, "ParamDecl",0,0);
																	add_child($$, $1);
																	aux = newNode( $2->value, "Id", $2->line, $2->column);
																	addBrother($1, aux);
																	addBrother($$, $3);
																	freeToken($2);}
			|	STRING LSQ RSQ ID									{$$ = newNode( NULL, "ParamDecl",0,0);
																	aux = newNode( NULL, "StringArray",$1->line, $1->column);
																	add_child($$, aux);
																	addBrother(aux, newNode( $4->value, "Id", $4->line, $4->column));
																	freeToken($1);
																	freeToken($4);}
			;

FormalParams2:	/* empty */											{$$ = NULL;}
			|	COMMA Type ID FormalParams2 						{$$ = newNode( NULL, "ParamDecl",0,0);
																	aux = newNode( $3->value, "Id", $3->line, $3->column);
																	add_child($$, $2);
																	addBrother($2, aux);
																	addBrother($$, $4);
																	freeToken($3);}
			;

MethodBody:	LBRACE MethodBody2 RBRACE								{$$ = newNode( NULL, "MethodBody",0,0);
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

VarDecl:	Type ID VarDecl2 SEMICOLON								{$$ = newNode( NULL, "VarDecl",0,0);
																	add_child($$, $1);
																	addBrother($1, newNode( $2->value, "Id", $2->line, $2->column));
																	if ($3 != NULL){
																		aux = $3;
																		while (aux != NULL) {
																			Node* aux1 = newNode( NULL, "VarDecl",0,0);
																			Node* aux2 = newNode( $1->valor, $1->s_type, $1->l, $1->column);
																			add_child(aux1, aux2);
																			addBrother(aux2, newNode( aux->valor, "Id",aux->l,aux->column));
																			addBrother($$, aux1);
																			aux = aux->brother;
																		}
																		free(aux);
																	}
																	freeToken($2);
																	}
		

VarDecl2:	/* empty */												{$$ = NULL;}
		|	COMMA ID VarDecl2										{$$ = newNode( $2->value, "Id", $2->line, $2->column);
																	addBrother($$, $3);
																	freeToken($2);}
		;

Statement:	LBRACE Statement2 RBRACE								{if (countBrother($2) > 1) {
																		aux = newNode( NULL, "Block",0,0);
																		$$ = aux;
																		add_child(aux, $2);
																	}
																	else {
																		$$ = $2;
																	}}
		|	IF LPAR Expr RPAR Statement %prec ELSE					{$$ = newNode( NULL, "If", $1->line, $1->column);
																	add_child($$,$3);
																	aux = newNode( NULL, "Block",0,0);
																	if (countBrother($5) == 1 && $5 != NULL) {
																		addBrother($3, $5);
																		addBrother($5, aux);
																	}
																	else {
																		addBrother($3, aux);
																		add_child(aux, $5);
																		addBrother(aux, newNode( NULL, "Block",0,0));
																	}
																	freeToken($1);}
		|	IF LPAR Expr RPAR Statement ELSE Statement				{$$ = newNode( NULL, "If", $1->line, $1->column);
																	add_child($$,$3);
																	aux = newNode( NULL, "Block",0,0);
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
																			Node* aux2 = newNode( NULL, "Block",0,0);
																			addBrother(aux, aux2);
																			add_child(aux2, $7);
																		}
																	}
																	freeToken($1);}
		|	WHILE LPAR Expr RPAR Statement							{$$ = newNode( NULL, "While", $1->line, $1->column);
																	add_child($$, $3);
																	if (countBrother($5) == 1 && $5 != NULL) {
																		addBrother($3, $5);
																	}
																	else {
																		aux = newNode( NULL, "Block",0,0);
																		addBrother($3, aux);
																		add_child(aux, $5);
																	}
																	freeToken($1);}
		|	RETURN ExprReturn SEMICOLON								{$$ = newNode( NULL, "Return", $1->line, $1->column);
																	add_child($$, $2);
																	freeToken($1);}
		|	Statement3 SEMICOLON									{$$ = $1;}
		|	PRINT LPAR StatementPrint RPAR SEMICOLON				{$$ = newNode( NULL, "Print", $1->line, $1->column);
																	add_child($$, $3);
																	freeToken($1);}
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
			|	STRLIT												{$$ = newNode( $1->value, "StrLit", $1->line, $1->column);
																	freeToken($1);}
			;

MethodInvocation:	ID LPAR MethodInvocation2 RPAR					{$$ = newNode( NULL, "Call",$1->line, $1->column);
																	aux = newNode( $1->value, "Id", $1->line, $1->column);
																	add_child($$, aux);
																	addBrother(aux, $3);
																	freeToken($1);}
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

Assignment:	ID ASSIGN Expr											{$$ = newNode( NULL, "Assign", $2->line, $2->column);
																	aux = newNode( $1->value, "Id", $1->line, $1->column);
																	add_child($$, aux);
																	addBrother(aux, $3);
																	freeToken($1);
																	freeToken($2);}
		;

ParseArgs:	PARSEINT LPAR ID LSQ Expr RSQ RPAR						{$$ = newNode( NULL, "ParseArgs", $1->line, $1->column);
																	aux = newNode( $3->value, "Id", $3->line, $3->column);
																	add_child($$, aux);
																	addBrother(aux, $5);
																	freeToken($3);
																	freeToken($1);}
		|	PARSEINT LPAR error RPAR								{$$ = NULL;
																	flag_erro = 1;}
		;

Expr:	Assignment													{$$ = $1;}
	|	ExprOperations												{$$ = $1;}
	;

ExprOperations:	ExprOperations PLUS ExprOperations					{$$ = newNode(NULL, "Add", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations MINUS ExprOperations					{$$ = newNode( NULL, "Sub", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations STAR ExprOperations					{$$ = newNode( NULL, "Mul", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations DIV ExprOperations					{$$ = newNode( NULL, "Div", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations MOD ExprOperations					{$$ = newNode( NULL, "Mod", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations AND ExprOperations					{$$ = newNode( NULL, "And", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations OR ExprOperations					{$$ = newNode( NULL, "Or", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations XOR ExprOperations					{$$ = newNode( NULL, "Xor", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations LSHIFT ExprOperations				{$$ = newNode( NULL, "Lshift", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations RSHIFT ExprOperations				{$$ = newNode( NULL, "Rshift", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations EQ ExprOperations					{$$ = newNode( NULL, "Eq", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations GE ExprOperations					{$$ = newNode( NULL, "Ge", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations GT ExprOperations					{$$ = newNode( NULL, "Gt", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations LE ExprOperations					{$$ = newNode( NULL, "Le", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations LT ExprOperations					{$$ = newNode( NULL, "Lt", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	ExprOperations NE ExprOperations					{$$ = newNode( NULL, "Ne", $2->line, $2->column);
																	add_child($$, $1);
																	addBrother($1, $3);
																	freeToken($2);}
			|	PLUS ExprOperations %prec NOT						{$$ = newNode( NULL, "Plus", $1->line, $1->column);
																	add_child($$, $2);
																	freeToken($1);}
			|	MINUS ExprOperations %prec NOT						{$$ = newNode( NULL, "Minus", $1->line, $1->column);
																	add_child($$, $2);
																	freeToken($1);}
			|	NOT ExprOperations									{$$ = newNode( NULL, "Not", $1->line, $1->column);
																	add_child($$, $2);
																	freeToken($1);}
			|	LPAR Expr RPAR										{$$ = $2;}
			|	LPAR error RPAR										{$$ = NULL;
																	flag_erro = 1;}
			|	Expr2												{$$ = $1;}
			|	ID													{$$ = newNode( $1->value, "Id", $1->line, $1->column);
																	freeToken($1);}
			|	ID DOTLENGTH										{$$ = newNode( NULL, "Length", $2->line, $2->column );
																	add_child($$, newNode( $1->value, "Id", $1->line, $1->column));
																	freeToken($1);
																	freeToken($2);}
			|	ExprLit												{$$ = $1;}
	;


Expr2:	MethodInvocation											{$$ = $1;}
	|	ParseArgs													{$$ = $1;}
	;

ExprLit:	INTLIT													{$$ = newNode( $1->value, "DecLit", $1->line, $1->column);
																	freeToken($1);}
		|	REALLIT													{$$ = newNode( $1->value, "RealLit", $1->line, $1->column);
																	freeToken($1);}
		|	BOOLLIT													{$$ = newNode( $1->value, "BoolLit", $1->line, $1->column);
																	freeToken($1);}
		;

%%
