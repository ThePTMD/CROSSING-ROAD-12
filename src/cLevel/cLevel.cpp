#include "cLevel.h"

cLevel::cLevel() {
  level = 1;
  nEnemy = 0;
  initialize();
}

cLevel::cLevel(int level, int nEnemy) {
  this->level = level;
  this->nEnemy = nEnemy;
  initialize();
}

void cLevel::initialize() {
  nRow = min(10, 3 + (level / 3));
  maxEnemy = min(70, nRow * 7 );
  maxSpeed = max(1, 10 - (level / 3));
}

void cLevel::newLevel(int lv) {
  level = lv;
  nEnemy = 0;
  initialize();
}

int cLevel::getMaxSpeed() {
  return maxSpeed;
}

cEnemy * cLevel::randNewEnemy(cPosition pos) {
  if (nEnemy == maxEnemy) return NULL;
  if ((nEnemy < (maxEnemy / 2)) || (rand() % 3)) {
    ++nEnemy;
    cEnemy * pEnemy = NULL;
//    pEnemy = new cEnemy(pos); //choose a random type of enemy
    return pEnemy;
  }
  return NULL;
}

void cLevel::decNEnemy(){
  --nEnemy;
}

