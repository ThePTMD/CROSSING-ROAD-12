#ifndef cOneRow_h
#define cOneRow_h

#include <vector>
#include "../cEnemy/cEnemy.h"

using namespace std;

class cOneRow
{
private:
  vector <cEnemy*> enemy;
  bool direction = 0; //0: to the left, 1: to the right
  bool redLight = false;
  int speed;
public:
  cOneRow() = default;
  cOneRow(int speed, bool direction, bool redLight){};
  ~cOneRow() = default;
  bool pushEnemy(cEnemy* newEnemy); // push a new new enemy, if !position => set base on direction
  void moveToNextState(int t) {}; // if % speed = 0, move all enemy left or right base on direction && redLight
  void toggleRedLight() {};
};

#endif // cOneRow
