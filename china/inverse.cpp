#include "head.h"

unsigned int inverse (unsigned int a, unsigned int b) {
	if (b == 1) {
		return 1;
	};

	unsigned int b0 = b, t, x0 = 0, x1 = 1;
	double q;

	int i = 0;

	while (a > 1) {
		if (b == 0) {
			break;
		};
		q = a / b;

		t = b;
		b = a % b;
		a = t;

		t = x0;
		x0 = x1 - q * x0;
		x1 = t;
	};

	if (x1 < 0) {
		x1 += b0;
	};

	return x1;
}