#include <iostream>
#include <omp.h>

void firstTask()
{
	srand(0);
	const int n = 5;
	int i = 0;
	int a[n] = { 0 };
	int b[n] = { 0 };
	int c[n] = { 0 };
	std::cout << "A:" << " ";
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		std::cout << a[i] << " ";
	}
	std::cout << std::endl << "B:" << " ";
	for (i = 0; i < n; i++)
	{
		b[i] = rand() % 100;
		std::cout << b[i] << " ";
	}
	std::cout << std::endl;
#pragma omp parallel private(i)
	{
#pragma omp for
		for (i = 0; i < n; i++)
		{
			c[i] = a[i] + b[i];
			std::cout << "Thread number: " << omp_get_thread_num() << ", i: " << i << std::endl;
		}
	}
	std::cout << std::endl << "C:" << " ";
	for (i = 0; i < n; i++)
	{
		std::cout << c[i] << " ";
	}
}

void secondTask()
{
	srand(0);
	const int n = 100;
	int i = 0;
	int sum = 0;
	int a[n] = { 0 };
	int b[n] = { 0 };
	std::cout << "A:" << " ";
	for (i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		std::cout << a[i] << " ";
	}
	std::cout << std::endl << "B:" << " ";
	for (i = 0; i < n; i++)
	{
		b[i] = rand() % 100;
		std::cout << b[i] << " ";
	}
	std::cout << std::endl;
#pragma omp parallel private(i)
	{
#pragma omp for reduction (+:sum)
		for (i = 0; i < n; i++)
		{
			sum += a[i] * b[i];
		}
	}
	std::cout << "sum: " << sum << std::endl;
}

int** newArray(int n)
{
	srand(0);
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			a[i][j] = rand() % 100;
		}
	}
	return a;
}

void deleteArray(int** a, int n)
{
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;
}

void printArray(int** a, int n)
{
	std::cout << "Array:" << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void thirdTask()
{
	srand(0);
	const int n = 3;
	int i = 0;
	int j = 0;
	int** a;
	int b[n] = { 0 };
	int c[n] = { 0 };
	a = newArray(n);
	for (i = 0; i < n; i++)
	{
		b[i] = rand() % 100;
	}
	printArray(a, n);
	std::cout << "Vector:" << std::endl;
	for (i = 0; i < n; i++)
	{
		std::cout << b[i] << std::endl;
	}
	omp_set_nested(1);
#pragma omp parallel default(shared) private(i, j)
	{
#pragma omp for
		for (i = 0; i < n; i++)
		{
#pragma omp parallel
#pragma omp for
			for (j = 0; j < n; j++)
			{
				c[i] += a[i][j] * b[j];
				std::cout << "Thread number: " << omp_get_thread_num() << ", i: " << i << ", value: " << c[i] << std::endl;
			}
		}
	}
	std::cout << "Vector:" << std::endl;
	for (i = 0; i < n; i++)
	{
		std::cout << c[i] << std::endl;
	}
	deleteArray(a, n);
}

void fourthTask()
{
	srand(0);
	const int n = 11;
	int i = 0;
	int j = 0;
	omp_set_nested(1);
#pragma omp parallel private(i, j)
	{
#pragma omp for ordered
		for (i = 1; i < n; i++)
		{
#pragma omp ordered
#pragma omp parallel num_threads(10)
#pragma omp for ordered
			for (j = 1; j < n; j++)
			{
#pragma omp ordered
				std::cout << "Thread number: " << omp_get_thread_num() << " - " << i << " * " << j << " = " << i * j << std::endl;
			}
			std::cout << std::endl;
		}
	}
}

int main()
{
	fourthTask();
	return 0;
}