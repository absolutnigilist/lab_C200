// ����:
// ���������� ����������.
// ���������� ������� 

//#include "stdafx.h"	//���� �� ����������� �������������� ������������
					//������, ���������������� ��� �������
#include "Base.h"
#include <tchar.h>


#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
//////////////////////////////////////////////////////////////////////
	
	//������� 1. ����������� "���� ������" � ����������� ����������� ��������������
	//�������. ������ �������� ������� (���� � ������� ��������, ������� ���������� ��������
	//� ���� ���� �� �����), � �������: ���, �������, ���������, ��������...
	//����������:
	//���������� ����������� � ����
	//���������� ���������� �� ����
	//����� ���������� � ���������� ����������
	//����� ���� (��� ������������) ���������� � ���� �����������
	//(��������� �� ���������� ���� � ����� "����_������-���.pdf")
	//��������:

	Base MyBase_1;	//�������� ������ ����
	stop

	////��������� ����������� � ����
	MyBase_1["Ivanov"] = MyData(MyData::MALE, 30, "Lehrer", 35.000);
	stop
	MyBase_1["Petrova"] = MyData(MyData::FEMALE, 35, "Bauer", 45.000);
	stop
	MyBase_1["Sidorov"] = MyData(MyData::MALE, 50, "Fahrer", 50.000);
	stop
	std::cout << MyBase_1; //������� ���������� ��� ���� �����������
	stop
	std::cout << MyBase_1["Ivanov"]; //������� ���������� � ����������
	stop
	MyBase_1.deletePair("Petrova"); //��������� ����������
	std::cout << MyBase_1; //������� ���������� ��� ���� �����������  �� ���� bd1
	stop

	//������� 2. ������������ ����������� ������ ��� ����, ����� ���,
	// ����������� ���� ���������� ���������

	//������� 2.1. �������� 2 �����  ����  bd1
	Base MyBase_2 = MyBase_1; 
	std::cout << MyBase_2; //������� ���������� ��� ���� �����������  �� ���� bd2
	stop
	Base MyBase_3 = MyBase_1;
	std::cout << MyBase_3; //������� ���������� ��� ���� �����������  �� ���� bd3
	stop
	//������� 2.2.  
	//�������� ����������� � ����  bd2
	std::cout << MyBase_2; //������� ���������� ��� ���� �����������  �� ���� bd2
	MyBase_2["Lomakina"] = MyData(MyData::FEMALE, 40, "Verkauferin", 45.000);
	MyBase_2["Gromova"] = MyData(MyData::FEMALE, 60, "Fahrerin", 50.000);
	MyBase_1 = MyBase_2;   //  �� "�������" � "���������"
	std::cout << MyBase_1; //������� ���������� ��� ���� �����������  �� ���� bd1
	stop
	//������� 2.3.
	MyBase_1 = MyBase_3;   //  �� "���������"  � "�������" 
	std::cout << MyBase_1; //������� ���������� ��� ���� �����������  �� ���� bd1
	stop

	//������� 3. ���������� ��� ��������� �����������
	//������� 3.1. �������� �����  ����  bd1
	Base MyBase_4 = std::move(MyBase_1);
	std::cout << MyBase_4; //������� ���������� ��� ���� �����������  �� ���� bd4
	std::cout << MyBase_1; //������� ���������� ��� ���� �����������  �� ���� bd1
	stop
	//������� 3.2. 

	MyBase_3 = std::move(MyBase_4);
	std::cout << MyBase_3; //������� ���������� ��� ���� �����������  �� ���� bd3
	stop
	std::cout << MyBase_4; //������� ���������� ��� ���� �����������  �� ���� bd4
	stop
	//������� 4.  ����������

	//������� 4.1. ������������ ���������� ���� ������  �� ����������� �����
	//���������, ��� ���� ����������� � ������ MyString
	
	//������� 4.2.������������ ����� ���� ������ � �������� ���������


	std::cout << MyBase_2 << std::endl;
	stop
	MyBase_2.Sort();
	std::cout << MyBase_2 << std::endl;
	stop
	system("pause");
	return 0;
}//endmain

