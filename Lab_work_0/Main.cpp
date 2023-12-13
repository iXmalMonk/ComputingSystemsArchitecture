#include <iostream>

int firstTask()
{
	int a = 200000;
	int b = a;
	int sumFirst = a + b;
	int sumSecond;
	__asm {
		mov eax, a
		add eax, b
		mov sumSecond, eax
	}
	__asm {
		jo OVERFL0W
	}
	std::cout << sumFirst << " " << sumSecond << std::endl;
	goto CONTINUE;
OVERFL0W:
	std::cout << "OVERFLOW" << std::endl;
CONTINUE:
	return 0;
}

int secondTask()
{
	int a = 2000000000;
	int b = a;
	int sumFirst = a + b;
	int sumSecond;
	__asm {
		mov eax, a
		add eax, b
		mov sumSecond, eax
	}
	__asm {
		jo OVERFL0W
	}
	std::cout << sumFirst << " " << sumSecond << std::endl;
	goto CONTINUE;
OVERFL0W:
	std::cout << "OVERFLOW" << std::endl;
CONTINUE:
	return 0;
}

int thirdTask()
{
	short int a = 15000;
	short int b = a;
	short int sum = a + b;
	__asm {
		jo OVERFL0W
	}
	std::cout << sum << std::endl;
	goto CONTINUE;
OVERFL0W:
	std::cout << "OVERFLOW" << std::endl;
CONTINUE:
	return 0;
}

int fourthTask()
{
	long int a = 200000000;
	long int b = a;
	long int firstSum = a + b;
	long int secondSum;
	__asm {
		mov eax, a
		add eax, b
		mov secondSum, eax
	}
	__asm {
		jo OVERFL0W
	}
	std::cout << firstSum << " " << secondSum << std::endl;
	goto CONTINUE;
OVERFL0W:
	std::cout << "OVERFLOW" << std::endl;
CONTINUE:
	return 0;
}

int main()
{
	return firstTask();
}