#include <iostream>
#include <omp.h>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: " << argv[0] << " parallel | serial" << std::endl;
        return 1;
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
        return 1;
    }

    return 0;
}
