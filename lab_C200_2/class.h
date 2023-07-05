#pragma once
#pragma once
#include <tchar.h>
#include <iostream>
#include <stdarg.h.>
#include < cstring >
using namespace std;

class Bin
{
	unsigned char m_bin0 : 1;
	unsigned char m_bin1 : 1;
	unsigned char m_bin2 : 1;
	unsigned char m_bin3 : 1;
	unsigned char m_bin4 : 1;
	unsigned char m_bin5 : 1;
	unsigned char m_bin6 : 1;
	unsigned char m_bin7 : 1;

//public:
	void Show()const;						//выводим все двоичные цифры
	void/*int*/ ShowPos(int pos)const ;		//выводим цифру в позиции
	void/*int*/ Edit(int pos, int val); //изменяем цифру в позиции
	friend union MyByte;
private:
};

class Oct
{
	unsigned char m_oct0 : 3;
	unsigned char m_oct1 : 3;
	unsigned char m_oct2 : 2;

public:
	void Show() const;						//выводим все восьмеричные цифры
	void/*int*/ ShowPos(int pos) const;		//выводим цифру в позиции
	void/*int*/ Edit(int pos, int val); //изменяем цифру в позиции
	friend union MyByte;
private:
};

class Hex
{
	unsigned char m_hex0 : 4;
	unsigned char m_hex1 : 4;
	
public:
	void Show() const;						//выводим все шестнадцатиричные цифры
	void/*int*/ ShowPos(int pos) const;		//выводим цифру в позиции
	void/*int*/ Edit(int pos, int val);		//изменяем цифру в позиции
	friend union MyByte;
private:
};