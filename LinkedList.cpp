// Thayna Gomes da Silva TIA:32092229
//Claudionor Domingues da Silva TIA:32086784
#include "LinkedList.h"

LinkedList* Create() {
	LinkedList* list = new LinkedList;

	list->count = 0;
	list->head = nullptr;
	list->tail = nullptr;
	
	return list;
}

void Destroy(LinkedList *list) {

	Clear(list);
	delete list;
}

void Insert(LinkedList* list, int elem)
{

	Node* n = new Node;

	n->data = elem;
	n->next = GetHead(list);

	if (IsEmpty(list)) list->tail = n;

	list->head = n;

	++list->count;
}

void Append(LinkedList *list, int elem)
{
	Node* n = new Node;
	n->data = elem;
	n->next = nullptr;
	if (IsEmpty(list))
	{
		list->head = n; 
		list->tail = n;
	}
	else
	{
		list->tail->next = n;
		list->tail = n;
	}
	++list->count;
}

Node* RemoveHead(LinkedList *list) {

	Node* toRemove = list->head;
	if ((list->head) == (list->tail)){
		list->head = nullptr;
		list->tail = nullptr;
	}else{  
		list->head = list->head->next;
	}
	--list->count;
	return toRemove;
}

Node* RemoveTail(LinkedList* list)
{

	
	if ((list->head) == (list->tail))
	{

		return RemoveHead(list);
	}

	Node* toRemove = list->head;
	Node* previous = nullptr;
	while (toRemove != (list->tail))
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}
	previous->next = nullptr;
	list->tail = previous;
	--list->count;

	return toRemove;
}

Node* RemoveNode(LinkedList* list, int value) {
		
	Node* toRemove = list->head;
	Node* previous = nullptr;
	while (toRemove != nullptr && toRemove->data != value) {
		previous = toRemove;
		toRemove = toRemove->next;
	}
	if (toRemove == nullptr) return nullptr;
	if (toRemove == list->head) return RemoveHead(list);
	if (toRemove == list->tail) return RemoveTail(list);
	else {
		previous->next = toRemove->next;
		--list->count;
		return toRemove;
	}
}

Node* GetHead(LinkedList* list) {
	return list->head;
}

Node* GetTail(LinkedList* list) {
	return list->tail;
}

Node* GetNode(LinkedList* list, int value) {

	Node* toRemove = list->head;
	while (toRemove != nullptr) {
		if (toRemove->data == value) return toRemove;
		toRemove = toRemove->next;
	}
	return nullptr;
}

int Count(LinkedList* list){
	return list->count;
}

bool IsEmpty(const LinkedList* list) {
	return list->count == 0;
}

void Clear(LinkedList* list)
{

	Node* toRemove = list->head;
	Node* next = nullptr;
	while (toRemove != nullptr){
		next = toRemove->next;
		delete toRemove;
		toRemove = next;
		--list->count;
	}
}


void DestroyNode(Node* node)
{
	delete node;
}
