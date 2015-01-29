#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

typedef char* String;

#define YUP 1
#define NOPE 0

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

void test_createList_will_give_empty_list() {
	LinkedList list = createList();
	assert(list.head == NULL);
	assert(list.tail == NULL);
	assert(list.count == NULL);
}

void test_add_to_list_should_say_YUP_when_node_is_added_to_List() {
	LinkedList list = createList();
	Node *node = create_node(NULL);
	int doesCreated = add_to_list(&list, node);
	assert(doesCreated == YUP);
}

void test_new_node_should_be_added_at_the_end_of_list() {
	LinkedList list = createList();
	Node *node1 = create_node("I am node1");
	Node *node2 = create_node("I am node2");

	add_to_list(&list, node1);
	assert(list.tail == node1);
	add_to_list(&list, node2);
	assert(list.tail == node2);
}

