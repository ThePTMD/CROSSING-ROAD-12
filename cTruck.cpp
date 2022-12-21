#include "cTruck.h"
using namespace std;

cTruck::cTruck(cPosition pos) : cEnemy(pos) {

	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}
	//Row1
	for (int i = 0; i < 8; i++)
	{
		if (i > 0 && i < 6)
			i = ' ';
		else
			i = '_';
	}
	//Row2
	for (int i = 0; i < 8; i++)
	{
		if (i == 0)
			a[1][i] = '|';
		else if (i == 6)
			a[1][i] = 'L';
		else if (i == 7)
			a[1][i] = '\\';
		else
			a[1][i] = ' ';
	}
	//Row3
	
	for (int i = 0; i < 8; i++) {
		if (i == 1 || i == 6)
			a[2][i] = 'O';
		else
			a[2][i] = '-';
	}

};


char **cTruck::shape()
{

	return a;
};
void cTruck::sound()
{
	PlaySound(TEXT("carstarthonkbackfire.wav"), NULL, SND_ASYNC);
}
cTruck::cTruck()
{
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}
	//Row1
	for (int i = 0; i < 8; i++)
	{
		if (i > 0 && i < 6)
			i = ' ';
		else
			i = '_';
	}
	//Row2
	for (int i = 0; i < 8; i++)
	{
		if (i == 0)
			a[1][i] = '|';
		else if (i == 6)
			a[1][i] = 'L';
		else if (i == 7)
			a[1][i] = '\\';
		else
			a[1][i] = ' ';
	}
	//Row3

	for (int i = 0; i < 8; i++) {
		if (i == 1 || i == 6)
			a[2][i] = 'O';
		else
			a[2][i] = '-';
	}
}
cTruck::~cTruck()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}

void cTruck::test()
{
	//Row1
	for (int i = 0; i < 8; i++)
	{
		if (i > 0 && i < 6)
			i = ' ';
		else
			i = '_';
	}
	//Row2
	for (int i = 0; i < 8; i++)
	{
		if (i == 0)
			a[1][i] = '|';
		else if (i == 6)
			a[1][i] = 'L';
		else if (i == 7)
			a[1][i] = '\\';
		else
			a[1][i] = ' ';
	}
	//Row3

	for (int i = 0; i < 8; i++) {
		if (i == 1 || i == 6)
			a[2][i] = 'O';
		else
			a[2][i] = '-';
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
}
int cTruck::getType()
{
	return 4;
}