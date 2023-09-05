#define _CRT_SECURE_NO_WARNINGS
#include "Counter.h"
#include <string.h>
#include <iostream>

Counter* Counter::m_pHead = nullptr;
unsigned int Counter::m_curCounters = 0;


Counter::Counter(const char* string) :m_nOwners(1), pNext(nullptr) {

	m_pStr = new char[strlen(string) + 1];
	strcpy(m_pStr, string);

	pNext = m_pHead;
	m_pHead = this;

	/*if (m_curCounters == 0)
	{
		m_pHead = this;
	}
	else
	{
		Counter* last = m_pHead;
		while (last->pNext != nullptr)
		{
			last = last->pNext;
		}
		last->pNext = this;
	}*/
	m_curCounters++;

}
Counter::~Counter() {
	delete[]m_pStr;

	if (this == m_pHead)
	{
		m_pHead = pNext;
	}
	else
	{
		Counter* prev = m_pHead;
		while (prev->pNext != this)
		{
			prev = prev->pNext;
		}
				
		prev->pNext = this->pNext;
		
	}
	m_curCounters--;
}
void Counter::AddOwnner() {
	m_nOwners++;
}
void Counter::RemoveOwner() {
	m_nOwners--;
	if (m_nOwners == 0)
	{
		delete this;
	};


}
const char* Counter::Set_m_pStr()const {
	return m_pStr;
}
std::ostream& operator<<(std::ostream& os, const Counter& other) {

	os << other.m_pStr;
	return os;
}
Counter* Counter::Find(const char* string) {
	Counter* current = m_pHead;
	while (current != nullptr)
	{
		if (strcmp(current->m_pStr, string) == 0)
		{
			current->m_nOwners++;
			return current;
		}

		current = current->pNext;

	}
	return new Counter(string);
}
void Counter::PrintAllStrings() {
	Counter* current = m_pHead;
	while (current != nullptr)
	{
		std::cout << current->m_pStr << "(" << current->m_nOwners << "users)" << std::endl;
		current = current->pNext;
	}
}
void Counter::ChangeCaseAllStrings() {

	Counter* current = m_pHead;
	while (current != nullptr)
	{
		char* str = current->m_pStr;
		while (*str != '\0')
		{
			if (islower(*str))
			{
				*str = toupper(*str);
			}
			else if (isupper(*str))
			{
				*str = tolower(*str);
			}
			str++;
		}
		current = current->pNext;
	}
}
void Counter::PrintStringsAlphabetically() {
	Counter* current = m_pHead;
	while (current != nullptr)
	{
		Counter* min_counter = current;
		Counter* tmp = current->pNext;
		while (tmp != nullptr)
		{
			if (strcmp(tmp->m_pStr, min_counter->m_pStr) < 0)
			{
				min_counter = tmp;
			}
			tmp = tmp->pNext;
		}
		std::cout << min_counter->m_pStr << std::endl;
		current = min_counter->pNext;
	}
}