#include <iostream>
#include <omp.h>

void firstTask(double start)
{
	int a = 0;
	int b = 2;
	int i = 0;
	int counter = 0;
	int output = 1;
	double x = 0;
	double present = 0;
	double next = 0;
	double height = 0;
	while (true)
	{
		if (!counter)
		{
			counter = 1;
			height = ((double)b - a) / counter;
#pragma omp parallel private(i, x) num_threads(4)
#pragma omp for reduction(+:present)
			for (i = 0; i < counter; i++)
			{
				x = a + (i * height);
				present += std::log(2.1 + sin(2 * x));
			}
			present *= height;
		}
		else
		{
			counter *= 2;
			next = 0;
			height = ((double)b - a) / counter;
#pragma omp parallel private(i, x) num_threads(4)
#pragma omp parallel reduction(+:next)
			for (i = 0; i < counter; i++)
			{
				x = a + (i * height);
				next += std::log(2.1 + sin(2 * x));
			}
			next *= height;
			if (fabs(next - present) <= 0.000001 && output == 1)
			{
				std::cout << "Accuracy 10^-5 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				output++;
			}
			else if (fabs(next - present) <= 0.0000001 && output == 2)
			{
				std::cout << "Accuracy 10^-6 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				output++;
			}
			else if (fabs(next - present) <= 0.00000001 && output == 3)
			{
				std::cout << "Accuracy 10^-7 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				break;
			}
			else
			{
				present = next;
			}
		}
	}
}

void secondTask(double start)
{
	int a = 0;
	int b = 2;
	int i = 0;
	int counter = 0;
	int output = 1;
	double x = 0;
	double present = 0;
	double next = 0;
	double height = 0;
	while (true)
	{
		if (!counter)
		{
			counter = 1;
			height = ((double)b - a) / counter;
#pragma omp parallel private(i, x) num_threads(4)
#pragma omp for reduction(+:present)
			for (i = 0; i < counter; i++)
			{
				x = a + (i * height);
				present += std::log(2.1 + sin(2 * x));
			}
			present *= height;
		}
		else
		{
			counter *= 2;
			next = 0;
			height = ((double)b - a) / counter;
#pragma omp parallel private(i, x) num_threads(4)
#pragma omp parallel reduction(+:next)
			for (i = 0; i < counter; i++)
			{
				x = a + (i * height);
				next += std::log(2.1 + sin(2 * x));
			}
			next *= height;
			if (fabs(next - present) <= 0.000001 && output == 1)
			{
				std::cout << "Accuracy 10^-5 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				output++;
			}
			else if (fabs(next - present) <= 0.0000001 && output == 2)
			{
				std::cout << "Accuracy 10^-6 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				output++;
			}
			else if (fabs(next - present) <= 0.00000001 && output == 3)
			{
				std::cout << "Accuracy 10^-7 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				break;
			}
			else
			{
				present = next;
			}
		}
	}
}

void thirdTask(double start)
{
	int a = 0;
	int b = 2;
	int i = 0;
	int counter = 0;
	int output = 1;
	double x = 0;
	double present = 0;
	double next = 0;
	double height = 0;
	while (true)
	{
		if (!counter)
		{
			counter = 1;
			height = ((double)b - a) / counter;
#pragma omp parallel private(i, x) num_threads(4)
#pragma omp for reduction(+:present)
			for (i = 0; i < counter; i++)
			{
				x = a + (i * height) + (height / 2);
				present += std::log(2.1 + sin(2 * x));
			}
			present *= height;
		}
		else
		{
			counter *= 2;
			next = 0;
			height = ((double)b - a) / counter;
#pragma omp parallel private(i, x) num_threads(4)
#pragma omp parallel reduction(+:next)
			for (i = 0; i < counter; i++)
			{
				x = a + (i * height) + (height / 2);
				next += std::log(2.1 + sin(2 * x));
			}
			next *= height;
			if (fabs(next - present) <= 0.000001 && output == 1)
			{
				std::cout << "Accuracy 10^-5 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				output++;
			}
			else if (fabs(next - present) <= 0.0000001 && output == 2)
			{
				std::cout << "Accuracy 10^-6 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				output++;
			}
			else if (fabs(next - present) <= 0.00000001 && output == 3)
			{
				std::cout << "Accuracy 10^-7 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				break;
			}
			else
			{
				present = next;
			}
		}
	}
}

