#pragma once
#include "class.h"


union MyByte
{
private://спецификатор доступа?
	Bin m_bin;
	Oct  m_oct;
	Hex m_hex;
	unsigned char m_dec;

public:
	MyByte(unsigned char byte) { m_dec = byte; }	//конструктор 

	void ShowBin()const { m_bin.Show(); }
	void ShowOct()const { m_oct.Show(); }
	void ShowHex()const { m_hex.Show(); }

	void ShowDec() const{ std::cout << static_cast<int>(m_dec) << std::endl; }
	void ShowChar() const{ std::cout << m_dec << std::endl; }

	void ShowBinPos(int pos)const { m_bin.ShowPos(pos); }
	void ShowOctPos(int pos)const { m_oct.ShowPos(pos); }
	void ShowHexPos(int pos)const { m_bin.ShowPos(pos); }

	void EditBin(int pos, int val) { m_bin.Edit(pos, val); }
	void EditOct(int pos, int val) { m_oct.Edit(pos, val); }
	void EditHex(int pos, int val) { m_hex.Edit(pos, val); }
};