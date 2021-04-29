//Thayna Gomes da Silva TIA:32092229
//Claudionor Domingues da Silva TIA:32086784
struct Node
{
	int data;
	Node* next;
};

struct LinkedList
{
	int count;
	Node* head;
	Node* tail;
};

LinkedList* Create();

void Destroy(LinkedList* list);

void Insert(LinkedList* list, int elem);

void Append(LinkedList* list, int elem);

Node* RemoveHead(LinkedList* list);

Node* RemoveTail(LinkedList* list);

Node* RemoveNode(LinkedList* list, int value);

Node* GetHead(LinkedList* list);

Node* GetTail(LinkedList* list);

Node* GetNode(LinkedList* list, int value);

int Count(LinkedList* list);

bool IsEmpty(const LinkedList* list);

void Clear(LinkedList* list);


void DestroyNode(Node* node);