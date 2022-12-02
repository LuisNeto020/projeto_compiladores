#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#include "symbol_table.h"

void clearParams(param_list *param){
    if(param == NULL){
        return;
    }

    if(param->type != NULL){
        free(param->type);
        param->type = NULL;
    }
    if(param->id != NULL){
        free(param->id);
        param->id = NULL;
    }

    clearParams(param->next);

    free(param);
    param = NULL;
}

void clearVars(var_list *var){
    if(var == NULL){
        return;
    }

    if(var->type != NULL){
        free(var->type);
        var->type = NULL;
    }
    if(var->name != NULL){
        free(var->name);
        var->name = NULL;
    }

    clearParams(var->paramTypes);
    clearVars(var->next);

    free(var);
    var = NULL;
}

void clearLocalTables(sym_table *local){
    if(local == NULL){
        return;
    }

    if(local->tableName != NULL){
        free(local->tableName);
        local->tableName = NULL;
    }
    if(local->tableType != NULL){
        free(local->tableType);
        local->tableType = NULL;
    }

    if(local->params != NULL){
        clearParams(local->params->next);
        if(local->params->type != NULL){
            free(local->params->type);
            local->params->type = NULL;
        }
        if(local->params->id != NULL){
            free(local->params->id);
            local->params->id = NULL;
        }
        free(local->params);
        local->params = NULL;
    }
    if(local->vars != NULL){
        clearVars(local->vars->next);
        if(local->vars->type != NULL){
            free(local->vars->type);
            local->vars->type = NULL;
        }
        if(local->vars->name != NULL){
            free(local->vars->name);
            local->vars->name = NULL;
        }
        free(local->vars);
        local->vars = NULL;
    }

    clearLocalTables(local->next);

    free(local);
    local = NULL;
}

void clearTables(sym_table *global, sym_table *local){
    if(global != NULL){
        if(global->tableName != NULL){
            free(global->tableName);
            global->tableName = NULL;
        }
        if(global->tableType != NULL){
            free(global->tableType);
            global->tableType = NULL;
        }

        clearVars(global->vars);

        free(global);
        global = NULL;
    }

    if(local != NULL){
        clearLocalTables(local);
    }
}

void print_table_global(sym_table *atual){
    var_list *auxV = atual->vars;
    param_list *auxP;

    printf("===== %s %s Symbol Table =====\n", atual->tableType, atual->tableName);
    while(auxV != NULL){
        if(auxV->function == 1){
            auxP = auxV->paramTypes;
            printf("%s\t(", auxV->name);
            while(auxP != NULL){
                printf("%s", auxP->type);
                if(auxP->next != NULL){
                    printf(",");
                }
                auxP = auxP->next;
            }
            printf(")\t%s", auxV->type);
        }
        else{
            printf("%s\t\t%s", auxV->name, auxV->type);
        }

        printf("\n");

        auxV = auxV->next;
    }
    printf("\n");
}

void print_tables_local(sym_table *atual){
    sym_table *aux = atual;
    var_list *auxV;
    param_list *auxP;

    while(aux != NULL){
        auxV = aux->vars;
        auxP = aux->params;
        if(auxP!=NULL){
            printf("===== %s %s(",  aux->tableType, aux->tableName);
            while(auxP != NULL){
                printf("%s", auxP->type);
                if(auxP->next !=NULL){
                    printf(",");
                }
                auxP = auxP->next;
            }
            printf(") Symbol Table =====\n");
        }
        else{
            printf("===== %s %s() Symbol Table =====\n", aux->tableType, aux->tableName);
        }
        while(auxV != NULL){
            if(auxV->flag == 2){
                //dont print, its repeated
            }
            else if(auxV->flag == 1){
                printf("%s\t\t%s\t%s\n", auxV->name, auxV->type, "param");
            }
            else{
                printf("%s\t\t%s\n", auxV->name, auxV->type);
            }

            auxV = auxV->next;
        }

        printf("\n");

        aux = aux->next;
    }
}

void add_to_local_table(sym_table *table, sym_table *element){
    sym_table *aux = table;

    if(aux == NULL){
        table = element;
        return;
    }

    while(aux->next != NULL){
        aux = aux->next;
    }

    aux->next = element;
}

param_list *create_param_type(char *type, char *id){
    param_list *new = (param_list*)malloc(sizeof(param_list));
    new->type = (char*)strdup(type);
    new->id = (char*)strdup(id);
    new->next = NULL;
    return new;
}

