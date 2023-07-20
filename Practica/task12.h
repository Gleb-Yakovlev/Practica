#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <windows.h>
#include "sqlite3.h"

static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

int readConfig(); 
bool LLT(unsigned long long n);
void task12();

void myDataBase(vector<unsigned long long> v);