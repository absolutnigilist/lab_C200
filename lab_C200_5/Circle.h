#pragma once
#include"Point.h"

class Circle
{
	Point center;
	int m_radius;
	
public:
	Circle();
	Circle(int x, int y, int rad);
	bool operator==(const Circle& other)const;
	~Circle();
	int GetRadius()const;
	Point GetCenter()const;
	friend std::ostream& operator<<(std::ostream& os, const Circle& other);
	friend std::istream& operator>>(std::istream& in, Circle& other);
};

