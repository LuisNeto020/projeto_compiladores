#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "symbol_table.h"

table tabela_simbolos;

void init_class(char * nome) {
    tabela_simbolos = calloc(1, sizeof(tab));
    tabela_simbolos->type = (char*)calloc((strlen("Class")+1), sizeof(char));
    strcpy(tabela_simbolos->type, "Class");
    tabela_simbolos->nome = (char*)calloc((strlen(nome)+1), sizeof(char));
    strcpy(tabela_simbolos->nome, nome);
    tabela_simbolos->array_params = NULL;
}

void print_tabela() {
    table aux_tab;
    node_table aux_node;
    for (aux_tab = tabela_simbolos; aux_tab; aux_tab = aux_tab->next) {
        printf("===== %s %s Symbol Table =====\n", aux_tab->type, aux_tab->nome);
        aux_node = aux_tab->tabela;
        while (aux_node) {
            if (strcmp(aux_node->param, "") != 0) {
                printf("%s\t\t%s\t%s\n", aux_node->valor, aux_node->s_type, aux_node->param);
            }
            else {
                printf("%s\t%s\t%s\n", aux_node->valor, aux_node->param_types, aux_node->s_type);
            }
            aux_node = aux_node->next;
        }
        printf("\n");
    }
}

table procura_tabela(char * nome) {
    table head = tabela_simbolos;
    while(head) {
        if (strcmp(head->nome, nome) == 0) {
            return head;
        }
        head = head->next;
    }
    return NULL;
}


void insere_elem(char * valor, char * s_type, char * param_types, char * param, char * tabela_t) {
    node_table n_node = calloc(1, sizeof(node_tab));
    n_node->valor = valor;
    n_node->s_type = s_type;
    n_node->next = NULL;
    if (param_types) {
        n_node->param_types = param_types;
    }
    else {
        n_node->param_types = "";
    }
    if (param) {
        n_node->param = param;
    }
    else {
        n_node->param = "";
    }
    table nova = NULL;
    if (strcmp(tabela_t, "Class") == 0) {
        nova = tabela_simbolos;
    }
    else {
        nova = procura_tabela(tabela_t);
    }
    if (!nova->tabela) {
        nova->tabela = n_node;
    }
    else {
        node_table head = nova->tabela;
        while (head->next) {
            head = head->next;
        }
        head->next = n_node;
    } 
}
