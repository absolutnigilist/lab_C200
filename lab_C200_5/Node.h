#pragma once
#include "Circle.h"


class Node
{
	Node* pPrev;
	Node* pNext;
	Circle m_Data;
public:
	Node();
	Node(const Circle& data);
	~Node();
	friend class List;
};

