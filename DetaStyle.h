#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

class Date
{
public:
	friend ostream& operator<<(ostream& out, const Date& d);
	friend istream& operator>>(istream& in, Date& d);

	Date(int year = 1900, int month = 1, int day = 1);
	int GetMonthDay(int year, int month);
	Date& operator =(const Date& d);
	Date& operator+=(int day);
	Date operator+(int day) const;
	Date& operator-=(int day);
	Date operator-(int day)const;

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	int operator-(const Date& d) const;
	bool operator < (const Date& d)const;
	bool operator ==(const Date& d)const;
	bool operator !=(const Date& d)const;
	bool operator >(const Date& d)const;
	bool operator <=(const Date& d)const;
	bool operator >=(const Date& d)const;

	

private:
	int _year;
	int _month;
	int _day;
};
