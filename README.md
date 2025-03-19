# OMP_Integration
This project implements **Numerical Integration** using **OpenMP** for parallelization.

## Features
- Sequential implementation
- Parallel implementation with OpenMP
- Performance evaluation using different thread counts
- Comparison of execution time using graphs

Compile and run:

# Sequential version
gcc -o sq_integration sq_integration.c -lm
./sq_integration

# Parallel version
gcc -fopenmp -o parallel_integration parallel_integration.c -lm
./parallel_integration
