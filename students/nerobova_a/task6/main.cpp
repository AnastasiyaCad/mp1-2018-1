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
	}
	
	void Print()
	{
		int size = ReturnSizeCom();
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++)
			{
				cout << ReturnVCom(x, y);
			}
			cout << "\n";
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
				//vCoordCom[ch].resize(sizesh + 1);
				int c1 = 0;
				int c2 = 1;

				for (int i = y; i < (y + sizesh); i++)
				{
					//vCoordCom[ch][c1] = x;
					vCom[x][i] = 1;
					//vCoordCom[ch][c2] = i;
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
				//vCoordCom[ch].resize(sizesh + 1);
				int c1 = 0;
				int c2 = 1;

				for (int i = x; i < (x + sizesh); i++)
				{
					vCom[i][y] = 1;
					//vCoordCom[ch][c1] = i;
					//vCoordCom[ch][c2] = y;
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
	int ReturnSizeComUs()
	{
		return vComUser.size();
	}
};

class User
{
private:
	vector<vector<int>> vUs;
	vector<vector<int>> vUsCom;
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

	int ReturnSizeUs()
	{
		return vUs.size();
	}

	int ReturnSizeUsCom()
	{
		return vUsCom.size();
	}
};

class Game
{
private:
	vector<vector<int>> vCoordCom;
	vector<vector<int>> vShipCom;
	vector<vector<int>> vCoordUs;
	vector<vector<int>> vShipUs;

	//int tmp;
	int x2;
	int y2;
	User us;
	Computer com;
	list<int> Movies;
	list<int> Movies1;
	int counter = 0;
	vector<int> vXY;
public:
	Game() { vXY.resize(2);
	
	vCoordCom.resize(10);
	vShipCom.resize(10);
	vShipCom[0].resize(4);
	vShipCom[1].resize(3);
	vShipCom[2].resize(3);
	vShipCom[3].resize(2);
	vShipCom[4].resize(2);
	vShipCom[5].resize(2);
	vShipCom[6].resize(1);
	vShipCom[7].resize(1);
	vShipCom[8].resize(1);
	vShipCom[9].resize(1);

	for (int i = 0, size = vShipCom.size(); i < size; i++)
		for (int j = 0, size = vShipCom[i].size(); j < size; j++)
		{
			vShipCom[i][j] = 1;
		}

	vCoordUs.resize(10);

	vShipUs.resize(10);
	vShipUs[0].resize(4);
	vShipUs[1].resize(3);
	vShipUs[2].resize(3);
	vShipUs[3].resize(2);
	vShipUs[4].resize(2);
	vShipUs[5].resize(2);
	vShipUs[6].resize(1);
	vShipUs[7].resize(1);
	vShipUs[8].resize(1);
	vShipUs[9].resize(1);

	for (int i = 0, size = vShipUs.size(); i < size; i++)
		for (int j = 0, size = vShipUs[i].size(); j < size; j++)
		{
			vShipUs[i][j] = 1;
		}

	}

	int Ship1Com(int n, int sizesh, int ch) // 0 --> 1 | установка кораблей n 
	{
		srand(time(0));
		int x, y;
		int tmp;
		int status = 0;
		int size = com.ReturnSizeCom();
		x = rand() % (size - 2) + 1; // [1 - 10]
		y = rand() % (size - 2) + 1;

		if ((n == 0) && ((y + sizesh - 1) <= (size - 2)))
		{
			tmp = 0;
			for (int i = (y - 1); i <= (y + sizesh); i++)
			{
				for (int j = (x - 1); j <= (x + 1); j++)
				{
					if (com.ReturnVCom(j,i) == 0)
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
					com.VCom(x, i, 1);
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
						if (com.ReturnVCom(i, j) == 0)
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
					com.VCom(i, y, 1);
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
	int ShipCom()
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
					status = Ship1Com(n, i, ch);
				}
				ch++;
				tmp--;
			}
		}
		return status;
	}

	int ShipUser(int x, int y, int n, int sizesh, int ch)
	{
		int tmp;
		int size = us.ReturnSizeUs();
		int status = 0;
		if ((n == 0) && ((y + sizesh - 1) <= (size - 2)))
		{
			tmp = 0;
			for (int i = (y - 1); i <= (y + sizesh); i++)
			{
				for (int j = (x - 1); j <= (x + 1); j++)
				{
					if (us.ReturnVUs(j, i) == 0)
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
					us.VUs(x, i, 1);
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
						if (us.ReturnVUs(i, j) == 0)
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
					us.VUs(i, y, 1);
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

	int ReturnShipYCom(int x, int y) /////
	{
		int tmpx = 0;
		int tmpy = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < vCoordCom[i].size(); j++) {
				if ((vCoordCom[i][j] == x) && (vCoordCom[i][j + 1] == y))
				{
					tmpy = j;
					break;
				}
			}
		return tmpy;
	}

	int ReturnShipXCom(int x, int y) /////
	{
		int tmpx = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < vCoordCom[i].size(); j++) {
				if ((vCoordCom[i][j] == x) && (vCoordCom[i][j + 1] == y))
				{
					tmpx = i; // вернуть размер и место x
				}
				break;
			}
		return tmpx;
	}

	void ExShipCom(int i, int j)
	{
		vShipCom[i][j] = 0;
	}
	// выстрел игрока
	int ShotUser(int x, int y)
	{
		int status;
		int i;
		int j;
		/*i = ReturnShipXCom(x, y);
		j = ReturnShipYCom(x, y);
		if ((i != 0) && (j != 0))
		{
			us.VUsCom(x, y, 2);
			ExShipCom(i, j);
			status = 1;
		}
		else
		{
			us.VUsCom(x, y, 1);
			status = 0;
		}
		return status;*/
		
		if (com.ReturnVCom(x, y) == 1)
		{
			us.VUsCom(x, y, 2);
			//v = com.ReturnShip(x, y);//#
			//com.ExShip(v[0], v[1]);
			i = ReturnShipXCom(x, y);
			j = ReturnShipYCom(x, y);
			ExShipCom(i, j);
			status = 1;
		}
		else
		{
			us.VUsCom(x, y, 1);
			status = 0;
		}
		return status;
	}

	int ReturnShipXUs(int x, int y) /////
	{
		int tmpx = 0;
		int tmpy = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < vCoordUs[i].size(); j++) {
				if ((vCoordUs[i][j] == x) && (vCoordUs[i][j + 1] == y))
				{
					tmpx = i; // вернуть размер и место x
				}
			}
		return tmpx;
	}

	int ReturnShipYUs(int x, int y) /////
	{
		int tmpx = 0;
		int tmpy = 0;
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < vCoordUs[i].size(); j++) {
				if ((vCoordUs[i][j] == x) && (vCoordUs[i][j + 1] == y))
				{
					tmpy = j;
					break;// вернуть размер и место x
				}
			}
		return tmpy;
	}
	
	void ExShipUs(int i, int j)
	{
		vShipUs[i][j] = 0;
	}

	int ShotComputer()
	{
		int size = com.ReturnSizeCom();
		int x, y;
		srand(time(0));
		int status = -1;
		int i;
		int j;
		while (status = -1)
		{
			x = rand() % (size - 2) + 1;
			y = rand() % (size - 2) + 1;
			if ((us.ReturnVUs(x, y) == 1) && (com.ReturnVComUser(x, y) == 0))
			{
				com.VComUser(x, y, 2);
				i = ReturnShipXCom(x, y);
				j = ReturnShipYCom(x, y);
				ExShipUs(i, j);
				status = 1;
				vXY[0] = x;
				vXY[1] = y;
			}
			else
			{
				if (com.ReturnVComUser(x, y) == 2)
					status = -1;
				else
				{
					com.VComUser(x, y, 1);
					status = 0;
				}
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
		int i;
		int j;
		if (us.ReturnVUs(x, y) == 1)
		{
			com.VComUser(x, y, 2);
			i = ReturnShipXCom(x, y);
			j = ReturnShipYCom(x, y);
			ExShipUs(i, j);
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
	int KillCom(int sizech)
	{
		int status = 0;
		int tmp = 0;
		int size = vShipCom[sizech].size();
		for (int i = 0; i < size; i++)
			if (vShipCom[sizech][i] == 0)
				tmp++;
		if (tmp == size)
			status = 1;
		return status;
	}

	int LossCom()
	{
		int status = 0;
		int tmp = 0;
		int size = vShipCom.size();
		for (int i = 0; i < size; i++)
			for (int j = 0, size1 = vShipCom[i].size(); j < size1; j++)
				if (vShipCom[i][j] == 0)
					tmp++;
		if (tmp == size)
			status = 1;
		return status;
	}

	int KillUs(int sizech)
	{
		int status = 0;
		int tmp = 0;
		int size = vShipUs[sizech].size();
		for (int i = 0; i < size; i++)
			if (vShipUs[sizech][i] == 0)
				tmp++;
		if (tmp == size)
			status = 1;
		return status;
	}

	int LossUs()
	{
		int status = 0;
		int tmp = 0;
		int size = vShipUs.size();
		for (int i = 0; i < size; i++)
			for (int j = 0, size1 = vShipUs[i].size(); j < size1; j++)
				if (vShipUs[i][j] == 0)
					tmp++;
		if (tmp == size)
			status = 1;
		return status;
	}

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
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1)) //*
			{
				ExShipUs(x1, y1);
				counter = 0;
				status = 1;
			}
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))//2
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
				if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))//3
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
					if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
					{
						status = 1;
						counter = 0;
						ExShipUs(x1, y1);
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
						if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
						{
							ExShipUs(x1, y1);
							counter = 0;
							status = 1;
						}
					}
				}
				if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
				{
					counter = 0;
					status = 1;
					ExShipUs(x1, y1);
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
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				ExShipUs(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))
			{
				while (KillCom(ReturnShipXCom(x1, y1)) != 1)
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
				ExShipUs(x1, y1);
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
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				ExShipUs(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))
			{
				while (KillCom(ReturnShipXCom(x1, y1)) != 1)
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
				ExShipUs(x1, y1);
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
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				ExShipUs(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))
			{
				while (KillCom(ReturnShipXCom(x1, y1)) != 1)
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
				ExShipUs(x1, y1);
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
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				ExShipUs(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))
			{
				while (KillCom(ReturnShipXCom(x1, y1)) != 1)
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
				ExShipUs(x1, y1);
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
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				ExShipUs(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))
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

				if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))//2
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
					if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))//3
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
						if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
						{
							status = 1;
							counter = 0;
							ExShipUs(x1, y1);
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
							if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
							{
								counter = 0;
								status = 1;
								ExShipUs(x1, y1);
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
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				ExShipUs(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))
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

				if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))//2
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
					if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))//3
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
						if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
						{
							status = 1;
							counter = 0;
							ExShipUs(x1, y1);
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
							if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
							{
								counter = 0;
								status = 1;
								ExShipUs(x1, y1);
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
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				ExShipUs(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))
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

				if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))//2
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
					if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))//3
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
						if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
						{
							status = 1;
							counter = 0;
							ExShipUs(x1, y1);
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
							if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
							{
								counter = 0;
								status = 1;
								ExShipUs(x1, y1);
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
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
			{
				status = 1;
				counter = 0;
				ExShipUs(x1, y1);
			}
			if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))
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

				if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))//2
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
					if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) != 1))//3
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
						if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
						{
							status = 1;
							counter = 0;
							ExShipUs(x1, y1);
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
							if ((ShotComputer1(x1, y1) == 1) && (KillCom(ReturnShipXCom(x1, y1)) == 1))
							{
								counter = 0;
								status = 1;
								ExShipUs(x1, y1);
							}
						}
					}
				}
			}
		}
		return status;
	} 
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

	void PrintCom()
	{
		int size = com.ReturnSizeCom();
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++)
			{
				cout << com.ReturnVCom(x, y);
			}
			cout << "\n";
		}
	}

	void Print2Com()
	{
		int size = com.ReturnSizeComUs();
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++)
			{
				cout << com.ReturnVComUser(x, y);
			}
			cout << "\n";
		}
	}

	void PrintUs()
	{
		int size = us.ReturnSizeUs();
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++)
			{
				cout << us.ReturnVUs(x, y);
			}
			cout << "\n";
		}
	}
	void Print2Us()
	{
		int size = us.ReturnSizeUsCom();
		for (int x = 0; x < size; x++) {
			for (int y = 0; y < size; y++)
			{
				cout << us.ReturnVUsCom(x, y);
			}
			cout << "\n";
		}
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
	int tmpprov = 1;
	game.ShipCom();
	/*for (int i = 4; i >= 1; i--)
	{
		tmp = 4;
		while (tmp >= i)
		{
			status = 0;
			while (status == 0)
			{
				game.PrintUs();
				cout << "Введите координаты "<<i<<"-х палубного корабля: \n";
				cout << "x = ";
				cin >> x;
				cout << "y = ";
				cin >> y;
				cout << "Введите положение корабля 0 - горизотальное, 1 - вертикальное: \n";
				cout << "StatusShip = ";
				cin >> StatusShip;
				status = game.ShipUser(x, y, StatusShip, i, CounterShip);
				system("cls");
			}
			CounterShip++;
			tmp--;
		}
	}*/

	cout << "\\\\\\\\\\\\\\\\ com \n";
	game.PrintCom();
	cout << "\\\\\\\\\\\\\\\\ us \n";
	game.PrintUs();
	cout << "\\\\\\\\\\\\\\\\";


	int UsLoss = game.LossUs();
	int ComLoss = game.LossCom();
	int ShotUser;
	int ShotCom;
	int KillUser;
	int KillCom;
	
	while ((UsLoss == 0) || (ComLoss == 0))
	{
		cout << "\\\\\\\\\\\\\\\\ us \n";
		game.PrintUs();
		cout << "\\\\\\\\\\\\\\\\ us com \n";
		game.Print2Us();
		cout << "\\\\\\\\\\\\\\\\";
		cout << "\n";
		cout << "Введите координаты: \n";
		cout << "x = ";
		cin >> x;
		cout << "y = ";
		cin >> y;
		ShotUser = game.ShotUser(x, y);
		
		while (ShotUser == 1)
		{
			if (ShotUser == 1)
			{
				cout << "Попал \n";
				KillUser = game.KillCom(game.ReturnShipXCom(x, y));
				if (KillUser == 1)
				{
					cout << "Потопил \n";
				}
				cout << "Введите координаты 2: \n";
				cout << "x = ";
				cin >> x;
				cout << "y = ";
				cin >> y;
				ShotUser = game.ShotUser(x, y);
				if (ShotUser == 0)
				{
					cout << "Промах \n";
				}
			}
			else 
			cout << "Промах \n";
		}
		


		//комп
		game.PrintCom();
		cout << "\n";
		game.Print2Com();
		cout << "\n";
	
		if (tmpprov == 1)
		{
			x1 = game.ReturnVX();
			y1 = game.ReturnVY();
			cout << x1;
			cout << y1;
			ShotCom = game.ShotComputer();// стреляем
			game.MDelit();
			game.MoviesAdd(x1, y1);
		}
		KillCom = game.KillUs(game.ReturnShipXUs(x1, y1)); // проверка убил
		if ((ShotCom == 1) && (KillUser == 1)) {
			
			cout << "Компьютер потопил \n";
			tmpprov = 1;
		}
		if ((ShotCom == 1) && (KillUser != 1))
		{
			cout << "Компьютер попал \n";
			while (ShotCom == 1)
			{
				ShotCom = game.Strategy(x1, y1);
			}
			tmpprov = 0;
		}
		else
			cout << "Компьютер промахнулся \n";
		system("cls");
		UsLoss = game.LossUs();
		ComLoss = game.LossCom();
	}
		
	system("pause");
}