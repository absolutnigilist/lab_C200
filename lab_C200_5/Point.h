#pragma once

class Point
{
	int m_x;
	int m_y;
public:
	Point();
	Point(int x, int y);
	bool operator==(const Point& other);
	~Point();
};

