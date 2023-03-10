#include "cBird.h"
using namespace std;

cBird::cBird(cPosition pos) : cEnemy(pos) {
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[6];
	}
	//Row1
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 5)
			a[0][i] = ' ';
		else if (i == 1)
			a[0][i] = '(';
		else if (i == 2)
			a[0][i] = '.';
		else if (i == 3)
			a[0][i] = ')';
		else if (i == 4)
			a[0][i] = '>';
	}
	//Row2
	a[1][0] = ' ';
	a[1][1] = '/';
	a[1][2] = ')';
	a[1][3] = ')';
	a[1][4] = ' ';
	a[1][5] = ' ';
	//Row3
	a[2][0] = ' ';
	a[2][1] = ' ';
	a[2][2] = '`';
	a[2][3] = '`';
	a[2][4] = ' ';
	a[2][5] = ' ';
};


char ** cBird::shape() {

	return a;
};
void cBird::sound() {
	PlaySound(TEXT("boc4.wav"), NULL, SND_ASYNC);
};
void cBird::test() {
	//Row1
	for (int i = 0; i < 6; i++)
	{
		if (i == 0 || i == 5)
			a[0][i] = ' ';
		else if (i == 1)
			a[0][i] = '(';
		else if (i == 2)
			a[0][i] = '.';
		else if (i == 3)
			a[0][i] = ')';
		else if (i == 4)
			a[0][i] = '>';
	}
	//Row2
	a[1][0] = ' ';
	a[1][1] = '/';
	a[1][2] = ')';
	a[1][3] = ')';
	a[1][4] = ' ';
	a[1][5] = ' ';
	//Row3
	a[2][0] = ' ';
	a[2][1] = ' ';
	a[2][2] = '`';
	a[2][3] = '`';
	a[2][4] = ' ';
	a[2][5] = ' ';

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << a[i][j];
		}
		cout << endl;
	}
};
cBird::cBird()
{
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[6];
	}
	//Row1
	for (int i = 0; i < 5; i++)
	{
		if (i == 0 || i == 5)
			a[0][i] = ' ';
		else if (i == 1)
			a[0][i] = '(';
		else if (i == 2)
			a[0][i] = '.';
		else if (i == 3)
			a[0][i] = ')';
		else if (i == 4)
			a[0][i] = '>';
	}
	//Row2
	a[1][0] = ' ';
	a[1][1] = '/';
	a[1][2] = ')';
	a[1][3] = ')';
	a[1][4] = ' ';
	a[1][5] = ' ';
	//Row3
	a[2][0] = ' ';
	a[2][1] = ' ';
	a[2][2] = '`';
	a[2][3] = '`';
	a[2][4] = ' ';
	a[2][5] = ' ';
}
cBird::~cBird()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}
int cBird::getType()
{
	return 0;
}