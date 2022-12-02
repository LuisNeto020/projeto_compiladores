

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>







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
void clearTables(sym_table *global, sym_table *local);
void print_table_global(sym_table *atual);
void print_tables_local(sym_table *atual);
void add_to_local_table(sym_table *table, sym_table *element);
param_list *create_param_type(char *type, char *id);
void add_param(param_list *paramList, param_list *new);
var_list *create_var(char *name, char *type);
void add_var(var_list *varList, var_list *new);
sym_table* create_table(char *name, char *type);
char *changeType(char *s_type);
void create_semantic_table(Node* atual);