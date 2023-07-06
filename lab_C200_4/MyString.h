#pragma once
#include <iostream>
#include <string>
#include <cstring>

class MyString
{
	char* p_Name;
public:
	MyString();																	//конструктор по умолчанию
	MyString(const char* string_other);											//конструктор с параметарми
	~MyString();																//деструктор
	MyString(const MyString& other);											//конструктор копирования
	MyString(MyString&&);														//перемещающий конструктор копирования
	MyString& operator=(const MyString& other);									//перегруженный методом оператор присваивания
	friend std::ostream& operator<<(std::ostream& os, const MyString& other);	//перегруженный с помощью ГФ оператор <<
	bool operator==(const char* string_other)const;
	bool operator<(const MyString& other)const;
	bool operator<(const char* string_other) const;
};
