#pragma once
#include"Point.h"

class Circle
{
	Point center;
	int radius;
	
public:
	Circle();
	Circle(int x, int y, int rad);
	bool operator==(const Circle& other);
	~Circle();
};

