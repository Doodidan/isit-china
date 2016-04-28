#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

int inverse (int a, int b) {
	if (b == 1) {
		return 1;
	};

	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	};
	if (x1 < 0) {
		x1 += b0;
	};
	return x1;
}

int main() {
	setlocale(LC_ALL, "Russian");

	int k = 3; // кол-во ур-ний
	int m[3] = { 7, 5, 6 }; // int[k] - k штук, целые попарно взаимно простые
	int a[3] = { 6, 1, 0 }; // int[k] - k штук, остатки
	int x = 0;
	int M = 1;
	int b;
	int c;

	// M = m1*m2*...*mj
	for (int j = 0; j < k; j++) {
		M *= m[j];
	}
	cout << "M: "<< M << endl;

	for (int i = 0; i < k; i++) {
		cout << "Итерация: " << i + 1 << endl;

		b = M / m[i];
		cout << "b=" << b << "; ";

		c = inverse(b, m[i]);
		cout << "c=" << c << "; ";

		x = (x + (a[i] * b * c)) % M;
		cout << "x=" << x << ";" << endl;
	};

	cout << "Результат: x=" << x << " (mod " << M << ")" << endl;

	return 0;
}
