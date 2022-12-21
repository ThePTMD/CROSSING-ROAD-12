Game: ./main.cpp ./cGame/cGame.cpp ./cGame/cGame.h ./cMap/cMap.cpp ./cMap/cMap.h ./cPlayer/cPlayer.cpp ./cPlayer/cPlayer.h ./cPosition/cPosition.cpp ./cPosition/cPosition.h ./cEnemy/cEnemy.cpp ./cEnemy/cEnemy.h ./cLevel/cLevel.cpp ./cLevel/cLevel.h ./cOneRow/cOneRow.cpp ./cOneRow/cOneRow.h ./cRows/cRows.cpp ./cRows/cRows.h
	g++ -std=c++11 -Wall -c ./cPosition/cPosition.cpp -o cPosition.o
	g++ -std=c++11 -Wall -c ./cEnemy/cEnemy.cpp -o cEnemy.o
	g++ -std=c++11 -Wall -c ./cLevel/cLevel.cpp -o cLevel.o
	g++ -std=c++11 -Wall -c ./cOneRow/cOneRow.cpp -o cOneRow.o
	g++ -std=c++11 -Wall -c ./cRows/cRows.cpp -o cRows.o
	g++ -std=c++11 -Wall -c ./cPlayer/cPlayer.cpp -o cPlayer.o
	g++ -std=c++11 -Wall -c ./cMap/cMap.cpp -o cMap.o
	g++ -std=c++11 -Wall -c ./cGame/cGame.cpp -o cGame.o
	g++ -std=c++11 -Wall ./main.cpp -o main *.o

clean: 
	rm -f core *.o
