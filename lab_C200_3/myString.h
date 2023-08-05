#pragma once
#include<iostream>

class MyString {
	char* p_Name;
public:
	MyString();																	//дефолтный окнструктор
	explicit MyString(const char* str_orig);									//конструктор с параметрами
	~MyString();																//деструктор
	MyString(const MyString& other);											//конструктор копирования
	MyString(MyString&& other);													//перемещающий конструктор копирования
	MyString& operator=(const MyString& other);									//перегруженный оператор присваивания
	MyString& operator=(const char* string);									//перегруженный оператор присваивания
	MyString& operator=(MyString&& other);										//перегруженный оператор присваивания
	MyString operator+(const MyString& other)const;								//перегруженный оператор сложения
	MyString& operator+=(const MyString& other);								//перегруженный оператор +=
	const char* GetString() const;												//метод извлекающий строку
	MyString operator--(int);													//перегруженный оператор постфиксного декремента
	MyString& operator++();														//перегруженный оператор префиксного инкримента
	char& operator[](int n);
	friend std::ostream& operator<<(std::ostream& os, const MyString& string);	//перегруженный с помощью ГФ оператор <<
};