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
	
	
	Counter(const char* string);
	~Counter();
	void AddOwnner();
	void RemoveOwner();
	static Counter* Find(const char* string);
	const char* Set_m_pStr()const;
	friend std::ostream& operator<<(std::ostream& os, const Counter& other);
	
	static void PrintAllStrings();
	static void ChangeCaseAllStrings();
	static void PrintStringsAlphabetically();
	
};

