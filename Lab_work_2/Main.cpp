#include <iostream>
#include <omp.h>

void firstTask()
{
    double numFirst;
    double numSecond;
    double result;
    double startTime;
    double endTime;
    std::cout << "Enter two real numbers: ";
    std::cin >> numFirst >> numSecond;
    startTime = omp_get_wtime();
    for (int i = 0; i < 1000000000; i++)
    {
        result = numFirst * numSecond;
    }
    endTime = omp_get_wtime();
    std::cout << "Single-threaded computing: " << endTime - startTime << " seconds" << std::endl;
    startTime = omp_get_wtime();
#pragma omp parallel num_threads(2)
    {
#pragma omp for
        for (int i = 0; i < 1000000000; i++)
        {
            result = numFirst * numSecond;
        }
    }
    endTime = omp_get_wtime();
    std::cout << "Parallel computing: " << endTime - startTime << " seconds" << std::endl;
}

void secondTask()
{
    double startTime;
    double endTime;
    startTime = omp_get_wtime();
#pragma omp parallel
    {
        //
    }
    endTime = omp_get_wtime();
    std::cout << endTime - startTime << std::endl;
}

void thirdTask()
{
    int threadNum;
    omp_set_num_threads(3);
#pragma omp parallel
    {
        threadNum = omp_get_thread_num();
#pragma omp single nowait
        {
            std::cout << "Start: " << threadNum + 1 << std::endl;
        }
#pragma omp single nowait
        {
            std::cout << "One thread: " << threadNum + 1 << std::endl;
        }
#pragma omp single nowait
        {
            std::cout << "End: " << threadNum + 1 << std::endl;
        }
    }
    std::cout << std::endl;
#pragma omp parallel
    {
        threadNum = omp_get_thread_num();
#pragma omp single nowait
        {
            std::cout << "Start: " << threadNum + 1 << std::endl;
        }
#pragma omp single nowait
        {
            std::cout << "One thread: " << threadNum + 1 << std::endl;
        }
#pragma omp single nowait
        {
            std::cout << "End: " << threadNum + 1 << std::endl;
        }
#pragma omp barrier
    }
}

void fourthTask()
{
    int threadNum;
    omp_set_num_threads(3);
#pragma omp parallel private(threadNum)
    {
        threadNum = omp_get_thread_num();
        std::cout << "Start: " << threadNum + 1 << std::endl;
#pragma omp barrier
#pragma omp master
        {
            std::cout << "Main: " << threadNum + 1 << std::endl;
            std::cout << "Main: " << threadNum + 1 << std::endl;
        }
#pragma omp barrier
        {
            std::cout << "Middle: " << threadNum + 1 << std::endl;
        }
#pragma omp barrier
#pragma omp master
        {
            std::cout << "Main: " << threadNum + 1 << std::endl;
            std::cout << "Main: " << threadNum + 1 << std::endl;
        }
#pragma omp for
        for (int i = 0; i < 3; i++)
        {
            std::cout << "End: " << threadNum + 1 << std::endl;
        }
    }
}

void fifthTask()
{
    int n = 10;
    std::cout << "N: " << n << std::endl;
#pragma omp parallel num_threads(2) private(n)
    {
        int threadNum = omp_get_thread_num();
        std::cout << "Thread: " << threadNum + 1 << " - " << n << std::endl;
        n = threadNum;
        std::cout << "Thread after: " << threadNum + 1 << " - " << n << std::endl;
    }
    std::cout << "Thread end: " << n << std::endl;
}

void sixthTask()
{
    int m[5] = { 0 };
    for (int i = 0; i < 5; i++)
    {
        std::cout << m[i] << " ";
    }
    std::cout << std::endl;
#pragma omp parallel num_threads(2) shared(m)
    {
        int threadNum = omp_get_thread_num();
        m[threadNum] = 1;
    }
    for (int i = 0; i < 5; i++)
    {
        std::cout << m[i] << " ";
    }
    std::cout << std::endl;
}

void seventhTask()
{
    int totalThreads = 0;
#pragma omp parallel reduction(+:totalThreads)
    {
        totalThreads += 1;
        int threadNum = omp_get_thread_num();
        std::cout << "Parallel area: " << threadNum << " - " << totalThreads << std::endl;
    }
    std::cout << "Sequential area: " << totalThreads << std::endl;
}

void eighthTask()
{
    int sum = 0;
#pragma omp parallel reduction(+:sum)
    {
        int threadNum = omp_get_thread_num();
        sum += threadNum;
        std::cout << "Thread: " << threadNum << ", sum: " << sum << std::endl;
    }
    std::cout << "Sum end: " << sum << std::endl;
}

int main()
{
	eighthTask();
	return 0;
}