#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <ctime>
#include <list>
#include <queue>

using namespace std;

class Computer
{
private:
	vector<vector<int>> vCom;
	vector<vector<int>> vComUser;
	vector<vector<int>> vCoordCom;
	vector<vector<int>> vShip;	
public:
	Computer()
	{
		vCom.resize(12);
		for (int i = 0, size = vCom.size(); i < size; i++)
			vCom[i].resize(12);
		for (int i = 0, size = vCom.size(); i < size; i++)
		{
			for (int j = 0, size = vCom.size(); j < size; j++)
			{
				vCom[i][j] = 0;
			}
		}

		vComUser.resize(12);
		for (int i = 0, size = vComUser.size(); i < size; i++)
			vComUser[i].resize(12);
		for (int i = 0, size = vComUser.size(); i < size; i++)
		{
			for (int j = 0, size = vComUser.size(); j < size; j++)
			{
				vComUser[i][j] = 0;
			}
		}

		vCoordCom.resize(10);

		vShip.resize(10);
		vShip[0].resize(4);
		vShip[1].resize(3);
		vShip[2].resize(3);
		vShip[3].resize(2);
		vShip[4].resize(2);
		vShip[5].resize(2);
		vShip[6].resize(1);
		vShip[7].resize(1);
		vShip[8].resize(1);
		vShip[9].resize(1);

		for (int i = 0, size = vShip.size(); i < size; i++)
			for (int j = 0, size = vShip[i].size(); j < size; j++)
			{
				vShip[i][j] = 1;
			}
	}
	
	int Ship1(int n, int sizesh, int ch) // 0 --> 1 | установка кораблей n 
	{
		srand(time(0));
		int x, y;
		int tmp;
		int status = 0;
		int size = vCom.size();
		x = rand() % (size - 2) + 1; // [1 - 10]
		y = rand() % (size - 2) + 1;

		if ((n == 0) && ((y + sizesh - 1) <= (size - 2)))
		{
			tmp = 0;
			for (int i = (y - 1); i <= (y + sizesh); i++)
			{
				for (int j = (x - 1); j <= (x + 1); j++)
				{
					if (vCom[j][i] == 0)
					{
						tmp++;
					}
					else
						break;

				}
			}
			if (tmp == (6 + 3 * sizesh))
			{
				vCoordCom[ch].resize(sizesh + 1);
				int c1 = 0;
				int c2 = 1;

				for (int i = y; i < (y + sizesh); i++)
				{
					vCoordCom[ch][c1] = x;
					vCom[x][i] = 1;
					vCoordCom[ch][c2] = i;
					c1++;
					c2++;
				}
				status = 1;
			}
		}
		if (((n == 1) && ((x + sizesh - 1) <= (size - 2))))
		{
			tmp = 0;
			for (int i = (x - 1); i <= (x + sizesh); i++)
				for (int j = (y - 1); j <= (y + 1); j++)
				{
					{
						if (vCom[i][j] == 0)
						{
							tmp++;
						}
						else
							break;
					}
				}
			if (tmp == (6 + 3 * sizesh))
			{
				vCoordCom[ch].resize(sizesh + 1);
				int c1 = 0;
				int c2 = 1;

				for (int i = x; i < (x + sizesh); i++)
				{
					vCom[i][y] = 1;
					vCoordCom[ch][c1] = i;
					vCoordCom[ch][c2] = y;
					c1++;
					c2++;
				}
				status = 1;
			}
		}
		return status;
	}

