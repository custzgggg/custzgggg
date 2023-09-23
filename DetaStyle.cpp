#include"DetaStyle.h"

bool Date::operator < (const Date& d)const
{
	if (_year < d._year)
	{
		return true;
	}
	else if (_month < d._month)
	{
		return true;
	}
	else if (_day < d._day)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Date::operator ==(const Date& d)const
{
	return (_year == d._year) &&
		(_month == d._month) &&
		(_day ==d._day);
}

bool Date :: operator !=(const Date& d)const
{
	return !(*this == d);
}

bool Date::operator >(const Date& d)const
{
	return (!(*this < d) || (*this == d));
}

bool Date::operator <=(const Date& d)const
{
	return (*this < d) || (*this == d);
}

bool Date::operator >=(const Date& d)const
{
	return !(*this < d);
}



Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

int Date::GetMonthDay(int year, int month)
{
	int month_day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month==2&& ((year % 4 == 0 && year % 100 != 0)||year%100==0))
	{
		return 29;
	}
	else
	{
		return month_day[month];
	}
}

Date& Date::operator =(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
	return *this;
}

Date& Date::operator+=(int day) 
{
	if (day < 0)
	{
		*this -= -day;
	}
	_day +=day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		if (_month == 13)
		{
			_year++;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day)const
{
	Date tmp(*this);
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += -_day;
	}
	_day -= day;

		while (_day < 0)
		{
			--_month;
			_day += GetMonthDay(_year, _month);
			if (_month == 0)
			{
				--_year;
				_month = 12;
			}
		}
	return *this;
}

Date Date::operator-(int day)const
{
	Date temp = *this;
	temp -= day;
	return temp;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

//后置++
Date Date::operator++(int)
{
	Date tmp = *this;
	*this += 1;
	return tmp;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date tmp = *this;
	*this -= 1;
	return tmp;
}

int Date::operator-(const Date& d) const
{
	Date max = *this;
	Date min = d;
	int flag = 1;
	if (*this < d)
	{
		max = d;
		min = *this;
		flag = -1;
	}
	int n = 0;
	while (min != max)
	{
		++min;
		++n;
	}
	return n * flag;
}

ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << "年" << d._month << "月" << d._day << "日" << endl;

	return out;
}

istream& operator>>(istream& in, Date& d)
{
	int year, month, day;
	in >> year >> month >> day;

	if (month > 0 && month < 13
		&& day > 0 && day <= d.GetMonthDay(year, month))
	{
		d._year = year;
		d._month = month;
		d._day = day;
	}
	else
	{
		cout << "非法日期" << endl;
		assert(false);
	}
	return in;
}