#pragma once
#include<iostream>

class Counter
{
	char* m_pStr;
	unsigned int m_nOwners;
	Counter* pNext;
	static Counter* m_pHead;
	static unsigned int m_curCounters;
	
public:
	
	Counter();
	Counter(const char* string);
	void AddOwnner();
	void RemoveOwner();
	char* return_m_pStr();
	friend std::ostream& operator<<(std::ostream& os, const Counter& other);
	~Counter();
	static void PrintAllStrings();
	static void ChangeCaseAllStrings();
	static void PrintStringsAlphabetically();
	friend class MyString;
};

