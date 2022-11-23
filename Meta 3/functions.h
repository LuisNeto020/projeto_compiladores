
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct token{
    char *value;
    int line, column;
} token;

typedef struct Node{
    int l;
    int column;
    char * valor;
	char * s_type;
    char *anoted;
    struct Node *child;
    struct Node *brother;
    struct Node *parent;
    int n_params;
    int to_anote;
    struct _param_list *params;
      
}Node;

token* createToken(char *value, int line, int colunm);
void freeToken(token *aux);
Node * newNode(token * val, char * s_type);
void add_child(Node* father, Node* child);
void addBrother(Node* node1, Node* node2);
void printTree(Node *node, int depth);
int countBrother(Node* root);
void freeTree(Node *node);
