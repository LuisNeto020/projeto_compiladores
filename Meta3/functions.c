

#include "functions.h"

token* createToken(char *value, int line, int column){
    token *new = (token*)malloc(sizeof(token));
    if(value != NULL){
        new->value = (char*)strdup(value);
    }
    else{
        new->value = NULL;
    }
    new->line = line;
    new->column = column;
    return new;
}

void freeToken(token *aux){
    if(aux->value != NULL){
        free(aux->value);
        aux->value = NULL;
    }
    free(aux);
    aux = NULL;
}


Node * newNode( char * val, char * s_type, int line, int column){
	Node * new = (Node *) malloc(sizeof(Node));
	new->s_type = (char*)strdup(s_type);;	
	if(val != NULL){
        new->valor = (char*)strdup(val);
    }
    else{
        new->valor = NULL;
    }
    new->child = NULL;
    new->brother = NULL;
	new->parent=NULL;
	new->n_params=0;
	new->l=line;
	new->column=column;
	new->to_anote=1;
	new->anoted=NULL;
    return new;
}

void add_child(Node* father, Node*
 novo){
    if (novo == NULL || father == NULL) {
			return ;
		}
	father->child = novo;
	novo->parent=father;
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
	temp->parent=node1->parent;
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

    if (node->valor != NULL) {
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

