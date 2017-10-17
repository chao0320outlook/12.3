#pragma once
#include <iostream>

#ifndef strngbad_h_
#define strngbad_h_

class String                                          //�Զ���string��
{
private:
	char* str;                                        //�洢�ַ�������
	int len;                                          //����
	static int mun_strings;                           //���鳤��
public:
	String(const char*s);                            //���캯��
	String(const String &st);                      //���캯��
	String();                                        //Ĭ�Ϲ��캯��
	~String();                                       //��������

	friend std::ostream & operator <<(std::ostream &os, const String &st);       //���� << �����
};


#endif // !strngbad_h_
