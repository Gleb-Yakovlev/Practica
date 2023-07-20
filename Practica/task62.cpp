#include "task62.h"

void writeSToArray(int x, int y, char s) {
	map[y][x] = s;
}

void writeKtoMatrix(int x, int y, int k) {
	if (map[y][x] != 'G' and map[y][x] != 'W' and exitMatrix[y][x] == 0) {
		exitMatrix[y][x] = k;
	}
}

void drawMap() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			if (map[y][x] == 'W') SetConsoleTextAttribute(hhConsole, 8);
			if (map[y][x] == 'G') SetConsoleTextAttribute(hhConsole, 3);
			if (map[y][x] == '.') SetConsoleTextAttribute(hhConsole, 15);
			if (map[y][x] == 'S') SetConsoleTextAttribute(hhConsole, 10);
			if (map[y][x] == 'E') SetConsoleTextAttribute(hhConsole, 12);
			cout << map[y][x];
			SetConsoleTextAttribute(hhConsole, 15);
		}	
		cout << y << endl;
	}
	for (int x = 0; x < N; x++) cout << x;
	cout << endl;
}
void drawMatrix() {
	for (int y = 0; y < N; y++) {
		for (int x = 0; x < M; x++) {
			SetConsoleTextAttribute(hhConsole, 15);
			for (int k = 0; k < path.size(); k++) {
				if (x == path[k][0] and y == path[k][1]) SetConsoleTextAttribute(hhConsole, 9);
			}
			if (y == entryY and x == entryX) SetConsoleTextAttribute(hhConsole, 10);
			if (y == exitY and x == exitX) SetConsoleTextAttribute(hhConsole, 12);
			cout << exitMatrix[y][x];
			SetConsoleTextAttribute(hhConsole, 15);
		}
		cout << endl;
	}
}

bool itIsWall(int x, int y) {
	if (x == 0 or y == 0 or x == N - 1 or y == M - 1) return true;
	else return false;
}

int getRandSymb() {
	// 1 = W 2 = G 3 = .
	int min = 1;
	int max = 2;
	int num = min + rand() % (max - min + 1);
	return num;
}

void fullRandomCreateMap() {
	srand(time(NULL));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (itIsWall(i, j)) writeSToArray(i, j, 'W');
			else {
				switch (getRandSymb())
				{
				case 1: {writeSToArray(i, j, 'W'); break; };
				case 2: {writeSToArray(i, j, '.'); break; };
				}
			}
		}

	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!itIsWall(i, j) and map[i][j] == 'W') {
				switch (getRandSymb()) {
				case 1: break;
				case 2: {writeSToArray(i, j, 'G'); break; }
				}
			}
		}
	}
}

void putEnterExit() {
	writeSToArray(entryX, entryY, 'S');
	writeSToArray(exitX, exitY, 'E');
}

bool inDirPass(int x, int y, string dir) {

	if (dir == "up") {
		if (map[y - 1][x] == '.' or map[y - 1][x] == 'E') return true;//map[x][y - 1]
		else return false;
	}
	if (dir == "down") {
		if (map[y + 1][x] == '.' or map[y + 1][x] == 'E') return true;//map[x][y + 1]
		else return false;
	}
	if (dir == "left") {
		if (map[y][x - 1] == '.' or map[y][x - 1] == 'E') return true;// map[x - 1][y]
		else return false;
	}
	if (dir == "right") {
		if (map[y][x + 1] == '.' or map[y][x + 1] == 'E') return true;// map[x + 1][y] 
		else return false;
	}
}

bool findGlasses(int x, int y, string dir) {
	if (dir == "up") {
		if (map[y - 1][x] == 'G') return true;//map[x][y - 1]
		else return false;
	}
	if (dir == "down") {
		if (map[y + 1][x] == 'G') return true;//map[x][y + 1]
		else return false;
	}
	if (dir == "left") {
		if (map[y][x - 1] == 'G') return true;//map[x - 1][y]
		else return false;
	}
	if (dir == "right") {
		if (map[y][x + 1] == 'G') return true;//map[x + 1][y]
		else return false;
	}
}

