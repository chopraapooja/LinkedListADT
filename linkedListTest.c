#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

typedef char* String;

#define YUP 1
#define NOPE 0
#define NODE_COUNT 6

LinkedList stringList, numberList;
Node *nodes[NODE_COUNT];
int numbers[] = {1,2,3,4,5};

void increment(int *num){
	*num++; 
}

void setup() {
	nodes[0] = create_node("I am node1");
	nodes[1] = create_node("I am node2");
	nodes[2] = create_node("I am Last node");

	stringList = createList();

	add_to_list(&stringList, nodes[0]);
	add_to_list(&stringList, nodes[1]);	
	add_to_list(&stringList, nodes[2]);
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
	assert(get_first_element(stringList) == "I am node1");
}

void test_first_element_and_last_element_of_list_should_be_same_in_one_node_list() {
	LinkedList list = createList();
	Node *node = create_node("I am the first node");
	
	add_to_list(&list, node);
	assert(get_first_element(list) == get_last_element(list));
}

void test_first_element_of_empty_list_should_be_NULL() {
	LinkedList list = createList();
	assert(get_first_element(list) == NULL);
}

void test_last_element_of_empty_list_should_be_NULL() {
	LinkedList list = createList();
	assert(get_last_element(list) == NULL);
}

void test_get_last_element_should_give_data_of_tail_node() {
	assert(get_last_element(stringList) == "I am Last node");
}

void test_getElementAt_should_give_data_of_node_at_provided_index(){
	assert(getElementAt(stringList,0) == "I am node1");
	assert(getElementAt(stringList,1) == "I am node2");
	assert(getElementAt(stringList,2) == "I am Last node");
}

void test_getElementAt_should_give_NULL_when_index_is_invalid(){
	assert(getElementAt(stringList,3) == NULL);
	assert(getElementAt(stringList,-1) == NULL);
}

void test_asArray() {
	String *str;
	int len_of_array = asArray(stringList,&str);
	assert(len_of_array == 3);
	assert(str[0] == "I am node1");
	assert(str[1] == "I am node2");
	assert(str[2] == "I am Last node");
}

void test_deleteElementAt_the_middle() {
	String deletedElement = deleteElementAt(&stringList, 1);
	assert(deletedElement == "I am node2");
	assert(stringList.head->next == nodes[2]);	
}

void test_deleteElementAt_the_beginning() {
	String deletedElement = deleteElementAt(&stringList, 0);
	assert(deletedElement == "I am node1");
	assert(stringList.head == nodes[1]);
}

void test_deleteElementAt_the_end() {
	String deletedElement = deleteElementAt(&stringList, 2);
	assert(deletedElement == "I am Last node");
	assert(stringList.tail == nodes[1]);
}

void test_deleteElementAt_the_emptyList() {
	String deletedElement = deleteElementAt(&stringList, 3);
	assert(deletedElement == NULL);
}

void test_delete_only_element_in_the_list() {
	LinkedList list = createList();
	String deletedElement;

	add_to_list(&list, nodes[0]);
	deletedElement = deleteElementAt(&list, 0);
	assert(deletedElement == "I am node1");
	assert(list.head == NULL);	
	assert(list.tail == NULL);	
}