	int Ship()
	{
		int tmp;
		int n;
		int status = 0;
		srand(time(0));
		int ch = 0;
		for (int i = 4; i >= 1; i--)
		{
			tmp = 4;
			while (tmp >= i)
			{
				status = 0;
				while (status == 0)
				{
					n = rand() % 2;
					status = Ship1(n, i, ch);
				}
				ch++;
				tmp--;
			}
		}
		return status;
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

	void Print2()
	{
		int size = vComUser.size();
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++)
			{
				cout << vComUser[x][y];
			}
			cout << "\n";
		}
	}

	int ReturnVCom(int x, int y)
	{
		return vCom[x][y];
	}

	void VCom(int x, int y, int n)
	{
		vCom[x][y] = n;
	}

	int ReturnVComUser(int x, int y)
	{
		return vComUser[x][y];
	}

	void VComUser(int x, int y, int n)
	{
		vComUser[x][y] = n;
	}

	int ReturnSizeCom()
	{
		return vCom.size();
	}
	
	int ReturnVCoordCom(int x, int y)
	{
		return vCoordCom[x][y];
	}

	vector<int>ReturnShip(int x, int y) /////
	{
		vector<int>v;
		v.resize(2);
		int size = -1;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 4; j++) {
				if ((vCoordCom[i][j] == x) && (vCoordCom[i][j + 1] == y))
				{
					v[0] = i; // вернуть размер и место x
					v[1] = j;
				}
			}
		return v;
	}

	int ReturnShip1(int x, int y) /////
	{
		int tmp;
		int size = -1;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 4; j++) {
				if ((vCoordCom[i][j] == x) && (vCoordCom[i][j + 1] == y))
				{
					tmp = i; // вернуть размер и место x
				}
			}
		return tmp;
	}

	void ExShip(int i, int j)
	{
		vShip[i][j] = 0;
	}

	int Kill(int sizech)
	{
		int status = 0;
		int tmp = 0;
		int size = vShip[sizech].size();
		for (int i = 0; i < size; i++)
			if (vShip[sizech][i] == 0)
				tmp++;
		if (tmp == size)
			status = 1;
		return status;
	}

	int Loss()
	{
		int status = 0;
		int tmp = 0;
		int size = vShip.size();
		for (int i = 0; i < size; i++)
			for (int j = 0, size1 = vShip[i].size(); j < size1; j++)
				if (vShip[i][j] == 0)
					tmp++;
		if (tmp == size)
			status = 1;
		return status;
	}
};

class User
{
private:
	vector<vector<int>> vUs;
	vector<vector<int>> vUsCom;
	vector<vector<int>> vCoordUs;
	vector<vector<int>> vShip;
public:
	User()
	{
		vUs.resize(12);
		for (int i = 0, size = vUs.size(); i < size; i++)
			vUs[i].resize(12);
		for (int i = 0, size = vUs.size(); i < size; i++)
		{
			for (int j = 0, size = vUs.size(); j < size; j++)
			{
				vUs[i][j] = 0;
			}
		}
		vUsCom.resize(12);
		for (int i = 0, size = vUsCom.size(); i < size; i++)
			vUsCom[i].resize(12);
		for (int i = 0, size = vUsCom.size(); i < size; i++)
		{
			for (int j = 0, size = vUsCom.size(); j < size; j++)
			{
				vUsCom[i][j] = 0;
			}
		}
		vCoordUs.resize(10);

		vShip.resize(10);
		vShip[0].resize(4);
		vShip[1].resize(3);
		vShip[2].resize(3);
		vShip[3].resize(2);
		vShip[4].resize(2);
		vShip[5].resize(2);
		vShip[6].resize(1);
		vShip[7].resize(1);
		vShip[8].resize(1);
		vShip[9].resize(1);

		for (int i = 0, size = vShip.size(); i < size; i++)
			for (int j = 0, size = vShip[i].size(); j < size; j++)
			{
				vShip[i][j] = 1;
			}
	}