void makeAPortal(int x, int y, string dir, int k) {

	int begX = x;
	int begY = y;
	bool canWriteF = false;
	if (dir == "up") {
		y--;
		while (map[y][x] == 'G') {
			y--;
			if (map[y][x] == 'W') canWriteF = false;
			if (map[y][x] == '.' and exitMatrix[y][x] > 0 and exitMatrix[y][x] < k) canWriteF = false;
			else if (map[y][x] == '.' or map[y][x] == 'E') {
				canWriteF = true;
				numbPort++;
				portals.resize(numbPort);
				portals[numbPort - 1].push_back(begY);
				portals[numbPort - 1].push_back(begX);
				portals[numbPort - 1].push_back(y);
				portals[numbPort - 1].push_back(x);
			}
		}
	}
	if (dir == "down") {
		y++;
		while (map[y][x] == 'G') {
			y++;
			if (map[y][x] == 'W') canWriteF = false;
			if (map[y][x] == '.' and exitMatrix[y][x] > 0 and exitMatrix[y][x] < k) canWriteF = false;
			else if (map[y][x] == '.' or map[y][x] == 'E') {
				canWriteF = true;
				numbPort++;
				portals.resize(numbPort);
				portals[numbPort - 1].push_back(begY);
				portals[numbPort - 1].push_back(begX);
				portals[numbPort - 1].push_back(y);
				portals[numbPort - 1].push_back(x);
			}
		}
	}
	if (dir == "right") {
		x++;
		while (map[y][x] == 'G') {
			x++;
			if (map[y][x] == 'W') canWriteF = false;
			if (map[y][x] == '.' and exitMatrix[y][x] > 0 and exitMatrix[y][x] < k) canWriteF = false;
			else if (map[y][x] == '.' or map[y][x] == 'E') {
				canWriteF = true;
				numbPort++;
				portals.resize(numbPort);
				portals[numbPort - 1].push_back(begY);
				portals[numbPort - 1].push_back(begX);
				portals[numbPort - 1].push_back(y);
				portals[numbPort - 1].push_back(x);
			}
		}
	}
	if (dir == "left") {
		x--;
		while (map[y][x] == 'G') {
			x--;
			if (map[y][x] == 'W') canWriteF = false;
			if (map[y][x] == '.' and exitMatrix[y][x] > 0 and exitMatrix[y][x] < k) canWriteF = false;
			else if (map[y][x] == '.' or map[y][x] == 'E') {
				canWriteF = true;
				numbPort++;
				portals.resize(numbPort);
				portals[numbPort - 1].push_back(begY);
				portals[numbPort - 1].push_back(begX);
				portals[numbPort - 1].push_back(y);
				portals[numbPort - 1].push_back(x);
			}
		}
	}

	if (canWriteF) { writeKtoMatrix(portals[numbPort - 1][3], portals[numbPort - 1][2], k);	}

}

void findPath(int k, int x, int y) {
	if (inDirPass(x, y, "up") ) writeKtoMatrix(x, y - 1, k);
	if (inDirPass(x, y, "down") ) writeKtoMatrix(x, y + 1, k); 
	if (inDirPass(x, y, "left")) writeKtoMatrix(x - 1, y, k); 
	if (inDirPass(x, y, "right") ) writeKtoMatrix(x + 1, y, k); 

	if (findGlasses(x, y, "up")) { makeAPortal(x, y, "up", k); }
	if (findGlasses(x, y, "down")) { makeAPortal(x, y, "down", k); }
	if (findGlasses(x, y, "left")) { makeAPortal(x, y, "left", k); }
	if (findGlasses(x, y, "right")) { makeAPortal(x, y, "right", k); }
}

void writePath(int i, int x, int y, char p) {
	path[i][0] = x;
	path[i][1] = y;
	Path.insert(Path.begin(), p);
	Path.insert(Path.begin(), ' ');
}

