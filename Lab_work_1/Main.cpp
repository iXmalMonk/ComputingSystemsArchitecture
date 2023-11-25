#include <iostream>
#include <omp.h>

void firstTask()
{
    int threadNum;
    int numThread;
    omp_set_num_threads(4);
    std::cout << "Sequential area 1" << std::endl;
#pragma omp parallel private(threadNum, numThread)
    {
        threadNum = omp_get_thread_num();
        numThread = omp_get_num_threads();
        std::cout << "Parallel region" << std::endl;
    }
    std::cout << "Sequential area 2" << std::endl;
}

void secondTask()
{
    int numThreads;
    int threadNum;
#pragma omp parallel
    {
        threadNum = omp_get_thread_num();
#pragma omp master
        {
            numThreads = omp_get_num_threads();
            std::cout << "Total number of threads: " << numThreads << std::endl;
        }
        std::cout << "Thread number: " << threadNum << std::endl;
    }
}

void thirdTask()
{
#pragma omp parallel
    {
#pragma omp critical
        {
            std::cout << "Parallel region 1" << std::endl;
        }
    }
#pragma omp parallel num_threads(3)
    {
#pragma omp critical
        {
            std::cout << "Parallel region 2" << std::endl;
        }
    }
    omp_set_num_threads(4);
#pragma omp parallel
    {
#pragma omp critical
        {
            std::cout << "Parallel region 3" << std::endl;
        }
    }
}

void fourthTask()
{
    int threadNum;
    int numThread;
    omp_set_num_threads(128);
    omp_set_dynamic(0);
#pragma omp parallel
    {
        threadNum = omp_get_thread_num();
        numThread = omp_get_num_threads();
        std::cout << threadNum << " / " << numThread << std::endl;
    }
}

void fifthTask(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " parallel | serial" << std::endl;
        return;
    }
    std::string mode = argv[1];
    if (mode == "parallel")
    {
#pragma omp parallel
        {
            std::cout << "Hello from thread " << omp_get_thread_num() << std::endl;
        }
    }
    else if (mode == "serial")
    {
        std::cout << "Hello from the serial mode" << std::endl;
    }
    else
    {
        std::cout << "Invalid mode: " << mode << std::endl;
        return;
    }
}

int main(int argc, char* argv[])
{
    firstTask();
    return 0;
}
