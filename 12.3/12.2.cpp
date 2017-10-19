
#include"stdafx.h"
#include "12.1.h"
#include<cstring>

using std::cout;

int String::mun_strings = 0;                                    //所创建对象数目

String::String(const char*s)                                    //构造函数
{
	len = std::strlen(s);                                       //计算 s 长度
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);                                  //将s复制到str
	mun_strings++;                                              //对象数目+1
}


String::String(const String &st)                                //复制构造函数
{
	mun_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
}

String::String()                                                //默认构造函数
{
	len = 4;
	str = new char[4];
	str[0] = '\0';                                              //构造长度为4的空字符串
	mun_strings++;
}

String::~String()                                               //析构函数
{
	--mun_strings;
	delete[]str;
}

String & String::operator=(const String &st)                   //赋值语句，从String对象到String对象
{
	if (this == &st)
		return *this;
	delete[]str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}

String & String::operator=(const char * s)                    //赋值语句，从*char到String对象
{
	delete[]str;
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}

char & String::operator[](int i)                              //返回字符串的某个字符，可用于字符修改
{
	return str[i];
}

const char & String::operator[](int i) const                  //返回字符串的某个字符，不可以修改字符

{
	return str[i];
}

int String::HowMany()
{
	return mun_strings;;
}

bool operator<(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str));
}

bool operator>(const String & st1, const String & st2)
{
	return st2 < st1;
}

bool operator==(const String & st1, const String & st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}



std::ostream & operator <<(std::ostream & os, const String &st)          //重载 << 运算符
{
	os << st.str;
	return os;
}

std::istream & operator>>(std::istream & is, String & st)                //重载 >> 运算符
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;                                                           //可以完成连续操作
}
