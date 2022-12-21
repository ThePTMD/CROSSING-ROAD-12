#ifndef cLevel_h
#define cLevel_h
#include <algorithm>
#include "cPosition.h"
#include "cEnemy.h"
#include "cBird.h"
#include "cCar.h"
#include "cDinosaur.h"
#include "cTruck.h"

class cLevel
{
private:
	int level;
	int maxEnemy, minSpeed, maxSpeed, nEnemy;
	int nRow;
	const int maxLevel = 5;
	void initialize();
public:
	cLevel();
	cLevel(int level, int nEnemy);
	int getLevel();
	bool newLevel(int lv);
	bool nextLevel();
	int getMaxSpeed();
	int getMinSpeed();
	cEnemy * randNewEnemy(cPosition pos);
	cEnemy * getNewEnemy(cPosition pos, int type);
	void decNEnemy(int d);
};

#endif // cLevel