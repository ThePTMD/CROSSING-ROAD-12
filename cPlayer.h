#ifndef cPlayer_h
#define cPlayer_h
#define RIGHTMAP 58
#define LEFTMAP 2
#include "cConsole.h"
#include "cPosition.h"
#include "cEnemy.h"
#include "cBird.h"
#include "cCar.h"
#include "cDinosaur.h"
#include "cTruck.h"
#include <cmath>

class cPlayer
{
private:
	cPosition pos;
	bool isDead;
	char ** a;  
	char ** emptyPlayer;
	int width = 5, height = 3;
public:
	cPlayer();
	cPosition getPos();
	cPlayer(cPosition pos);
	~cPlayer();
	void Up();
	void Down();
	void Right();
	void Left();
	bool checkIsDead();
	void killPlayer(); 
	char ** shape();
	char ** emptyShape();
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	bool crash(cPosition pos, int w, int h);
	void sound();
};
#endif // cPlayer