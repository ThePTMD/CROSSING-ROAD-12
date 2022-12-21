#include <iostream>
#include <fstream>
#include <string>
#include "./cMap/cMap.h"

using namespace std;

// print log to log.txt so that we can track easily, should be called in every function
// only on development
void printLog(string logString) {
  ofstream out;
  out.open("log.txt", ofstream::out | ofstream::app);
  out << logString << endl;
  out.close();
}


int main() {
  printLog("Running main . . .");
  cMap map;
  map.printMap();
  return 0;
}
