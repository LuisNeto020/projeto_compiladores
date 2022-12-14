#include "semantics.h"
#include "llvm.h"

strlit_list *list_global_strlit;
strlit_list *found_vars;

strlit_list *create_strlit(char *value, char *type){
    strlit_list *new = (strlit_list*)malloc(sizeof(strlit_list));
    new->value = (char*)strdup(value);
    new->type = (char*)strdup(type);
    new->next = NULL;
    return new;
}

void clear_strlit_list(strlit_list *var){
    if(var == NULL){
        return;
    }

    if(var->value != NULL){
        free(var->value);
        var->value = NULL;
    }
    if(var->type != NULL){
        free(var->type);
        var->type = NULL;
    }

    clear_strlit_list(var->next);

    free(var);
    var = NULL;
}

void add_strlit(strlit_list *strList, strlit_list *new){
    strlit_list *aux = strList;

    if(aux == NULL){
        strList = new;
        return;
    }

    while(aux->next != NULL){
        aux = aux->next;
    }

    aux->next = new;
}

void print_strlit(strlit_list *strList){
    strlit_list *aux = strList;
    printf("\n");
    while(aux != NULL){
        printf("%s", aux->value);
        aux = aux->next;
    }
}


void print_global_var_and_decl(){
    var_list * aux_var = global_table->vars;
    while (aux_var != NULL) {
        if (aux_var->function == 0) {
        if (strcmp(aux_var->type, "int") == 0) {
            printf("@global_var_%s = common global i32 0, align 4\n", aux_var->name);
        }
        if (strcmp(aux_var->type, "double") == 0) {
            printf("@global_var_%s = common global double 0.000000e+00, align 4\n", aux_var->name);
        }
        if (strcmp(aux_var->type, "boolean") == 0) {
            printf("@global_var_%s = common global i1 0, align 4\n", aux_var->name);
        }

        //count_global_vars++;
        }
        aux_var = aux_var->next;
    }
    printf("declare i32 @atoi(i8*)\n");
    printf("declare i32 @printf(i8*, ...)\n\n");
    printf("define i32 @main(i32 %%argc, i8** %%argv) {\n");
    printf("\tcall void @function_v_main_s_(i32 %%argc, i8** %%argv)\n");
    printf("\tret i32 0\n\n");
}


void llvm(Node *atual){
    if(atual == NULL || atual->s_type == NULL){
        return;
    }
    Node *aux;
    if(strcmp(atual->s_type, "Program") == 0){
        aux = atual->child;
        while(aux != NULL){
            llvm(aux);
            aux = aux->brother;
        }
    }else if(strcmp(atual->s_type, "MethodHeader") == 0){
        function_header(atual);
    }

}

