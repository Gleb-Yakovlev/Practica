#pragma once
// W = wall G = glasses . = empty plase

#include <iostream>
#include <vector>
#include <windows.h>
#include <ctime>
#include <string>

static HANDLE hhConsole = GetStdHandle(STD_OUTPUT_HANDLE);
using namespace std;

static int N, M;
static vector <vector<char>> map;
static int entryX, entryY, exitX, exitY;

static vector <vector<int>> exitMatrix;
static vector <vector<int>> path;
static string Path;
static vector <vector<int>> portals;
static int numbPort = 0;

void writeSToArray(int x, int y, char s);
void writeKtoMatrix(int x, int y, int k);
void writePath(int i, int x, int y, char p);

void drawMap();
void drawMatrix();

bool itIsWall(int x, int y);

int getRandSymb();

void fullRandomCreateMap();

void putEnterExit();

bool inDirPass(int x, int y, string dir);

bool findGlasses(int x, int y, string dir);

void makeAPortal(int x, int y, string dir, int k);

void findPath(int k, int x, int y);

void findSequence();
void findExit();

void task62();

