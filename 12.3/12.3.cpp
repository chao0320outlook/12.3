// 12.3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "12.1.h"
#include <ctime>

const int Arsize = 10;                                         //最多对象数
const int Maxlen = 81;                                         //最多字符数

int main()
{
	using std::cout;
	using std::cin;
	using std::endl;

	String name;
	cout << "Hi,What is your name?" << endl;
	cin >> name;

	cout << name << ", please enter up to " << Arsize 
	<< " short sayings <empty line to quit>:" << endl;

	String sayings[Arsize];
	char temp[Maxlen];
	int i;
	for(i=0;i<Arsize;i++)                                         //循环对sayings数组进行输入
	{
		cout << i + 1 << ": ";
		cin.get(temp, Maxlen);
		while (cin&&cin.get() != '\n')                            //空格继续
			continue;
		if (!cin )
			break;
		else
		sayings[i] = temp;
	}                                    
	auto total = i;

	if (total > 0)
	{
		cout << "Here are you sayings: " << endl;                       //输出sayings数组
		for (i = 0; i < total; i++)
			cout << sayings[i][0] << ": " << sayings[i] << endl;

		int shorstest = 0;                                              //最短的序号
		int first = 0;                                                  //最小的序号
		for (i = 1; i < total; i++)
		{
			if (sayings[i].length() < sayings[shorstest].length())
				shorstest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}
		cout << "Shortest saying: " << endl << sayings[shorstest] << endl;
		cout << "First alphabetically: " << endl << sayings[first] << endl;
		cout << "This program used " << String::HowMany() << " String objects. Bay!" << endl;
	}

	else
		cout << "No input! Bye!" << endl;

	int secs = 60;                                   //延时60s的程序
	clock_t delay = secs*CLOCKS_PER_SEC;             //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

    return 0;
}
