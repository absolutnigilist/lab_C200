#include "class.h"
static const char* ar = "0123456789ABCDEF";

void Bin::Show()const{
		std::cout << 
		static_cast<int>(m_bin7) << 
		static_cast<int>(m_bin6) << 
		static_cast<int>(m_bin5) << 
		static_cast<int>(m_bin4) << 
		static_cast<int>(m_bin3) << 
		static_cast<int>(m_bin2) <<
		static_cast<int>(m_bin1) <<
		static_cast<int>(m_bin0) << 
		std::endl;
};
void Bin::ShowPos(int pos)const {
	if (pos>=0&&pos<=7)
	{
		int tmp[] = { m_bin0, m_bin1,m_bin2,m_bin3,m_bin4,m_bin5,m_bin6 };
		std::cout << tmp[pos];
	}else
		std::cout << "Incorrect val";
};
void Bin::Edit(int pos, int val) {
	switch (pos)
	{
	case 0:
		m_bin0 = val;
		break;
	case 1:
		m_bin1 = val;
		break;
	case 2:
		m_bin2 = val;
		break;
	case 3:
		m_bin3 = val;
		break;
	case 4:
		m_bin4 = val;
		break;
	case 5:
		m_bin5 = val;
		break;
	case 6:
		m_bin6 = val;
		break;
	case 7:
		m_bin6 = val;
		break;
	default:
		std::cout << "Incorrect val";
		break;
	}
};


void Oct::Show()const{
	std::cout << 
		static_cast<int>(m_oct2) << 
		static_cast<int>(m_oct1) <<
		static_cast<int>(m_oct0) << 
		std::endl;
};
void Oct::ShowPos(int pos)const{
	int tmp[] = { m_oct0,m_oct1,m_oct2 };
	switch (pos)
	{
	case 0:
		std::cout << tmp[0] << std::endl;
		break;
	case 1:
		std::cout << tmp[1] << std::endl;
		break;
	case 2:
		std::cout << tmp[2] << std::endl;
		break;
	default:
		std::cout << "Incorrect val";
		break;
	}
}; 
void Oct::Edit(int pos, int val) {
	switch (pos)
	{
	case 0:
		m_oct0 = val;
		break;
	case 1:
		m_oct1 = val;
		break;
	case 2:
		m_oct2 = val;
		break;
	default:
		std::cout << "Incorrect val";
		break;
	}
};

void Hex::Show()const{
	
	std::cout << 
		static_cast<int>(ar[m_hex1]) << 
		static_cast<int>(ar[m_hex0]) << 
		std::endl;
};
void Hex::ShowPos(int pos)const{
	switch (pos)
	{
	case 0:
		std::cout << ar[m_hex0] << std::endl;
		break;
	case 1:
		std::cout << ar[m_hex1] << std::endl;
		break;
	default:
		std::cout << "Incorrect val";
		break;
	}
};
void Hex::Edit(int pos, int val) {
	switch (pos)
	{
	case 0:
		m_hex0=val;
		break;
	case 1:
		m_hex1=val;
		break;
	default:
		std::cout << "Incorrect val";
		break;
	}
};