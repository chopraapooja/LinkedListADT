#include <stdlib.h>
#include "linkedList.h"

#define DONE 1

Node* create_node(void *data) {
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

int add_to_list(LinkedList *list,Node *node) {
	if(list->tail == NULL) {
		list->head = node;
		list->tail = node;
	}
	list->tail->next = node;
	list->tail = node;	
	list->count++; 
	return DONE;
}

int parseInt(void *ref){
	return *(int*)(ref);
}

char* parseString(void *ref){
	return *(char**)(ref);
}



