#ifndef cRow_h
#define cRow_h

#include <vector>
#include "cOneRow.h"

using namespace std;

class cRows
{
private:
	vector <cOneRow*> subRows;
public:
	cRows();
	~cRows() = default;
	bool pushEnemy(int row, cEnemy* enemy); 
	void pushRow(cOneRow*);
	vector <cEnemy*> listEnemy();
	vector <cOneRow*> listRow();
	int moveToNextState(int t);
	void redrawState();

};

#endif // cRows