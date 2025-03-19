#include <stdio.h>
#include <math.h>
#include <omp.h>

#define N 100000000  // Large number of intervals
#define A 0.0        // Lower limit
#define B 1.0        // Upper limit

// Function to integrate (Example: f(x) = x^2)
double f(double x) {
    return x * x;
}

// Parallel Trapezoidal Integration with OpenMP
double integrate_trapezoidal_parallel(int num_threads, int schedule_type) {
    double sum = 0.0;
    double dx = (B - A) / N;

    #pragma omp parallel num_threads(num_threads)
    {
        if (schedule_type == 1) {  
            // Static Scheduling
            #pragma omp for schedule(static,10000) reduction(+:sum)
            for (int i = 0; i < N; i++) {
                double x1 = A + i * dx;
                double x2 = A + (i + 1) * dx;
                sum += (f(x1) + f(x2)) / 2.0 * dx;
            }
        } else if (schedule_type == 2) {  
            // Dynamic Scheduling
            #pragma omp for schedule(dynamic, 10000) reduction(+:sum)
            for (int i = 0; i < N; i++) {
                double x1 = A + i * dx;
                double x2 = A + (i + 1) * dx;
                sum += (f(x1) + f(x2)) / 2.0 * dx;
            }
        }
    }
    return sum;
}

int main() {
    int threads[2] = {4, 8}; // Compare with 4 and 8 threads

    for (int t = 0; t < 2; t++) {
        int num_threads = threads[t];

        // Run with Static Scheduling
        double start_static = omp_get_wtime();
        double result_static = integrate_trapezoidal_parallel(num_threads, 1);
        double end_static = omp_get_wtime();

        // Run with Dynamic Scheduling
        double start_dynamic = omp_get_wtime();
        double result_dynamic = integrate_trapezoidal_parallel(num_threads, 2);
        double end_dynamic = omp_get_wtime();

        // Print results
        printf("\n===== Results with %d Threads =====\n", num_threads);
        printf("Static Scheduling - Result: %lf, Time: %f seconds\n", result_static, end_static - start_static);
        printf("Dynamic Scheduling - Result: %lf, Time: %f seconds\n", result_dynamic, end_dynamic - start_dynamic);

       
    }

    return 0;
}