	int ShipUser1(int x, int y, int n, int sizesh, int ch)
	{
		int tmp;
		int size = vUs.size();
		int status = 0;
		if ((n == 0) && ((y + sizesh - 1) <= (size - 2)))
		{
			tmp = 0;
			for (int i = (y - 1); i <= (y + sizesh); i++)
			{
				for (int j = (x - 1); j <= (x + 1); j++)
				{
					if (vUs[j][i] == 0)
					{
						tmp++;
					}
					else
						break;
				}
			}
			if (tmp == (6 + 3 * sizesh))
			{
				vCoordUs[ch].resize(sizesh + 1);
				int c1 = 0;
				int c2 = 1;
				for (int i = y; i < (y + sizesh); i++)
				{
					vCoordUs[ch][c1] = x;
					vUs[x][i] = 1;
					vCoordUs[ch][c2] = i;
					c1++;
					c2++;
				}
				status = 1;
			}
		}
		if (((n == 1) && ((x + sizesh - 1) <= (size - 2))))
		{
			tmp = 0;
			for (int i = (x - 1); i <= (x + sizesh); i++)
				for (int j = (y - 1); j <= (y + 1); j++)
				{
					{
						if (vUs[i][j] == 0)
						{
							tmp++;
						}
						else
							break;
					}
				}
			if (tmp == (6 + 3 * sizesh))
			{
				vCoordUs[ch].resize(sizesh + 1);
				int c1 = 0;
				int c2 = 1;
				for (int i = x; i < (x + sizesh); i++)
				{
					vUs[x][i] = 1;
					vCoordUs[ch][c1] = i;
					vCoordUs[ch][c2] = y;
					c1++;
					c2++;
				}
				status = 1;
			}
		}
		return status;
	}

	int ShipUser(int x, int y, int n, int sizesh, int ch)
	{
		int tmp;
		int status = 0;
		int size = vUs.size();
		if ((n == 0) && ((y + sizesh - 1) <= (size - 2)))
		{
			tmp = 0;
			for (int i = (y - 1); i <= (y + sizesh); i++)
			{
				for (int j = (x - 1); j <= (x + 1); j++)
				{
					if (vUs[j][i] == 0)
					{
						tmp++;
					}
					else
						break;

				}
			}
			if (tmp == (6 + 3 * sizesh))
			{
				vCoordUs[ch].resize(sizesh + 1);
				int c1 = 0;
				int c2 = 1;

				for (int i = y; i < (y + sizesh); i++)
				{
					vCoordUs[ch][c1] = x;
					vUs[x][i] = 1;
					vCoordUs[ch][c2] = i;
					c1++;
					c2++;
				}
				status = 1;
			}
		}
		if (((n == 1) && ((x + sizesh - 1) <= (size - 2))))
		{
			tmp = 0;
			for (int i = (x - 1); i <= (x + sizesh); i++)
				for (int j = (y - 1); j <= (y + 1); j++)
				{
					{
						if (vUs[i][j] == 0)
						{
							tmp++;
						}
						else
							break;
					}
				}
			if (tmp == (6 + 3 * sizesh))
			{
				vCoordUs[ch].resize(sizesh + 1);
				int c1 = 0;
				int c2 = 1;

				for (int i = x; i < (x + sizesh); i++)
				{
					vUs[i][y] = 1;
					vCoordUs[ch][c1] = i;
					vCoordUs[ch][c2] = y;
					c1++;
					c2++;
				}
				status = 1;
			}
		}
		return status;
	}

	void Print()
	{
		int size = vUs.size();
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++)
			{
				cout << vUs[x][y];
			}
			cout << "\n";
		}
	}
	void Print2()
	{
		int size = vUsCom.size();
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++)
			{
				cout << vUsCom[x][y];
			}
			cout << "\n";
		}
	}

	int ReturnVUs(int x, int y)
	{
		return vUs[x][y];
	}

	void VUs(int x, int y, int n)
	{
		vUs[x][y] = n;
	}

	int ReturnVUsCom(int x, int y)
	{
		return vUsCom[x][y];
	}

	void VUsCom(int x, int y, int n)
	{
		vUsCom[x][y] = n;
	}

	vector<int>ReturnShip(int x, int y) /////
	{
		vector<int>v;
		v.resize(2);
		int size = -1;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 4; j++) {
				if ((vCoordUs[i][j] == x) && (vCoordUs[i][j + 1] == y))
				{
					v[0] = i; // вернуть размер и место x
					v[1] = j;
				}
			}
		return v;
	}

	int ReturnShip1(int x, int y) /////
	{
		int tmp;
		int size = -1;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < 4; j++) {
				if ((vCoordUs[i][j] == x) && (vCoordUs[i][j + 1] == y))
				{
					tmp = i; // вернуть размер и место x
				}
			}
		return tmp;
	}

	void ExShip(int i, int j)
	{
		vShip[i][j] = 0;
	}

	int Kill(int sizech)
	{
		int status = 0;
		int tmp = 0;
		int size = vShip[sizech].size();
		for (int i = 0; i < size; i++)
			if (vShip[sizech][i] == 0)
				tmp++;
		if (tmp == size)
			status = 1;
		return status;
	}

	int Loss()
	{
		int status = 0;
		int tmp = 0;
		int size = vShip.size();
		for (int i = 0; i < size; i++)
			for (int j = 0, size1 = vShip[i].size(); j < size1; j++)
				if (vShip[i][j] == 0)
					tmp++;
		if (tmp == size)
			status = 1;
		return status;
	}
};

