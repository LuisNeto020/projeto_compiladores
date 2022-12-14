#include <limits.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <float.h>
#include "AstTree.h"

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
    int flag; 
    int function; 
    int n_params; 
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
extern int nErrors;


void clearParams(param_list *param);
void clearVars(var_list *var);
void clearLocalTables(sym_table *local);
void clearGlobalTable(sym_table *global);
void print_table_global(sym_table *atual);
void print_tables_local(sym_table *atual);
void add_local_table(sym_table *table, sym_table *new_table);
param_list *create_param(char *type, char *id);
void add_param(param_list *paramList, param_list *new);
var_list *create_var(char *name, char *type);
void add_var(var_list *varList, var_list *new);
sym_table* create_table(char *name, char *type);
char *change_Type(char *s_type);
void create_semantic_table(Node* atual);

char *search_var_exists(param_list *params, char *var_name);
int search_function_exists(sym_table *table_global, param_list *aux_paramTypes, int count_params, char *name);
void anote_ast(sym_table *table_global, sym_table *table_local, Node *atual);
int itsExpression(char *nodeType);
void printAnotedAST(Node *current, int n);
char *search_type_var_in_table(sym_table *table, char *var_name);
char *search_type_var(sym_table *table_global, sym_table *table_local, char *var_name);