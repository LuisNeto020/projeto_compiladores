
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct Node{
    char * valor;
	char * s_type;
    struct Node *child;
    struct Node *brother;
}Node;

Node * newNode(char * valor, char * s_type);
void add_child(Node* father, Node* child);
void addBrother(Node* node1, Node* node2);
void printTree(Node *node, int depth);
int countBrother(Node* root);
void freeTree(Node *node);
