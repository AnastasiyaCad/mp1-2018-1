#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class Thermometer;
class Date
{
	int num;
	int month;
	int year;
public:
	Date() : year(0), month(0), num(0) {}
	Date(int _year, int _month, int _num): year(_year), month(_month), num(_num){} // למזוע דמה מעהוכüםמ?
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
	void PrintDate();
};

//num
void Date::SetDateNum(int _num)
{
	num = _num;
}
int Date::GetDateNum()
{
	return num;
}
//month
void Date::SetDateMonth(int _month)
{
	month = _month;
}
int Date::GetDateMonth()
{
	return month;
}
//year
void Date::SetDateYear(int _year)
{
	year = _year;
}
int Date::GetDateYear()
{
	return year;
}

void Date::PrintDate()
{
	cout << num << "." << month << "." << year << "\n";
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
	void PrintTime();
};

void Time::SetDateHour(int _hour)
{
	hour = _hour;
}
int Time::GetDateHour()
{
	return hour;
}

void Time::PrintTime()
{
	cout << hour << ".00 \n";
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
	Date d();
	Time t();
public:
	Thermometer():degree(0){}
	//Thermometer(int _degree): degree(_degree){}
	Thermometer(Date _d, Time _t, int _degree) : degree(_degree) {}
	Thermometer(const Thermometer &th);
	~Thermometer();

	Thermometer& operator=(const Thermometer &th)
	{
		degree = th.degree;
		return *this;
	}

	int GetDateDegree();
	void SetDateDegree(int _degree);
	void PrintThermometer();
	void InputTherm(Date& d, Time& t);
	friend Date;
	friend Time;

	/*int GetDateNum();
	void SetDateNum(int _num);
	int GetDateMonth();
	void SetDateMonth(int _month);
	int GetDateYear();
	void SetDateYear(int _year);
	void PrintDate();*/

};

void Thermometer::SetDateDegree(int _degree)
{
	degree = _degree;
}
int Thermometer::GetDateDegree()
{
	return degree;
}

void Thermometer::PrintThermometer()
{
	cout << degree << " C";
}

Thermometer::Thermometer(const Thermometer &th)
{
	degree = th.degree;
}
Thermometer::~Thermometer()
{

}

/*void Thermometer::InputTherm(Date &d, Time &t)
{
	Thermometer tr1();
}*/

/*void Thermometer::SetDateNum(int _num)
{
	num = _num;
}
int Thermometer::GetDateNum()
{
	return num;
}
//month
void Thermometer::SetDateMonth(int _month)
{
	month = _month;
}
int Thermometer::GetDateMonth()
{
	return month;
}
//year
void Thermometer::SetDateYear(int _year)
{
	year = _year;
}
int Thermometer::GetDateYear()
{
	return year;
}

void Thermometer::PrintDate()
{
	cout << num << "." << month << "." << year << "\n";
}*/

void main()
{
	int num, month, year;
	Date d(0,0,0);
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
	d.PrintDate();

	int hour;
	Time t(0);
	cout << "Vvedite time: \n";
	cin >> hour;
	t.SetDateHour(hour);
	t.PrintTime();

	int degree;
	//Thermometer tr(0);
	cout << "Vvedite temperatury: \n";
	cin >> degree;
	//tr.SetDateDegree(degree);
	//tr.PrintThermometer();
	Thermometer tr1(d, t, degree);
	tr1.PrintThermometer();
	//tr.InputTherm(d, t);

	double *koef;
	koef = new double[365 + 1];
		
	for (int i = 0; i < 365; i++)
	{
		Date d(0, 0, 0);
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
		d.PrintDate();
		Time t(0);
		cout << "Vvedite time: \n";
		cin >> hour;
		t.SetDateHour(hour);
		t.PrintTime();
		cout << "Vvedite temperatury: \n";
		cin >> degree;
		Thermometer tr1(d, t, degree);
		tr1.PrintThermometer();
	}

	cout << "\n";
	system("pause");
}