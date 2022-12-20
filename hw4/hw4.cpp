#include <omp.h>
#include <iostream>

int main( )
{
    // the number of threads to be used
    omp_set_num_threads(4);
    // returns a nonzero value if called from within a parallel region.
    std::cout << omp_in_parallel() << std::endl;

    #pragma omp parallel
        #pragma omp master
        {
            std::cout << omp_in_parallel() << std::endl;
        }
}
