#pragma once
#include "Pair.h"
class Base
{
	size_t count;
	size_t capacity;
	Pair* pBase;
public:
	Base();
	~Base();
	Base(const Base& other);
	Base(Base&& other);
	Base& operator=(const Base& other);
	Base& operator=(Base&& other);
	MyData& operator[](const char* k);
	int deletePair(const char* key);
	friend std::ostream& operator<<(std::ostream& os, const Base& bd);
};