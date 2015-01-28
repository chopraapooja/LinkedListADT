#include <stdlib.h>
#include "linkedList.h"

Node * create_node(void *data) {
	Node *n = malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	return n;
}

LinkedList createList(void) {
	LinkedList list;
	list.head = NULL;
	list.tail = NULL;
	list.count = 0;
	return list;
}

int parseInt(void *ref){
	return *(int*)(ref);
}

char* parseString(void *ref){
	return *(char**)(ref);
}



