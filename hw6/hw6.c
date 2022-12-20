#include <stdio.h>
#include "mpi.h"


int main(int argc, char **argv)
{
	int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); //rank of the processor, root = 0
    MPI_Comm_size(MPI_COMM_WORLD, &size); //number of processors
    if (size != 4) {
        MPI_Abort(MPI_COMM_WORLD, 1); //abort properly with error code '1' if not using 4 processes
    }
    printf("hello I am process: %d, size should only be 4: %d\n", rank, size);
    MPI_Finalize();
	return 0;
}