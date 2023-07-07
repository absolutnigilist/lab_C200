# include"stdafx.h"

Point::Point() {														//����������� �� ���������
	m_x = 0;
	m_y = 0;
};

Point::Point(int x, int y) {											//����������� � �����������
	m_x = x;
	m_y = y;
};
//Point::Point(const Point& other) {										//����������� �����������
//	m_x = other.m_x;
//	m_y = other.m_y;
//};

Point& Point::operator+=(const Point& other) {							//������������� �������� �������� ������������
	m_x += other.m_x;
	m_y += other.m_y; 
	std::cout << "operator+=(const Point& other)" << std::endl;
	return *this;
};
Point& Point::operator+=(int val) {										//������������� �������� �������� ������������ ������������ ����������� ���
	m_x += val;
	m_y += val;
	std::cout << "operator+=(int val)" << std::endl;
	return *this;
};
Point Point::operator+(int val)const {									//������������� �������� ��������
	std::cout << "operator+(int val)const" << std::endl;
	return Point (m_x + val, m_y + val);
};

Point Point::operator+(const Point& other)const {						//������������� � ������� �� �������� �������� ���� �������
	std::cout << "operator+(const Point& other)" << std::endl;
	return Point(m_x + other.m_x, m_y + other.m_y);
};

const Point& Point::operator+() const{												//������������� ������� ��������+
	std::cout << "unary operator+()" << std::endl;
	return *this;
};

Point::~Point() {};														//����������

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

Point& Point::operator-=(Point& other) {								//������������� �������� ��������� ������������
	m_x -= other.m_x;
	m_y -= other.m_y;
	std::cout << "operator-=(Point& other)" << std::endl;
	return *this;
};

Point& Point::operator-=(int val) {										//������������� �������� ��������� ������������
	m_x -= val;
	m_y -= val;
	std::cout << "operator-=(int val)" << std::endl;
	return *this;

};				

Point Point::operator-(int val) const {									//������������� �������� ���������
	std::cout << "operator-(int val)const" << std::endl;
	return Point(m_x - val, m_y - val);
};

Point Point::operator-(const Point& other){								//������������� �������� ���������
	std::cout << "operator-(const Point& other)const" << std::endl;
	return Point(m_x - other.m_x, m_y - other.m_y);
};

//Point& Point::operator=(const Point& other) {							//������������� �������� ������������ 
//	m_x = other.m_x;
//	m_y = other.m_y;
//	std::cout << "operator=(const Point& other)" << std::endl;
//	return *this;
//};

Point operator+(int val, const Point& other){							//������������� � ������� �� �������� �������� ���+������			
	std::cout << "operator+(int val, const Point& other)" << std::endl;
	return Point(other.GetPoint_m_x() + val, other.GetPoint_m_y()+val);
	//return other + val;
};
Point operator-(int val, const Point& other) {							//������������� � ������� �� �������� ���������
	std::cout << "operator-(int val, const Point& other)" << std::endl;
	return Point(val - other.GetPoint_m_x(), val - other.GetPoint_m_y());
};

Point operator-(const Point& other) {										//������������� � ������� �� ������� ��������-
	std::cout << "unary operator-(const Point& other)" << std::endl;
	Point tmp(-other.m_x, -other.m_y);
	return tmp;
}
	
std::ostream& operator<<(std::ostream& os, const Point& other) {		//������������� �������� ������ �  �����
	os << "m_x=" << other.m_x <<", " << "m_y=" << other.m_y;
	return os;
}
