#pragma once
#include <iostream>

#ifndef strngbad_h_
#define strngbad_h_

using namespace std;

class String                                          //自定义string类
{
private:
	char* str;                                        //存储字符串内容
	int len;                                          //str长度
	static int mun_strings;                           //数组长度
	static const int CINLIM = 80;                     //输入最大限制
public:
	String(const char*s);                            //构造函数
	String(const String &st);                        //构造函数
	String();                                        //默认构造函数
	~String();                                       //析构函数
	int length()const { return len; };               //返回长度  （）后加const 保证调用对象不会被修改
	
	String & operator =(const String &st);           //赋值语句，从String对象到String对象
	String & operator =(const char*s);               //赋值语句，从*char到String对象
	char & operator[](int i);                        //返回字符串的某个字符，可用于字符修改
	const char & operator [](int i)const;            //返回字符串的某个字符，不可以修改字符
	
	friend bool operator <(const String &st1, const String &st2);
	friend bool operator >(const String &st1, const String &st2);
	friend bool operator ==(const String &st1, const String &st2);

	friend std::ostream & operator <<(std::ostream &os, const String &st);       //重载 << 运算符
	friend std::istream & operator >>(std::istream &is, String &st);             //重载 << 运算符

	static int HowMany();                            //所创建对象数目
};


#endif // !strngbad_h_
