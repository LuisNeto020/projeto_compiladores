#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

typedef struct node_tab* node_table;
typedef struct node_tab {
    char * valor;
    char * s_type;
    char * param_types;
    char * param;
    node_table next;
} node_tab;

typedef struct tab* table;
typedef struct tab {
    char * type;
    char * nome;
    char * c_nome;
    char ** array_params;
    int n_params;
    node_table tabela;
    table next;
} tab;


void init_class(char * nome);
void init_method(char * nome, char * c_nome, char ** array_params, char * s_type);
table procura_tabela(char * nome);
table check_call(char * id, char ** params, int p);
void insere_elemento(char * valor, char * s_type, char * param_types, char * param, table tabela);
void insere_elem(char * valor, char * s_type, char * param_types, char * param, char * tabela_t);
void print_tabela();
char * procura_tabela_char(char * nome, char * nome_tab);
#endif