#include <iostream>

double firstQE(double a, double b, double c)
{
	return (-b + sqrt(b * b - 4 * a * c)) / 2 / a;
}

double secondQE(double a, double b, double c)
{
	double two = 2.0;
	double four = 4.0;

	__asm {
		fld b
		fmul b
		fld four
		fmul a
		fmul c
		fsub
		fsqrt
		fsub b
		fdiv two
		fdiv a
	}
}

int main()
{
	double a = 1;
	double b = -3;
	double c = 1;
	double firstX = firstQE(a, b, c);
	double secondX = secondQE(a, b, c);

	std::cout << firstX << " " << secondX << std::endl;

	return 0;
}