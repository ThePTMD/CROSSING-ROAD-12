
#ifndef cEnemy_h
#define cEnemy_h

#include "../cPosition/cPosition.h"


class cEnemy
{
private:
	cPosition point;
  bool outMap;
public:
  cPosition getPos();
	int getX()
	{
		return point.getX();
	}
	int getY()
	{
		return point.getY();
	}
  cEnemy();
  cEnemy(cPosition st); // create new enemy with starting position
  ~cEnemy() = default;
//  virtual void draw() =0;
  virtual char ** shape() =0; // return the shape of enemy to draw
  virtual void sound() =0;
  bool isOutOfMap();
  void goOutMap();
  int getWidth();
  int getHeight();
};

#endif // cEnemy
