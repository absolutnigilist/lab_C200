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

WEEKDAY operator+(WEEKDAY wd, int days) {							//проверка на отрицательное значение инт
	int result=(static_cast<int>(wd) + days) % 7;
	if (result >= 0){
		result += 7;
	}
	return static_cast<WEEKDAY>(result);
};
WEEKDAY& operator+=(WEEKDAY& wd, int days) {
	wd = wd + days;
	return wd;
}; 
std::ostream& operator<<(std::ostream& os, const WEEKDAY& wd) {		//допили
	if (wd >= 1 && wd <= 7) {
		const char* ar[] = { "monday","tueday","wednsday","thursday","friday","saturday","sunday" };
		std::cout << ar[wd];
	}
	else
		std::cout << "Incorrect val";
	return os;
}