#pragma once
#include<iostream>

class MyString {
	char* p_Name;
public:
	MyString();																	//��������� �����������
	explicit MyString(const char* str_orig);												//����������� � �����������
	~MyString();																//����������
	MyString(const MyString& other);											//����������� �����������
	MyString(MyString&& other);													//������������ ����������� �����������
	MyString& operator=(const MyString& other);									//������������� �������� ������������
	MyString& operator=(const char* string);									//������������� �������� ������������
	MyString& operator=(MyString&& other);										//������������� �������� ������������
	MyString operator+(const MyString& other)const;								//������������� �������� ��������
	MyString& operator+=(const MyString& other);								//������������� �������� +=
	const char* GetString() const;												//����� ����������� ������
	MyString operator--(int);													//������������� �������� ������������ ����������
	MyString& operator++();														//������������� �������� ����������� ����������
	char& operator[](int n);
	friend std::ostream& operator<<(std::ostream& os, const MyString& string);	//������������� � ������� �� �������� <<
};