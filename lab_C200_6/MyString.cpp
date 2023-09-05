#include "MyString.h"

MyString::MyString() {
	m_pMyCounter = nullptr;
}
MyString::MyString(const char* string) {
	if (string)
	{
		m_pMyCounter = m_pMyCounter->Find(string);
	}
	else
	{
		m_pMyCounter = nullptr;
	}
}
MyString::MyString(const MyString& other) {
	
	m_pMyCounter = other.m_pMyCounter;
	if (m_pMyCounter!=nullptr)
	{
		
		m_pMyCounter->AddOwnner();
	}
	
	
}
MyString::~MyString() {
	if (m_pMyCounter)
	{
		m_pMyCounter->RemoveOwner();
	}
}
MyString& MyString::operator=(const MyString& other) {
	if (m_pMyCounter!=other.m_pMyCounter)
	{
		if (m_pMyCounter)
		{
			m_pMyCounter->RemoveOwner();
		}
		
		m_pMyCounter=other.m_pMyCounter;
		if (m_pMyCounter)
		{
			m_pMyCounter->AddOwnner();
		}
		
	}
	return *this;
}

MyString::MyString(MyString&& other) {
	m_pMyCounter = other.m_pMyCounter;
	other.m_pMyCounter = nullptr;
}
MyString& MyString::operator=(MyString&& other) {
	if (m_pMyCounter!=other.m_pMyCounter)
	{
		if (m_pMyCounter)
		{
			m_pMyCounter->RemoveOwner();
		}
		m_pMyCounter = other.m_pMyCounter;
		other.m_pMyCounter = nullptr;
	}
	
	return *this;
}

std::ostream& operator<<(std::ostream& os, const MyString& other) {
	os << other.m_pMyCounter->Set_m_pStr();
		return os;
}
bool MyString::operator==(const MyString& other)const {
	return strcmp(m_pMyCounter->Set_m_pStr(), other.m_pMyCounter->Set_m_pStr()) == 0;
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
