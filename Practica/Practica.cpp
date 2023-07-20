#include <iostream>
#include "task58.h"
#include <math.h>
#include "task12.h"
#include "task62.h"



using namespace std;
int main() {
	setlocale(LC_ALL, "Russian");


	int task = -1;
	while (1) {
		cout << "Yakovlev Gleb 1044" << endl;
		cout << "Which task do you want to choose?" << endl;
		cout << "1 - 58 task" << endl << "2 - 62 task" << endl << "3 - 12 task" << endl << "0 - close" << endl;

		cin >> task;
		switch (task)
		{
		case 0: return 0;
		case 1: {system("cls"); task58(); break; }
		case 2: {system("cls"); task62(); break; }
		case 3: {system("cls"); task12(); break; }
		default: {cout << "Wrong input" << endl; break; }
		}
	}
	return 0;
}