void add_param(param_list *paramList, param_list *new){
    param_list *aux = paramList;

    if(aux == NULL){
        paramList = new;
        return;
    }

    while(aux->next != NULL){
        aux = aux->next;
    }

    aux->next = new;
}

var_list *create_var(char *name, char *type){
    var_list *new = (var_list*)malloc(sizeof(var_list));
    new->name = (char*)strdup(name);
    new->type = (char*)strdup(type);
    new->function = 0;
    new->flag = 0;
    new->n_params = 0;
    new->paramTypes = NULL;
    new->next = NULL;
    return new;
}

void add_var(var_list *varList, var_list *new){
    var_list *aux = varList;

    if(aux == NULL){
        varList = new;
        return;
    }

    while(aux->next != NULL){
        aux = aux->next;
    }

    aux->next = new;
}

sym_table* create_table(char *name, char *type){
    sym_table* aux = (sym_table*)malloc(sizeof(sym_table));
    aux->tableName = (char*)strdup(name);
    aux->tableType = (char*)strdup(type);

    aux->vars = NULL;
    aux->params = NULL;
    aux->next = NULL;
    return aux;
}

char *changeType(char *s_type){

    if(strcmp(s_type, "Int") == 0){
        s_type = "int";
        return s_type;
    }

    if(strcmp(s_type, "Double") == 0){
        s_type = "double";
        return s_type;
    }

    if(strcmp(s_type, "Bool") == 0){
        s_type = "boolean";
        return s_type;
    }

    if(strcmp(s_type, "Void") == 0){
        s_type = "void";
        return s_type;
    }

    if(strcmp(s_type, "StringArray") == 0){
        s_type = "String[]";
        return s_type;
    }

    return s_type;
}

