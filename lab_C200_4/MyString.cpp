#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#define	  stop __asm nop

MyString::MyString() {												//конструктор по умолчанию
	p_Name = nullptr;
};
MyString::MyString(const char* string_other) {						//конструктор с параметрами
	p_Name = new char[strlen(string_other) + 1];
	strcpy(p_Name, string_other);
};
MyString::~MyString() {												//деструктор
	if (p_Name)
	{
		delete[]p_Name;
		p_Name = nullptr;
	}
};
MyString::MyString(const MyString& other) {							//конструктор копирования
	if (other.p_Name != nullptr) {
		p_Name = new char[strlen(other.p_Name) + 1];
		strcpy(p_Name, other.p_Name);
	}
	else
		p_Name = nullptr;
};

MyString::MyString(MyString&& other) {								//перемещающий конструктор копирования
	p_Name = other.p_Name;
	other.p_Name = nullptr;
};

MyString& MyString::operator=(const MyString& other) {				//перегруженный методом оператор присваивания
	if (this != &other) {
		delete[]p_Name;
			if (other.p_Name != nullptr) {
			p_Name = new char[strlen(other.p_Name) + 1];
			strcpy(p_Name, other.p_Name);
		}
		else
			p_Name = nullptr;
	}
	return *this;
};
std::ostream& operator<<(std::ostream& os, const MyString& other) {//перегруженный ГФ оператор вывода в поток
	os << other.p_Name;
	return os;
};
bool MyString::operator==(const char* string_other)const {
	return strcmp(p_Name, string_other) == 0;
};

bool MyString::operator<(const MyString& other)const {
	return strcmp(p_Name, other.p_Name) < 0;
	std::cout << "MyString operator >& called" << std::endl;
};

bool MyString::operator<(const char* string_other) const {
	return strcmp(p_Name, string_other) < 0;
};