void fourthTask(double start)
{
	int a = 0;
	int b = 2;
	int i = 0;
	int counter = 0;
	int output = 1;
	double x = 0;
	double x1 = 0;
	double x2 = 0;
	double present = 0;
	double next = 0;
	double height = 0;
	while (true)
	{
		if (!counter)
		{
			counter = 1;
			height = ((double)b - a) / counter;
#pragma omp parallel private(i, x1, x2) num_threads(4)
#pragma omp for reduction(+:present)
			for (i = 0; i < counter; i++)
			{
				x1 = a + (double)i * height;
				x2 = a + ((double)i + 1) * height;
				present += std::log(2.1 + sin(2 * x)) + std::log(2.1 + sin(2 * x)) / 2;
			}
			present *= height;
		}
		else
		{
			counter *= 2;
			next = 0;
			height = ((double)b - a) / counter;
#pragma omp parallel private(i, x1, x2) num_threads(4)
#pragma omp parallel reduction(+:next)
			for (i = 0; i < counter; i++)
			{
				x1 = a + (double)i * height;
				x2 = a + ((double)i + 1) * height;
				next += std::log(2.1 + sin(2 * x)) + std::log(2.1 + sin(2 * x)) / 2;
			}
			next *= height;
			if (fabs(next - present) <= 0.000001 && output == 1)
			{
				std::cout << "Accuracy 10^-5 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				output++;
			}
			else if (fabs(next - present) <= 0.0000001 && output == 2)
			{
				std::cout << "Accuracy 10^-6 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				output++;
			}
			else if (fabs(next - present) <= 0.00000001 && output == 3)
			{
				std::cout << "Accuracy 10^-7 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				break;
			}
			else
			{
				present = next;
			}
		}
	}
}

void fifthTask(double start)
{
	int a = 0;
	int b = 2;
	int i = 0;
	int counter = 0;
	int output = 1;
	double x = 0;
	double x1 = 0;
	double x2 = 0;
	double x3 = 0;
	double present = 0;
	double next = 0;
	double height = 0;
	while (true)
	{
		if (!counter)
		{
			counter = 1;
			height = ((double)b - a) / counter;
#pragma omp parallel private(i, x1, x2, x3) num_threads(4)
#pragma omp for reduction(+:present)
			for (i = 0; i < counter; i++)
			{
				x1 = a + (double)i * height;
				x2 = a + ((double)i + 1) * height;
				x3 = (x1 + x2) / 2;
				present += std::log(2.1 + sin(2 * x)) + std::log(2.1 + sin(2 * x)) + 4 * std::log(2.1 + sin(2 * x));
			}
			present *= height;
		}
		else
		{
			counter *= 2;
			next = 0;
			height = ((double)b - a) / counter;
#pragma omp parallel private(i, x, x1, x2, x3) num_threads(4)
#pragma omp parallel reduction(+:next)
			for (i = 0; i < counter; i++)
			{
				x1 = a + (double)i * height;
				x2 = a + ((double)i + 1) * height;
				x3 = (x1 + x2) / 2;
				next += std::log(2.1 + sin(2 * x)) + std::log(2.1 + sin(2 * x)) + 4 * std::log(2.1 + sin(2 * x));
			}
			next *= height / 6;
			if (fabs(next - present) <= 0.000001 && output == 1)
			{
				std::cout << "Accuracy 10^-5 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				output++;
			}
			else if (fabs(next - present) <= 0.0000001 && output == 2)
			{
				std::cout << "Accuracy 10^-6 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				output++;
			}
			else if (fabs(next - present) <= 0.00000001 && output == 3)
			{
				std::cout << "Accuracy 10^-7 signs" << std::endl;
				std::cout << "Total number of iter: " << counter << std::endl;
				std::cout << "Value calculation time: " << (omp_get_wtime() - start) << "sec" << std::endl;
				break;
			}
			else
			{
				present = next;
			}
		}
	}
}

int main()
{
	fifthTask(omp_get_wtime());
	return 0;
}
