#pragma once
#ifndef cBird_h
#define cBird_h
#include "cEnemy.h"


class cBird : public cEnemy
{
	char **a; 
public:

	cBird(cPosition pos);
	char ** shape();
	void sound();
	void test();
	int getWidth()
	{
		return 6;
	}
	int getType();
	cBird();
	~cBird();
};
#endif // !cBird_h
