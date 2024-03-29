#include "functions.h"

Node * newNode( char * valor, char * s_type){
    Node * new = (Node *) malloc(sizeof(Node));
	new->s_type = s_type;	
    new->valor=valor;
    new->child = NULL;
    new->brother = NULL;

    return new;
}

void add_child(Node* father, Node*
 novo){
    if (novo == NULL || father == NULL) {
			return ;
		}
	father->child = novo;
}

void addBrother(Node* node1, Node* node2){
	if (node1 == NULL || node2 == NULL) {
			return ;
	}
    Node* temp;
    temp= node1;
    while(temp->brother!= NULL){
        temp=temp->brother;
    }
    temp->brother=node2;
}

void printTree(Node *node, int depth){
    if (node == NULL) {
			return ;
		}
    int i=0;
    while (i < depth) {
				printf("..");
				i++;
			}

    if (strcmp(node->valor,"") != 0) {
		printf("%s(%s)\n",  node->s_type, node->valor);
	}
	else {
		printf("%s\n", node->s_type);
	}
    if (node->child)    printTree(node->child, depth+1);
    if (node->brother)  printTree(node->brother, depth);

    free(node);
}

int countBrother(Node * root) {
		int count = 0;
		Node* aux;
		aux = root;
		while (aux != NULL) {
			aux = aux->brother;
			count++;
		}
		return count;
	}

void freeTree(Node *node){
	if (node == NULL) {
			return ;
	}
    if (node->child)    freeTree(node->child);
    if (node->brother)  freeTree(node->brother);
    free(node);
}

