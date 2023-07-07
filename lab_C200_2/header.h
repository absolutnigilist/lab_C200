#pragma once
#include <tchar.h>
#include <iostream>
#include <stdarg.h.>
#include < cstring >
using namespace std;

class MyString {
	char* p_Name;
public:
	MyString();										//��������� �����������
	MyString(const char* str_orig);					//����������� � �����������
	~MyString();									//����������
	MyString(const MyString& other);				//����������� �����������
	MyString(MyString&& other);						//������������ ����������� �����������
	MyString& operator=(const MyString& other);		//������������� �������� ������������
	MyString operator+(const MyString& other)const;	//������������� �������� ��������
	const char* GetString() const;					//����� ����������� ������
};

enum COLOR { RED=1, GREEN=2, BLUE=3 };

class Shape{

protected:
	COLOR m_color;
public:
	Shape();
	Shape(COLOR c);
	//Shape(const Shape& other);
	virtual ~Shape();
	void WhereAmI()const;
	virtual void WhereAmIVirtual()const;
	virtual void Inflate(int);
private:

};

class Rect :public Shape {
	int length;
	int height;
	
public:
	Rect();
	Rect(int val_lenght, int val_height, COLOR c);
	//Rect(const Rect& other);
	virtual ~Rect();
	void WhereAmI() const;
	virtual void WhereAmIVirtual()const;
	virtual void Inflate(int);
	void GetRect(int& val_lenght, int& val_height)const;
};

class Circle :public Shape {
	int radius;
public:
	Circle();
	Circle(int val_radius, COLOR c);
	//Circle(const Circle& other);
	Circle(const Rect& other);
	virtual ~Circle();
	void WhereAmI();
	virtual void WhereAmIVirtual()const;
	virtual void Inflate(int);
};

MyString String�oncatenation(const char* string, ...);