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
	double NumSegments();
public:
	Integral() {}
	Integral(double _a, double _b, int _c) : a(_a), b(_b), FuncNum(_c) {}
	double OutputParameter_a(double a);
	double OutputParameter_b(double b);
	
	Integral(const Integral &i);
	~Integral();

	double Integral::Calculate(double x)
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
		return 0;
	}

	double Integral::Rectangle(double a, double b, double n)
	{
		int i;
		double result, h;
		result = 0;
		h = (b - a) / n; 
		for (i = 0; i < n; i++)
		{
			result += Calculate(a + h * (i + 0.5));
		}
		result *= h;
		return result;
	}

	double Integral::RectangleRight(double a, double b, double n)
	{
		int i;
		double result, h;
		result = 0;
		h = (b - a) / n;
		for (i = 1; i <= n; i++)
		{
			result += Calculate(a + h * i);
		}
		result *= h;
		return result;
		
	}

	double Integral::RectangleLeft(double a, double b, double n)
	{
		int i;
		double result, h;
		result = 0;
		h = (b - a) / n;
		for (i = 0; i <= n-1; i++)
		{
			result += Calculate(a + h * i);
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

Integral::~Integral() 
{
}

double Integral::CalculateSin(double x)
{
	return sin(x);
}

double Integral::CalculateCos(double x)
{
	return cos(x);
}

double Integral::CalculateExp(double x)
{
	return exp(x);
}

double Integral::OutputParameter_a(double a) 
{
	return a;
}
double Integral::OutputParameter_b(double b)
{
	return b;
}

double Integral::NumSegments()
{
	double n;
	cin >> n;
	return n;
}

int main()
{
	double a;
	double b;
	double n;
	int FuncNum;
	cout << "Input a \n";
	cin >> a;
	cout << "Input b \n";
	cin >> b;
	cout << "Input FuncNum: 0 -sin; 1- cos; 2 - exp \n";
	cin >> FuncNum;
	Integral i(a, b, FuncNum);

	cout << "Input n \n"; 
	cin >> n;

	int s;
	cout << "1 - lev, 2 - prav, 3 - cred \n";
	cin >> s;
	switch (s)
	{
	case 1:
	{
		cout << i.RectangleLeft(a, b, n) << "\n";
		break;
	}
	case 2:
	{
		cout << i.RectangleRight(a, b, n) << "\n";
		break;
	}
	case 3:
	{
		cout << i.Rectangle(a, b, n) << "\n";
		break;
	}
	}

	cout << "Output the parameter a \n" << i.OutputParameter_a(a) << "\n";
	cout << "Output the parameter b \n" << i.OutputParameter_b(b) << "\n";
	
	system("pause");
	return 0;
}