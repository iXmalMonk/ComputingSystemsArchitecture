#include <iostream>
#include <omp.h>
#include <immintrin.h>

void firstTask()
{
    double a[4] = { 100.0, 200.0, 300.0, 400.0 };
    double b[4] = { 4.4, 3.3, 2.2, 1.1 };
    double c[4];
    double time;
    time = omp_get_wtime();
    for (int i = 0; i < 1000000; i++)
    {
        c[0] = a[0] * b[0];
        c[1] = a[1] * b[1];
        c[2] = a[2] * b[2];
        c[3] = a[3] * b[3];
    }
    time = omp_get_wtime() - time;
    std::cout << "Type double without SSE: " << time << "seconds" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "[" << i << "] = " << c[i] << std::endl;
    }
    std::cout << std::endl;
    time = omp_get_wtime();
    for (int i = 0; i < 1000000; i++)
    {
        __asm
        {
            movupd xmm0, a
            movupd xmm1, b
            mulpd xmm0, xmm1
            movupd c, xmm0
        }
    }
    time = omp_get_wtime() - time;
    std::cout << "Type double with SSE: " << time << "seconds" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << "[" << i << "] = " << c[i] << std::endl;
    }
}

void secondTask()
{
    char a[16] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150, 160 };
    char b[16] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16 };
    char c[16];
    double time;
    time = omp_get_wtime();
    for (int i = 0; i < 1000000; i++)
    {
        c[0] = a[0] * b[0];
        c[1] = a[1] * b[1];
        c[2] = a[2] * b[2];
        c[3] = a[3] * b[3];
        c[4] = a[4] * b[4];
        c[5] = a[5] * b[5];
        c[6] = a[6] * b[6];
        c[7] = a[7] * b[7];
        c[8] = a[8] * b[8];
        c[9] = a[9] * b[9];
        c[10] = a[10] * b[10];
        c[11] = a[11] * b[11];
        c[12] = a[12] * b[12];
        c[13] = a[13] * b[13];
        c[14] = a[14] * b[14];
        c[15] = a[15] * b[15];
    }
    time = omp_get_wtime() - time;
    std::cout << "Type char without SSE: " << time << "seconds" << std::endl;
    for (int i = 0; i < 16; i++)
    {
        std::cout << "[" << i << "] = " << static_cast<int>(c[i]) << std::endl;
    }
    std::cout << std::endl;
    time = omp_get_wtime();
    for (int i = 0; i < 1000000; i++)
    {
        __m128i xmm_a = _mm_load_si128((__m128i*)a);
        __m128i xmm_b = _mm_load_si128((__m128i*)b);
        __m128i xmm_c = _mm_mullo_epi16(xmm_a, xmm_b);
        _mm_store_si128((__m128i*)c, xmm_c);
    }
    time = omp_get_wtime() - time;
    std::cout << "Type char with SSE: " << time << "seconds" << std::endl;
    for (int i = 0; i < 16; i++)
    {
        std::cout << "[" << i << "] = " << static_cast<int>(c[i]) << std::endl;
    }
}

int main()
{
    secondTask();
    return 0;
}
