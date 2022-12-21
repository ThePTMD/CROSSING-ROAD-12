#ifndef cMap_h
#define cMap_h

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <cmath>
#include "cPlayer.h"
#include "cPosition.h"
#include "cRows.h"
#include "cLevel.h"
#include "cEnemy.h"

using namespace std;
class cMap
{
	const int width = 115, height = 36;
	char map[40][125];
	cPlayer player;
	cRows rowsData;
	cLevel level;
	int t = 0;
public:
	cMap();
	~cMap() = default;
	void resetMap(); 
	void drawMap();
	void redrawMap();
	int draw(cPosition pos, char ** shape, int w, int h);
	void deleteOldPlayer();
	void drawPlayer(); 
	void drawEnemies(cEnemy * enemy); 
	void randomNextState(); 
	void initializeNewState(); 
	void updatePosPlayer(char moving);
	void printMap();
	void bombEffect();
	void saveGame(string file);
	bool loadGame(string file);
	void printBorder();
	void printCongrats();
	bool printLevelUp();
	bool isEnd();
	bool isWin();
	void nextLevel();
	void printInt(int x, ofstream& outfile);
	int readInt(ifstream& infile);
};
#endif // cMap