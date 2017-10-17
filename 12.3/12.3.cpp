// 12.3.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include "12.1.h"
#include <ctime>

using namespace std;

void callme1(StrngBad &);
void callme2(StrngBad &);

int main()
{
	{
		cout << "Staring an inner block.\n";
		StrngBad headline1("Celery Stalks at Midnight.");
		StrngBad headline2("lettuce Prey");
		StrngBad sports("Spinch leaves Bowl for Dollars");
		cout << "Headline1: " << headline1 << endl;
		cout << "Headline2: " << headline2 << endl;
		cout << "Sports: " << sports << endl;
		callme1(headline1);
		cout << "Headline1: " << headline1 << endl;
		callme2(headline2);
		cout << "Headline2: " << headline2 << endl;

		cout << "Initialize one object to another:\n";
		StrngBad sailor = sports;
		cout << "sailor: " << sailor << endl;

		cout << "Assign one object to another:\n ";
		StrngBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;

		cout << "Exiting the block" << endl;
	}
	cout << "End of main()" << endl;


	int secs = 60;                                   //延时60s的程序
	clock_t delay = secs*CLOCKS_PER_SEC;             //总延时
	clock_t start = clock();                         //开始时间
	while (clock() - start < delay);                 //时间差大于总延时 跳出循环

    return 0;
}

void callme1(StrngBad &rsb)
{
	cout << "String passed by reference" << endl;
	cout << "   \"" << rsb << "\"\n";
}
void callme2(StrngBad &rsb)
{
	cout << "String passed by value" << endl;
	cout << "   \"" << rsb << "\"\n";
}