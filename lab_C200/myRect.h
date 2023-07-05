#pragma once
class Rect{
	int m_left, m_right, m_top, m_bottom;
public:
	
	Rect();																	// �������� ��������� ����������� �� ���������� �� ���������
	Rect(int l, int r, int t, int b);										// �������� ����������� � �����������
	void Normal(int &l, int& r, int& t, int& b);
	void InflateRect(int dl, int dr, int dt, int db);						// �������� ����� ��� ���������� ������ ��������������
	Rect(const Rect& other);												// �������� ������������ ����������� �����������
	void InflateRect(int dl_dr = 1, int dt_db=1);							// �������� ����� ��� ���������� ������ �������������� �� ���������� �� ���������
	void SetAll(int l, int r, int t, int b);
	void GetAll(int& l, int& r, int& t, int& b)const;
	Rect BoundingRect(const Rect& r1, const Rect& r2);
	~Rect();
};

Rect BoundingRect(Rect r1, Rect r2);
Rect BoundingRect2(const Rect& r1, const Rect& r2);