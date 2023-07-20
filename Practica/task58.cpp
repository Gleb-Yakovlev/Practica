#include "task58.h"

bool isItAPrimeNumber(unsigned long long numb) {

	for (unsigned long long i = 2; i <= sqrt(numb); i++) {
		if (numb % i == 0)
			return 0;
	}
	return 1;
}

vector <unsigned long long> decIntoPrimeNumb(unsigned long long numb) {
	vector <unsigned long long> primeNumb;
	unsigned long long comeNumb = numb;
	int del = 2;
	while (numb != 1) {
		if (numb % del == 0) {
			primeNumb.push_back(del);
			numb /= del;
		}
		else {
			do
				del++;
			while (isItAPrimeNumber(del) != 1);
		}
	}
	cout << "Number " << comeNumb << endl;
	cout << "Prime numbers: ";
	for (int i = 0; i < primeNumb.size(); i++) cout << primeNumb[i] << " ";
	cout << endl;
	return primeNumb;
}



void task58() {

	ofstream file("bd58.txt", ofstream::trunc);

	while (1) {
		cout << "в единственной строке вводятся два целых числа n и b (4 <= n <= 10^18 , 2 <= b <= 500)." << endl
			<< "выведите количество b - гладких чисел от 1 до n.и покажите их на экране.дополнительно" << endl
			<< "сохраните результат в текстовом файле, в котором каждая строка для одного найденного b - гладкого" << endl
			<< "числа" << endl;

		cout << "enter n and b if you want to get out enter 0 and 0" << endl;
		int b;
		unsigned long long n;
		n = b = 0;
		cin >> n >> b;

		if (n == 0 and b == 0) return;
		if (n < 4 or n > 1000000000000000000) cout << "wrong number n" << endl;
		else if(b < 2 or b > 500) cout << "wrong number b" << endl;
		else
			for (int i = 2; i <= n; i++) {	
				vector <unsigned long long> primevector;
				primevector = decIntoPrimeNumb(i);
				bool smoothnumb = true;
				for (int j = 0; j < primevector.size(); j++)  if (primevector[j] > b) {smoothnumb = false; break;}
				if (smoothnumb) { 
					cout << "it is b-smooth number" << endl; 
					file << i << endl;
				}
				else cout << "it is not b-smooth number" << endl;
				cout << "---------------" << endl;
			}
		system("pause");
		system("cls");

	}
	file.close();
}
