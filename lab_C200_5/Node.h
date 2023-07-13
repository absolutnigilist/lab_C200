#pragma once
#include "Circle.h"


class Node
{
	Node* pPrev;
	Node* pNext;
	Circle m_Data;
public:
	Node();
	Node(Node* prev, const Circle& data);
	~Node();
	Node* Get_pPrev()const;
	Node* Get_pNext()const;
	Circle Get_m_Data()const;
	
	friend class List;

	 
	
};

