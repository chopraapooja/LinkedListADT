typedef struct Node Node;
typedef struct LinkedList LinkedList;

struct Node{
	void *data;
	void *next;
};

struct LinkedList
{
	Node *head;
	Node *tail;
	int count;
};

Node * create_node(void *data);
LinkedList createList(void);

int parseInt(void *ref);
char* parseString(void *ref);