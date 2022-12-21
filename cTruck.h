#ifndef cTruck_h
#define cTruck_h
#include "cEnemy.h"

class cTruck : public cEnemy
{
	char** a;
public:
	cTruck(cPosition pos);
	char **shape();
	void sound();
	void test();
	int getWidth()
	{
		return 8;
	}
	int getType();
	cTruck();
	~cTruck();
};
#endif 
