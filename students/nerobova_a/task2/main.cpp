#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class  Polinom
{
	int n;
	float x;
	int *koef;
public:
	void InputPolynom();
	int Print_n();
	void Count();
	void Print_koef();

	Polinom() 
	{
		n = 0;
		koef = new int[n + 2];
		koef[0] = 0;
	};
	Polinom(int _n, int *_koef)
	{
		int a=0;
		for (int i = 0; i < _n; i++)
			if (_koef[i]!=0)

		
	};
	Polinom(const Polinom &p);
	Polinom::~Polinom();
};

Polinom::Polinom(const Polinom &p)
{
	n = p.n;
	koef = new int[n + 2];
	for (int i = 0; i <= n; i++)
		koef[i] = p.koef[i];
}

Polinom::~Polinom() 
{
	delete[] koef;
}

void Polinom::InputPolynom()
{
	cout << "n = ";
	cin >> n;
	koef = new int[n + 2]; // k0*x^n+k1*x^(n-1)+...+k(n-1)*x+kn - k = n+1 
	for (int i = 0; i <= n; i++)
	{
		cout << "k" << i << " = ";
		cin >> koef[i];
	}
}

void Polinom::Print_koef()
{
	int k;
	cout << "¹ koef = ";
	cin >> k;
	for (int i = 0; i <= n; i++)
		if (k == i)
			cout << "koef = " << koef[i];
};

void Polinom::Count()
{
	cout << "x = ";
	cin >> x;
	int s = 0;
	int tmp = n;
	int p;

	for (int i = 0; i <= n; i++)
	{
		p = 0;
		p = koef[i] * x^tmp;
		s = s + p;
		tmp--;
	}

};

int Polinom::Print_n() 
{
	return n;
}



int main()
{

}