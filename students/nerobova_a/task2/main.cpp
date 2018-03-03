#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;


class  Polinom
{
	int n;
	double *koef;
public:
	int GetDegree(int n);
	double GetCoef(int i);
	double Calculate(double x);
	void Output();
	void Derivative();

	Polinom(): n(0), koef (0) {}
	Polinom(int _n, double _koef[]): n(_n)
	{
		koef = new double[_n + 1];
		for (int i = 0; i <= _n; i++)
			koef[i] = _koef[i];
	}


	Polinom(const Polinom &p);
	~Polinom();

	Polinom& operator=(const Polinom& obj)
	{
		if (this == &obj)
			return *this;
		if (n != obj.n) {
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


double Polinom::GetCoef(int i)
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


int Polinom::GetDegree(int n)
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
		cout << "Degree the polynomial = " << p.GetDegree(n);
		break;
	}
case 2:
{	
	int i = 0;
	cout << "Input index coefficient ";
	cin >> i;
		cout << p.GetCoef(i);
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
		double p;
		double *koef1;
		int tmp;
		tmp = n;
		koef1 = new double[n];
		for (int i = 0; i < tmp; i++) {
			koef1[i] = n * koef[i];
			n--;
		}
		Polinom p1(tmp-1, koef1);
		p1.Output();
	}
	system("pause");
	}
}