class Game
{
private:
	int tmp;
	int x2;
	int y2;
	User us;
	Computer com;
	list<int> Movies;
	list<int> Movies1;
	queue <int> q;
	int counter = 0;
	vector<int> vXY;
public:
	Game() { vXY.resize(2); }
	// выстрел игрока
	int ShotUser(int x, int y)
	{
		int status;
		vector<int> v;
		if (com.ReturnVCom(x, y) == 1)
		{
			us.VUsCom(x, y, 2);
			v = com.ReturnShip(x, y);//#
			com.ExShip(v[0], v[1]);
			status = 1;
		}
		else
		{
			us.VUsCom(x, y, 1);
			status = 0;
		}
		return status;
	}
	//
	int ShotComputer()
	{
		int size = com.ReturnSizeCom();
		int x, y;
		vector<int> v;
		srand(time(0));
		int status = -1;
		while (status = -1)
		{
			x = rand() % (size - 2) + 1;
			y = rand() % (size - 2) + 1;
			if ((us.ReturnVUs(x, y) == 1) && (com.ReturnVComUser(x, y) == 0))
			{
				com.VComUser(x, y, 2);
				v = us.ReturnShip(x, y);//#
				us.ExShip(v[0], v[1]);
				status = 1;
				vXY[0] = x;
				vXY[1] = y;
			}
			else
				if (com.ReturnVComUser(x, y) == 2)
					status = -1;
				else
				{
					com.VComUser(x, y, 1);
					status = 0;
				}
		}
		return status;
	}
	//
	int ShotComputer1(int x, int y)
	{
		int size = com.ReturnSizeCom();
		vector<int> v;
		srand(time(0));
		int status;
		if (us.ReturnVUs(x, y) == 1)
		{
			com.VComUser(x, y, 2);
			v = us.ReturnShip(x, y);//#
			us.ExShip(v[0], v[1]);
			status = 1;
		}
		else
		{
			com.VComUser(x, y, 1);
			status = 0;
		}
		return status;
	}
	//
	void MoviesAdd(int x, int y)
	{
		Movies.push_back(x - 1);//
		Movies.push_back(y);
		Movies.push_back(x + 1);//
		Movies.push_back(y);
		Movies.push_back(x);//
		Movies.push_back(y + 1);
		Movies.push_back(x);
		Movies.push_back(y - 1);
	}
	//
	void MDelit()
	{
		while (!Movies.empty())
			Movies.pop_front();
	}
	//
	int Strategy(int x, int y)
	{
		int x1, y1;
		int status = 0;
		x2 = x;
		y2 = y;
		if ((x != 1) || (y != 1) || (x != 10) || (y != 10))
		{
			x1 = Movies.front();//1
			Movies.pop_front();
			y1 = Movies.front();
			Movies.pop_front();
			if (ShotComputer1(x1, y1) != 1) //*
			{
				status = 0;
				counter++;
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1)) //*
			{
				us.ExShip(x1, y1);
				counter = 0;
				status = 1;
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))//2
			{
				MDelit();
				MoviesAdd(x1, y1);

				for (int i = 0; i < counter; i++)
				{
					Movies.pop_front();
					Movies.pop_front();
				}

				x1 = Movies.front();
				Movies.pop_front();
				y1 = Movies.front();
				Movies.pop_front();
				if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))//3
				{
					MDelit();
					MoviesAdd(x1, y1);

					for (int i = 0; i < counter; i++)
					{
						Movies.pop_front();
						Movies.pop_front();
					}

					x1 = Movies.front();
					Movies.pop_front();
					y1 = Movies.front();
					Movies.pop_front();
					if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
					{
						status = 1;
						counter = 0;
						us.ExShip(x1, y1);
					}
					else
					{
						counter++;
						status = 0;
						MoviesAdd(x2, y2);
						for (int i = 0; i < counter; i++)
						{
							Movies.pop_front();
							Movies.pop_front();
						}
						x1 = Movies.front();
						Movies.pop_front();
						y1 = Movies.front();
						Movies.pop_front();
						if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
						{
							us.ExShip(x1, y1);
							counter = 0;
							status = 1;
						}
					}
				}
				if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
				{
					counter = 0;
					status = 1;
					us.ExShip(x1, y1);
				}
				if (ShotComputer1(x1, y1) != 1)
				{
					status = 0;
					counter++;
					MoviesAdd(x2, y2);
					for (int i = 0; i < counter; i++)
					{
						Movies.pop_front();
						Movies.pop_front();
					}
				}

			}
		}
		if ((x == 1) && (y == 1)) ///
		{
			counter++;
			for (int i = 0; i < counter; i++)
			{
				Movies.pop_front();
				Movies.pop_front();
			}
		
			x1 = Movies.front();
			Movies.pop_front();
			y1 = Movies.front();
			Movies.pop_front();
			if (ShotComputer1(x1, y1) != 1)
			{
				status = 0;
				counter++;
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				us.ExShip(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))
			{
				while (com.Kill(com.ReturnShip1(x1, y1)) != 1)
				{
					MoviesAdd(x1, y1);
					for (int i = 0; i < counter; i++)
					{
						Movies.pop_front();
						Movies.pop_front();
					}
					x1 = Movies.front();
					Movies.pop_front();
					y1 = Movies.front();
					Movies.pop_front();
				}
				status = 1;
				counter = 0;
				us.ExShip(x1, y1);
			}
		}
		if ((x == 10) && (y == 1)) ///
		{
			for (int i = 0; i < counter; i++)
			{
				Movies.pop_front();
				Movies.pop_front();
			}
			x1 = Movies.front();
			Movies.pop_front();
			y1 = Movies.front();
			Movies.pop_front();
			if (ShotComputer1(x1, y1) != 1)
			{
				status = 0;
				counter++;
				counter++;
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				us.ExShip(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))
			{
				while (com.Kill(com.ReturnShip1(x1, y1)) != 1)
				{
					MoviesAdd(x1, y1);
					for (int i = 0; i < counter; i++)
					{
						Movies.pop_front();
						Movies.pop_front();
					}
					x1 = Movies.front();
					Movies.pop_front();
					y1 = Movies.front();
					Movies.pop_front();
				}
				status = 1;
				counter = 0;
				us.ExShip(x1, y1);
			}
		}
		if ((x == 1) && (y == 10))///
		{
			counter++;
			for (int i = 0; i < counter; i++)
			{
				Movies.pop_front();
				Movies.pop_front();
			}

			x1 = Movies.front();
			Movies.pop_front();
			y1 = Movies.front();
			Movies.pop_front();
			if (ShotComputer1(x1, y1) != 1)
			{
				status = 0;
				counter++;
				counter++;
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				us.ExShip(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))
			{
				while (com.Kill(com.ReturnShip1(x1, y1)) != 1)
				{
					MoviesAdd(x1, y1);
					for (int i = 0; i < counter; i++)
					{
						Movies.pop_front();
						Movies.pop_front();
					}
					x1 = Movies.front();
					Movies.pop_front();
					y1 = Movies.front();
					Movies.pop_front();
				}
				status = 1;
				counter = 0;
				us.ExShip(x1, y1);
			}
		}
		if ((x == 10) && (y == 10)) ///
		{
			for (int i = 0; i < counter; i++)
			{
				Movies.pop_front();
				Movies.pop_front();
			}
			x1 = Movies.front();
			Movies.pop_front();
			y1 = Movies.front();
			Movies.pop_front();
			if (ShotComputer1(x1, y1) != 1)
			{
				status = 0;
				counter++;
				counter++;
				counter++;
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				us.ExShip(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))
			{
				while (com.Kill(com.ReturnShip1(x1, y1)) != 1)
				{
					MoviesAdd(x1, y1);
					for (int i = 0; i < counter; i++)
					{
						Movies.pop_front();
						Movies.pop_front();
					}
					x1 = Movies.front();
					Movies.pop_front();
					y1 = Movies.front();
					Movies.pop_front();
				}
				status = 1;
				counter = 0;
				us.ExShip(x1, y1);
			}
		}
		if ((x == 1) && (y != 1) && (y != 10))
		{
			counter++;
			for (int i = 0; i < counter; i++)
			{
				Movies.pop_front();
				Movies.pop_front();
			}

			x1 = Movies.front();
			Movies.pop_front();
			y1 = Movies.front();
			Movies.pop_front();
			if (ShotComputer1(x1, y1) != 1)
			{
				status = 0;
				counter++;
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				us.ExShip(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))
			{
				MDelit();
				MoviesAdd(x1, y1);
				for (int i = 0; i < counter; i++)
				{
					Movies.pop_front();
					Movies.pop_front();
				}
				x1 = Movies.front();
				Movies.pop_front();
				y1 = Movies.front();
				Movies.pop_front();

				if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))//2
				{
					MDelit();
					MoviesAdd(x1, y1);

					for (int i = 0; i < counter; i++)
					{
						Movies.pop_front();
						Movies.pop_front();
					}

					x1 = Movies.front();
					Movies.pop_front();
					y1 = Movies.front();
					Movies.pop_front();
					if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))//3
					{
						MDelit();
						MoviesAdd(x1, y1);

						for (int i = 0; i < counter; i++)
						{
							Movies.pop_front();
							Movies.pop_front();
						}

						x1 = Movies.front();
						Movies.pop_front();
						y1 = Movies.front();
						Movies.pop_front();
						if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
						{
							status = 1;
							counter = 0;
							us.ExShip(x1, y1);
						}
						else
						{
							counter++;
							status = 0;
							MoviesAdd(x2, y2);
							for (int i = 0; i < counter; i++)
							{
								Movies.pop_front();
								Movies.pop_front();
							}
							x1 = Movies.front();
							Movies.pop_front();
							y1 = Movies.front();
							Movies.pop_front();
							if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
							{
								counter = 0;
								status = 1;
								us.ExShip(x1, y1);
							}
						}
					}
				}
			}
			  
		}
		if ((x == 10) && (y != 1) && (y != 10))
		{
			for (int i = 0; i < counter; i++)
			{
				Movies.pop_front();
				Movies.pop_front();
			}

			x1 = Movies.front();
			Movies.pop_front();
			y1 = Movies.front();
			Movies.pop_front();
			if (ShotComputer1(x1, y1) != 1)
			{
				status = 0;
				counter++;
				counter++;
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				us.ExShip(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))
			{
				MDelit();
				MoviesAdd(x1, y1);
				for (int i = 0; i < counter; i++)
				{
					Movies.pop_front();
					Movies.pop_front();
				}
				x1 = Movies.front();
				Movies.pop_front();
				y1 = Movies.front();
				Movies.pop_front();

				if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))//2
				{
					MDelit();
					MoviesAdd(x1, y1);

					for (int i = 0; i < counter; i++)
					{
						Movies.pop_front();
						Movies.pop_front();
					}

					x1 = Movies.front();
					Movies.pop_front();
					y1 = Movies.front();
					Movies.pop_front();
					if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))//3
					{
						MDelit();
						MoviesAdd(x1, y1);

						for (int i = 0; i < counter; i++)
						{
							Movies.pop_front();
							Movies.pop_front();
						}

						x1 = Movies.front();
						Movies.pop_front();
						y1 = Movies.front();
						Movies.pop_front();
						if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
						{
							status = 1;
							counter = 0;
							us.ExShip(x1, y1);
						}
						else
						{
							counter++;
							status = 0;
							MoviesAdd(x2, y2);
							for (int i = 0; i < counter; i++)
							{
								Movies.pop_front();
								Movies.pop_front();
							}
							x1 = Movies.front();
							Movies.pop_front();
							y1 = Movies.front();
							Movies.pop_front();
							if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
							{
								counter = 0;
								status = 1;
								us.ExShip(x1, y1);
							}
						}
					}
				}
			}
		}
		if ((y == 1) && (x != 1) && (x != 10))
		{
			for (int i = 0; i < counter; i++)
			{
				Movies.pop_front();
				Movies.pop_front();
			}
			x1 = Movies.front();
			Movies.pop_front();
			y1 = Movies.front();
			Movies.pop_front();
			if (ShotComputer1(x1, y1) != 1)
			{
				status = 0;
				counter++;
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				us.ExShip(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))
			{
				MDelit();
				MoviesAdd(x1, y1);
				for (int i = 0; i < counter; i++)
				{
					Movies.pop_front();
					Movies.pop_front();
				}
				x1 = Movies.front();
				Movies.pop_front();
				y1 = Movies.front();
				Movies.pop_front();

				if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))//2
				{
					MDelit();
					MoviesAdd(x1, y1);

					for (int i = 0; i < counter; i++)
					{
						Movies.pop_front();
						Movies.pop_front();
					}

					x1 = Movies.front();
					Movies.pop_front();
					y1 = Movies.front();
					Movies.pop_front();
					if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))//3
					{
						MDelit();
						MoviesAdd(x1, y1);

						for (int i = 0; i < counter; i++)
						{
							Movies.pop_front();
							Movies.pop_front();
						}

						x1 = Movies.front();
						Movies.pop_front();
						y1 = Movies.front();
						Movies.pop_front();
						if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
						{
							status = 1;
							counter = 0;
							us.ExShip(x1, y1);
						}
						else
						{
							counter++;
							status = 0;
							MoviesAdd(x2, y2);
							for (int i = 0; i < counter; i++)
							{
								Movies.pop_front();
								Movies.pop_front();
							}
							x1 = Movies.front();
							Movies.pop_front();
							y1 = Movies.front();
							Movies.pop_front();
							if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
							{
								counter = 0;
								status = 1;
								us.ExShip(x1, y1);
							}
						}
					}
				}
			}
		}
		if ((y == 10) && (x != 1) && (x != 10))
		{
			for (int i = 0; i < counter; i++)
			{
				Movies.pop_front();
				Movies.pop_front();
			}

			x1 = Movies.front();
			Movies.pop_front();
			y1 = Movies.front();
			Movies.pop_front();
			if (ShotComputer1(x1, y1) != 1)
			{
				status = 0;
				counter++;
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				us.ExShip(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))
			{

				MDelit();
				MoviesAdd(x1, y1);
				for (int i = 0; i < counter; i++)
				{
					Movies.pop_front();
					Movies.pop_front();
				}
				x1 = Movies.front();
				Movies.pop_front();
				y1 = Movies.front();
				Movies.pop_front();

				if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))//2
				{
					MDelit();
					MoviesAdd(x1, y1);

					for (int i = 0; i < counter; i++)
					{
						Movies.pop_front();
						Movies.pop_front();
					}

					x1 = Movies.front();
					Movies.pop_front();
					y1 = Movies.front();
					Movies.pop_front();
					if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) != 1))//3
					{
						MDelit();
						MoviesAdd(x1, y1);

						for (int i = 0; i < counter; i++)
						{
							Movies.pop_front();
							Movies.pop_front();
						}

						x1 = Movies.front();
						Movies.pop_front();
						y1 = Movies.front();
						Movies.pop_front();
						if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
						{
							status = 1;
							counter = 0;
							us.ExShip(x1, y1);
						}
						else
						{
							counter++;
							status = 0;
							MoviesAdd(x2, y2);
							for (int i = 0; i < counter; i++)
							{
								Movies.pop_front();
								Movies.pop_front();
							}
							x1 = Movies.front();
							Movies.pop_front();
							y1 = Movies.front();
							Movies.pop_front();
							if ((ShotComputer1(x1, y1) == 1) && (com.Kill(com.ReturnShip1(x1, y1)) == 1))
							{
								counter = 0;
								status = 1;
								us.ExShip(x1, y1);
							}
						}
					}
				}
			}
		}
		return status;
	} //
	//
	int ReturnVX()
	{
		return vXY[0];
	} 
	//
	int ReturnVY()
	{
		return vXY[1];
	}
};


