
#include"stdafx.h"
#include "12.1.h"
#include<cstring>

using std::cout;

int String::mun_strings = 0;                                   //数组内成员数

String::String(const char*s)                                    //构造函数
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str,len+1, s);
	mun_strings++;
	cout << mun_strings << ": \"" << str << "\" object created\n";
}


String::String(const String &st)                              //复制构造函数
{
	mun_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	mun_strings++;
	cout << mun_strings << ": \"" << str << "\" object created\n";
}

String::String()                                                //默认构造函数
{
	len = 4;
	str = new char[4];
	strcpy_s(str,len+1, "C++");
	mun_strings++;
	cout << mun_strings << ": \"" << str << "\" default object created\n";
}

String::~String()                                               //析构函数
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
