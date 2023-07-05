#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "myString.h"

MyString::MyString() {										//��������� �����������
	m_pStr = nullptr;
};
// ����������� ������������.
MyString::MyString(const char* string_orig) {				//�����������
	m_pStr = new char[strlen(string_orig) + 1];
	strcpy(m_pStr, string_orig);
};

// ����������� �����������.
MyString::~MyString() {											//����������
	if (m_pStr) {
		delete[] m_pStr;
		m_pStr = nullptr;
	}
};

MyString::MyString(const MyString& other) {						//����������� �����������
	if (other.m_pStr != 0) {
	m_pStr = new char[strlen(other.m_pStr) + 1];
	strcpy(m_pStr, other.m_pStr);
	}
	else
		m_pStr = nullptr;
};

const char* MyString::GetString() const {						// ����� ����������� ���������� ������
	return m_pStr;
};

void MyString::SetNewString(const char* other) {
	delete[]m_pStr;
	m_pStr = new char[strlen(other) + 1];
	strcpy(m_pStr, other);
};

