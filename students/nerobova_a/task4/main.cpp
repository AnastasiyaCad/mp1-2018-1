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
public:
	int num;
	int month;
	int year;
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
public:
	int hour;
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
	friend ostream &operator<<(ostream& os, const Thermometer &th);
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

	void SetDegree(Date _d, Time _t, int _degree); //наюл.дение
	void SetSeveralDegree(Date _d, int _degree);
	int GetDegree(Date _d, Time _t); // вернуть тепературу
	double GetAverage(); //средн€€ вообще
	int GetCase(int _month); //числа дл€ подсчета дней за мес€ц
	double GetAverageMonth(int month); //средн€€ за мес€ц
	double GetAverageDate(Date _d); //средн€€ за день
	double GetAverageNight(int month); // средн€€ ночна€
	double GetAverageDay(int month); // средн€€ дневна€
	void SaveToFile(int k);
	int Test();
	Date GetD();
	Time GetT();
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

Date Thermometer::GetD()
{
	d.num;
	d.month;
	d.year;
	return d;
}

Time Thermometer::GetT()
{
	t.hour;
	return t;
}

int Thermometer::GetHour(Time _t)
{
	_t.hour; 
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

int Thermometer::Test()
{
	int k = 0;
	for (int i = 0; i < values.size(); i++)
		for (int j = 0; j < 24; j++)
					k++;
	return k;
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

double Thermometer::GetAverageDate(Date _d)
{
	double k = 0;
	for (int i = 0; i < 24; i++)
		k = k + values[GetN(_d)][i];
	k = k / 24;
	return k;
}

double Thermometer::GetAverageMonth(int month)
{
	double k = 0;
	for (int i = GetCase(month); i < GetCase(month + 1); i++)
		for (int j = 0; j < 24; j++)
			k = k + values[i][j];
	k = k / (GetCase(month + 1) - GetCase(month));
	return k;
}
double Thermometer::GetAverage()
{
	double k = 0;
	for (int i = 0; i < values.size(); i++)
		for (int j = 0; j < 24; j++)
		{
			k = k + values[i][j];
		}
	k = k / Test();
	return k;
}

double Thermometer::GetAverageNight(int month)
{
	double k = 0;
	for (int i = GetCase(month); i < GetCase(month + 1); i++)
		for (int j = 0; j < 3; j++)
			k = k + values[i][j];
	for (int i = GetCase(month); i < GetCase(month + 1); i++)
		for (int j = 16; j < 24; j++)
			k = k + values[i][j];
	k = k / (GetCase(month + 1) - GetCase(month));
	return k;
}

double Thermometer::GetAverageDay(int month) 
{
	double k = 0;
	for (int i = GetCase(month); i < GetCase(month + 1); i++)
		for (int j = 4; j < 16; j++)
			k = k + values[i][j];
	k = k / (GetCase(month + 1) - GetCase(month));
	return k;
}

ofstream Thermometer_in;
ifstream Thermometer_out;
ostream &operator<<(ostream& os, const Thermometer &th)
{
	os << th.d.num  << '.' << th.d.month << '.' << th.d.year << '.' << th.t.hour << '.' << th.degree;
	return os;
}

void Thermometer::SaveToFile(int k)
{
	Thermometer_in << "Degree Counts: " << k << endl;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < 24; j++)
		{
			Thermometer_in <<  << endl << endl << values[i][j] << endl << endl;
		}
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
		int k;
		k = tr.Test();
		Thermometer_in.open("C:\Games\Temp.txt");
		tr.SaveToFile(k);
		Thermometer_in.close();
	}
	}
	system("pause");
}

	