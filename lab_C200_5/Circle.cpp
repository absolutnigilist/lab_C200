#include "Circle.h"

Circle::Circle(): m_radius(1){}

Circle::Circle(int x, int y, int rad) :center(Point(x, y)), m_radius(rad) {}

bool Circle::operator==(const Circle& other){
	return ((center == other.center) && (m_radius == other.m_radius));
}



Circle::~Circle() {}

int Circle::GetRadius()const
{
	return m_radius;
}

Point Circle::GetCenter() const
{
	return center;
}

std::ostream& operator<<(std::ostream& os, const Circle& other)
{
	os << "Center:  " << other.center<<" " << "Radius: " << other.m_radius << std::endl;
	return os;
}

std::istream& operator>>(std::istream& in, Circle& other)
{
	in >> other.center >> other.m_radius;
	return in;
}
