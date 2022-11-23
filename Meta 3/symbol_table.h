#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "functions.h"




typedef struct _sym_table{
    char *tableName;
    char *tableType;
    struct _var_list *vars;
    struct _param_list *params;
    struct _sym_table *next;
} sym_table;

typedef struct _var_list {
    int line, colunm;
    char *name;
    char *type;
    int flag; //indica se é param ou não (1 se for) (2 se nao for para imprimir)
    int function; //indica se é funçao ou nao
    int n_params; //se for function tem o numero de parametros
    struct _param_list *paramTypes;
    struct _var_list *next;
} var_list;

typedef struct _param_list {
    int line, colunm;
    char *id;
    char *type;
    struct _param_list *next;
} param_list;


extern sym_table *global_table, *local_table;
extern int nErrorsSemantic;

void clearParams(param_list *param);
void clearVars(var_list *var);
void clearLocalTables(sym_table *local);
void clearTables(sym_table *global, sym_table *local);
void create_semantic_table(Node* atual);
void add_to_local_table(sym_table *local_table, sym_table *element);
void print_table_global(sym_table *atual);
void print_tables_local(sym_table *atual);
char *changeType(char *nodeType);
var_list *create_var(char *name, char *type);
void add_var(var_list *varList, var_list *new);
param_list *create_param_type(char *type, char *id);
void add_param(param_list *paramList, param_list *new);
sym_table* create_table(char *name, char *type);
char *search_var_exists(param_list *params, char *var_name);
int search_function_exists(sym_table *table_global, param_list *aux_paramTypes, int count_params, char *name);
void anote_ast(sym_table *table_global, sym_table *table_local, Node *atual);
int itsExpression(char *nodeType);
void printAnotedAST(Node *current, int n);
char *search_type_var_in_table(sym_table *table, char *var_name);
char *search_type_var(sym_table *table_global, sym_table *table_local, char *var_name);
#endif