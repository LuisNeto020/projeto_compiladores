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


void insere_elemento(char * valor, char * s_type, char * param_types, char * param, table tabela_t) {
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
    tabela_t->tabela = n_node;
}

void init_method(char * nome, char * c_nome, char ** array_params, char * s_type) {
    table n_node = calloc(1, sizeof(tab));
    n_node->type = (char*)calloc((strlen("Method")+1), sizeof(char));
    strcpy(n_node->type, "Method");
    n_node->nome = nome;
    n_node->c_nome = c_nome;
    n_node->array_params = array_params;
    table head = tabela_simbolos;
    if (head == NULL) {
        tabela_simbolos = n_node;
    }
    else {
        while (head->next) {
            head = head->next;
        }
        head->next = n_node;
    }
    insere_elemento("return", s_type, NULL, NULL, head->next);
}

char * procura_tabela_char(char * nome, char * nome_tab) {
    table aux = NULL;
    node_table aux_node = NULL;
    char string[500] = " - ";
    aux = procura_tabela(nome_tab);
    if (aux) {
        for (aux_node = aux->tabela; aux_node; aux_node = aux_node->next) {
            if (strcmp(aux_node->valor, nome) == 0) {
                strcat(string, aux_node->s_type);
                return strdup(string);
            }
        }
    }
    aux = tabela_simbolos;
    for (aux_node = aux->tabela; aux_node; aux_node = aux_node->next) {
        if (strcmp(aux_node->valor, nome) == 0 && strcmp(aux_node->param_types, "") == 0) {
            strcat(string, aux_node->s_type);
            return strdup(string);
        }
    }
    return strdup("- undef");
}

table check_call(char * id, char ** params, int p) {
    table head = tabela_simbolos->next;
    while (head != NULL) {
        if (strcmp(head->c_nome, id) == 0) {
            if (head->array_params != NULL && params != NULL) {
                if (strcmp(head->array_params[0], params[0]) == 0) {
                    int i;
                    int j = atoi(params[0]);
                    int tab = 0;
                    for (i = 1; i <= j; i++) {
                        if (p == 1) {
                            if (strcmp(head->array_params[i], params[i]) != 0 && !(strcmp(head->array_params[i], "double") == 0 && strcmp(params[i], "int") == 0)) {
                                tab = 1;
                            }
                        }
                        else {
                            if (strcmp(head->array_params[i], params[i]) != 0) {
                                tab = 1;
                            }
                        }
                    }
                    if (tab == 0) {
                        return head;
                    }
                }
            }
        }
        head = head->next;
    }
    if (p == 0) {
        return check_call(id, params, 1);
    }
    return NULL;
}