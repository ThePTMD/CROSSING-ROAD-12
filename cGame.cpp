#include "cGame.h"

void cGame::gameSettings() {
	system("cls");
	const char *setting[3] = { "MODE:", "SOUND:", "MENU" };
	char * currentSettting[3] = { "HARD", "ON", "" };
	if (constantVar::isHard) {
		currentSettting[0] = "HARD";
	}
	else
	{
		currentSettting[0] = "EASY";
	}
	if (constantVar::isMute) {
		currentSettting[1] = "OFF";
	}
	else {
		currentSettting[1] = "ON ";
	}
	int pos1 = 0;
	const int y = 20;
	const int x = 25;
	int flag = 0;
	int color = rand() % 7 + 9;
	map.printBorder();
	bool currentKey = true;
	while (1) {
		if (currentKey) {
			//system("cls");
			color = rand() % 7 + 9;
			TextColor(color);
			drawTitle();
			//TextColor(7);
			for (int i = 0; i < 4 - 1; i++) {
				gotoXY(x, y + i);
				if (i == pos1) {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				}
				else {
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				cout << setting[i] << " " << currentSettting[i];
			}
			currentKey = false;
		}
		while (1) {
			if (kbhit()) {
				currentKey = true;
				//system("cls");
				
				char key = getch();
				if (key == 'W' || key == 'w') {
					pos1--;
					pos1 = (pos1 + 3) % 3;
					break;
				}
				if (key == 'S' || key == 's') {
					pos1++;
					pos1 %= 3;
					break;
				}
				if (key == 13) {
					switch (pos1) {
					case 0: {
						//Game mode : easy || hard
						toggleHard();
						if (constantVar::isHard) {
							currentSettting[0] = "HARD";
							if (!constantVar::isMute) {
								PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
								PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
							}
						}
						else
						{
							currentSettting[0] = "EASY";
							if (!constantVar::isMute) {
								PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
								PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
							}
						}
						break;
					}
					case 1: {
						toggleMute();
						if (constantVar::isMute) {
							currentSettting[1] = "OFF";
							if (constantVar::isMute)PlaySound(NULL("PUBG.wav"), NULL, SND_APPLICATION);
						}
						else {
							currentSettting[1] = "ON ";
							PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
							PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
						}
						//flag = 1;
						break;
					}
					case 2: {
						system("cls");
						flag = 1;
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
						return;
					}
					}
					break;
				}

			}
		}
		
	}
	return;
}

void cGame::menu(bool &isFinish) {
}

void cGame::menu() {
	const string choice[4] = { "NEW GAME","LOAD GAME","SETTINGS","EXIT" };
	int pos = 0;
	int x = 35, y = 20;
	if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
	bool changeInput = true;
	while (true) {
		changeInput = true;
		map.printBorder();
		if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
		while (true) {
			if (changeInput) {
				for (int i = 0; i < 4; i++) {
					gotoXY(x, y + i);
					if (i == pos)
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
					}
					else
					{
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					}
					cout << choice[i] << endl;
				}

				//TextColor(7);
				int color = rand() % 7 + 9;
				TextColor(color);
				gotoXY(20, 10); cout << "   __________  ____  __________    ____  ____  ___    ____ " << endl;
				gotoXY(20, 11); cout << "  / ____/ __ \\/ __ \\/ ___/ ___/   / __ \\/ __ \\/   |  / __ \\" << endl;
				gotoXY(20, 12); cout << " / /   / /_/ / / / /\\__ \\\\__ \\   / /_/ / / / / /| | / / / /" << endl;
				gotoXY(20, 13); cout << "/ /___/ _, _/ /_/ /___/ /__/ /  / _, _/ /_/ / ___ |/ /_/ / " << endl;
				gotoXY(20, 14); cout << "\\____/_/ |_|\\____//____/____/  /_/ |_|\\____/_/  |_/_____/  " << endl;
				TextColor(7);
			}
			changeInput = false;
			switch (inputKey()) {
				changeInput = true;
				PlaySound(TEXT("RING.wav"), NULL, SND_ASYNC);
			case 'w':
				changeInput = true;
				pos--;
				pos = (pos + 4) % 4;
				break;
			case 's':
				changeInput = true;
				pos++;
				pos %= 4;
				break;
			case 13:
				switch (pos) {
				case 0:
					while (1) {
						loading();

						if (newGame()) {
							Sleep(1000);
							clrscr();
							map.printBorder();
							if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
							changeInput = true;
							break;// thang nhung k choi tiep
							Sleep(1000);
						}
						else if (!continueMenu()) {
							if (isLoaded) {
								map.~cMap();
								new(&map) cMap;
							}
							Sleep(1000);
							clrscr();
							map.printBorder();
							if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
							changeInput = true;
							break;//thua nhung khong choi tiep
						}
					}
					break;
				case 1: {
					Sleep(1000);
					if (loadGameMenu()) {
						while (1) {
							loading();

							if (newGame()) {
								Sleep(1000);
								clrscr();
								map.printBorder();
								if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
								changeInput = true;
								break;// thang nhung k choi tiep
								Sleep(1000);
							}
							else if (!continueMenu()) {
								Sleep(1000);
								TextColor(7);
								clrscr();
								map.printBorder();
								if (!constantVar::isMute)PlaySound(TEXT("PUBG.wav"), NULL, SND_ASYNC);
								changeInput = true;
								break;//thua nhung khong choi tiep
							}
						}
					}
					else {
						changeInput = true;
						map.printBorder();
					}
				}break;
				case 2: {
					Sleep(500);
					gameSettings();
					changeInput = true;
					map.printBorder();
				}break;
				case 3:
					clrscr();
					return;
				}
				break;
			}
		}
	}
}

