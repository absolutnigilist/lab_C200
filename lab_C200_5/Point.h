#pragma once
#include <iostream>
#include <fstream>

class Point
{
	int m_x;
	int m_y;
public:
	Point();
	Point(int x, int y);
	bool operator==(const Point& other)const;
	int Get_m_x()const;
	int Get_m_y() const;
	~Point();
	friend std::ostream& operator<<(std::ostream& os, const Point& other);
	friend std::istream& operator>>(std::istream& in, Point& other);
		
};

