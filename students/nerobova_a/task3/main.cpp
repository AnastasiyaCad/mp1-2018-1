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
	Integral(int _a, int _b, int _c) : a(_a), b(_b), FuncNum(_c) {} // c- ot 0 do 2
	double InputParameter_a();
	double InputParameter_b();
	double PrintParameter_a(double a);
	double PrintParameter_b(double b);
	int NumSegments();

	double Integral::Calculate(double x)
	{	
		switch (FuncNum)
		{
		case 0:
		{
			CalculateSin(x);
			break;
		}
		case 1:
		{
			CalculateCos(x);
			break;
		} 
		case 2:
		{
			CalculateExp(x);
			break;
		}
		}
	}
	
};

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
	int n = 10; // можно также запросить у пользователя
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
	double n = 0.0;
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

double Integral::InputParameter_a() //введение прарметра а
{
	cin >> a;
	return a;
}

double Integral::InputParameter_b() // введение прарметра в
{
	cin >> b;
	return b;
}

double Integral::PrintParameter_a(double a) //узнать предел интегрирования
{
	return a;
}
double Integral::PrintParameter_b(double b)
{
	return b;
}

int Integral::NumSegments()
{
	int n;
	cin >> n;
	return n;
}

double Integral::Pryamoug(double a, double b, int n)
{
	//double CalcIntegral(double a, double b, int n)
	//{
		int i;
		double result, h;

		result = 0;

		h = (b - a) / n; //Шаг сетки

		for (i = 0; i < n; i++)
		{
			result += InFunction(a + h * (i + 0.5)); //Вычисляем в средней точке и добавляем в сумму
		}

		result *= h;

		return result;
}

	int main(void)
	{
		double integral;

		integral = CalcIntegral(0, 2, 500);
		printf("The value of the integral is: %lf \n", integral);
		return 0;
	}
}

double InputX()
{
	double x;
	cin >> x;
	return x;
}

double InFunction(double x)
{
	return sin(x); 
}


int main()
{
	int s;
	cout << "Input (0 - sin, 1 - cos, 2 - e^x) \n";
	cin >> s;
	switch (s)
	{
	case 1:
	{

	}
	}
}

/*
double mycos(double x,double eps)
{
double s,an;
int n;
n=0;
an=1;
s=0;
while(fabs(an)>eps)
{
s+=an;
n++;
an*=-x*x/(2.*n-1.0)/(2.0*n);
}
return s;
}
double mysin(double x,double eps)
{
double s,an;
int n;
n=1;
an=x;
s=0;
while(fabs(an)>eps)
{
s+=an;
n++;
an*=-x*x/(2.*n-1.0)/(2.0*n-2.0);
}
return s;
}



double CalcIntegral(double a, double b, int n)
{
	int i;
	double result, h;

	result = 0;

	h = (b - a) / n; //Шаг сетки

	for (i = 0; i < n; i++)
	{
		result += InFunction(a + h * (i + 0.5)); //Вычисляем в средней точке и добавляем в сумму
	}

	result *= h;

	return result;
}

int main(void)
{
	double integral;

	integral = CalcIntegral(0, 2, 500);
	printf("The value of the integral is: %lf \n", integral);
	return 0;
}*/