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
	int day;
	int month;
	int year;
public:
	
	Date() : year(0), month(0), day(0) {}
	Date(int _year, int _month, int _day): year(_year), month(_month), day(_day){} 
	friend Thermometer;
	Date(const Date &d);
	~Date();

	Date& operator=(const Date& d)
	{
		day = d.day;
		month = d.month;
		year = d.year;
		return *this;
	}

	int GetDateDay();
	void SetDateDay(int _day);
	int GetDateMonth();
	void SetDateMonth(int _month);
	int GetDateYear();
	void SetDateYear(int _year);
};

void Date::SetDateDay(int _day)
{
	day = _day;
}
int Date::GetDateDay()
{
	return day;
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
	day = d.day;
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
	int GetDay(Date _d);
	int GetN(Date _d);
	int GetDay1(Date _d);
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
	void SaveToFile();
	int Test();
	Date GetD();
	Time GetT();
	void ConsiderFromFile();
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
		values.erase(values.begin(), values.begin()+ values.size());
}

int Thermometer::GetMonth(Date _d)
{
	return _d.GetDateMonth();
}
int Thermometer::GetDay(Date _d)
{
	return _d.GetDateDay();
}
int Thermometer::GetYear(Date _d)
{
	return _d.GetDateYear();
}

Date Thermometer::GetD()
{
	d.day;
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
int Thermometer::GetDay1(Date _d)
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
	Num = GetDay(_d) + GetDay(_d);
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

/*ofstream Thermometer_in;
ifstream Thermometer_out;
ostream &operator<<(ostream& os, const Thermometer &th)
{
	os << th.d.num  << '.' << th.d.month << '.' << th.d.year << '-' << th.t.hour << '|' << th.degree;
	return os;
}*/

void Thermometer::SaveToFile()
{
	/*Thermometer_in << "Degree Counts: " << k << endl;
	for (int i = 0; i < k; i++)
		for (int j = 0; j < 24; j++)
		{
			Thermometer_in << d.num << endl << d.month << endl << d.year << endl << t.hour << endl << values[i][j];
		}*/
	ofstream file("Temp.txt");
	for (int i = 0; i = 365; i++)
	{
		for (int j = 0; j < 24; j++)
			file << values[i][j];
		file << "\n";
	}
}

void Thermometer::ConsiderFromFile()
{
	ifstream file("Temp.txt");
	for (int i = 0; i = 365; i++)
		for (int j = 0; j < 24; j++)
			file >> values[i][j];
	file.close();
}

void main()
{
	int g;
	Date d(2000, 1, 1);
	Time t(0);
	int day, month, year;
	int hour;
	int degree;

	cout << "Enter the date: \n";
	cout << "Enter year: \n";
	cin >> year;
	d.SetDateYear(year);
	cout << "Enter the month: \n";
	cin >> month;
	d.SetDateMonth(month);
	cout << "Enter the day: \n";
	cin >> day;
	d.SetDateDay(day);
	cout << "Enter time: \n";
	cin >> hour;
	t.SetDateHour(hour);
	cout << "Enter degree: \n";
	cin >> degree;
	Thermometer tr(d, t);
	tr.SetDegree(d, t, degree);
	cout << "\n";
	cout << "Enter 1 : Initial date and time of observations: \n";
	cout << "Enter 2 : If you want to know the temperature in the selected observation \n";
	cout << "Enter 3 : If you want to set a series of observations for the selected date \n";
	cout << "Enter 4 : If you want to find the average temperature for the selected date \n";
	cout << "Enter 5 : if you want to find the average temperature for the selected month \n";
	cout << "Enter 6 : If you want to find the average temperature for the whole history of observations \n";
	cout << "Enter 7 : If you want to find the average daily temperature \n";
	cout << "Enter 8 : If you want to find the average night temperature \n";
	cout << "Enter 9 : If you want to save the observation history to a file \n";
	cout << "Enter 10 : If you want to read the observation history from a file \n";
	cin >> g;

	switch (g)
	{
	case 1:
	{
		cout << tr.GetDay(d) << "." << tr.GetMonth(d) << "." << tr.GetYear(d) << "\n";
		cout << tr.GetHour(t) << ".00 \n";
		break;
	}
	case 2:
	{
		cout << "Enter the date: \n";
		cout << "Enter year: \n";
		cin >> year;
		d.SetDateYear(year);
		cout << "Enter the month: \n";
		cin >> month;
		d.SetDateMonth(month);
		cout << "Enter the day: \n";
		cin >> day;
		d.SetDateDay(day);
		cout << "Enter time: \n";
		cin >> hour;
		t.SetDateHour(hour);
		cout << tr.GetDegree(d, t);
	}
	case 3:
	{	// 5
		cout << "Enter the date: \n";
		cout << "Enter year: \n";
		cin >> year;
		d.SetDateYear(year);
		cout << "Enter the month: \n";
		cin >> month;
		d.SetDateMonth(month);
		cout << "Enter the day: \n";
		cin >> day;
		d.SetDateDay(day);
		cout << "Enter degree: \n";
		for (int i = 0; i < 24; i++) {
			cout << i << ".00 \n";
			cin >> degree;
			tr.SetSeveralDegree(d, degree);
		}
		cout << "\n";
	}
	case 4:
	{
		cout << "Enter the date: \n";
		cout << "Enter year: \n";
		cin >> year;
		d.SetDateYear(year);
		cout << "Enter the month: \n";
		cin >> month;
		d.SetDateMonth(month);
		cout << "Enter the day: \n";
		cin >> day;
		d.SetDateDay(day);
		cout << tr.GetAverageDate(d);
	}
	case 5:
	{
		cout << "Enter the month: \n";
		cin >> month;
		cout << tr.GetAverageMonth(month);
	}
	case 6:
	{
		cout << tr.GetAverage();
	}
	case 7:
	{
		cout << "Enter the month: \n";
		cin >> month;
		cout << tr.GetAverageDay(month);
	}
	case 8:
	{
		cout << "Enter the month: \n";
		cin >> month;
		cout << tr.GetAverageNight(month);
	}
	case 9:
	{
		tr.SaveToFile();
	}
	case 10:
	{
		tr.ConsiderFromFile();
	}
	}
system("pause");
}

	