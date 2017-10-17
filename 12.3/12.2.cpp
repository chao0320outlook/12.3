
#include"stdafx.h"
#include "12.1.h"
#include<cstring>

using std::cout;

int StrngBad::mun_strings = 0;                                   //数组内成员数

StrngBad::StrngBad(const char*s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str,len+1, s);
	mun_strings++;
	cout << mun_strings << ": \"" << str << "\" object created\n";
}

StrngBad::StrngBad()
{
	len = 4;
	str = new char[4];
	strcpy_s(str,len+1, "C++");
	mun_strings++;
	cout << mun_strings << ": \"" << str << "\" default object created\n";
}

StrngBad::~StrngBad()
{
	cout <<"\""<< str <<"\"  object seleted, ";
	--mun_strings;
	cout << mun_strings << " left\n";
	delete[]str;
}

std::ostream & operator <<(std::ostream & os, const StrngBad &st)
{
	os << st.str;
	return os; 
}