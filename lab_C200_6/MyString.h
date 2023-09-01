#pragma once
#include "Counter.h"
#include <iostream>


class MyString
{
	Counter* m_pMyCounter;
public:
	MyString();
	MyString(const char* string);
	MyString(const MyString&);
	~MyString();
	MyString& operator=(const MyString&);
	bool operator==(const MyString& other);
	friend std::ostream& operator<<(std::ostream& os, const MyString& other);

	static void print();
	static void changeCase();
	static void printAlph();
	friend class Counter;
};
