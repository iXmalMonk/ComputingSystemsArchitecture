#include <iostream>
#include <omp.h>
#include <intrin.h>

int main()
{
    char a8 = 100, b8 = a8, c8_ = a8 * b8;
    short c16 = a8 * b8;
    std::cout << "For short:" << std::endl;
    printf("%d * %d = %d = %d = %d\n\n", a8, b8, c8_, c16, a8 * b8);
    short a16 = 30000, b16 = a16, c16_ = a16 * b16;
    int c32 = a16 * b16;
    std::cout << "For int:" << std::endl;
    printf("%d * %d = %d = %d = %d\n\n", a16, b16, c16_, c32, a16 * b16);
    int a32 = 2000000000, b32 = a32, c32_ = a32 * b32;
    __int64 c64 = a32 * b32;
    __int64 c64_ = __int64(a32) * b32;
    std::cout << "For __int64:" << std::endl;
    printf("%d * %d = %d = %lld = %lld = %lld\n\n", a32, b32, c32_, c64, c64_, __int64(a32) * b32);
    __int64 a64 = 2000000000000000000, b64 = a64, c64__ = a64 * b64, oo = 0;
    __int64 AB1, AB0 = _mul128(a64, b64, &AB1);
    std::cout << "For unsigned __int64:" << std::endl;
    printf("%lld * %lld = %lld = %lld * 2^64 + %llu \n\n", a64, b64, c64__, AB1, (unsigned __int64)AB0);
    return 0;
}