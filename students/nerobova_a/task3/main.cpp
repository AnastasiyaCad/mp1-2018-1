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
	Integral(double _a, double _b, int _c) : a(_a), b(_b), FuncNum(_c) {}
	double GetLeftBound();
	double GetRightBound();
	
	Integral(const Integral &i);
	~Integral();

	double Calculate(double x)
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

	double Rectangle(double n)
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

	double RectangleRight(double n)
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

	double RectangleLeft(double n)
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
		a = i.a;
		b = i.b;
		FuncNum = i.FuncNum;
		return *this;
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

double Integral::GetLeftBound()
{
	return a;
}
double Integral::GetRightBound()
{
	return b;
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
		cout << i.RectangleLeft(n) << "\n";
		break;
	}
	case 2:
	{
		cout << i.RectangleRight(n) << "\n";
		break;
	}
	case 3:
	{
		cout << i.Rectangle(n) << "\n";
		break;
	}
	}

	cout << "Output the parameter a \n" << i.GetLeftBound() << "\n";
	cout << "Output the parameter b \n" << i.GetRightBound() << "\n";
	
	system("pause");
	return 0;
}