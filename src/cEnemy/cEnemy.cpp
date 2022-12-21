#include "cEnemy.h"

cEnemy::cEnemy() {
  outMap = false;
}

cPosition cEnemy::getPos(){
  return point;
}

bool cEnemy::isOutOfMap(){
  return outMap;
}

void cEnemy::goOutMap() {
  outMap = true;
}

int cEnemy::getWidth(){
  return 5;
}

int cEnemy::getHeight(){
  return 3;
}
