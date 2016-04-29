#include "head.h"
#include "functions.h"

int main() {
	setlocale(LC_ALL, "Russian");

	int m[5] = { 121, 122, 125, 127, 133 }; // int[n] - n штук, целые попарно взаимно простые
	int o[5] = { 3, 2, 1, 5, 8 }; // int[n] - n штук, остатки

	int n = 5; // количество уравнений
	unsigned int x = 0, M = 1, a, b;

	// вывод системы уравнений
	cout << "Дана система:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "x = " << o[i] << " (mod " << m[i] << ")" << endl;
	}
	cout << endl;

	// M = m1*m2*...*mj
	for (int i = 0; i < n; i++) {
		M *= m[i];
	}
	cout << "M: " << M << endl << endl;

	for (int i = 0; i < n; i++) {
		cout << "Итерация: " << i + 1 << endl;

		a = M / m[i];
		cout << "b=" << a << "; ";

		b = inverse(a, m[i]);
		cout << "c=" << b << "; ";

		x = (x + (o[i] * a * b)) % M;
		cout << "x=" << x << ";" << endl << endl;
	};

	cout << "Результат: x=" << x << " (mod " << M << ")" << endl;

	return 0;
}
