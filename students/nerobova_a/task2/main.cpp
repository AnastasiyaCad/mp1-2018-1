#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;


class  Polinom
{
	int n;
	double *koef;
public:
	int Output_n(int n);
	double Output_koef(int i); 
	double Calculate(double x);
	void Output();
	void Derivative();

	Polinom(): n(0), koef (0) {}
	Polinom(int _n, double _koef[]): n(_n), koef(_koef) {}

	Polinom(const Polinom &p);
	~Polinom();

	Polinom& operator=(const Polinom& obj)
	{
		if (this == &obj)
			return *this;
		if (koef != obj.koef) {
			delete[] koef;
			koef = new double[n + 1];
		}
		for (int i = 0; i <= n; i++)
			koef[i] = obj.koef[i];
		koef = obj.koef;
		return *this;
	}
};

Polinom::Polinom(const Polinom &p)
{
	n = p.n;
	koef = new double[n + 1];
	for (int i = 0; i <= n; i++)
		koef[i] = p.koef[i];
}

Polinom::~Polinom() 
{
	delete[] koef;
}


double Polinom::Output_koef(int i)
{
	return koef[i];
};

double Polinom::Calculate(double x)
{
	
	double s = 0;
	int tmp = n;
	double p;

	for (int i = 0; i <= n; i++)
	{
		p = pow(x,n-i) *  koef[i];
		s = s + p;
	}
	return s;
};


int Polinom::Output_n(int n)
{
	return n;
}

void Polinom::Output()
{
	cout << koef[0] << "x^(" << n << ")";
	for (int i = 1; i < n; i++)
	{
		cout << " + " << koef[i] << "x^(" << n - i << ")";
	}
	cout << " + " << koef[n]<<"\n";
}

void Polinom::Derivative()
{
	double p;
	int tmp;
	tmp = n;
	p = n * koef[0];
	n--;
	cout << p << "x^(" << n << ")";
	for (int i = 1; i < tmp-1; i++)
	{
		p = n * koef[i];
		n--;
		cout << " + " << p << "x^(" << n << ")";
	}
	cout << " + " << koef[tmp-1];
		
}

int main()
{
	int n, i;
	int c;
	double koef[13];
	double x;
	cout << "Input degree the polynomialn:  n=  ";
	cin >> n;
	cout << "Input coefficients the polynomial: \n";
	for (int i = 0; i <= n; i++)
	{
		cout << "k" << i << " = ";
		cin >> koef[i];
	}
	Polinom p(n, koef);
	p.Output();

	cout << "Output degree the polynomial- 1 \n";
	cout << "Output index coefficient - 2 \n";
	cout << "Calculate the polynomial value at a given x-point - 3 \n";
	cout << "Derive the derivative of the polynomial - 4 \n";
	cin >> c;
	switch (c)
	{
	case 1:
	{
		cout << "Degree the polynomial = " << p.Output_n(n);
		break;
	}
case 2:
	{
		cout << "Input index coefficient ";
		cin >> i;
		cout << "Coefficient = " << p.Output_koef(i);
		break;
	}
	case 3:
	{
		cout << "Input x = ";
		cin >> x;
		cout << "\n";
		cout << p.Calculate(x);
		break;
	}
	case 4:
	{
		p.Derivative();
		break;
	}
	system("pause");
	}
}