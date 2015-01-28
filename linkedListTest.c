#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

typedef char* String;

void test_nextNode_field_of_newly_created_node_should_be_null() {
	Node *n = create_node(NULL);
	assert(n->next == NULL);
	free(n);
}

void test_create_node_can_create_node_having_integer_data() {
	int i = 90;
	Node *n = create_node(&i);
	assert(parseInt(n->data) == 90);
	assert(n->next == NULL);
	free(n);
}

void test_create_node_can_create_node_having_string_data() {
	String s = "I am String";
	Node *n = create_node(&s);
	assert(parseString(n->data) == s);
	assert(n->next == NULL);
	free(n);
}