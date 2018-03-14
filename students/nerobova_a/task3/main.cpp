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
	Integral(double _a, double _b, int _FuncNum) : a(_a), b(_b), FuncNum(_FuncNum) {}
	double GetLeftBound();
	double GetRightBound();
	double InputFuncNum();
	double InputLeftBound();
	double InputRightBound();

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

	double Rectangle(int n)
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

	double RectangleRight(int n)
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

	double RectangleLeft(int n)
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
double Integral::InputFuncNum()
{
	cin >> FuncNum;
	return FuncNum;
}

double Integral::InputLeftBound()
{
	cin >> a;
	return a;
}
double Integral::InputRightBound()
{
	cin >> b;
	return b;
}

int main()
{
	int n;
	Integral i2;
	cout << "Input a \n";
	i2.InputLeftBound();
	cout << "Input b \n";
	i2.InputRightBound();
	cout << "Input FuncNum: 0 -sin; 1- cos; 2 - exp \n";
	i2.InputFuncNum();
	cout << "Input n \n";
	cin >> n;

	int s1;
	cout << "1 - lev, 2 - prav, 3 - cred \n";
	cin >> s1;
	switch (s1)
	{
	case 1:
	{
		cout << i2.RectangleLeft(n) << "\n";
		break;
	}
	case 2:
	{
		cout << i2.RectangleRight(n) << "\n";
		break;
	}
	case 3:
	{
		cout << i2.Rectangle(n) << "\n";
		break;
	}
	return 0;
	}
	cout << "Output the parameter a \n" << i2.GetLeftBound() << "\n";
	cout << "Output the parameter b \n" << i2.GetRightBound() << "\n";
	system("pause");
	return 0;
}