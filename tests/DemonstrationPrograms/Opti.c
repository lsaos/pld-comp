#include <stdint.h>

int main() {
	// Declarations
	int a, b;

	// We can precompute the constant
	a = (126 + 45) * 9;

	// 1 is the neutral element of multiplication
	b = a * 1;

	// 0 is the neutral element of addition
	a = b + 0;

	return a;
}
