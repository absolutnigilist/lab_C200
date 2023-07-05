#pragma once
#include<iostream>

enum WEEKDAY
{
	MONDAY=1,
	TUESDAY=2,
	WEDNSDAY=3,
	THURSDAY=4,
	FRIDAY=5,
	SATURDAY=6,
	SUNDAY=7
};

WEEKDAY operator+(WEEKDAY wd, int days) {
	return static_cast<WEEKDAY>((static_cast<int>(wd) + days) % 7);
};
WEEKDAY& operator+=(WEEKDAY& wd, int days) {
	wd = wd + days;
	return wd;
};
std::ostream& operator<<(std::ostream& os, const WEEKDAY& wd) {
	switch (wd)
	{
	case 1:
		os << "monday";
		break;
	case 2:
		os << "tuesday";
		break;
	case 3:
		os << "wednsday";
		break;
	case 4:
		os << "thursday";
		break;
	case 5:
		os << "friday"; 
		break;
	case 6:
		os << "saturday";
		break;
	case 7:
		os << "sunday";
		break;
	default:
		os << "incorrect value";
		break;
	}
	return os;
}