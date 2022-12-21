#include "cRows.h"

cRows::cRows() {
	subRows.reserve(100);
}

bool cRows::pushEnemy(int row, cEnemy* enemy) {
	if (row >= (int)subRows.size())  return false;
	return subRows[row]->pushEnemy(enemy);
}

void cRows::pushRow(cOneRow* row) {
	subRows.push_back(row);
}

vector<cEnemy*> cRows::listEnemy() {
	vector<cEnemy*> listEnemy, tmp;
	for (int i = 0; (unsigned)i < subRows.size(); i++) {
		tmp = subRows[i]->getEnemy();
		listEnemy.insert(listEnemy.end(), tmp.begin(), tmp.end());
	}
	return listEnemy;
}

int cRows::moveToNextState(int t) {
	int nDelete = 0;
	for (int i = 0; i < (int)subRows.size(); ++i) {
		nDelete += subRows[i]->moveToNextState(t);
	}
	return nDelete;
}

void cRows::redrawState() {
	for (int i = 0; i < (int)subRows.size(); ++i) {
		subRows[i]->redrawState();
	}
}

vector <cOneRow*> cRows::listRow() {
	return subRows;
}