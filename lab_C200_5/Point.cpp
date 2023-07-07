#include "Point.h"

Point::Point() {};

Point::Point(int x = 0, int y = 0) :m_x(x), m_y(y) {}

bool Point::operator==(const Point& other)
{
	return (m_x == other.m_x && m_y == other.m_y);
	   
}

Point::~Point() {}