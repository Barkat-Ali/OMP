# OMP_Integration
This project implements **Numerical Integration** using **OpenMP** for parallelization.

## Features
- Sequential implementation
- Parallel implementation with OpenMP
- Performance evaluation using different thread counts
- Comparison of execution time using graphs

Compile and run:

# Sequential version
gcc -o integrate_seq integrate_seq.c -lm
./integrate_seq

# Parallel version
gcc -fopenmp -o integrate_parallel integrate_parallel.c -lm
./integrate_parallel
