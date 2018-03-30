#include <iostream>
#include <math.h>
#include <stdio.h>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

class Thermometer;
class Date
{
	int num;
	int month;
	int year;
public:
	Date() : year(0), month(0), num(0) {}
	Date(int _year, int _month, int _num): year(_year), month(_month), num(_num){} 
	friend Thermometer;
	Date(const Date &d);
	~Date();

	Date& operator=(const Date& d)
	{
		num = d.num;
		month = d.month;
		year = d.year;
		return *this;
	}

	int GetDateNum();
	void SetDateNum(int _num);
	int GetDateMonth();
	void SetDateMonth(int _month);
	int GetDateYear();
	void SetDateYear(int _year);
};

void Date::SetDateNum(int _num)
{
	num = _num;
}
int Date::GetDateNum()
{
	return num;
}
void Date::SetDateMonth(int _month)
{
	month = _month;
}
int Date::GetDateMonth()
{
	return month;
}
void Date::SetDateYear(int _year)
{
	year = _year;
}
int Date::GetDateYear()
{
	return year;
}

Date::Date(const Date &d)
{
	num = d.num;
	month = d.month;
	year = d.year;
}
Date::~Date()
{
}

class Time
{
	int hour;
public:
	Time(): hour(0){}
	Time(int _hour): hour(_hour){}
	friend Thermometer;
	Time(const Time &t);
	~Time();

	Time& operator=(const Time& t)
	{
		hour = t.hour;
		return *this;
	}

	void SetDateHour(int _hour);
	int GetDateHour();
};

void Time::SetDateHour(int _hour)
{
	hour = _hour;
}
int Time::GetDateHour()
{
	return hour;
}
Time::Time(const Time &t)
{
	hour = t.hour;
}
Time::~Time()
{
}

class Thermometer
{
	double degree;
	double *degreeMas;
	Date d;
	Time t;
	vector<vector<int>> values;
public://values.size()
	Thermometer():degree(0){} 
	Thermometer(Date _d, Time _t) : d(_d), t(_t)
	{
		values.resize(365);
		for (int i = 0; i < values.size(); i++)
			values[i].resize(24);
	}
	Thermometer(Date _d, Time _t, double _degree) :degree(_degree), d(_d), t(_t)
	{
		values.resize(365);
		for (int i = 0; i < 365; i++)
			values[i].resize(24);
		values[SetN(_d)][_t.GetDateHour()] = _degree;
	}

	/*Thermometer(Date _d, Time _t, double _degreeMas[]) : d(_d), t(_t)
	{
		values.resize(365);
		for (int i = 0; i < 365; i++)
			values[i].resize(24);
		for (int i = SetN(_d); i < 365; i++)
		{
			for (int j = GetHour(_t); j < 24; j++)
				for (int k = 0; k < 365; k ++)
					values[i][j] = _degreeMas[k];
		}
	}*/

	Thermometer(const Thermometer &th);
	~Thermometer();

	Thermometer& operator=(const Thermometer &th)
	{
		d = th.d;
		t = th.t;
		degree = th.degree;
		return *this;
	}
	Date GetStartDate();
	Time GetStartTime();
	int GetDateDegree();
	void SetDateDegree(int _degree);
	void PrintThermometer();
	int SetMonth(Date _d);
	int SetNum(Date _d);
	int SetN(Date _d);
	int SetNum1(Date _d);
	int SetYear(Date _d);
	int GetHour(Time _t);
	friend Date;
	friend Time;
	void PrintDate(Date d);
	void PrintTime(Time _t);
	void SetDegree(Date _d, Time _t);
};

Date Thermometer::GetStartDate()
{
	return d;
}
Time Thermometer::GetStartTime()
{
	return t;
}

void Thermometer::SetDateDegree(int _degree)
{
	degree = _degree;
}
int Thermometer::GetDateDegree()
{
	return degree;
}

Thermometer::Thermometer(const Thermometer &th)
{
	degree = th.degree;
}
Thermometer::~Thermometer()
{

}

int Thermometer::SetMonth(Date _d)
{
	return _d.GetDateMonth();
}
int Thermometer::SetNum(Date _d)
{
	return _d.GetDateNum();
}
int Thermometer::SetYear(Date _d)
{
	return _d.GetDateYear();
}
int Thermometer::GetHour(Time _t)
{
	return _t.GetDateHour();
}

int Thermometer::SetNum1(Date _d)
{
	switch (SetMonth(_d))
	{
	case 1: { return 0; }
	case 2: { return 31; }
	case 3: { return 60; }
	case 4: { return 91; }
	case 5: { return 121; }
	case 6: { return 152; }
	case 7: { return 182; }
	case 8: { return 213; }
	case 9: { return 244; }
	case 10: { return 274; }
	case 11: { return 305; }
	case 12: { return 335; }
	}
}
// число €чейки
int Thermometer::SetN(Date _d) 
{
	int Num;
	Num = SetNum(_d) + SetNum1(_d);
	return Num;
} 

void Thermometer::PrintDate(Date _d)
{
	cout << SetNum(_d) << "." << SetMonth(_d) << "." << SetYear(_d) << "\n";
}
void Thermometer::PrintTime(Time _t)
{
	cout << GetHour(_t) << ".00 \n";
}
void Thermometer::PrintThermometer()
{
	cout << degree << "C \n";
}
void main()
{
	Date d(2000, 1, 1);
	Time t(0);
	//Thermometer tr(d, t, );
	//tr.SetDateDegree(degree);
	//tr.PrintThermometer();
	//tr.InputTherm(d, t);*/

	int num, month, year;
	int hour;
	double degree;
	cout << "Vvedite daty: \n";
	cout << "Vvedite year: \n";
	cin >> year;
	d.SetDateYear(year);
	cout << "Vvedite month: \n";
	cin >> month;
	d.SetDateMonth(month);
	cout << "Vvedite num: \n";
	cin >> num;
	d.SetDateNum(num);
	cout << "Vvedite time: \n";
	cin >> hour;
	t.SetDateHour(hour);

	Thermometer tr(d, t);

	double tr;
	for (int i = SetN(d); i < 365; i++)
	{
		cout <<
			for (int j = GetHour(t); j < 24; j++)
			{
				cin >> tr;
				values[i][j] = tr;
			}
	}
	cout << "Vvedite temperatury: \n";
	tr.SetDegree(d, t);
	
	/*Thermometer tr(d, t, degree);
	tr.PrintDate(d);
	tr.PrintTime(t);
	tr.PrintThermometer();*/


	cout << "\n";
	system("pause");
}

	