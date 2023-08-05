# include"stdafx.h"

Point::Point() {														//конструктор по умолчанию
	m_x = 0;
	m_y = 0;
};

Point::Point(int x, int y) {											//конструктор с параметрами
	m_x = x;
	m_y = y;
};
//Point::Point(const Point& other) {									//конструктор копирования
//	m_x = other.m_x;
//	m_y = other.m_y;
//};

Point& Point::operator+=(const Point& other) {							//перегруженный оператор сложения присваивания
	m_x += other.m_x;
	m_y += other.m_y; 
	std::cout << "operator+=(const Point& other)" << std::endl;
	return *this;
};
Point& Point::operator+=(int val) {										//перегруженный оператор сложения присваивания присваивания принимающий инт
	m_x += val;
	m_y += val;
	std::cout << "operator+=(int val)" << std::endl;
	return *this;
};
Point Point::operator+(int val)const {									//перегруженный оператор сложения
	std::cout << "operator+(int val)const" << std::endl;
	return Point (m_x + val, m_y + val);
};

Point Point::operator+(const Point& other)const {						//перегруженный с помощью ГФ оператор сложения двух классов
	std::cout << "operator+(const Point& other)" << std::endl;
	return Point(m_x + other.m_x, m_y + other.m_y);
};

const Point& Point::operator+() const{									//перегруженный унарный оператор+
	std::cout << "unary operator+()" << std::endl;
	return *this;
};

Point::~Point() {};														//деструктор

int Point::GetPoint_m_x()const {
	return m_x;
};
int Point::GetPoint_m_y()const {
	return m_y;
};

void Point::SetPoint() {
	m_x=-m_x;
	m_y=-m_y;
};

Point& Point::operator-=(Point& other) {								//перегруженный оператор вычитания присваивания
	m_x -= other.m_x;
	m_y -= other.m_y;
	std::cout << "operator-=(Point& other)" << std::endl;
	return *this;
};

Point& Point::operator-=(int val) {										//перегруженный оператор вычитания присваивания
	m_x -= val;
	m_y -= val;
	std::cout << "operator-=(int val)" << std::endl;
	return *this;

};				

Point Point::operator-(int val) const {									//перегруженный оператор вычитания
	std::cout << "operator-(int val)const" << std::endl;
	return Point(m_x - val, m_y - val);
};

Point Point::operator-(const Point& other){								//перегруженный оператор вычитания
	std::cout << "operator-(const Point& other)const" << std::endl;
	return Point(m_x - other.m_x, m_y - other.m_y);
};

//Point& Point::operator=(const Point& other) {							//перегруженный оператор присваивания 
//	m_x = other.m_x;
//	m_y = other.m_y;
//	std::cout << "operator=(const Point& other)" << std::endl;
//	return *this;
//};

Point operator+(int val, const Point& other){							//перегруженный с помощью ГФ оператор сложения инт+класса			
	std::cout << "operator+(int val, const Point& other)" << std::endl;
	return Point(other.GetPoint_m_x() + val, other.GetPoint_m_y()+val);
	//return other + val;
};
Point operator-(int val, const Point& other) {							//перегруженный с помощью ГФ оператор вычитания
	std::cout << "operator-(int val, const Point& other)" << std::endl;
	return Point(val - other.GetPoint_m_x(), val - other.GetPoint_m_y());
};

Point operator-(const Point& other) {										//перегруженный с помощью ГФ унарный оператор-
	std::cout << "unary operator-(const Point& other)" << std::endl;
	Point tmp(-other.m_x, -other.m_y);
	return tmp;
}
	
std::ostream& operator<<(std::ostream& os, const Point& other) {		//перегруженный оператор вывода в  поток
	os << "m_x=" << other.m_x <<", " << "m_y=" << other.m_y;
	return os;
}
