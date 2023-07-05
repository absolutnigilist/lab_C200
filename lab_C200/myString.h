#pragma once

class MyString
{
    char* m_pStr;	//������-���� ������
public:
    MyString();                                 //��������� �����������
    MyString(const char* string_orig);          //�����������
    ~MyString();                                //����������
    MyString(const MyString& other);            //����������� �����������
    const char* GetString() const;
    void SetNewString(const char* other);
};
