#include "functions.h"

Node * newNode(char * node_type , char * valor, char * s_type){
    Node * new = (Node *) malloc(sizeof(Node));
    new->s_type = (char *)malloc(1 + strlen(s_type) * sizeof(char));
	strcpy(new->s_type, s_type);
	new->valor = (char *)malloc(1 + strlen(valor) * sizeof(char));	
    strcpy(new->valor, valor);
    new->node_type = (char *)malloc(1 + strlen(node_type) * sizeof(char));
    strcpy(new->node_type, node_type);
    new->num_child = 0;
    new->child = NULL;
    new->brother = NULL;

    return new;
}

void add_child(Node* father, Node*
 child){
    if (child == NULL) {
			return ;
		}
	father->child = child;
	father->num_child++;
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
    char dots[depth*2];
    for (int i = 0; i<depth*2; i++){
        dots[i]='.';
    }
    dots[2*depth]='\0';

    if (strcmp(node->valor,"") != 0) {
		printf("%s%s(%s)\n", dots, node->s_type, node->valor);
	}
	else {
		printf("%s%s\n", dots, node->s_type);
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
    if (node->child)    freeTree(node->child);
    if (node->brother)  freeTree(node->brother);
    free(node);
}

