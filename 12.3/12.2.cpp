
#include"stdafx.h"
#include "12.1.h"
#include<cstring>

using std::cout;

int String::mun_strings = 0;                                   //�����ڳ�Ա��

String::String(const char*s)                                    //���캯��
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str,len+1, s);
	mun_strings++;
	cout << mun_strings << ": \"" << str << "\" object created\n";
}


String::String(const String &st)                              //���ƹ��캯��
{
	mun_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	mun_strings++;
	cout << mun_strings << ": \"" << str << "\" object created\n";
}

String::String()                                                //Ĭ�Ϲ��캯��
{
	len = 4;
	str = new char[4];
	strcpy_s(str,len+1, "C++");
	mun_strings++;
	cout << mun_strings << ": \"" << str << "\" default object created\n";
}

String::~String()                                               //��������
{
	cout <<"\""<< str <<"\"  object seleted, ";
	--mun_strings;
	cout << mun_strings << " left\n";
	delete[]str;
}

std::ostream & operator <<(std::ostream & os, const String &st)
{
	os << st.str;
	return os; 
}
