#include "MyString.h"

MyString::MyString() {
	m_pMyCounter = new Counter();
}
MyString::MyString(const char* string) {
	if (string)
	{
		m_pMyCounter = new Counter(string);
		m_pMyCounter->AddOwnner();
	}
	else
	{
		m_pMyCounter = nullptr;
	}
}
MyString::MyString(const MyString& other) {
	if (other.m_pMyCounter!=nullptr)
	{
		m_pMyCounter = other.m_pMyCounter;
		m_pMyCounter->AddOwnner();
	}
	else
	{
		m_pMyCounter = nullptr;
	}
	
}
MyString::~MyString() {
	if (m_pMyCounter)
	{
		m_pMyCounter->RemoveOwner();
	}
}
MyString& MyString::operator=(const MyString& other) {
	if (this!=&other)
	{
		m_pMyCounter->RemoveOwner();
		m_pMyCounter=other.m_pMyCounter;
		m_pMyCounter->AddOwnner();
	}
	return *this;
}
std::ostream& operator<<(std::ostream& os, const MyString& other) {
	os << other.m_pMyCounter->return_m_pStr();
		return os;
}
bool MyString::operator==(const MyString& other) {
	return strcmp(m_pMyCounter->m_pStr, other.m_pMyCounter->m_pStr) == 0;
}

void MyString::print() {
	Counter::PrintAllStrings();
}
void MyString::changeCase() {
	Counter::ChangeCaseAllStrings();
}
void MyString::printAlph() {
	Counter::PrintStringsAlphabetically();
}
