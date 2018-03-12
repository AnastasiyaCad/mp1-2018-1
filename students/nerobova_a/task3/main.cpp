#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
  
class Integral
{
	double a;
	double b;
	int FuncNum;

	double CalculateExp(double x);
	double CalculateCos(double x);
	double CalculateSin(double x);
public:
	Integral() {}
	Integral(double _a, double _b, int _c) : a(_a), b(_b), FuncNum(_c) {} // c- ot 0 do 2
	//double InputParameter_a();
	//double InputParameter_b();
	double PrintParameter_a(double a);
	double PrintParameter_b(double b);
	double NumSegments();
	Integral(const Integral &i);

	double Integral::Calculate(double x) //  FuncNum 0 -sin; 1- cos; 2 - exp;
	{	
		switch (FuncNum)
		{
		case 0:
		{
			return CalculateSin(x);
			break;
		}
		case 1:
		{
			return CalculateCos(x);
			break;
		} 
		case 2:
		{
			return CalculateExp(x);
			break;
		}
		}
	}

	double Integral::Pryamoug(double a, double b, double n)
	{
		int i;
		double result, h;
		result = 0;
		h = (b - a) / n; //Шаг сетки 
		for (i = 0; i < n; i++)
		{
			result += Calculate(a + h * (i + 0.5)); //Вычисляем в средней точке и добавляем в сумму
		}
		result *= h;
		return result;
	}

	double Integral::PryamougPr(double a, double b, double n)
	{
		int i;
		double result, h;
		result = 0;
		h = (b - a) / n; //Шаг сетки
		for (i = 1; i <= n; i++)
		{
			result += Calculate(a + h * i); //Вычисляем в средней точке и добавляем в сумму
		}
		result *= h;
		return result;
		
	}

	double Integral::PryamougLev(double a, double b, double n)
	{
		int i;
		double result, h;
		result = 0;
		h = (b - a) / n; //Шаг сетки
		for (i = 0; i <= n-1; i++)
		{
			result += Calculate(a + h * i); //Вычисляем в средней точке и добавляем в сумму
		}
		result *= h;
		return result;
	}

	Integral& operator=(const Integral &i)
	{

	}
};

Integral::Integral(const Integral &i)
{
	a = i.a;
	b = i.b;
	FuncNum = i.FuncNum;
}
/*
Polinom::~Polinom() 
{
	delete[] koef;
}*/

double sin_reference(double x)
{
	return sin(x);
}
double multsin(double x, int n)
{
	return -x * x / (4 * n * n + 2 * n);
}

double Integral::CalculateSin(double x)
{
	double sum, last;
	double n = 10;
	sum = x;
	last = sum;
	double current = 0.0;
	double val = sin_reference(x);
	double *errors;
	errors = new double[n + 1];
	errors[0] = fabs(sum - val);
	for (int i = 1; i <= n; i++)
	{
		current = last * multsin(x, i);
		sum = sum + current;
		last = current;
		errors[i] = fabs(sum - val);
	}
	return sum;
}

double cos_reference(double x)
{
	return cos(x);
}
double multcos(double x, int n)
{
	return -x * x / (4 * n * n - 2 * n);
}

double Integral::CalculateCos(double x)
{
	double sum, last;
	double n = 10;
	NumSegments(); 
	sum = 1.0;
	last = sum;
	double current = 0.0;
	double val = cos_reference(x);
	double *errors;
	errors = new double[n + 1];
	errors[0] = fabs(sum - val);
	for (int i = 1; i <= n; i++)
	{
		current = last * multcos(x, i);
		sum = sum + current;
		last = current;
		errors[i] = fabs(sum - val);
	}
	return sum;
}

double exp_reference(double x)
{
	return exp(x);
}
double multexp(double x, int n)
{
	return x/n;
}

double Integral::CalculateExp(double x)
{
	double sum, last;
	double n = 10;
	NumSegments();
	sum = 1.0; //
	last = sum; //
	double current = 0.0;
	double val = exp_reference(x); 
	double *errors;
	errors = new double[n + 1];
	errors[0] = fabs(sum - val);
	for (int i = 1; i <= n; i++)
	{
		current = last * multexp(x, i);
		sum = sum + current;
		last = current;
		errors[i] = fabs(sum - val);
	}
	return sum;
}

/*double Integral::InputParameter_a() //введение прарметра а
{
	cin >> a;
	return a;
}

double Integral::InputParameter_b() // введение прарметра в
{
	cin >> b;
	return b;
}*/

double Integral::PrintParameter_a(double a) //узнать предел интегрирования
{
	return a;
}
double Integral::PrintParameter_b(double b)
{
	return b;
}

double Integral::NumSegments() // число отрезков метода
{
	double n;
	cin >> n;
	return n;
}

double InputX()
{
	double x;
	cin >> x;
	return x;
}

int main()
{
	double a;
	double b;
	double n;
	int FuncNum;
	/*InputParameter_a();
	InputParameter_b();*/
	cout << "Input a \n";
	cin >> a;
	cout << "Input b \n";
	cin >> b;
	cout << "Input FuncNum: 0 -sin; 1- cos; 2 - exp \n";
	cin >> FuncNum;
	Integral i(a, b, FuncNum);

	cout << "Input n"; 
	cin >> n;

	int s;
	cout << "1 - lev, 2 - prav, 3 - cred \n";
	cin >> s;
	switch (s)
	{
	case 1:
	{
		cout << i.PryamougLev(a, b, n);
		break;
	}
	case 2:
	{
		cout << i.PryamougPr(a, b, n);
		break;
	}
	case 3:
	{
		cout << i.Pryamoug(a, b, n);
		break;
	}
	}
	system("pause");
}