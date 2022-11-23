

#include "functions.h"




Node * newNode( token * val, char * s_type){
	Node * new = (Node *) malloc(sizeof(Node));
	if(val!=NULL){
	new->s_type = s_type;	
    new->valor=val->value;
    new->child = NULL;
    new->brother = NULL;
	new->parent=NULL;
	new->n_params=0;
	new->l=val->line;
	new->column=val->column;
	new->to_anote=0;
	
	new->anoted="";
	freeToken(val);
}
	else{
	new->s_type = s_type;	
    new->valor="";
    new->child = NULL;
    new->brother = NULL;
	new->parent=NULL;
	new->n_params=0;
	new->l=0;
	new->column=0;
	new->to_anote=0;
	new->anoted="";
		
	}
	
	

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

