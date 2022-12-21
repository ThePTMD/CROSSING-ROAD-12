#include "cMap.h"
#include "cConsole.h"

cMap::cMap() {
    resetMap();
}

void cMap::resetMap(){
    for (int i = 0; i <= width + 1; i++){
        map[0][i] = map[height + 1][i] = '-';
    }
    for (int i = 1; i <= height; ++i) {
        map[i][0] = map[i][width + 1] = '|';
        for (int j = 1; j <= width; ++j) {
            map[i][j] = ' ';
        }
    }
}

void cMap::printMap()
{
//    TextColor(14);
    for (int i = 0; i <= height + 1; ++i) {
        for (int j = 0; j <= width + 1; ++j){
            cout << map[i][j];
        }
        cout << endl;
    }
}

void cMap::drawMap() {
  resetMap();
  vector <cEnemy*> enemyList = rowsData.listEnemy();
  for (int i = 0; i < (int)enemyList.size(); ++i) {
    drawEnemies(enemyList[i]);
  }
  drawPlayer();
}

int cMap::draw(cPosition pos, char ** shape, int w, int h) {
  int X = pos.getX();
  int Y = pos.getY();
  if (Y + w <= 0) return 0;
  if (Y > width) return 0;
  for (int i = 0; i < h; ++i) {
    for (int j = max(1, Y); j <= min(width, Y + w - 1); ++j) {
      if (map[X + i][Y + j] != ' ') return -1;
      map[X + i][Y + j] = shape[i][j - max(1, Y)];
    }
  }
  return 1;
}

void cMap::drawEnemies(cEnemy * enemy) {
  int status = draw(enemy->getPos(), enemy->shape(), enemy->getWidth(), enemy->getHeight());
  if (status == 0) {
    enemy->goOutMap();
  }
  if (status == -1) {
    player.killPlayer();
  }
}

void cMap::drawPlayer() {
  int status = draw(player.getPos(), player.shape(), player.getWidth(), player.getHeight());
  if (status == -1){
    player.killPlayer();
  }
}

void cMap::initializeNewState() {
  srand((unsigned int)time(NULL));
  player = cPlayer();
  rowsData = cRows();
  int padding[10];
  for (int i = 0; i < 10; ++i) {
    padding[i] = 0;
    int speed = rand() % level.getMaxSpeed();
    bool direction = rand() % 2;
    bool redLight = rand() % 2;
    rowsData.pushRow(new cOneRow(speed, direction, redLight));
  }
  cEnemy * newEnemy;
  cPosition pos;
  int tryCount = 10000;
  while (tryCount--) {
    int rRow = (rand() % 10) + 1;
    padding[rRow] += (rand() % 20) + 1;
    pos = cPosition((rRow - 1) * 3 + 1, padding[rRow]);
    newEnemy = level.randNewEnemy(pos);
    if (!newEnemy) break;
    rowsData.pushEnemy(rRow, newEnemy);
  }
  drawMap();
}

void cMap::randomNextState() {
  int t = rand(); // this will be get from global clock
  rowsData.moveToNextState(t);
  cEnemy * newEnemy;
  cPosition pos;
  int tryCount = 10000;
  while (tryCount--) {
    int rRow = rand() % 10;
    pos = cPosition((rRow  * 3) + 1, -1);
    newEnemy = level.randNewEnemy(pos);
    if (!newEnemy) break;
    if (!rowsData.pushEnemy(rRow, newEnemy)) {
      level.decNEnemy();
      delete newEnemy;
    };
  }
  drawMap();
}