void function_header(Node *atual){
    char * function_type, function_name;
    Node * function_params;

    function_type = atual->child->s_type;
    function_name = atual->child->brother->valor;
    function_params = atual->child->brother->brother->child;

    char *aux_name_f = (char*)malloc(1024*sizeof(char));
    char *aux_params_f = (char*)malloc(1024*sizeof(char));

    if(strcmp(function_type, "Void") == 0){
        sprintf(aux_name_f, "function_%s_%s_", "v", function_name);
    }
    else if(strcmp(function_type, "Int") == 0){
        sprintf(aux_name_f, "function_%s_%s_", "i", function_name);
    }
    else if(strcmp(function_type, "Double") == 0){
        sprintf(aux_name_f, "function_%s_%s_", "d", function_name);
    }
    else{
        sprintf(aux_name_f, "function_%s_%s_", "b", function_name);
    }
    //Guarda todos os parametros
    while(function_params != NULL){
        Node *param_aux = function_params->child;

        if(strcmp(function_params->s_type, "ParamDecl") == 0){
            if(found_vars == NULL){
                found_vars = create_strlit(param_aux->brother->valor, param_aux->s_type);
            }
            else{
                add_strlit(found_vars, create_strlit(param_aux->brother->valor, param_aux->s_type));
            }
        }

        function_params = function_params->brother;
    }

    strlit_list* aux_function_params = found_vars;
    int stringArray = 0;

    while( aux_function_params != NULL){

        if(strcmp(aux_function_params->type, "StringArray") == 0){
            stringArray = 1;
            break;
        }
        if(strcmp(aux_function_params->type, "Int") == 0){
            char *aux;
            aux = (char*)malloc(1024*sizeof(char));
            if(aux_function_params->next != NULL){
                sprintf(aux, "i32 %%%s_aux, ", aux_function_params->value);
            }
            else{
                sprintf(aux, "i32 %%%s_aux", aux_function_params->value);
            }
            strcat(aux_params_f,aux);
            free(aux);
            aux = NULL;
        }
        if(strcmp(aux_function_params->type, "Bool") == 0){
            char *aux;
            aux = (char*)malloc(1024*sizeof(char));
            if(aux_function_params->next != NULL){
                sprintf(aux, "i1 %%%s_aux, ", aux_function_params->value);
            }
            else{
                sprintf(aux, "i1 %%%s_aux", aux_function_params->value);
            }
            strcat(aux_params_f,aux);
            free(aux);
            aux = NULL;
        }
        if(strcmp(aux_function_params->type, "Double") == 0){
            char *aux;
            aux = (char*)malloc(1024*sizeof(char));
            if(aux_function_params->next != NULL){
                sprintf(aux, "double %%%s_aux, ", aux_function_params->value);
            }
            else{
                sprintf(aux, "double %%%s_aux", aux_function_params->value);
            }
            strcat(aux_params_f,aux);
            free(aux);
            aux = NULL;
        }

        aux_function_params = aux_function_params->next;
    }

    if(strcmp(function_type, "Void") == 0){
        if(stringArray == 0){
            printf("define void @%s(%s) {\n", aux_name_f, aux_params_f);
        }
        else{
            printf("define void @%s(%s) {\n", aux_name_f, "i32 %argc, i8** %argv");
        }
    }
    else if(strcmp(function_type, "Int") == 0){
        if(stringArray == 0){
            printf("define i32 @%s(%s) {\n", aux_name_f, aux_params_f);
        }
        else{
            printf("define i32 @%s(%s) {\n", aux_name_f, "i32 %argc, i8** %argv");
        }
    }
    else if(strcmp(function_type, "Double") == 0){
        if(stringArray == 0){
            printf("define double @%s(%s) {\n", aux_name_f, aux_params_f);
        }
        else{
            printf("define double @%s(%s) {\n", aux_name_f, "i32 %argc, i8** %argv");
        }
    }
    else if(strcmp(function_type, "Bool") == 0){
        if(stringArray == 0){
            printf("define i1 @%s(%s) {\n", aux_name_f, aux_params_f);
        }
        else{
            printf("define i1 @%s(%s) {\n", aux_name_f, "i32 %argc, i8** %argv");
        }
    }

    if(stringArray == 1){
        printf("\t%%argc_aux = alloca i32, align 4\n");
        printf("\t%%argv_aux = alloca i8**, align 8\n");
        printf("\tstore i32 %%argc, i32* %%argc_aux, align 4\n");
        printf("\tstore i8** %%argv, i8*** %%argv_aux, align 8\n");
        clearList(found_vars);
        found_vars = NULL;
    }
    else{
        strlit_list *atual = found_vars;
        while(atual != NULL){
            if(strcmp(atual->type, "Int") == 0){
                printf("\t%%%s = alloca i32, align 4\n", atual->value);
                printf("\tstore i32 %%%s_aux, i32* %%%s, align 4\n", atual->value, atual->value);
            }
            else if(strcmp(atual->type, "Double") == 0){
                printf("\t%%%s = alloca double, align 8\n", atual->value);
                printf("\tstore double %%%s_aux, double* %%%s, align 8\n", atual->value, atual->value);
            }
            else if(strcmp(atual->type, "Bool") == 0){
                printf("\t%%%s = alloca i1\n", atual->value);
                printf("\tstore i1 %%%s_aux, i1* %%%s\n", atual->value, atual->value);
            }
            
            atual = atual->next;
        }
    }
    free(aux_name_f);
    aux_name_f = NULL;
    free(aux_params_f);
    aux_params_f = NULL;
}