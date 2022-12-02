#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "functions.h"
#include "semantics.h"






char *search_var_exists(param_list *params, char *var_name);
int search_function_exists(sym_table *table_global, param_list *aux_paramTypes, int count_params, char *name);
void anote_ast(sym_table *table_global, sym_table *table_local, Node *atual);
int itsExpression(char *nodeType);
void printAnotedAST(Node *current, int n);
char *search_type_var_in_table(sym_table *table, char *var_name);
char *search_type_var(sym_table *table_global, sym_table *table_local, char *var_name);
#endif