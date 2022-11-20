#include "functions.h"
#include "symbol_table.h"



void check_program(Node* raiz);
void check_field_decl(Node* raiz);
char * check_method_decl(Node* raiz);
void check_method_body(Node* raiz, char * tabela);
char * check_s_type(char * raiz);
char * check_method_params(Node* raiz);
char ** check_array_method_params(Node* raiz);
char ** check_calls_method_params(Node* raiz);
void adiciona_method_params(Node* raiz, char * tabela);
void check_ast(Node* raiz);
