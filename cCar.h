#ifndef cCar_h
#define cCar_h
#include "cEnemy.h"

class cCar : public cEnemy
{
	char **a; 
public:
	cCar(cPosition pos);
	char ** shape();
	void sound();
	void test();
	int getWidth()
	{
		return 8;
	}
	int getType();
	cCar();
	~cCar();

};
#endif // !cCar_h
