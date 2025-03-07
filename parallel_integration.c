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
        // Reduction for sum
        #pragma omp for schedule(static) reduction(+:sum)
        for (int i = 0; i < N; i++) {
            double x1 = A + i * dx;
            double x2 = A + (i + 1) * dx;
            sum += (f(x1) + f(x2)) / 2.0 * dx;
        }
          // Run Dynamic Scheduling if selected
          if (schedule_type == 2) {
            #pragma omp for schedule(dynamic) reduction(+:sum)
            for (int i = 0; i < N; i++) {
                double x1 = A + i * dx;
                double x2 = A + (i + 1) * dx;
                sum += (f(x1) + f(x2)) / 2.0 * dx;
            }
        }
    }

    return sum;
}