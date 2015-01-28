#include <stdlib.h>
#include "linkedList.h"

Node * create_node(void *data) {
	Node *n = malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	return n;
}

int parseInt(void *ref){
	return *(int*)(ref);
}

char* parseString(void *ref){
	return *(char**)(ref);
}



