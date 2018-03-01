#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class  Polinom
{
	int n;
	double *koef;
public:
	int Input_n();
	int Output_n(int n);
	int Output_koef(int i); 
	void Input_koef();
	void Calculate();

	Polinom() 
	{
		n = 0;
		koef = new double[n + 1];
		koef[0] = 0;
	};
	Polinom(int _n, double *_koef)
	{
		n = _n;
		koef = new double[_n + 1];
		for (int i = 0; i <= _n; i++)
			koef[i] = _koef[i];
	};

	Polinom(const Polinom &p);
	Polinom::~Polinom();
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

int Polinom::Input_n()
{
	cout << "n = ";
	cin >> n;
	return n;
}

void Polinom::Input_koef()
{
	koef = new double[n + 1]; 
	for (int i = 0; i <= n; i++)
	{
		cout << "k" << i << " = ";
		cin >> koef[i];
	}
}

int Polinom::Output_koef(int i)
{
	return koef[i];
};

void Polinom::Calculate()
{
	int x;
	cout << "x = ";
	cin >> x;
	int s = 0;
	int tmp = n;
	double p;

	for (int i = 0; i <= n; i++)
	{
		p = (x^n) *  koef[i];
		s = s + p;
		tmp--;
	}

};

int Polinom::Output_n(int n)
{
	return n;
}



int main()
{
	int n;
	
	Polinom();
	
	
	

}