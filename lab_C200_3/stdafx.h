#pragma once
#include<iostream>


class Point
{//������ ������
	int m_x;
	int m_y;
public:
	Point();																//����������� �� ���������
	Point(int x, int y);													//����������� � �����������
	//Point (const Point& other);												//����������� �����������
	Point& operator+=(const Point& other);									//������������� �������� �������� ������������	
	Point& operator+=(int val);												//������������� �������� �������� ������������
	Point operator+(int val)const;											//������������� �������� ��������
	Point operator+(const Point& other)const;								//������������� �������� ��� �������� ���� �������
	Point& operator-=(Point& other);										//������������� �������� ��������� ������������
	Point& operator-=(int val);												//������������� �������� ��������� ������������
	Point operator-(int val) const;											//������������� �������� ���������
	Point operator-(const Point& other);									//������������� �������� ���������
	//Point& operator=(const Point& other);									//������������� �������� ������������
	const Point& operator+()const;											//������������� ������� ��������+
	
	~Point();																//����������

	int GetPoint_m_x()const;
	int GetPoint_m_y()const;
	void SetPoint();

	friend Point operator+(int val, const Point& other);					//������������� � ������� ���������� ������� �������� ��������
	friend Point operator-(int val, const Point& other);					//������������� � ������� �� �������� ���������
	friend Point operator-(const Point& other);								//������������� � ������� �� ��������-
	friend std::ostream& operator<<(std::ostream& os, const Point& other);
	
	

};

