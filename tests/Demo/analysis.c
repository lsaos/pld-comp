#include <stdint.h>

int main() {
	// Declarations
	int var1 = 2, var2, var3, unusedVar;
	char signedChar;
	int tab[3];

	// Some operations on a, b and c
	var2 = 5;
	var3 = 10;
	var1 = var1 * var2 + var3;

	// We assign value to d but never use it
	unusedVar = var1 + 3;

	// 240 is outside of signed char value range
	signedChar = 120 * 2;

	// Wrong array constant indexing
	tab[3] = signedChar;

	tab[0] = var1;
	return tab[0];
}