bool cGame::continueMenu() {
	clrscr();
	map.printMap();
	map.deleteOldPlayer();
	map.bombEffect();
	gotoXY(15, 5); cout << "     )   )          (    (      (      " << endl;
	gotoXY(15, 6); cout << "  ( /(( /(          )\\ ) )\\ )   )\\ )   " << endl;
	gotoXY(15, 7); cout << "  )\\())\\())    (   (()/((()/(( (()/(   " << endl;
	gotoXY(15, 8); cout << " ((_)((_)\\     )\\   /(_))/(_))\\ /(_))  " << endl;
	gotoXY(15, 9); cout << "__ ((_)((_) _ ((_) (_))_(_))((_|_))_   " << endl;
	gotoXY(15, 10); cout << " \\ V / (_) | |_| |  | |) | || _|| |) | " << endl;
	gotoXY(15, 11); cout << "  |_| \\___/ \\___/   |___/___|___|___/  " << endl;
	gotoXY(35, 13); cout << "CONTINUE ?" << endl;
	const char *choice[2] = { "<YES>", "<NO>" };
	int pos = 0, x = 36, y = 25;
	TextColor(7);

	while (1) {
		TextColor(7);
		for (int i = 0; i < 2; i++) {
			if (i == pos) {
				TextColor(227);
				gotoXY(x, y + i);
				cout << choice[i];
				TextColor(7);
			}
			else {
				gotoXY(x, y + i);
				cout << choice[i];
			}
		}

		switch (inputKey()) {
		case 'w':
			pos--;
			pos = abs(pos);
			pos %= 2;
			break;
		case 's':
			pos++;
			pos %= 2;
			break;
		case 13:
			return !pos;
		}
	}

}