void main()
{
	setlocale(LC_ALL, "rus");
  /*   1 2 3 4 5 6 7 8
	 ==================________________
|1 ||0 0 0 0 0 0 0 0 ||
 2 ||
 3 ||
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
	Computer com;
	User us;
	Game game;
	int x, y;
	int x1, y1;
	int StatusShip;
	int CounterShip = 0;
	int tmp, status;
	com.Ship();
	/*for (int i = 4; i >= 1; i--)
	{
		tmp = 4;
		while (tmp >= i)
		{
			status = 0;
			while (status == 0)
			{
				us.Print();
				cout << "Введите координаты "<<i<<"-х палубного корабля: \n";
				cout << "x = ";
				cin >> x;
				cout << "y = ";
				cin >> y;
				cout << "Введите положение корабля 0 - горизотальное, 1 - вертикальное: \n";
				cout << "StatusShip = ";
				cin >> StatusShip;
				status = us.ShipUser(x, y, StatusShip, i, CounterShip);
				system("cls");
			}
			CounterShip++;
			tmp--;
		}
	}*/

	cout << "\\\\\\\\\\\\\\\\ com ";
	com.Print();
	cout << "\\\\\\\\\\\\\\\\ us ";
	us.Print();
	cout << "\\\\\\\\\\\\\\\\";

	int UsLoss = us.Loss();
	int ComLoss = com.Loss();
	int ShotUser;
	int ShotCom;
	int KillUser;
	int KillCom;
	int tmp1 = 1;
	while ((UsLoss == 0) || (ComLoss == 0))
	{
		cout << "\\\\\\\\\\\\\\\\ us";
		us.Print();
		cout << "\\\\\\\\\\\\\\\\ us com";
		us.Print2();
		cout << "\\\\\\\\\\\\\\\\";
		cout << "\n";
		cout << "Введите координаты: \n";
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		ShotUser = game.ShotUser(x, y);
		KillUser = com.Kill(com.ReturnShip1(x, y));
		if (ShotUser == 1) {
			cout << "Попал \n";
			if (KillUser == 1)
			{
				cout << "Потопил \n";
			}
			while (ShotUser == 1)
			{
				cout << "Введите координаты: \n";
				cout << "x = ";
				cin >> x;
				cout << "y = ";
				cin >> y;
				ShotUser = game.ShotUser(x, y);
			}
		}
		else 
			cout << "Промах \n";
		system("cls");


		//комп
		com.Print();
		cout << "\n";
		com.Print2();
		cout << "\n";
		if (tmp1 == 1)
		{
			ShotCom = game.ShotComputer();// стреляем
			x1 = game.ReturnVX();
			y1 = game.ReturnVY();
			game.MDelit();
			game.MoviesAdd(x1, y1);
		}
		KillCom = us.Kill(us.ReturnShip1(x1, y1)); // проверка убил
		if ((ShotCom == 1) && (KillUser == 1)) {
			
			cout << "Компьютер потопил \n";
			tmp1 = 1;
		}
		if ((ShotCom == 1) && (KillUser != 1))
		{
			cout << "Компьютер попал \n";
			while (ShotCom == 1)
			{
				ShotCom = game.Strategy(x1, y1);
			}
			tmp1 = 0;
		}
		else
			cout << "Компьютер промахнулся \n";
		system("cls");
		UsLoss = us.Loss();
		ComLoss = com.Loss();
	}
		
		
	system("pause");
}