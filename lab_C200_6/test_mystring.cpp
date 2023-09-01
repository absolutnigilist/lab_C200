//------------------------------------------------------------------------------
// ��������� ����� MyString
//------------------------------------------------------------------------------
#include "MyString.h"

#define	  stop __asm nop

int main()
{
	MyString test("test");
	std::cout << test << std::endl;

	// � ������� �������������� ��������� ��� �� ������������ ������ ����������
	stop  // ����� ������ 1-�� ������ ������

	{
		//
		// 1. ������� ������
		//
		MyString str("bbb");
		MyString str2("bbb");
		MyString str3("CCC");
		MyString* str4 = new MyString("ddd");
		MyString* str5 = new MyString("CCC");

		MyString::print();   // ��� ������ ������� ���������� ������������� ������
		//
		// 2. ����������� �����������
		//
		MyString s;
		MyString s2 = str2;
		MyString s3 = s2;
		MyString::print();

		MyString s4 = std::move(*str4);
		delete str4;
		MyString::print();
		//
		// 3. �������� ������������
		//
		s3 = s4;
		MyString::print();

		*str5 = std::move(s3);
		MyString::print();

		s4 = "bbb";
		MyString::print();

		delete str5;
		MyString::print();

		s4 = "FFF";
		MyString::print();
		//
		// 4. �������� ������� � ���� ����� �� ���������������
		//
		MyString s5("FFF");
		MyString::print();

		MyString::changeCase();
		MyString::print();
		//
		// 5. ����������� ������ � ���������� �������
		//
		MyString::printAlph();		
		//
		// 6. �������������� �����
		//
		// ...
	}

    stop		// ����� ������ 2-�� ������ ������ � ������� ����������
		 
	return 0;
}