#include<iostream>
using namespace std;

class Data
{
public:
	int GetMonthDay(int year, int month)
	{
		int monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			monthday[2] = 29;
		}
		return monthday[month];
	}
	Data(int year = 0, int month = 1, int day = 1)
	{
		if (year >= 0 && month > 0 && month < 13 && day>0 && day <= GetMonthDay(year,month))
		{
			_year = year;
			_month = month;
			_day = day;
		}
		
		else
		{
			cout << "日期输入错误" << endl;
		}
			
		
	}
	Data(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	
	bool operator>(const Data& d)
	{
		if (_year > d._year)
			return true;
		else if (_year == d._year && _month > d._month)
			return true;
		else if(_year == d._year && _month == d._month && _day > d._day)
			return true;
			
		return false;
	}

	bool operator==(const Data& d)
	{
		return _year == d._year && _month == d._month && _day == d._day;
	}

	bool operator>=(const Data& d)
	{
		return *this > d || *this == d;
	}

	bool operator<(const Data& d)
	{
		return !(*this >= d);
	}
	bool operator<=(const Data& d)
	{
		return !(*this > d);
	}
	bool operator!=(const Data& d)
	{
		return !(*this == d);
	}

	Data operator+(int day)
	{
		Data ret(*this);//拷贝构造函数
		ret._day += day;
		while (ret._day > GetMonthDay(ret._year, ret._month))
		{
			ret._day -=GetMonthDay(ret._year,ret._month);
			ret._month++;
			if (ret._month > 12)
			{
				ret._year++;
				ret._month = 1;
			}
		}
		return ret;
	}

	void  operator+=(int day)
	{
		_day += day;
		while (_day > GetMonthDay(_year , _month))
		{
			_day -= GetMonthDay(_year, _month);
			_month++;
			if (_month > 12)
			{
				_year++;
				_month = 1;
			}
		}

	}
	void operator=(const Data& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	void print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Data d1;
	d1.print();
	Data d2(2021, 3, 21);
	d2.print();

	d2 = d1;
	d2.print();

	//Data d3(d1);
	//d3.print();
	/*cout << (d1 > d2) << endl;
	cout << (d1 < d2) << endl;
	cout << (d1 >= d2) << endl;
	cout << (d1 <= d2) << endl;
	cout << (d1 == d2) << endl;
	cout << (d1 != d2) << endl;

	Data d3=d2 + 130;
	d3.print();

	d1 += 10000;
	d1.print();
	*/
	return 0;
}