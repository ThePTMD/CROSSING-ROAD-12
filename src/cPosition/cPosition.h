#ifndef cPosition_h
#define cPosition_h

class cPosition {
  int X, Y;
public:
  int getX();
	int getY();
  
  cPosition() {};
  cPosition(int x, int y) : X(x), Y(y){};
  ~cPosition() {};
};

#endif // cPosition
