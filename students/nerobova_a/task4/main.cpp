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
	int degree;
	double *degreeMas;
	Date d;
	Time t;
	vector<vector<int>> values;
public:
	Thermometer():degree(0){} 

	Thermometer(Date _d, Time _t) : d(_d), t(_t)
	{
		values.resize(365);
		for (int i = 0; i < values.size(); i++)
			values[i].resize(24);
	}
	
	Thermometer(const Thermometer &th);
	~Thermometer();

	Thermometer& operator=(const Thermometer &th)
	{
		d = th.d;
		t = th.t;
		degree = th.degree;
		return *this;
	}
	int GetDateDegree();
	void SetDateDegree(int _degree);
	int GetMonth(Date _d);
	int GetNum(Date _d);
	int GetN(Date _d);
	int GetNum1(Date _d);
	int GetYear(Date _d);
	int GetHour(Time _t);
	friend Date;
	friend Time;
	void SetDegree(Date _d, Time _t, int _degree);
	void SetSeveralDegree(Date _d, int _degree);
	int GetDegree(Date _d, Time _t);
	double GetAverage(Date _d);
	int GetCase(int _month);
};

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
	d = th.d;
	t = th.t;
	degree = th.degree;
}
Thermometer::~Thermometer()
{

}

int Thermometer::GetMonth(Date _d)
{
	return _d.GetDateMonth();
}
int Thermometer::GetNum(Date _d)
{
	return _d.GetDateNum();
}
int Thermometer::GetYear(Date _d)
{
	return _d.GetDateYear();
}
int Thermometer::GetHour(Time _t)
{
	return _t.GetDateHour();
}
int Thermometer::GetNum1(Date _d)
{
	switch (GetMonth(_d))
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
	return 0;
	}
	return 0;
}
int Thermometer::GetCase(int _month)
{
	switch(_month)
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
			 return 0;
	}
}
// число €чейки
int Thermometer::GetN(Date _d) 
{
	int Num;
	Num = GetNum(_d) + GetNum1(_d);
	return Num;
} 

void Thermometer::SetDegree(Date _d, Time _t, int _degree) // 3
{
	values[GetN(_d)][_t.GetDateHour()] = _degree;
}

int Thermometer::GetDegree(Date _d, Time _t) // 4
{
	return values[GetN(_d)][_t.GetDateHour()];
}

void Thermometer::SetSeveralDegree(Date _d, int _degree) // 5
{
	for (int i = 0; i < 24; i++)
	{
		values[GetN(_d)][i] = _degree;
	}
}

double Thermometer::GetAverage(Date _d)
{
	//1
	int k = 0;
	for (int i = 0; i < 24; i++)
		k = k + values[GetN(_d)][i];
	k = k / 24;
	return k;
	//2
	for (int i = GetCase(GetMonth(_d)); i < GetCase(GetMonth(_d)+1); i++)
		for(int j = 0; j < 24; j++)
		k = k + values[i][j];
	k = k / (GetCase(GetMonth(_d) + 1) - GetCase(GetMonth(_d)));
	return k;
	//3
	for (int i = 0; i < values.size(); i++)
		for (int j = 0; j < 24; j++)
		{
			k = k + values[i][j];
		}
	k = k / 365;
}

void main()
{
	int g;
	Date d(2000, 1, 1);
	Time t(0);
	int num, month, year;
	int hour;
	int degree;

	cout << "";
	cin >> g;
	
	switch (g)
	{
	case 1:
	{
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
		cout << "Vvedite degree: \n";
		cin >> degree;
		Thermometer tr(d, t);
		tr.SetDegree(d, t, degree);
		cout << "\n";
		break;
	
		cout << tr.GetNum(d) << "." << tr.GetMonth(d) << "." << tr.GetYear(d) << "\n";
		cout << tr.GetHour(t) << ".00 \n";

		cout << "";
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
		cout << tr.GetDegree(d, t);
		// 5
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
		for (int i = 0; i < 24; i++) {
			cout << "Vvedite degree: \n";
			cin >> degree;
			tr.SetSeveralDegree(d, degree);
		}
		
		
		cout << "\n";
	}
	}
	system("pause");
}

	