#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#define	  stop __asm nop

MyString::MyString() {												//����������� �� ���������
	p_Name = nullptr;
};
MyString::MyString(const char* string_other) {						//����������� � �����������
	p_Name = new char[strlen(string_other) + 1];
	strcpy(p_Name, string_other);
};
MyString::~MyString() {												//����������
	if (p_Name)
	{
		delete[]p_Name;
		p_Name = nullptr;
	}
};
MyString::MyString(const MyString& other) {							//����������� �����������
	p_Name = new char[strlen(other.p_Name) + 1];
	strcpy(p_Name, other.p_Name);
};

MyString::MyString(MyString&& other) {								//������������ ����������� �����������
	p_Name = other.p_Name;
	other.p_Name = nullptr;
};

MyString& MyString::operator=(const MyString& other) {				//������������� ������� �������� ������������
	if (this != &other) {
		delete[]p_Name;
		p_Name = new char[strlen(other.p_Name) + 1];
		strcpy(p_Name, other.p_Name);
	}
	return *this;
};
std::ostream& operator<<(std::ostream& os, const MyString& other) {//������������� �� �������� ������ � �����
	os << other.p_Name;
	return os;
};
bool MyString::operator==(const char* string_other)const {
	return strcmp(p_Name, string_other) == 0;
};

bool MyString::operator>(const MyString& other)const {
	return strcmp(p_Name, other.p_Name) > 0;
	std::cout << "MyString operator >& called" << std::endl;
};

bool MyString::operator>(const char* string_other) const {
	return strcmp(p_Name, string_other) > 0;
	std::cout << "MyString operator >* called" << std::endl;
};

