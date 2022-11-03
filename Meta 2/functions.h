#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    char * valor;
	char * s_type;
	char * node_type;
    int num_child;
    struct node *brother;
    struct node *child;
}Node;