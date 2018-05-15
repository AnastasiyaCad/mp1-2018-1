#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <ctime>
using namespace std;

class Computer;
class User;

class Game
{
private:
	User us;
	Computer com;
public:

	// выстрел игрока
	int ShotUser(int x, int y) 
	{
		int status;
		if (com.vCom[x][y] == 1)
		{
			us.vUsCom[x][y] = 2;
			status = 1;
		}
		else
		{
			us.vUsCom[x][y] = 1;
			status = 0;
		}
		return status;
	}


	int ShotComputer()
	{
		int size = com.vCom.size();
		int x, y;
		srand(time(0));
		int tmp = -1;
		while (tmp = -1)
		{
			x = rand() % size;
			y = rand() % size;
			if ((us.vUs[x][y] == 1) && (com.vComUser[x][y] != 2))
			{
				com.vComUser[x][y] = 2;
				tmp = 1;
			}
			else
				if (com.vComUser[x][y] == 2)
					tmp = -1;
				else
				{
					com.vComUser[x][y] = 1;
					tmp = 0;
				}
		}
		return tmp;
	}

	int Strategy(int x, int y)
	{
		srand(time(0));
		int x1 = x;
		int y1 = y;
		int tmp;
		while ((x1 == x) && (y1 == y))
		{
			x1 = rand() % (x + 1) + (x - 1);
			y1 = rand() % (y + 1) + (y - 1);
		}
		if (us.vUs[x1][y1] == 1)
		{
			com.vComUser[x1][y1] = 2;
			tmp = 1;
		}
		else
		{
			com.vComUser[x][y] = 1;
			tmp = 0;
		}
		return tmp;
	}

	void StatusUser()
	{
		us.StatusUs = 0;
	}

	void StatusComputer()
	{
		com.StatusCom = 0;
	}
};

class Computer
{
private:
	vector<vector<int>> vCom;
	vector<vector<int>> vComUser;
	int StatusCom = 1;
public:
	
	friend Game;
	Computer()
	{
		vCom.resize(10);
		for (int i = 0, size = vCom.size(); i < size; i++)
			vCom[i].resize(10);
		for (int i = 0, size = vCom.size(); i < size; i++)
		{
			for (int j = 0, size = vCom.size(); j < size; j++)
			{
				vCom[i][j] = 0;
			}
		}
		/*vComUser.resize(10);
		for (int i = 0, size = vComUser.size(); i < size; i++)
			vComUser[i].resize(10);
		for (int i = 0, size = vComUser.size(); i < size; i++)
		{
			for (int j = 0, size = vComUser.size(); j < size; j++)
			{
				vComUser[i][j] = 0;
			}
		}*/
		/*vCom[17][17] = {
			"   0123456789  ",
			" #============#",
			"0||0000000000||",
			"1||0000000000||",
			"2||0000000000||",
			"3||0000000000||",
			"4||0000000000||",
			"5||0000000000||",
			"6||0000000000||",
			"7||0000000000||",
			"8||0000000000||",
			"9||0000000000||",
			" #============#",
		};
		vComUser[16][16] = {
			"   0123456789  ",
			" #============#",
			"0||0000000000||",
			"1||0000000000||",
			"2||0000000000||",
			"3||0000000000||",
			"4||0000000000||",
			"5||0000000000||",
			"6||0000000000||",
			"7||0000000000||",
			"8||0000000000||",
			"9||0000000000||",
			" #============#",
		}*/
	}

	

	int Ship1(int n, int sizesh) // 0 --> 1 | установка кораблей
	{
		int x, y;
		int tmp = 0;
		srand(time(0));
		int size = vCom.size();
		x = rand() % size +1;
		y = rand() % size +1;
		if (n = 0)
		{
			for (int i = (y - 1); i <= (y + sizesh + 1); i++) // может объект?
				for (int j = (x - 1); j <= (x + 1); j++)
				{
					{
						if ( vCom[j][i] == 0)
						{
							tmp = tmp + 1;
						}
						else
							break;
					}
				}
			if (tmp == (sizesh + 8))
			{
				for (int i = y; i < (y + sizesh); i++)
					vCom[x][i] = 1;
				tmp = 1;
			}
			else
				tmp = 0;
			return tmp;
		}
		else
		{
			for (int i = (x - 1); i <= (x + sizesh + 1); i++) // может объект?
				for (int j = (y - 1); j <= (y + 1); j++)
				{
					{
						if (vCom[i][j] == 0)
						{
							tmp = tmp + 1;
						}
						else
							break;
					}
				}
			if (tmp == (sizesh + 8))
			{
				for (int i = x; i <= (x + sizesh); i++)
					vCom[i][y] = 1;
				tmp = 1;
			}
			else
				tmp = 0;
			return tmp;
		}
	}

	void Ship()
	{
		int n;
		int tmp = 1;
		srand(time(0));
		for (int i = 4; i >= 1; i--)
		{
			for (int j = 1; j <= 4; j++)
			{
				while (tmp == 1)
				{
					n = rand() % 1;
					tmp = Ship1(n, i);
				}
			}
		}
	}

	void Print()
	{
		int size = vCom.size();
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++)
			{
				cout << vCom[x][y];
			}
			cout << "\n";
		}
	}
};

class User
{
private:
	vector<vector<int>> vUs;
	vector<vector<int>> vUsCom;
	int StatusUs = 1;
public:
	friend Game;
	User()
	{
		vUs.resize(10);
		for (int i = 0, size = vUs.size(); i < size; i++)
			vUs[i].resize(10);
		for (int i = 0, size = vUs.size(); i < size; i++)
		{
			for (int j = 0, size = vUs.size(); j < size; j++)
			{
				vUs[i][j] = 0;
			}
		}
		vUsCom.resize(10);
		for (int i = 0, size = vUsCom.size(); i < size; i++)
			vUsCom[i].resize(10);
		for (int i = 0, size = vUsCom.size(); i < size; i++)
		{
			for (int j = 0, size = vUsCom.size(); j < size; j++)
			{
				vUsCom[i][j] = 0;
			}
		}
	}
	
	int GameUser(int x, int y, int n, int sizesh)
	{
		int size = vUs.size();
		int status;
		if (n = 0)
		{
			if (((y + sizesh - 1) <= size) && (x <= size))
			{
				vUs[x][y] = 1;
				status = 1;
			}

			else
				status = 0;
		}
		else
		{
			if (((x + sizesh - 1) <= size) && (y <= size))
			{
				vUs[x][y] = 1;
				status = 1;
			}

			else
				status = 0;
		}
		return status;
	}
};



void main()
{
  /*   1 2 3 4 5 6 7 8
	 ==================________________
|1 ||0 0 0 0 0 0 0 0 ||
 2 ||
 3 ||
 */
	Computer com;
	User us;
	//com.Ship(); // бот расставил корбали
	com.Print();
	system("pause");
}