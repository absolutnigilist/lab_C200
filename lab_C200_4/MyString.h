#pragma once
#include <iostream>
#include <string>
#include <cstring>

class MyString
{
	char* p_Name;
public:
	MyString();																	//����������� �� ���������
	MyString(const char* string_other);											//����������� � �����������
	~MyString();																//����������
	MyString(const MyString& other);											//����������� �����������
	MyString(MyString&&);														//������������ ����������� �����������
	MyString & operator=(const MyString& other);								//������������� ������� �������� ������������
	friend std::ostream& operator<<(std::ostream& os, const MyString& other);	//������������� � ������� �� �������� <<
	bool operator==(const char* string_other)const;
};