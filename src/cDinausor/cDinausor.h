
#ifndef cDino_h
#define cDino_h
#include "cEnemy.h"
class cDinosaur : public cEnemy
{
	char **a; //a[3][6]
public:
	char ** shape();
	void sound();
	void test();
	cDinosaur();
	~cDinosaur();
};
#endif // !cBird_h
