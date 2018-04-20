#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>

using namespace std;

struct Person
{
	string CardNumber;
	string PinCode;
	string FullName;
	int Score;
	int StatusCart;
	Person &operator=(const Person &per)
	{
		this->CardNumber = per.CardNumber;
		this->PinCode = per.PinCode;
		this->FullName = per.FullName;
		this->Score = per.Score;
		this->StatusCart = per.StatusCart;
		return *this;
	}
	friend ostream &operator<<(ostream& os, const Person &_pr);
	bool operator ==(const Person &tmp) const
	{
		return (this->CardNumber == tmp.CardNumber && this->PinCode == tmp.PinCode && this->FullName == tmp.FullName && this->Score == tmp.Score && this->StatusCart == tmp.StatusCart);
	}
};
 
class ATM;
class ProcessingCenter
{
private:
	Person person;
	vector<Person> person_v;
public:
	ProcessingCenter(): person_v() {}
	ProcessingCenter(vector<Person> _v): person_v(_v) {}
	friend Person;
	friend ATM;
	void GetPerson();
	int OutputFile();
	void SetCount(const int i, string _CardNumber, string _PinCode, string _FullName, int _Score, int _StatusCart);
};

void ProcessingCenter::SetCount(const int i, string _CardNumber, string _PinCode, string _FullName, int _Score, int _StatusCart)
{
	person.CardNumber = _CardNumber;
	person.PinCode = _PinCode;
	person.FullName = _FullName;
	person.Score = _Score;
	person.StatusCart = _StatusCart;
}

//ofstream Person_in;
//ifstream Person_out;
ostream &operator<<(ostream& os, const Person &_pr)
{
	os << _pr.CardNumber << '.' << _pr.PinCode << '.' << _pr.FullName << '.' << _pr.Score << '.' << _pr.StatusCart;
	return os;
}
	
int ProcessingCenter::OutputFile()
{
	char per[100];
	int size;
	ifstream file("C:/Games/Temp.txt");
	//if (!file.is_open())
	if (!file)
		cout << "The file can not be opened!\n"; 
	else
	{
		file >> size;
		file.getline(per, 3);
		for (int i = 0; i < size; i++)
		{
			file.getline(per, 5, '.');
			person.CardNumber = per;
			file.getline(per, 5, '.');
			person.PinCode = per;
			file.getline(per, 50, '.');
			person.FullName = per;
			file.getline(per, 20, '.');
			person.Score = atoi(per);
			file.getline(per, 3, '\n');
			person.StatusCart = atoi(per);
			person_v.push_back(person);
		}

		file.close();
		return size;
	}
	return 0;
}

void ProcessingCenter::GetPerson()
{

}

class ATM
{
private:
	int Case100;
	int Case200;
	int Case500;
	int Case1000;
	int Case2000;
	int Case5000;
	ProcessingCenter pr;
	//int _Case100 = 1600000, int _Case200 = 1600000, int _Case500 = 1600000, int _Case1000 = 1600000, int _Case2000 = 1600000, int _Case5000 = 1600000
public:
	ATM(): Case100(1600000), Case200(1600000), Case500(1600000), Case1000(1600000), Case2000(1600000), Case5000(1600000){}
	int AcceptCardClient(int size, string _CardNumber);
	int FindCartClient(int size, string _CardNumber);
	string ReturnFullName(int i);
	int FindCardClient2(int i, string _CardNumber);
	int CheckPinCode(int k, string _CardNumber);
	void ChangeStatusCard(int i);
	int CustomerAccountBalance(int i);
	int ReturnCardStatus(int i);
	void WithdrawCashFromTheAccount(int i, int _Case100, int _Case200, int _Case500, int _Case1000, int _Case2000, int _Case5000);
};
//проверяем есть ли карта с таким номером
int ATM::AcceptCardClient(int size, string _CardNumber) // print your card adopted
{
	int tmp = 0;
	for (int i = 0; i < size; i++)
	{
		if (pr.person_v[i].CardNumber == _CardNumber)
		{
			tmp = 1;
			break;
		}
	}
	return tmp;
}
//находим карту клиента
int ATM::FindCartClient(int size, string _CardNumber)
{
	int tmp;
	for (int i = 0; i < size; i++)
	{
		if (pr.person_v[i].CardNumber == _CardNumber)
		{
			tmp = i;
			break;
		}
	}
	return tmp;
}

string ATM::ReturnFullName(int i)
{
	return pr.person_v[i].FullName;
}

int ATM::FindCardClient2(int i, string _PinCode)
{
	int tmp = 0;
	if (pr.person_v[i].PinCode == _PinCode)
	{
		tmp = 1;
	}
	return tmp;
}

