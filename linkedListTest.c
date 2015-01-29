#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

typedef char* String;

#define YUP 1
#define NOPE 0

LinkedList sampleList;

void setup() {
	Node *node1 = create_node("I am node1");
	Node *node2 = create_node("I am node2");
	Node *node3 = create_node("I am Last node");
	sampleList = createList();
	add_to_list(&sampleList, node1);
	add_to_list(&sampleList, node2);	
	add_to_list(&sampleList, node3);		
}

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

void test_add_to_list_should_say_YUP_when_operation_is_successful() {
	LinkedList list = createList();
	Node *node = create_node(NULL);
	int doesCreated = add_to_list(&list, node);
	assert(doesCreated == YUP);
}

void test_add_to_list_should_say_NOPE_when_operation_is_unsuccessful() {
	LinkedList list = createList();
	int doesCreated = add_to_list(&list, NULL);
	assert(doesCreated == NOPE);
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

void test_adding_new_node_should_increment_count_of_nodes_in_list() {
	LinkedList list = createList();
	Node *node1 = create_node("I am node1");
	Node *node2 = create_node("I am node2");

	assert(list.count == 0);
	add_to_list(&list, node1);
	assert(list.count == 1);
	add_to_list(&list, node2);
	assert(list.count == 2);	
}

void test_adding_a_node_in_a_empty_list_should_update_both_the_head_and_tail_of_the_list() {
	LinkedList list = createList();
	Node *node = create_node("I am a new node");

	add_to_list(&list, node);
	assert(list.head == node);
	assert(list.tail == node);
}

void test_adding_a_node_in_a_nonEmpty_list_should_not_change_the_head_of_list() {
	Node *node1 = create_node("I am node1");
	Node *node2 = create_node("I am node2");
	LinkedList list = {node1, node1, 1};

	add_to_list(&list, node2);
	assert(list.head == node1);
}

void test_a_node_should_be_accessble_through_the_front_node_in_a_list() {
	LinkedList list = createList();
	Node *node1 = create_node("I am node1");
	Node *node2 = create_node("I am node2");

	add_to_list(&list, node1);
	add_to_list(&list, node2);
	assert(list.head->next == node2);	
}

void test_next_node_pointer_of_last_node_in_the_list_should_be_NULL() {
	LinkedList list = createList();
	Node *node1 = create_node("I am node1");
	Node *node2 = create_node("I am node2");

	add_to_list(&list, node1);
	assert(list.head->next == NULL);
	add_to_list(&list, node2);
	assert(((Node*)list.head->next)->next == NULL);
}

void test_get_first_element_should_give_data_of_head_node() {
	assert(get_first_element(sampleList) == "I am node1");
}

void test_get_last_element_should_give_data_of_tail_node() {
	assert(get_last_element(sampleList) == "I am Last node");
}