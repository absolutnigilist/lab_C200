#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include "myString.h"


MyString::MyString() {											//дефолтный конструктор
	p_Name = nullptr;
	std::cout << "MyString default constructor called" << std::endl;
};

MyString::MyString(const char* str_orig) {						//конструктор
	p_Name = new char[strlen(str_orig) + 1];
	strcpy(p_Name, str_orig);
	std::cout << "MyString constructor called" << std::endl;
};

MyString::~MyString() {											//деструктор
	if (p_Name) {
		delete[] p_Name;
		p_Name = nullptr;
		std::cout << "MyString destructor called" << std::endl;
	}
};

MyString::MyString(const MyString& other) {						//конструктор копирования
	p_Name = new char[strlen(other.p_Name) + 1];
	strcpy(p_Name, other.p_Name);
	std::cout << "MyString copy constructor called" << std::endl;
};
MyString::MyString(MyString&& other) {							//перемещающий конструктор копирования
	p_Name = other.p_Name;
	other.p_Name = nullptr;
	std::cout << "MyString move constructor called" << std::endl;
};
const char* MyString::GetString() const {						//метод извлекающий строку
	if (this)
	{
		if (p_Name)
			return p_Name;
		else
			return "Null_String";
	}
	else
		return "Null_Ptr";
};
char& MyString::operator[](int n) {
	if (n >= 0 && n < sizeof(strlen(p_Name)+1))
		return p_Name[n];
	std::cout << "MyString operator[] called" << std::endl;
};

MyString MyString::operator--(int) {
	MyString tmp(*this);
	for (size_t i = 0; i < p_Name[i]; i++)
	{
		if(isupper(p_Name[i]))
		p_Name[i]=static_cast<char>(tolower(p_Name[i]));
	}
	std::cout << "MyString postfix operator-- called" << std::endl;
	return tmp;
};

MyString& MyString::operator++() {
	for (size_t i = 0; i < p_Name[i]; i++)
	{
		if (islower(p_Name[i]))
			p_Name[i] = static_cast<char>(toupper(p_Name[i]));
	}
	std::cout << "MyString prefix operator++ called" << std::endl;
	return *this;
};

MyString& MyString::operator=(const MyString& other) {			//перегруженный оператор присваивания
	if (this != &other) {
		delete[] p_Name;
		p_Name = new char[strlen(other.p_Name) + 1];
		strcpy(p_Name, other.p_Name);
		std::cout << "MyString operator= called" << std::endl;
		return *this;
		
	}
	return *this;
};

MyString MyString::operator+(const MyString& other)const {		//перегруженный оператор сложения
	char* buffer = new char[(strlen(p_Name) + strlen(other.p_Name) + 1)];
	strcpy(buffer, p_Name);
	strcat(buffer, other.p_Name);
	MyString tmp(buffer);
	delete[]buffer;
	std::cout << "MyString operator+ called" << std::endl;
	return tmp;
};
MyString& MyString::operator+=(const MyString& other) {			//перегруженный оператор +=
	char* buffer = new char[strlen(p_Name) + strlen(other.p_Name) + 1];
	strcpy(buffer, p_Name);
	strcat(buffer, other.p_Name);
	delete[]p_Name;
	p_Name= new char[strlen(buffer)];
	strcpy(p_Name, buffer);
	delete[]buffer;
	std::cout << "MyString operator+= called" << std::endl;
	return *this;
};

std::ostream& operator<<(std::ostream& os, const MyString& string) {//перегруженный оператор потокового вывода
	os << "contents:"<< string.p_Name << std::endl;
	return os;
};
