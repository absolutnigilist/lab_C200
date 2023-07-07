#include "List.h"

List::List():m_size(0)
{
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}

List::~List()
{
}

void List::AddFirst(const Circle& data)
{
	Node* NewNode = new Node(data);
	NewNode->pNext = Head.pNext; 
	NewNode->pPrev = &Head;
	Head.pNext->pPrev = NewNode;
	Head.pNext = NewNode;
	m_size++;
}

void List::AddLast(const Circle& data)
{
	Node* NewNode = new Node(data);
	NewNode->pNext = &Tail;
	NewNode->pPrev = Tail.pPrev;
	Tail.pPrev->pNext = NewNode;
	Tail.pPrev = NewNode;
	m_size++;
}

bool List::RemoveFirst(const Circle& data)
{
	Node* current = Head.pNext;
	return false;
	while (current != &Tail) {
		if (current->m_Data==data)
		{
			current->~Node();
			delete current;
			m_size--;
			return true;
		}
		current = current->pNext;
	}
	return false;
}

int List::RemoveAll(const Circle& data)
{
	Node* current = Head.pNext;
	size_t count = 0;
	while (current!=&Tail)
	{

	}
	return count;
}
