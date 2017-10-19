
#include"stdafx.h"
#include "12.1.h"
#include<cstring>

using std::cout;

int String::mun_strings = 0;                                    //������������Ŀ

String::String(const char*s)                                    //���캯��
{
	len = std::strlen(s);                                       //���� s ����
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);                                  //��s���Ƶ�str
	mun_strings++;                                              //������Ŀ+1
}


String::String(const String &st)                                //���ƹ��캯��
{
	mun_strings++;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
}

String::String()                                                //Ĭ�Ϲ��캯��
{
	len = 4;
	str = new char[4];
	str[0] = '\0';                                              //���쳤��Ϊ4�Ŀ��ַ���
	mun_strings++;
}

String::~String()                                               //��������
{
	--mun_strings;
	delete[]str;
}

String & String::operator=(const String &st)                   //��ֵ��䣬��String����String����
{
	if (this == &st)
		return *this;
	delete[]str;
	len = st.len;
	str = new char[len + 1];
	strcpy_s(str, len + 1, st.str);
	return *this;
}

String & String::operator=(const char * s)                    //��ֵ��䣬��*char��String����
{
	delete[]str;
	len = std::strlen(s);
	str = new char[len + 1];
	strcpy_s(str, len + 1, s);
	return *this;
}

char & String::operator[](int i)                              //�����ַ�����ĳ���ַ����������ַ��޸�
{
	return str[i];
}

const char & String::operator[](int i) const                  //�����ַ�����ĳ���ַ����������޸��ַ�

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



std::ostream & operator <<(std::ostream & os, const String &st)          //���� << �����
{
	os << st.str;
	return os;
}

std::istream & operator>>(std::istream & is, String & st)                //���� >> �����
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is;                                                           //���������������
}
