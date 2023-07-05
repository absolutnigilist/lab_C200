#define _CRT_SECURE_NO_WARNINGS
#include "header.h"

MyString::MyString() {									//дефолтный конструктор
	p_Name = nullptr;
};

MyString::MyString(const char* str_orig) {				//конструктор
	p_Name = new char[strlen(str_orig)+1];
	strcpy(p_Name, str_orig);
};

MyString::~MyString() {									//деструктор
	if (p_Name) {
		delete[] p_Name;
		p_Name = nullptr;
	}
};								

MyString::MyString(const MyString& other) {				//конструктор копирования
	p_Name = new char[strlen(other.p_Name) + 1];
	strcpy(p_Name, other.p_Name);
};
MyString::MyString(MyString&& other) {					//перемещающий конструктор копирования
	p_Name = other.p_Name;
	other.p_Name = nullptr;
	
};
const char* MyString::GetString() const{				//метод извлекающий строку
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

MyString& MyString::operator=(const MyString& other) {
	if (this != &other) {
		delete[] p_Name;
		p_Name = new char[strlen(other.p_Name) + 1];
		strcpy(p_Name, other.p_Name);
		return *this;
		std::cout << "MyString operator= called" << std::endl;
	}
	return *this;
};

MyString MyString::operator+(const MyString& other)const{
	
	char* buffer = new char[(strlen(p_Name) + strlen(other.p_Name) + 1)];
	strcpy(buffer, p_Name);
	strcat(buffer, other.p_Name);
	MyString tmp(buffer);
	delete[]buffer;
	std::cout << "MyString operator+ called" << std::endl;
	return tmp;
};

Shape::Shape(){
	m_color = RED;
	std::cout << "Shape default constructor called" << std::endl;
}

Shape::Shape(COLOR c) {
	m_color = c;
	std::cout << "Shape constructor called" << std::endl;
};

Shape::Shape(const Shape& other) {
	m_color = other.m_color;
	std::cout << "Shape copy constructor called" << std::endl;
};

Shape::~Shape() {
	std::cout << "Now I am in Shape's destructor!" << std::endl;
};

void Shape::WhereAmI()const {
	std::cout << "Now I am in class Shape" << std::endl;
};

void Shape::Inflate(int) {
	std::cout << "Shape Inflate method called" << std::endl;
};

Rect::Rect() {
	length = 2; 
	height = 2;
	std::cout << "Rect default constructor called" << std::endl;
	};

Rect::Rect(int val_lenght, int val_height, COLOR c):Shape(c){
	length = val_lenght;
	height = val_height;
	std::cout << "Rect constructor called" << std::endl;
};

Rect::Rect(const Rect& other):Shape(other) {
	length = other.length;
	height = other.height;
	std::cout << "Rect copy constructor called" << std::endl;
};

Rect::~Rect() {
	std::cout << "Now I am in Rect's destructor!" << std::endl;
};

void Rect::WhereAmI()const {
	std::cout << "Now I am in class Rect" << std::endl;
};

void Rect::Inflate(int) {
	std::cout << "Rect Inflate method called" << std::endl;
};

void Rect::GetRect(int& val_lenght, int& val_height)const {
	val_lenght = length;
	val_height = height;
};

Circle::Circle() {
	radius = 1;
	std::cout << "Circle default constructor called" << std::endl;
};
Circle::Circle(int val_radius, COLOR c):Shape(c){
	radius = val_radius;
	std::cout << "Circle constructor called" << std::endl;
};

Circle::Circle(const Circle& other):Shape(other) {
	radius = other.radius;
	std::cout << "Circle copy constructor called" << std::endl;
};

Circle::Circle(const Rect & other) :Shape(other) {
	int tmp1, tmp2;
	other.GetRect(tmp1,tmp2);
	radius = (tmp1 < tmp2) ? tmp1:tmp2;
	std::cout << "Circle copy constructor from Rect called" << std::endl;
};
Circle::~Circle() {
	std::cout << "Now I am in Circle's destructor!" << std::endl;
};

void Circle::WhereAmI() {
	std::cout << "Now I am in class Circle" << std::endl;
};

void Circle::Inflate(int) {
	std::cout << "Circle Inflate method called" << std::endl;
};

void Shape::WhereAmIVirtual()const {
	std::cout << "Now I am in class Shape" << std::endl;
};

void Rect::WhereAmIVirtual()const {
	std::cout << "Now I am in class Rect" << std::endl;
};

void Circle::WhereAmIVirtual()const {
	std::cout << "Now I am in class Circle" << std::endl;
};

MyString StringСoncatenation(const char* string, ...) {
	/*const char** pointer = &string;
	int lenght = 0;
	while (*pointer)
	{
		lenght += strlen(*pointer);
		pointer++;
	}
	char* buffer = new char[lenght + 1];
	buffer[0] = 0;
	pointer = &string;
	while (*pointer)
	{
		strcat(buffer, *pointer);
		pointer++;
	}
	MyString tmp(buffer);
	delete[]buffer;
	return tmp;
};*/
	/*va_list pointer;
	va_start(pointer, string);
	MyString res(string);
	const char* current = va_arg(pointer, const char*);
	while (current) {
		res = res + MyString(current);
		current = va_arg(pointer, const char*);
	}
	va_end(pointer);
	return res;*/
	va_list pointer;
	va_start(pointer, string);
	int lenght = strlen(string);
	while (*pointer != 0) {
		lenght += strlen(va_arg(pointer, const char*));
	}
	char* buffer = new char[lenght + 1];
	buffer[0] = 0;
	va_start(pointer, string);
	strcat(buffer, string);
	while (*pointer != 0) {
		strcat(buffer,(va_arg(pointer, const char*)));
	}
	MyString tmp(buffer);
	delete[]buffer;
	return tmp;
};