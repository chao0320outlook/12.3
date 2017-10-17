#pragma once
#include <iostream>

#ifndef strngbad_h_
#define strngbad_h_

class String                                          //自定义string类
{
private:
	char* str;                                        //存储字符串内容
	int len;                                          //长度
	static int mun_strings;                           //数组长度
public:
	String(const char*s);                            //构造函数
	String(const String &st);                      //构造函数
	String();                                        //默认构造函数
	~String();                                       //析构函数

	friend std::ostream & operator <<(std::ostream &os, const String &st);       //重载 << 运算符
};


#endif // !strngbad_h_
