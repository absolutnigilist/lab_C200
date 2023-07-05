#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "myString.h"

MyString::MyString() {										//дефолтный конструктор
	m_pStr = nullptr;
};
// Определение конструктора.
MyString::MyString(const char* string_orig) {				//конструктор
	m_pStr = new char[strlen(string_orig) + 1];
	strcpy(m_pStr, string_orig);
};

// Определение деструктора.
MyString::~MyString() {											//деструктор
	if (m_pStr) {
		delete[] m_pStr;
		m_pStr = nullptr;
	}
};

MyString::MyString(const MyString& other) {						//конструктор копирования
	if (other.m_pStr != 0) {
	m_pStr = new char[strlen(other.m_pStr) + 1];
	strcpy(m_pStr, other.m_pStr);
	}
	else
		m_pStr = nullptr;
};

const char* MyString::GetString() const {						// метод извлекающий содержимое строки
	return m_pStr;
};

void MyString::SetNewString(const char* other) {
	delete[]m_pStr;
	m_pStr = new char[strlen(other) + 1];
	strcpy(m_pStr, other);
};

