#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_table.h"
#include "semantics.h"


void check_program(Node* raiz) {
    if (raiz == NULL) {
        return;
    }
    else if (strcmp(raiz->s_type, "Program") == 0) {
        char * nome = (char*)strdup(raiz->child->valor);
        init_class(nome);
    }
    else if (strcmp(raiz->s_type, "FieldDecl") == 0) {
        check_field_decl(raiz);
    }
    else if (strcmp(raiz->s_type, "MethodDecl") == 0) {
        check_method_decl(raiz->child);
    }
    Node* aux_filho = raiz->child;
    while (aux_filho != NULL) {
        check_program(aux_filho);
        aux_filho = aux_filho->brother;
    }
    
}

void check_field_decl(Node* raiz) {
    char * s_type = check_s_type(raiz->child->s_type);
    char * valor = (char*)strdup(raiz->child->brother->valor);
    insere_elem(valor, s_type, NULL, NULL, "Class");
}

char * check_s_type(char * raiz) {
    char * s_type = NULL;
    if (strcmp(raiz, "StringArray") == 0) {
        s_type = (char*)calloc((strlen("String[]")+1), sizeof(char));
        strcpy(s_type, "String[]");
    }
    else if (strcmp(raiz, "Int") == 0) {
        s_type = (char*)calloc((strlen("int")+1), sizeof(char));
        strcpy(s_type, "int");
    }
    else if (strcmp(raiz, "Double") == 0) {
        s_type = (char*)calloc((strlen("double")+1), sizeof(char));
        strcpy(s_type, "double");
    }
    else if (strcmp(raiz, "Bool") == 0) {
        s_type = (char*)calloc((strlen("boolean")+1), sizeof(char));
        strcpy(s_type, "boolean");
    }
    else if (strcmp(raiz, "Void") == 0) {
        s_type = (char*)calloc((strlen("void")+1), sizeof(char));
        strcpy(s_type, "void");
    }
    else if (strcmp(raiz, "ParseArgs") == 0) {
        s_type = (char*)calloc((strlen("int")+1), sizeof(char));
        strcpy(s_type, "int");
    }
    return s_type;
}

char * check_method_decl(Node* raiz) {
    char * s_type = check_s_type(raiz->child->s_type);
    char * valor = (char*)strdup(raiz->child->brother->valor);
    char * params = check_method_params(raiz->child->brother->brother);
    char ** array_params = check_array_method_params(raiz->child->brother->brother);
    char * n_string;

    if ((n_string = malloc(strlen(valor)+strlen(params)+1)) != NULL) {
        n_string[0] = '\0';
        strcat(n_string, valor);
        strcat(n_string, params);
    }
    insere_elem(valor, s_type, params, NULL, "Class");
    init_method(n_string, valor, array_params, s_type);
    adiciona_method_params(raiz->child->brother->brother, n_string);
    return n_string;
}

char * check_method_params(Node* raiz) {
    char params[500] = "(";
    Node* aux = NULL;
    if (raiz->child) {
        aux = raiz->child;
    }
    while (aux) {
        if (strcmp(aux->child->s_type, "StringArray") == 0) {
            strcat(params, "String[]");
        }
        else if (strcmp(aux->child->s_type, "Int") == 0) {
            strcat(params, "int");
        }
        else if (strcmp(aux->child->s_type, "Double") == 0) {
            strcat(params, "double");
        }
        else if (strcmp(aux->child->s_type, "Bool") == 0) {
            strcat(params, "boolean");
        }
        if (aux->brother) {
            strcat(params, ",");    // adicionar , caso mais que um parametro
        }
        aux = aux->brother;
    }
    strcat(params, ")");
    return strdup(params);
}


char ** check_array_method_params(Node* raiz) {
    char ** params = (char**)malloc(50 * sizeof(char*));
    Node* aux = NULL;
    int i = 1;
    if (raiz->child) {
        aux = raiz->child;
    }
    while (aux) {
        if (strcmp(aux->child->s_type, "StringArray") == 0) {
            params[i] = strdup("String[]");
        }
        else if (strcmp(aux->child->s_type, "Int") == 0) {
            params[i] = strdup("int");
        }
        else if (strcmp(aux->child->s_type, "Double") == 0) {
            params[i] = strdup("double");
        }
        else if (strcmp(aux->child->s_type, "Bool") == 0) {
            params[i] = strdup("boolean");
        }
        i++;
        aux = aux->brother;
    }
    char string[10];
    sprintf(string, "%d", i-1);
    params[0] = strdup(string);
    return params;
}

void adiciona_method_params(Node* raiz, char * tabela) {
    Node* head = NULL;
    if (raiz->child) {
        head = raiz->child;
    }
    while (head) {
        char * s_type = check_s_type(head->child->s_type);
        insere_elem(head->child->brother->valor, s_type, NULL, "param", tabela);
        head = head->brother;
    }
}


