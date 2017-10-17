#pragma once
#include <iostream>

#ifndef strngbad_h_
#define strngbad_h_

class StrngBad
{
private:
	char* str;                                        //string 指针
	int len;                                          //长度
	static int mun_strings;                           //数组长度
public:
	StrngBad(const char*s);                            //构造函数
	StrngBad();                                        //默认构造函数
	~StrngBad();                                       //析构函数

	friend std::ostream & operator <<(std::ostream &os, const StrngBad &st);          //重载 << 运算符
};


#endif // !strngbad_h_
