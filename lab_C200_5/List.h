#pragma once
#include "Node.h"

class List
{
	Node Head;
	Node Tail;
	size_t m_size;
public:
	List();
	~List();
	void AddFirst(const Circle& data);
	void AddLast(const Circle& data);
	bool RemoveFirst(const Circle& data);
	int RemoveAll(const Circle& data);
	void MakeEmpty();
};

