#include "Point.h"

Point::Point():m_x(0),m_y(0) {};

Point::Point(int x, int y) :m_x(x), m_y(y) {}

bool Point::operator==(const Point& other)const
{
	return (m_x == other.m_x && m_y == other.m_y);
	   
}

int Point::Get_m_x() const
{
	return m_x;
}

int Point::Get_m_y() const
{
	return m_y;
}

Point::~Point() {}

std::ostream& operator<<(std::ostream& os, const Point& other) {
	
	os << "x: " << other.m_x<<" " << "y: " << other.m_y;
	return os;
	
}

std::istream& operator>>(std::istream& in, Point& other)
{
	in >> other.m_x >> other.m_y;
	return in;
}
