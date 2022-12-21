
#ifndef cBird_h
#define cBird_h
#include "cEnemy.h"
class cBird : public cEnemy
{
	char **a; //a[3][6]
public:
	void draw();
	char ** shape();
	void sound();
	void test();
	cBird();
	~cBird();
};
#endif // !cBird_h
