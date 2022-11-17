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

#endif