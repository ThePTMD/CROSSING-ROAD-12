#include "cCar.h"
using namespace std;

cCar::cCar(cPosition pos) : cEnemy(pos) {
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}
	//Row1
	for (int i = 0; i < 8; i++) {
		if (i == 2 || i == 3 || i == 4)
			a[0][i] = '_';
		else
			a[0][i] = ' ';
	}
	//Row2
	for (int i = 0; i < 8; i++) {
		if (i > 1 && i < 5)	a[1][i] = ' ';
		else if (i == 0 || i == 6 || i == 7)
			a[1][i] = '_';
		else if (i == 2)	
			a[1][5] = '/';
		else if (i == 6)
			a[1][6] = '\\';
	}

	//Row3
	for (int i = 0; i < 8; i++) {
		if (i == 1)
			a[2][i] = 'O';
		else if (i == 6)
			a[2][i] = 'O';
		else 
			a[2][i] = '-';
	}
};


cCar::cCar()
{
	a = new char*[3];
	for (int i = 0; i < 3; i++)
	{
		a[i] = new char[8];
	}
	//Row1
	for (int i = 0; i < 8; i++) {
		if (i == 2 || i == 3 || i == 4)
			a[0][i] = '_';
		else
			a[0][i] = ' ';
	}
	//Row2
	for (int i = 0; i < 8; i++) {
		if (i > 1 && i < 5)	a[1][i] = ' ';
		else if (i == 0 || i == 6 || i == 7) a[1][i] = '_';
		else if (i == 2)	
			a[1][5] = '/';
		else if (i == 6)	
			a[1][6] = '\\';
	}

	//Row3
	for (int i = 0; i < 8; i++) {
		if (i == 1)	
			a[2][i] = 'O';
		else if (i == 6) 
			a[2][i] = 'O';
		else 
			a[2][i] = '-';
	}
}
cCar::~cCar()
{
	for (int i = 0; i < 3; i++)
		delete[] a[i];
	delete[] a;
}
char ** cCar::shape()
{

	return a;
}
void cCar::sound()
{
	PlaySound(TEXT("trafficjam.wav"), NULL, SND_ASYNC);
}
void cCar::test()
{
	//Row1
	for (int i = 0; i < 8; i++) {
		if (i == 2 || i == 3 || i == 4)
			a[0][i] = '_';
		else
			a[0][i] = ' ';
	}
	//Row2
	for (int i = 0; i < 8; i++) {
		if (i > 1 && i < 5)	a[1][i] = ' ';
		else if (i == 0 || i == 6 || i == 7) 
			a[1][i] = '_';
		else if (i == 2)	
			a[1][5] = '/';
		else if (i == 6)	
			a[1][6] = '\\';
	}

	//Row3
	for (int i = 0; i < 8; i++) {
		if (i == 1)
			a[2][i] = 'O';
		else if (i == 6)
			a[2][i] = 'O';
		else
			a[2][i] = '-';
	}

}
int cCar::getType()
{
	return 1;
}