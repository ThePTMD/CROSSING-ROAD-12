#ifndef cPlayer_h
#define cPlayer_h

#include <stdio.h>
#include "../cPosition/cPosition.h"
//#include "../cEnemy/cEnemy.h"

class cPlayer
{
private:
  cPosition pos;
  bool isDead;
  char ** a;
  int width, height;
public:
  cPlayer() = default; // set default position
  cPlayer(cPosition pos); // set current position when load game
  ~cPlayer() = default;
  void Up();
  void Down();
  void Right();
  void Left();
//    bool checkIsDead();
  void killPlayer(); // set isDead
  void draw();
  char ** shape();
  cPosition getPos();
  int getWidth();
  int getHeight();
//    bool crash(cEnemy);
};

#endif // cPlayer
