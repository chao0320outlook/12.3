#pragma once
#include <iostream>

#ifndef strngbad_h_
#define strngbad_h_

using namespace std;

class String                                          //�Զ���string��
{
private:
	char* str;                                        //�洢�ַ�������
	int len;                                          //str����
	static int mun_strings;                           //���鳤��
	static const int CINLIM = 80;                     //�����������
public:
	String(const char*s);                            //���캯��
	String(const String &st);                        //���캯��
	String();                                        //Ĭ�Ϲ��캯��
	~String();                                       //��������
	int length()const { return len; };               //���س���  �������const ��֤���ö��󲻻ᱻ�޸�
	
	String & operator =(const String &st);           //��ֵ��䣬��String����String����
	String & operator =(const char*s);               //��ֵ��䣬��*char��String����
	char & operator[](int i);                        //�����ַ�����ĳ���ַ����������ַ��޸�
	const char & operator [](int i)const;            //�����ַ�����ĳ���ַ����������޸��ַ�
	
	friend bool operator <(const String &st1, const String &st2);
	friend bool operator >(const String &st1, const String &st2);
	friend bool operator ==(const String &st1, const String &st2);

	friend std::ostream & operator <<(std::ostream &os, const String &st);       //���� << �����
	friend std::istream & operator >>(std::istream &is, String &st);             //���� << �����

	static int HowMany();                            //������������Ŀ
};


#endif // !strngbad_h_
