#ifndef cLevel_h
#define cLevel_h

#include <algorithm>
#include "../cPosition/cPosition.h"
#include "../cEnemy/cEnemy.h"

using namespace std;

class cLevel
{
private:
  int level;
  int maxEnemy, maxSpeed, nEnemy;
  int nRow;
//  int nColumn;
  void initialize();
public:
  cLevel();
  cLevel(int level, int nEnemy);
//  ~cLevel();
  void newLevel(int lv);
  int getMaxSpeed();
  cEnemy * randNewEnemy(cPosition pos);
  void decNEnemy();
};

#endif // cLevel
