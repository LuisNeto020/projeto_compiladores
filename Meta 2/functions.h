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

Node * newNode(char * node_type , char * valor, char * s_type);
void add_child(Node father, Node child);
void addBrother(Node* node1, Node* node2);
void printTree(Node *node, int depth);
int countBrother(node root);