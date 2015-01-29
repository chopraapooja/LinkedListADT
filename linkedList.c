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
	if(!node) return 0;
	if(list->tail == NULL) {
		list->head = node;
		list->tail = node;
	} else{
		list->tail->next = node;
		list->tail = node;
	}
	list->count++; 
	return DONE;
}

void* get_first_element(LinkedList list) {
	if(!list.head) return NULL;
	return list.head->data;
}

void* get_last_element(LinkedList list) {
	if(!list.head) return NULL;
	return list.tail->data;
}

int parseInt(void *ref){
	return *(int*)(ref);
}

char* parseString(void *ref){
	return *(char**)(ref);
}

void traverse(LinkedList list, void (*operation)(void *data)) {
	Node *walker = list.head;
	while(!walker){	operation(walker->data); }
}

void* getElementAt(LinkedList list, int index) {
	Node *walker = list.head;
	int i;
	if(index >= list.count || index < 0) return NULL;
	for (i = 0; i < index; ++i) {
		walker = walker->next;
	}
	return walker->data;
}


