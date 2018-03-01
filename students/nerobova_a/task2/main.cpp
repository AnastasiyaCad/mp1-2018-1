#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;

class  Polinom
{
	int n;
	//int koef[13];
	int *koef;
public:
	void InputPolynom();
	Polinom() 
	{
		n = 0;
		koef = new int[n + 2];
		koef[0] = 0;
	};
	Polinom(int _n, int *_koef)
	{
		for (int i = 0; i < _n; i++)
		{

		}
	};


};

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


int main()
{

}