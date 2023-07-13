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
	List(const List& other);
	List(List&& other);
	List& operator=(const List& other);
	List& operator=(List&& other);
	void AddFirst(const Circle& data);
	void AddLast(const Circle& data);
	bool RemoveFirst(const Circle& data);
	int RemoveAll(const Circle& data);
	void MakeEmpty();
	void ListSort();
	friend std::ostream& operator<<(std::ostream& os, const List& other);
	friend std::istream& operator>>(std::istream& in, List& other);
	void WriteToFile(const std::string& filename);
	void ReadFromFile(const std::string& filename);
};