void check_method_body(Node* raiz, char * tabela_t) {
    if (raiz == NULL) {
        return ;
    }
    if (strcmp(raiz->s_type, "VarDecl") == 0) {
        char * s_type = check_s_type(raiz->child->s_type);
        insere_elem(raiz->child->brother->valor, s_type, NULL, NULL, tabela_t);
    }
    if (strcmp(raiz->s_type, "Id") == 0) {
        if (raiz->parent != NULL) {
            if (strcmp(raiz->parent->s_type, "VarDecl") != 0) {
                char * type_simbolo = procura_tabela_char(raiz->valor, tabela_t);
                raiz->type_tab = type_simbolo;
            }
        }
        else {
            char * type_simbolo = procura_tabela_char(raiz->valor, tabela_t);
            raiz->type_tab = type_simbolo;
        }
    }
    // Lshift, Rshift e Xor não precisam de anotação
    if (strcmp(raiz->s_type, "DecLit") == 0 || strcmp(raiz->s_type, "ParseArgs") == 0 || strcmp(raiz->s_type, "Length") == 0) {
        char * anota = (char*)strdup(" - int");
        raiz->type_tab = anota;
    }
    if (strcmp(raiz->s_type, "RealLit") == 0) {
        char * anota = (char*)strdup(" - double");
        raiz->type_tab = anota;
    }
    if (strcmp(raiz->s_type, "StrLit") == 0) {
        char * anota = (char*)strdup(" - String");
        raiz->type_tab = anota;
    }
    if (strcmp(raiz->s_type, "Eq") == 0 || strcmp(raiz->s_type, "Ne") == 0 || strcmp(raiz->s_type, "Gt") == 0 || strcmp(raiz->s_type, "Ge") == 0 || strcmp(raiz->s_type, "Lt") == 0 || strcmp(raiz->s_type, "Le") == 0 || strcmp(raiz->s_type, "And") == 0 || strcmp(raiz->s_type, "Or") == 0 || strcmp(raiz->s_type, "Not") == 0 || strcmp(raiz->s_type, "BoolLit") == 0) {
        char * anota = (char*)strdup(" - boolean");
        raiz->type_tab = anota;
    }
    Node* aux = raiz->child;
    while (aux != NULL) {
        check_method_body(aux, tabela_t);
        aux = aux->brother;
    }
    if (strcmp(raiz->s_type, "Assign") == 0 || strcmp(raiz->s_type, "Plus") == 0 || strcmp(raiz->s_type, "Minus") == 0) {
        char * anota = (char*)strdup(raiz->child->type_tab);
        raiz->type_tab = anota;
    }
    if (strcmp(raiz->s_type, "Add") == 0 || strcmp(raiz->s_type, "Sub") == 0 || strcmp(raiz->s_type, "Mul") == 0 || strcmp(raiz->s_type, "Div") == 0 || strcmp(raiz->s_type, "Mod") == 0) {
        char * anota;
        if (strcmp(raiz->child->type_tab, raiz->child->brother->type_tab) == 0) {
            anota = (char*)strdup(raiz->child->type_tab);
        }
        else {
            anota = (char*)strdup(" - double");
        }
        raiz->type_tab = anota;
    }
    if (strcmp(raiz->s_type, "Call") == 0) {
        char ** params = check_calls_method_params(raiz);
        table anota = check_call(raiz->child->valor, params, 0);
        if (anota != NULL) {
            char * n_string;
            if ((n_string = malloc(strlen(" - ")+strlen(anota->tabela->s_type)+1)) != NULL) {
                n_string[0] = '\0';
                strcat(n_string, " - ");
                strcat(n_string, anota->tabela->s_type);
            }
            raiz->type_tab = n_string;
            int i = strlen(anota->c_nome);
            char * n_string2;
            if ((n_string2 = malloc(strlen(" - ")+strlen(&anota->nome[i])+1)) != NULL) {
                n_string2[0] = '\0';
                strcat(n_string2, " - ");
                strcat(n_string2, &anota->nome[i]);
            }
            raiz->child->type_tab = n_string2;
        }
        else {
            char * n_string;
            if ((n_string = malloc(strlen(" - undef")+1)) != NULL) {
                n_string[0] = '\0';
                strcat(n_string, " - undef");
            }
            raiz->type_tab = n_string;
            raiz->child->type_tab = n_string;
        }
    }
}

char ** check_calls_method_params(Node* raiz) {
    char ** params = (char**)malloc(50*sizeof(char*));
    Node* aux = NULL;
    int i = 1;
    if (raiz->child->brother) {
        aux = raiz->child->brother;
    }
    while (aux != NULL) {
        if (aux->type_tab != NULL) {
            params[i] = strdup(&aux->type_tab[3]);
            i++;
        }
        aux = aux->brother;
    }
    char string[10];
    sprintf(string, "%d", i-1);
    params[0] = strdup(string);
    return params;
}

void check_ast(Node* raiz) {
    if (raiz == NULL) {
        return ;
    }
    if (strcmp(raiz->s_type, "MethodDecl") == 0) {
        char * params = check_method_params(raiz->child->child->brother->brother);
        char * valor = (char*)strdup(raiz->child->child->brother->valor);
        char * n_string;
        if ((n_string = malloc(strlen(valor)+strlen(params)+1)) != NULL) {
            n_string[0] = '\0';
            strcat(n_string, valor);
            strcat(n_string, params);
        }
        check_method_body(raiz->child->brother, n_string);
    }
      Node* aux = raiz->child;
    while (aux != NULL) {
        check_ast(aux);
        aux = aux->brother;
    }
}