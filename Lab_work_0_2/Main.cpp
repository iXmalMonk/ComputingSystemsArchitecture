#include <iostream>

int main()
{
	double a = 2.3;
	double b = 5.8;
	double firstSum = a + b;
	double secondSum;

	__asm {
		fld a
		fadd b
		fstp secondSum
	}

	std::cout << firstSum << " " << secondSum << std::endl;

	return 0;
}