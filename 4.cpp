#include<iostream>
#include"DetaStyle.h"
using namespace std;

 int main()
 {
	Date d1;
	cout << d1 << endl;
	Date d2(2021,12,1);
	cout << d2 << endl;
	d1 = d2;
	cout << d1 << endl;
	Date d3(d2);
	cout << d3 << endl;

	if (d1 < d2)
	{
		cout << "ture" << endl;
	}
	else 
	{
		cout << "false" << endl;
	}
	if (d1 <= d2)
	{
		cout << "ture" << endl;
	}
	else
	{
		cout << "false" << endl;
	}

	d2++;
	cout << d2 << endl;
	d2 += 100;
	cout << d2 << endl;
	d3 -= 100;
	cout << d3 << endl;
	int day = d3 - d2;
	cout << day << endl;

	return 1000;
 }


