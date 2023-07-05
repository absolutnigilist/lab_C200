#pragma once

class MyString
{
    char* m_pStr;	//строка-член класса
public:
    MyString();                                 //дефолтный конструктор
    MyString(const char* string_orig);          //конструктор
    ~MyString();                                //деструктор
    MyString(const MyString& other);            //конструктор копирования
    const char* GetString() const;
    void SetNewString(const char* other);
};