void ATM::ChangeStatusCard(int i)
{
	pr.person_v[i].StatusCart = 0;
}

int ATM::CustomerAccountBalance(int i)
{
	return pr.person_v[i].Score;
}

int ATM::ReturnCardStatus(int i)
{
	return pr.person_v[i].StatusCart;
}

void ATM::WithdrawCashFromTheAccount(int i, int _Case100, int _Case200, int _Case500, int _Case1000, int _Case2000, int _Case5000) //списать выданную сумму со счета
{
	int p;
	if ((Case100 >= _Case100) && (Case200 >= _Case200) && (Case500 = _Case500) && (Case1000 = _Case1000) && (Case2000 = _Case2000) && (Case5000 = _Case5000))
	{
		Case100 = Case100 - _Case100;
		Case200 = Case200 - _Case200;
		Case500 = Case500 - _Case500;
		Case1000 = Case1000 - _Case1000;
		Case2000 = Case2000 - _Case2000;
		Case5000 = Case5000 - _Case5000;
		p = 100 * _Case100 + 200 * _Case200 + 500 * _Case500 + 1000 * _Case1000 + 2000 * _Case2000 + 5000 * _Case5000;
		if (p <= pr.person_v[i].Score)
		{
			pr.person_v[i].Score = pr.person_v[i].Score - p;
		}
		else
		{
			cout << "The operation was not performed. Not enough money on the account.\n";
		}
	}
	else
	{

	}
}



void main()
{
	ProcessingCenter Pr;
	ATM ATM;
	string CardNumber;
	string PinCode;
	string FullName;
	int Score;
	int StatusCart;
	int size;
	size = Pr.OutputFile();
	cout << size << "\n";
	int end = 1;
	int end2 = 1;
	
	cout << ATM.ReturnCardStatus(1);
	/*while (end == 1)
	{
		cout << "Enter the card: \n";
		//getline(cin, CardNumber);
		cin >> CardNumber;
		if (ATM.AcceptCardClient(size, CardNumber) != 1)
		{
			while (ATM.AcceptCardClient(size, CardNumber) != 1)
			{
				cout << "Your card is not accepted!\n";
				cout << "Enter the card: \n";
				//getline(cin, CardNumber);
				cin >> CardNumber;
			}
		}

		// проверяем статус карты
		int i;
		i = ATM.FindCartClient(size, CardNumber);

		int tmp = 0;
		if (ATM.ReturnCardStatus(i) == 0)
		{
			cout << "";
			//break;
		}
		cout << "Your card has been accepted.\n";

		while (end2 == 1)
		{
			for (int k = 0; k < 2; k++)
			{
				cout << "Enter password: \n";
				getline(cin, PinCode);
				if (ATM.FindCardClient2(i, PinCode) == 1)
				{
					cout << "Your card adopted!";
					break;
				}
				else
				{
					cout << "The password is incorrect!\n";
					tmp++;
				}
			}
			if (tmp >= 3)
			{
				cout << "Your card is locked! \n";
				ATM.ChangeStatusCard(i);

			}

			int a;
			cout << "Customer account balance - 1\n";
			cout << "Withdraw money from the account - 2\n";
			cout << "Transfer money from an account - 3\n";
			cout << "Exit - 4\n";
			cin >> a;
			switch (a)
			{
			case 1:
			{
				cout << ATM.CustomerAccountBalance(i);
				break;
			}
			case 2:
			{
				int _case100;
				int _case200;
				int _case500;
				int _case1000;
				int _case2000;
				int _case5000;
				cout << "Enter 100: ";
				cin >> _case100;
				cout << "Enter 200: ";
				cin >> _case200;
				cout << "Enter 500: ";
				cin >> _case500;
				cout << "Enter 1000: ";
				cin >> _case1000;
				cout << "Enter 2000: ";
				cin >> _case2000;
				cout << "Enter 5000: ";
				cin >> _case5000;
				ATM.WithdrawCashFromTheAccount(i, _case100, _case200, _case500, _case1000, _case2000, _case5000);
				break;
			}
			case 3:
			{
				int _case100;
				int _case200;
				int _case500;
				int _case1000;
				int _case2000;
				int _case5000;
				cout << "Enter 100: ";
				cin >> _case100;
				cout << "Enter 200: ";
				cin >> _case200;
				cout << "Enter 500: ";
				cin >> _case500;
				cout << "Enter 1000: ";
				cin >> _case1000;
				cout << "Enter 2000: ";
				cin >> _case2000;
				cout << "Enter 5000: ";
				cin >> _case5000;
				break;
			}
			case 4:
			{
				end2 = 0;
				break;
			}
			}
		}
	}*/

}