bool cGame::newGame() { // tao game moi
	
	char key;
	if (!isLoaded) {
		map.~cMap();
		new(&map) cMap();
	}
	isPausing = false;
	map.printMap();
	if(!isLoaded) map.initializeNewState();
	isLoaded = false;

	const string choice[3] = { "SAVE GAME","LOAD GAME","QUIT" };
	int pos = 0;
	while (!map.isEnd()) {
		if (!isPausing) {
			map.randomNextState();
		}

		int x = 125, y = 22;
		if (isPausing) {
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			gotoXY(125, 19); cout << "PAUSE MENU" << endl;
			for (int i = 0; i < 3; i++) {
				gotoXY(x, y + i);
				if (i == pos)
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
				}
				else
				{
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				cout << choice[i] << endl;
			}
		}
			
		if (kbhit())
		{
			key = getch();
			if (key == 'l')
			{
				saveGameMenu();
			}
			if (key == 't')
			{
				togglePauseGame();
				loadGameMenu();
				loading();
				clrscr();
				map.redrawMap();
				togglePauseGame();
				isLoaded = false;
			}
			if (key == 'p')
			{
				togglePauseGame();
				pos = 0;
				if (!isPausing) {
					gotoXY(125, 19); cout << "                  " << endl;
					for (int i = 0; i < 3; i++) {
						gotoXY(x, y + i);
						cout << "                 " << endl;
					}
				}
			}
			if (key == 'a')
			{
				if (!isPausing) map.updatePosPlayer('a');
			}
			if (key == 'w')
			{
				if(!isPausing) map.updatePosPlayer('w');
				else {
					pos--;
					pos = (pos + 3) % 3;
				}

			}
			if (key == 's')
			{
				if (!isPausing) map.updatePosPlayer('s');
				else {
					pos++;
					pos %= 3;
				}
			}
			if (key == 'd')
			{
				if (!isPausing) map.updatePosPlayer('d');
			}
			if (isPausing && key == 13) {
				switch (pos) {
				case 0:
					saveGameMenu();
					break;
				case 1:
					loadGameMenu();
					loading();
					clrscr();
					map.redrawMap();
					togglePauseGame();
					isLoaded = false;
					break;
				case 2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					return true;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			map.drawPlayer();
			map.drawMap();
		}
		if (map.isWin()) {
			if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
			if (map.printLevelUp()) {
				clrscr();
				map.nextLevel();
				map.printMap();
				map.deleteOldPlayer();
				map.initializeNewState();
				map.drawPlayer();
			}
			else return true;
		}
	}
	return false;
}

bool cGame::continueGame()
{
	char key;
	isPausing = false;
	map.printMap();
	map.initializeNewState();
	const string choice[3] = { "SAVE GAME","LOAD GAME","QUIT" };
	int pos = 0;
	while (!map.isEnd()) {
		if (!isPausing) {
			map.randomNextState();
		}

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		gotoXY(125, 19); cout << "PAUSE MENU" << endl;
		int x = 125, y = 22;
		for (int i = 0; i < 3; i++) {
			gotoXY(x, y + i);
			if (isPausing && i == pos)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			}
			cout << choice[i] << endl;
		}

		if (kbhit())
		{
			key = getch();
			if (key == 'l')
			{
				togglePauseGame();
				saveGameMenu();
				togglePauseGame();
			}
			if (key == 't')
			{
				togglePauseGame();
				loadGameMenu();
				togglePauseGame();
			}
			if (key == 'p')
			{
				togglePauseGame();
				pos = 0;
			}
			if (key == 'a')
			{
				if (!isPausing) map.updatePosPlayer('a');
			}
			if (key == 'w')
			{
				if (!isPausing) map.updatePosPlayer('w');
				else {
					pos--;
					pos = (pos + 3) % 3;
				}

			}
			if (key == 's')
			{
				if (!isPausing) map.updatePosPlayer('s');
				else {
					pos++;
					pos %= 3;
				}
			}
			if (key == 'd')
			{
				if (!isPausing) map.updatePosPlayer('d');
			}
			if (isPausing && key == 13) {
				switch (pos) {
				case 0:
					saveGameMenu();
					break;
				case 1:
					loadGameMenu();
					break;
				case 2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					return true;
				}
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			map.drawPlayer();
			map.drawMap();
		}
		if (map.isWin()) {
			if (!constantVar::isMute)PlaySound(TEXT("CompleteStage.wav"), NULL, SND_ASYNC);
			if (map.printLevelUp()) {
				clrscr();
				map.nextLevel();
				map.printMap();
				map.deleteOldPlayer();
				map.initializeNewState();
				map.drawPlayer();
			}
			else return true;
		}
	}
	return false;
}


void cGame::loading()
{
	if (!constantVar::isMute)PlaySound(TEXT("RaceStart.wav"), NULL, SND_ASYNC);
	map.printMap();
	map.deleteOldPlayer();
	drawTitle();
	gotoXY(30, 25);
	cout << "[";
	for (int i = 0; i <= 50; i++)
	{
		Sleep(35);
		gotoXY(30 + i, 25);
		cout << "=>";
		gotoXY(30 + 25, 26);
		cout << i * 2 << "%";
	}

}

vector<string> cGame::getAllFilename(const string& name)
{
		vector<string> v;
		string pattern(name);
		pattern.append("\\*");
		std::wstring stemp = std::wstring(pattern.begin(), pattern.end());
		LPCWSTR sw = stemp.c_str();
		WIN32_FIND_DATA data;					
		HANDLE hFind;
		if ((hFind = FindFirstFile(sw, &data)) != INVALID_HANDLE_VALUE) {
			do {
				wchar_t* txt = data.cFileName;
				wstring ws(txt);
				string str(ws.begin(), ws.end());
				if (str[0] == '.') continue;
				v.push_back(str);
			} while (FindNextFile(hFind, &data) != 0);
			FindClose(hFind);
		}
		return v;
}

bool cGame::loadGameMenu() {
	string filename;
	clrscr();
	vector <string> files = getAllFilename("data");
	if (files.size() == 0) {
		gotoXY(30, 15);
		cout << "No saved file to load !!!";
		Sleep(1000);
		return false;
	}
	int curPos = 0;
	clrscr();
	map.printBorder();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	gotoXY(15, 5); cout << "  _      ____          _____    __  __ ______ _   _ _    _ " << endl;
	gotoXY(15, 6); cout << " | |    / __ \\   /\\   |  __ \\  |  \\/  |  ____| \\ | | |  | |" << endl;
	gotoXY(15, 7); cout << " | |   | |  | | /  \\  | |  | | | \\  / | |__  |  \\| | |  | |" << endl;
	gotoXY(15, 8); cout << " | |   | |  | |/ /\\ \\ | |  | | | |\\/| |  __| | . ` | |  | |" << endl;
	gotoXY(15, 9); cout << " | |___| |__| / ____ \\| |__| | | |  | | |____| |\\  | |__| |" << endl;
	gotoXY(15, 10); cout << " |______\\____/_/    \\_\\_____/  |_|  |_|______|_| \\_|\\____/ " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoXY(30, 13); cout << "<Press ESC to escape...>";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gotoXY(30, 15);
	cout << "Choose Filename to load: ";

	for (int i = 0; i < (int)files.size(); ++i) {
		if (i == curPos) {
			gotoXY(26, 16 + i);
			cout << ">> ";
		}
		gotoXY(30, 16 + i);
		cout << files[i] << endl;
	}
	while (true) {
		if (kbhit())
		{
			char key=getch();
			if (key == 'w')
			{
				gotoXY(26, 16 + curPos);
				cout << "    " << files[curPos];
				curPos--;
				curPos = (curPos + files.size()) % files.size();
				gotoXY(26, 16 + curPos);
				cout << ">>  " << files[curPos];
			}
			if (key == 's')
			{
				gotoXY(26, 16 + curPos);
				cout << "    " << files[curPos];
				curPos++;
				curPos = (curPos + files.size()) % files.size();
				gotoXY(26, 16 + curPos);
				cout << ">>  " << files[curPos];
			}
			if (key == 13)
			{
				isLoaded = true;
				map.loadGame(files[curPos]);
				clrscr();
				return true;
			}
			if (key == 27)
			{
				clrscr();
				return false;
			}
		}
		Sleep(200);
	}
}

void cGame::saveGameMenu() { 
	string filename;
	clrscr();
	map.printBorder();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoXY(15, 5); cout << " _____  ___  _   _ _____  ___  ___ _____ _   _ _   _ " << endl;
	gotoXY(15, 6); cout << "/  ___|/ _ \\| | | |  ___| |  \\/  ||  ___| \\ | | | | |" << endl;
	gotoXY(15, 7); cout << "\\ `--./ /_\\ \\ | | | |__   | .  . || |__ |  \\| | | | |" << endl;
	gotoXY(15, 8); cout << " `--. \\  _  | | | |  __|  | |\\/| ||  __|| . ` | | | |" << endl;
	gotoXY(15, 9); cout << "/\\__/ / | | \\ \\_/ / |___  | |  | || |___| |\\  | |_| |" << endl;
	gotoXY(15, 10); cout << "\\____/\\_| |_/\\___/\\____/  \\_|  |_/\\____/\\_| \\_/\\___/ " << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoXY(15, 20);
	cout << "<Press ESC to escape>";
	map.deleteOldPlayer();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoXY(15, 15);
	cout << "Input file name to save: ";
	//getline(cin, filename);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	char key;
	while ((key = getch()) != 27 ) {
		switch (key) {
		case '\b':
			if (filename.size() != 0) {
				filename.pop_back();
				gotoXY(50, 15);
				cout << "                                                 ";
				gotoXY(50, 15);
				cout << filename;
			}
			break;
		case 13:
			map.saveGame(filename);
			break;
		default:
			filename.push_back(key);
			gotoXY(50, 15);
			cout << filename;
		}
		if (key == 13) break;
	}
	clrscr();
	map.redrawMap();
}

void cGame::togglePauseGame() {
	isPausing = !isPausing;
};

void cGame::gameOver() {
	cout << "GAME OVER" << endl;
};

void cGame::toggleMute() {
	constantVar::isMute = !constantVar::isMute;
}


void cGame::toggleHard()
{
	constantVar::isHard = !constantVar::isHard;
}