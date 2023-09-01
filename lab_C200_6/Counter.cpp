#define _CRT_SECURE_NO_WARNINGS
#include "Counter.h"
#include <string.h>
#include <iostream>

Counter* Counter::m_pHead = nullptr;
unsigned int Counter::m_curCounters = 0;

Counter::Counter() {
	m_pStr = nullptr;
}
Counter::Counter(const char* string) :m_nOwners(1), pNext(nullptr) {

		m_pStr = new char[strlen(string) + 1];
		strcpy(m_pStr, string);

		if (m_curCounters == 0)
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
		}
		m_curCounters++;

}
Counter::~Counter() {
	delete[]m_pStr;
}
void Counter::AddOwnner() {
	m_nOwners++;
}
void Counter::RemoveOwner() {
	m_nOwners--;
	if (m_nOwners == 0)
	{
		if (this == m_pHead)
		{
			m_pHead == pNext;
		}
		else
		{
			Counter* prev = m_pHead;
			while (prev != nullptr && prev->pNext != this)
			{
				prev = prev->pNext;
			}
			if (prev != nullptr)
			{
				prev->pNext = this->pNext;
			}
		}
		delete this;
		m_curCounters--;
	}
}
char* Counter::return_m_pStr() {
	return m_pStr;
}
std::ostream& operator<<(std::ostream& os, const Counter& other) {
	
	os << other.m_pStr;
	return os;
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