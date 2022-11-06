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

void printTree(Node *root, int depth){
          if (root == NULL) {
            return ;
        }
        int i = 0;
        Node* aux;
        if (strcmp(root->node_type,"node_root")==0){
            printf("%s\n", root->s_type);
        }
        else {
            while (i < depth) {
                printf("..");
                i++;
            }
            if (strcmp(root->valor,"") != 0) {
                printf("%s(%s)\n", root->s_type, root->valor);
            }
            else {
                printf("%s\n", root->s_type);
            }
        }
        aux = root->child;
        while (aux != NULL) {
            Node* aux_free = aux;
            printTree(aux, depth+1);
            aux = aux->brother;
            free(aux_free->valor);
            free(aux_free->s_type);
            free(aux_free);
        }
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

