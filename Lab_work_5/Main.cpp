#include <iostream>
#include <omp.h>
#include <iomanip>

void firstTask()
{
    srand(time(NULL));
    const int n = 100;
    int i, a[n], b[n], c[n];
    double timeStart, timeEnd;
    for (int j = 0; j < n; j++)
    {
        a[j] = rand();
        b[j] = rand();
    }
#pragma omp parallel sections num_threads(2)
    {
#pragma omp section
        {
            timeStart = omp_get_wtime();
            for (i = 0; i < n / 2; i++)
            {
                c[i] = a[i] + b[i];
            }
        }
#pragma omp section
        {
            for (i = n / 2; i < n; i++)
            {
                c[i] = a[i] + b[i];
            }
            timeEnd = omp_get_wtime();
        }
    }
    std::cout << "Vector A:" << std::endl;
    for (int j = 0; j < n; j++)
    {
        std::cout << " " << a[j] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Vector B:" << std::endl;
    for (int j = 0; j < n; j++)
    {
        std::cout << " " << b[j] << " ";
    }
    std::cout << std::endl << std::endl;

    std::cout << "Vector C (sum result):" << std::endl;
    for (int j = 0; j < n; j++)
    {
        std::cout << " " << c[j] << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Parallel mode. Time: " << std::fixed << std::setprecision(6) << timeEnd - timeStart << " seconds" << std::endl;
}

void merge(int array[], int l, int m, int n) {
    int i, j, k;
    int nFirst = m - l + 1;
    int nSecond = n - m;
    int* left = new int[nFirst];
    int* right = new int[nSecond];
    for (i = 0; i < nFirst; i++)
        left[i] = array[l + i];
    for (j = 0; j < nSecond; j++)
        right[j] = array[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < nFirst && j < nSecond)
    {
        if (left[i] <= right[j])
        {
            array[k] = left[i];
            i++;
        }
        else
        {
            array[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < nFirst)
    {
        array[k] = left[i];
        i++;
        k++;
    }
    while (j < nSecond)
    {
        array[k] = right[j];
        j++;
        k++;
    }
    delete[] left;
    delete[] right;
}

void mergeSort(int array[], int i, int j) {
    if (i < j)
    {
        int k = i + (j - i) / 2;
#pragma omp sections
        {
#pragma omp section
            mergeSort(array, i, k);
#pragma omp section
            mergeSort(array, k + 1, j);
        }
        merge(array, i, k, j);
    }
}

void secondTask()
{
    srand(time(NULL));
    int n;
    double timeStart, timeEnd;
    std::cout << "Enter array size: ";
    std::cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
    }
    std::cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;
    timeStart = omp_get_wtime();
    mergeSort(array, 0, n - 1);
    timeEnd = omp_get_wtime();
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Sequential execution time: " << timeEnd - timeStart << " seconds" << std::endl;
    omp_set_nested(0);
    timeStart = omp_get_wtime();
    mergeSort(array, 0, n - 1);
    timeEnd = omp_get_wtime();
    std::cout << "Parallel execution time with nested parallelism disabled: " << timeEnd - timeStart << " seconds" << std::endl;
    omp_set_nested(1);
    timeStart = omp_get_wtime();
    mergeSort(array, 0, n - 1);
    timeEnd = omp_get_wtime();
    std::cout << "Parallel execution time with nested parallelism enabled: " << timeEnd - timeStart << " seconds" << std::endl;
    delete[] array;
}

int partition(int array[], int low, int high) {
    int arrayHigh = array[high];
    int i = (low - 1);
    for (int j = low; j < high; j++)
    {
        if (array[j] <= arrayHigh)
        {
            i++;
            std::swap(array[i], array[j]);
        }
    }
    std::swap(array[i + 1], array[high]);
    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high)
    {
        int i;
#pragma omp sections
        {
#pragma omp section
            {
                i = partition(array, low, high);
                quickSort(array, low, i - 1);
            }
#pragma omp section
            {
                quickSort(array, i + 1, high);
            }
        }
    }
}

void thirdTask()
{
    srand(time(NULL));
    int n;
    double timeStart, timeEnd;
    std::cout << "Enter array size: ";
    std::cin >> n;
    int* array = new int[n];
    for (int i = 0; i < n; i++)
    {
        array[i] = rand() % 100;
    }
    std::cout << "Unsorted array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;
    timeStart = omp_get_wtime();
    quickSort(array, 0, n - 1);
    timeEnd = omp_get_wtime();
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl << std::endl;
    std::cout << "Sequential execution time: " << timeEnd - timeStart << " second" << std::endl;
    omp_set_nested(0);
    timeStart = omp_get_wtime();
    quickSort(array, 0, n - 1);
    timeEnd = omp_get_wtime();
    std::cout << "Parallel execution time with nested parallelism prohibited: " << timeEnd - timeStart << " second" << std::endl;
    omp_set_nested(1);
    timeStart = omp_get_wtime();
    quickSort(array, 0, n - 1);
    timeEnd = omp_get_wtime();
    std::cout << "Parallel execution time with nested parallelism enabled: " << timeEnd - timeStart << " seconds" << std::endl;
    delete[] array;
}

int main() 
{
    thirdTask();
    return 0;
}