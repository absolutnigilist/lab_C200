#include "Circle.h"

Circle::Circle() {}

Circle::Circle(int x, int y, int rad) :center(Point(x, y)), radius(rad) {}

bool Circle::operator==(const Circle& other){
	return ((center == other.center) && (radius == other.radius));
}



Circle::~Circle() {}