void findSequence() {
	path.resize(exitMatrix[exitY][exitX]);
	for (int i = 0; i < path.size(); i++) {
		path[i].resize(2);
		path[i][0] = 0;
		path[i][1] = 0;
	}
	Path = "";
	int x = exitX;
	int y = exitY;
	cout << "The path: ";
	path[0][0] = exitX;
	path[0][1] = exitY;
	
	for (int i = 1; i < exitMatrix[exitY][exitX]; i++) {
		if ((exitMatrix[y][x] - exitMatrix[y][x - 1]) == 1) { x--; writePath(i, x, y, 'R');  }
		else if ((exitMatrix[y][x] - exitMatrix[y][x + 1]) == 1) { x++; writePath(i, x, y, 'L');  }
		else if ((exitMatrix[y][x] - exitMatrix[y - 1][x]) == 1) { y--; writePath(i, x, y, 'D'); }
		else if ((exitMatrix[y][x] - exitMatrix[y + 1][x]) == 1) { y++; writePath(i, x, y, 'U');}
		else for (int j = 0; j < numbPort; j++) {
			//B - вход O - выход
			if (y == portals[j][2] and x == portals[j][3]) {
				string s;
				s = "O(" + to_string(portals[j][1]) + ";" + to_string(portals[j][0]) + ")B(" +
					to_string(portals[j][3]) + ";" + to_string(portals[j][2]) + ")";
				Path = s + Path;
				Path.insert(Path.begin(), ' ');
				x = portals[j][1];
				y = portals[j][0];
				path[i][0] = x;
				path[i][1] = y;
				break;
			}
		}
	}
	for (int i = path.size() - 1; i >= 0; i--) {
		cout << "(" << path[i][0] << ";" << path[i][1] << ") ";
	}
	cout << endl << Path << endl;
}

void findExit() {
	exitMatrix.resize(N);
	for (int i = 0; i < N; i++) exitMatrix[i].resize(M);
	for (int i = 0; i < exitMatrix.size(); i++)
		for (int j = 0; j < exitMatrix[i].size(); j++) exitMatrix[i][j] = 0;

	int maxK = 9;

	exitMatrix[entryY][entryX] = 1;
	for (int i = 2; i < maxK; i++) {
		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (exitMatrix[y][x] == i - 1) {
					/*system("cls");
					drawMap();
					drawMatrix();*/
					findPath(i, x, y);
					//system("pause");
				}
				if (exitMatrix[exitY][exitX] != 0) {
					findSequence();
					return;
				}
			}
		}
	}

	cout << "(" << 0 << ";" << 0 << ") " << endl;
	return;
}

void task62() {
	cout << "Сделать лабиринт N на M. Символ W = стена, G = стекло . = пустное пространство" << endl;
	while (1) {
		cout << "Enter N and M" << endl;
		cin >> N >> M;
		cout << "If you want, you can enter the input and output points randomly(enter 1 if rand, 0 if not)" << endl;
		int wantRandom = 1;
		cin >> wantRandom;
		if (wantRandom) {
			srand(time(NULL));
			// (2 ≤ rS, rE ≤ N – 1;2 ≤ cS, cE ≤ M – 1)
			int min = 2;
			int max = N - 2;
			entryX = min + rand() % (max - min + 1);
			exitX = min + rand() % (max - min + 1);
			max = M - 2;
			entryY = min + rand() % (max - min + 1);
			exitY = min + rand() % (max - min + 1);
			int x = entryX;
			int y = entryY;
			int yfds;
		}
		else {
			int flag = 1;
			while (flag) {
				cout << "Entry X: ";
				cin >> entryX;
				cout << endl;
				cout << "Entry Y: ";
				cin >> entryY;
				cout << endl;
				cout << "Exit X: ";
				cin >> exitX;
				cout << endl;
				cout << "Exit Y: ";
				cin >> exitY;
				cout << endl;
				if (entryX >= 2 and entryY <= (N - 1) and exitX >= 2 and exitY <= (M - 1)) flag = 0;
				else {
					system("cls");
					cout << "Error input, try again" << endl;
				}
			}
		}

		if (N < 3) cout << "N < 3 - error" << endl;
		else if (M > 1000) cout << "M > 1000 error" << endl;
		else {
			system("cls");

			map.resize(N);
			for (int i = 0; i < N; i++) map[i].resize(M);

			fullRandomCreateMap();
			putEnterExit();



			drawMap();
			findExit();


			drawMatrix();

			system("pause");
			system("cls");

			return;
		}
	}
}

