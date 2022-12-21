#ifndef cOneRow_h
#define cOneRow_h
#define RIGHTMAP 58
#define LEFTMAP 2
#include <vector>
#include "cEnemy.h"

using namespace std;

class cOneRow
{
private:
	vector <cEnemy*> enemy;
	bool direction; 
	bool redLight = false;
	int speed;
	int currentRow;
public:
	cOneRow() = default;
	cOneRow(int speed, bool direction, bool redLight, int currentRow);
	~cOneRow() = default;
	bool pushEnemy(cEnemy* newEnemy); 
	int moveToNextState(int t); 
	void redrawState();
	void toggleRedLight();
	void deleteOldEnemy(cPosition pos, int w, int h);
	bool printNewEnemy(cPosition pos, char ** shape, int w, int h);
	vector<cEnemy*> getEnemy();
	bool getDirection();
	bool getRedLight();
	int getSpeed();
	int getCurrentRow();
};

#endif // cOneRow