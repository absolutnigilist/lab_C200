#pragma once
#include "MyData.h"

class Pair
{
	MyString key;
	MyData data;
public:
	Pair();
	Pair(const char* k, const MyData& d);
	~Pair();
	Pair(const Pair& other);
	Pair(Pair&& other);
	Pair& operator=(const Pair& other);
	Pair& operator=(Pair& other);
	bool operator==(const char* k) const;
	friend class Base;
	friend std::ostream& operator<<(std::ostream& os, const Pair& other);
};
