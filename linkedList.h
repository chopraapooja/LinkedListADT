typedef struct Node Node;

struct Node{
	void *data;
	void *next;
};

struct linkedList
{
	Node *head;
	Node *tail;
	int count;
};

Node * create_node(void *data);
int parseInt(void *ref);
char* parseString(void *ref);