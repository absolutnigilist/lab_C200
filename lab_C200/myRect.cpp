#include "myRect.h"

Rect::Rect() {										//определили дефолтный конструктор со значениями по умолчанию
	m_left = 0;
	m_right = 0;
	m_top = 0;
	m_bottom = 0;
};
void Rect::Normal(int& l, int& r, int& t, int& b) {		// метод класса нормализующий значения
	if ((l < r) && (t < b)) {
		m_left = l;
		m_right = r;
		m_top = t;
		m_bottom = b;
	}
	else {
		m_left = r;
		m_right = l;
		m_top = b;
		m_bottom = t;
	}
};
Rect::Rect(int l, int r, int t, int b) {					//определили конструктор с параметрами
	Normal(l, r, t, b);
};

void Rect::InflateRect(int dl, int dr, int dt, int db)		// определили метод для увеличения сторон прямоугольника
{
	m_left -= dl;
	m_right += dr;
	m_top -= dt;
	m_bottom += db;
};

Rect::Rect(const Rect& other) {
	m_left = other.m_left;
	m_right = other.m_right;
	m_top = other.m_top;
	m_bottom = other.m_bottom;
};

void Rect::InflateRect(int dl_dr, int dt_db) {
	m_left -= dl_dr;
	m_right += dl_dr;
	m_top -= dt_db;
	m_bottom += dt_db;
};

void Rect::SetAll(int l, int r, int t, int b) {
	Normal(l, r, t, b);
};
void Rect::GetAll(int& l, int& r, int& t, int& b) const{
	l= m_left;
	r= m_right;
	t= m_top;
	b= m_bottom;
};
Rect BoundingRect(Rect r1, Rect r2) {
	
	int m_left_1, m_right_1, m_top_1, m_bottom_1;
	int m_left_2, m_right_2, m_top_2, m_bottom_2;

	r1.GetAll(m_left_1, m_right_1, m_top_1, m_bottom_1);
	r2.GetAll(m_left_2, m_right_2, m_top_2, m_bottom_2);
	
	m_left_1 = (m_left_1 < m_left_2) ? m_left_1: m_left_2;
	m_right_1= (m_right_1 > m_right_2) ? m_right_1 : m_right_2;
	m_top_1 = (m_top_1 < m_top_2) ? m_top_1 : m_top_2;
	m_bottom_1= (m_bottom_1 > m_bottom_2) ? m_bottom_1 : m_bottom_2;
	
	Rect tmp(m_left_1, m_right_1, m_top_1, m_bottom_1);
	
	return tmp;
};

Rect BoundingRect2(const Rect& r1, const Rect& r2) {
	
	int m_left_1, m_right_1, m_top_1, m_bottom_1;
	int m_left_2, m_right_2, m_top_2, m_bottom_2;

	r1.GetAll(m_left_1, m_right_1, m_top_1, m_bottom_1);
	r2.GetAll(m_left_2, m_right_2, m_top_2, m_bottom_2);

	m_left_1 = (m_left_1 < m_left_2) ? m_left_1 : m_left_2;
	m_right_1 = (m_right_1 > m_right_2) ? m_right_1 : m_right_2;
	m_top_1 = (m_top_1 < m_top_2) ? m_top_1 : m_top_2;
	m_bottom_1 = (m_bottom_1 > m_bottom_2) ? m_bottom_1 : m_bottom_2;

	Rect tmp(m_left_1, m_right_1, m_top_1, m_bottom_1);

	return tmp;
};

Rect Rect::BoundingRect(const Rect& r1, const Rect& r2) {
	Rect tmp;
	tmp.m_left = (r1.m_left < r2.m_left) ? r1.m_left : r2.m_left;
	tmp.m_right = (r1.m_right > r2.m_right) ? r1.m_right : r2.m_right;
	tmp.m_top = (r1.m_top < r2.m_top) ? r1.m_top : r2.m_top;
	tmp.m_bottom = (r1.m_bottom > r2.m_bottom) ? r1.m_bottom : r2.m_bottom;

	return tmp;
};
Rect::~Rect() {}; //определили деструктор
