#ifndef cMap_h
#define cMap_h

#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include "../cPlayer/cPlayer.h"
#include "../cPosition/cPosition.h"
#include "../cRows/cRows.h"
#include "../cLevel/cLevel.h"

using namespace std;

class cMap
{
   	//old figure: width=height =300
    const int width = 115, height = 35;
    char map[40][120];
    cPlayer player;
    cRows rowsData;
    cLevel level;
public:
  cMap();
//    ~cMap();
  void resetMap(); // reset the map to default with no enemy and no player
  void printMap(); // print map to screen
  void drawMap(); // draw all enemies and player
  int draw(cPosition pos,char ** shape, int w, int h); // draw from position pos(x, y) shape(w, h) | 1: ok, 0: go out of map, -1: crash
  void drawPlayer(); // draw player to map, check if crash => kill player
  void drawEnemies(cEnemy * enemy); // draw enemy to map
  void randomNextState(); // generate new enemies base on level and push to rows
  void initializeNewState(); // intialize a new map base on level, reset player state
//    void handleKeyInput(); // receive key input from cGame and call appropriate function
};

#endif // cMap
