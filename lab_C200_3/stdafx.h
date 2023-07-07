#pragma once
#include<iostream>


class Point
{//лишние методы
	int m_x;
	int m_y;
public:
	Point();																//конструктор по умолчанию
	Point(int x, int y);													//конструктор с параметрами
	//Point (const Point& other);												//конструктор копирования
	Point& operator+=(const Point& other);									//перегруженный оператор сложения присваивания	
	Point& operator+=(int val);												//перегруженный оператор сложения присваивания
	Point operator+(int val)const;											//перегруженный опреатор сложения
	Point operator+(const Point& other)const;								//перегруженный оператор для сложения двух классов
	Point& operator-=(Point& other);										//перегруженный оператор вычитания присваивания
	Point& operator-=(int val);												//перегруженный оператор вычитания присваивания
	Point operator-(int val) const;											//перегруженный оператор вычитания
	Point operator-(const Point& other);									//перегруженный оператор вычитания
	//Point& operator=(const Point& other);									//перегруженный оператор присваивания
	const Point& operator+()const;											//перегруженный унарный оператор+
	
	~Point();																//деструктор

	int GetPoint_m_x()const;
	int GetPoint_m_y()const;
	void SetPoint();

	friend Point operator+(int val, const Point& other);					//перегруженный с помощью глобальной функции оператор сложения
	friend Point operator-(int val, const Point& other);					//перегруженный с помощью ГФ оператор вычитания
	friend Point operator-(const Point& other);								//перегруженный с помощью ГФ опреатор-
	friend std::ostream& operator<<(std::ostream& os, const Point& other);
	
	

};

