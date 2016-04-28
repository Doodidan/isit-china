#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

int mul_inv(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
void main(){
	int k = 3;
	int m[3] = { 7, 5, 6 };//new int[k];//k штук, целые взаимно простые
	int a[3] = { 6, 1, 0 };//new int[k];//k штук
	int x = 0;
	int i = 0;
	int M = 1;
	int b;
	int c;
	//ƒл¤ начал обозначим M=sum(m1,m2...mj)
	for (int j = 0; j<k; j++){
		M *= m[j];
	}
	std::cout << M<<std::endl;
	while (i<k){
		b = M / m[i];
		std::cout << "b=" << b << std::endl;
		c = mul_inv(b, m[i]);
		std::cout << "c=" << c << std::endl;
		x = (x + (a[i] * b*c)) % M;
		std::cout << "x=" << x << std::endl;
		i = i + 1;
		std::cout << "i=" << i << std::endl;
		}
	std::cout << x << std::endl;
	std::cout << "x=" << x<<"(mod"<<M<<")"<<std::endl;
}
