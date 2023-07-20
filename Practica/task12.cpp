#include "task12.h"

int readConfig() {
	int confNumber = 0;
	string l;
	ifstream file("config12.txt");
	getline(file, l);
	confNumber = stoi(l);
	file.close();
	return confNumber;
}

bool LLT(unsigned long long n) {
	SetConsoleTextAttribute(hConsole, 15);
	unsigned long long stepen = n + 1;
	stepen = log2(stepen);
	unsigned long long s = 4;
	cout << endl << "-----------------" << endl;
	for (int i = 2; i < stepen; i++) {
		unsigned long long oldS = s;
		cout << i << ") " << oldS << "^2 - 2 % " << n << " = " << (s = (oldS * oldS - 2) % n) << endl;
	}
	cout << "-----------------" << endl;
	if (s == 0) return true;
	else return false;
}

void task12() {
	string m = "Вывести на экран все n первых чисел Мерсена, простые числа этого ряда вывести другим цветом.\nЗначение n считывается из конфигурационного файла.";
	cout << m << endl;


	int n = readConfig();
	vector <unsigned long long> mersenNumbers;
	for (int i = 1; i <= n; i++) mersenNumbers.push_back(pow(2, i) - 1);

	cout << "A series of Mersenne numbers:" << endl;
	for (int i = 0; i < mersenNumbers.size(); i++) {

		if (mersenNumbers[i] == 3) {
			SetConsoleTextAttribute(hConsole, 12);
			cout << mersenNumbers[i];
		}
		else if (mersenNumbers[i] == 1) {
			SetConsoleTextAttribute(hConsole, 9);
			cout << mersenNumbers[i] << endl;
		}
		else
			if (LLT(mersenNumbers[i])) {
				SetConsoleTextAttribute(hConsole, 12);
				cout << mersenNumbers[i];
			}
			else {
				SetConsoleTextAttribute(hConsole, 15);
				cout << mersenNumbers[i];
			}
	}
	SetConsoleTextAttribute(hConsole, 15);
	cout << endl;
	myDataBase(mersenNumbers);
	system("pause");
	system("cls");
}

void myDataBase(vector<unsigned long long> v) {
	const char* SQL = "CREATE TABLE IF NOT EXISTS foo(mersenNumbers); DELETE FROM foo;"; 
	sqlite3* db = 0; 
	char* err = 0;
	if (sqlite3_open("my_cosy_database.dblite", &db))
		fprintf(stderr, "Ошибка открытия/создания БД: %s\n", sqlite3_errmsg(db));
	else 
	{
		sqlite3_exec(db, SQL, 0, 0, &err);
		for (int i = 0; i < v.size(); i++) {
			string insert = "INSERT INTO foo(mersenNumbers) VALUES ";
			insert += "(" + to_string(v[i]) + ");";
			sqlite3_exec(db, insert.c_str(), 0, 0, &err);
		}

	}
	sqlite3_close(db);
}