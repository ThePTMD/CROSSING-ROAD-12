#ifndef cGame_h
#define cGame_h

#include <iostream>
#include "../cMap/cMap.h"

class cGame
{
    cMap map;
    bool isPausing = false;
public:
    cGame();
    ~cGame();
    void gameSettings();
    void newGame(); // start a new game, initialize cMap map
    void loadGame(); // get file of cMap map
    void saveGame(); // print file of cMap map
    void togglePauseGame(); // toggle status of isPausing
    void playGame(); // manage game process: randomNextState, draw (tick time)
    void quitGame();
    void gameOver();
};

#endif // cGame
