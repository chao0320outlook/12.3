#pragma once
#include <iostream>

#ifndef strngbad_h_
#define strngbad_h_

class StrngBad
{
private:
	char* str;                                        //string ָ��
	int len;                                          //����
	static int mun_strings;                           //���鳤��
public:
	StrngBad(const char*s);                            //���캯��
	StrngBad();                                        //Ĭ�Ϲ��캯��
	~StrngBad();                                       //��������

	friend std::ostream & operator <<(std::ostream &os, const StrngBad &st);          //���� << �����
};


#endif // !strngbad_h_
