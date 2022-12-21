#ifndef cRow_h
#define cRow_h

#include <vector>
#include "../cOneRow/cOneRow.h"
#include "../cEnemy/cEnemy.h"

using namespace std;

class cRows
{
private:
  vector <cOneRow*> subRows;
public:
  cRows() = default;
  ~cRows() = default;
  bool pushEnemy(int row, cEnemy* enemy){ return false; }; //  push a new enemy to a row
  void pushRow(cOneRow* row) {};
  vector <cEnemy*> listEnemy(){
    vector<cEnemy*> tmp;
    return tmp;
  }; // return all enemies from all rows
  void moveToNextState(int t) {}; // trigger moveToNextState of each row
};

#endif // cRows