void create_semantic_table(Node* atual){
    char *aux;
    int error;
    sym_table *auxTable;
    var_list *auxVar, *auxVarLocal;
    param_list *auxParam, *auxParamPrint;
    Node *aux1, *aux2, *aux3, *aux4, *aux5, *aux6, *auxProgram;
    int count_params;

    nErrors = 0;

    if(atual == NULL){
        return;
    }

    if(strcmp(atual->s_type, "Program")==0){ //Fazemos primeiro a tabela global toda
        aux1 = atual->child; //ID

        global_table = create_table(aux1->valor, "Class");
        auxProgram = aux1->brother; //FieldDecl ou MethodDecl
        atual = aux1->brother; //FieldDecl ou MethodDecl

        while(atual != NULL){ //Fazemos primeiro a tabela global toda
            if(strcmp(atual->s_type, "FieldDecl")==0){
                aux1 = atual->child; //TYPE
                aux2 = aux1->brother; //ID
                auxVar = create_var(aux2->valor, changeType(aux1->s_type));
                if(search_type_var(global_table, NULL, aux2->valor) != NULL){
                    nErrors = 1;
                    printf("Line %d, col %d: Symbol %s already defined\n", aux2->l, aux2->column, aux2->valor);
                    clearVars(auxVar);
                }
                else{
                    if(global_table->vars == NULL){
                        global_table->vars = auxVar;
                    }
                    else{
                        add_var(global_table->vars, auxVar);
                    }
                }
            }
            if(strcmp(atual->s_type, "MethodDecl")==0){
                aux1 = atual->child; //MethodHeader
                count_params = 0;
                while(aux1 != NULL){
                    if(strcmp(aux1->s_type, "MethodHeader") == 0){
                        aux2 = aux1->child; //TYPE
                        aux3 = aux2->brother; //ID

                        auxVar = create_var(aux3->valor, changeType(aux2->s_type)); //ADD TO GLOBAL

                        aux4 = aux3->brother; //MethodParams
                        aux5 = aux4->child; //ParamDecl ou nada
                        while(aux5 != NULL){ //WHILE EXISTS ParamDecl's
                            if(aux5->s_type!= NULL){
                                count_params++;
                                //add to auxVar to global_table
                                auxParam = create_param_type(changeType(aux5->child->s_type), (aux5->child)->brother->valor);
                                
                                aux = search_var_exists(auxVar->paramTypes, (aux5->child)->brother->valor);
                                if(aux != NULL){
                                    nErrors = 1;
                                    printf("Line %d, col %d: Symbol %s already defined\n", (aux5->child)->brother->l, (aux5->child)->brother->column, (aux5->child)->brother->valor);
                                }

                                if(auxVar->paramTypes == NULL){
                                    auxVar->paramTypes = auxParam;
                                }
                                else{
                                    add_param(auxVar->paramTypes, auxParam);
                                }
                            }
                            aux5 = aux5->brother;
                        }

                        auxVar->function = 1; //ITS FUNCTION
                        auxVar->n_params = count_params;
                        if(search_function_exists(global_table, auxVar->paramTypes, count_params, aux3->valor) == 1){
                            nErrors = 1;
                                printf("Line %d, col %d: Symbol %s(", aux3->l, aux3->column, aux3->valor);
                            auxParamPrint = auxVar->paramTypes;
                            while(auxParamPrint != NULL){
                                printf("%s", auxParamPrint->type);
                                if(auxParamPrint->next != NULL){
                                    printf(",");
                                }
                                auxParamPrint = auxParamPrint->next;
                            }
                            printf(") already defined\n");
                            aux3->to_anote = 0;
                            clearVars(auxVar);
                        }
                        else{
                            if(global_table->vars == NULL){
                                global_table->vars = auxVar;
                            }
                            else{
                                add_var(global_table->vars, auxVar);
                            }
                        }
                    }

                    aux1 = aux1->brother; //MethodHeader ou MethodBody
                }
            }

            atual = atual->brother;
        }

        atual = auxProgram;

        while(atual != NULL){ //Depois fazemos as tabelas locais
            if(strcmp(atual->s_type, "MethodDecl")==0){
                error = 0;
                aux1 = atual->child; //MethodHeader
                while(aux1 != NULL){
                    if(strcmp(aux1->s_type, "MethodHeader") == 0){
                        aux2 = aux1->child; //TYPE
                        aux3 = aux2->brother; //ID

                        if(aux3->to_anote == 0){
                            error = 1;
                            break;
                        }
                        
                        auxTable = create_table(aux3->valor, "Method");

                        auxVar = create_var("return", changeType(aux2->s_type)); //CREATE VAR TYPE
                        auxVar->flag = 0;
                        auxTable->vars = auxVar; //TO LOCAL TABLE

                        aux4 = aux3->brother; //MethodParams
                        aux5 = aux4->child; //ParamDecl ou nada
                        while(aux5 != NULL){ //WHILE EXISTS ParamDecl's
                            if(aux5->s_type != NULL){
                                //add to auxVar to global_table
                                auxParam = create_param_type(changeType(aux5->child->s_type), (aux5->child)->brother->valor);
                                
                                aux = search_var_exists(auxVar->paramTypes, (aux5->child)->brother->valor);

                                if(auxVar->paramTypes == NULL){
                                    auxVar->paramTypes = auxParam;
                                }
                                else{
                                    add_param(auxVar->paramTypes, auxParam);
                                }

                                //add to local_table
                                aux6 = (aux5->child)->brother; //ID OF ParamDecl
                                auxVarLocal = create_var(aux6->valor, changeType(aux5->child->s_type));
                                if(aux!=NULL){
                                    auxVarLocal->flag = 2; //DONT PRINT, ITS REPEATED
                                }
                                else{
                                    auxVarLocal->flag = 1; //ITS VAR
                                }
                                auxTable->params = auxVar->paramTypes;
                                add_var(auxTable->vars, auxVarLocal);
                            }
                            aux5 = aux5->brother;
                        }
                    }
                    if(strcmp(aux1->s_type, "MethodBody") == 0){
                        aux2 = aux1->child;
                        while(aux2 != NULL){
                            if(strcmp(aux2->s_type, "VarDecl") == 0){
                                aux3 = aux2->child;
                                aux4 = aux3->brother;
                                
                                if(search_type_var(NULL, auxTable, aux4->valor) != NULL){
                                    nErrors = 1;
                                    printf("Line %d, col %d: Symbol %s already defined\n", aux4->l, aux4->column, aux4->valor);
                                }
                                else{
                                    auxVar = create_var(aux4->valor, changeType(aux3->s_type));
                                    auxVar->flag = 0;
                                    add_var(auxTable->vars, auxVar); //TO LOCAL TABLE
                                }
                            }
                            else{
                                if(aux2->s_type != NULL ){
                                    anote_ast(global_table, auxTable, aux2);
                                }
                            }

                            aux2 = aux2->brother;
                        }
                    }

                    aux1 = aux1->brother; //MethodHeader ou MethodBody
                }

                if(error != 1){
                    if(local_table == NULL){
                        local_table = auxTable;
                    }
                    else{
                        add_to_local_table(local_table, auxTable); //ADD TO LOCAL TABLE
                    }  
                }
            }

            atual = atual->brother;
        }
    }
}

