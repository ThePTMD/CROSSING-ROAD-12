#ifndef cDino_h
#define cDino_h
#include "cEnemy.h"
class cDinosaur : public cEnemy
{
	char **a; 
public:

	cDinosaur(cPosition pos);

	char ** shape();
	void sound();
	void test();
	int getWidth()
	{
		return 6;
	}
	int getType();
	cDinosaur();
	~cDinosaur();
};
#endif // !cBird_h
