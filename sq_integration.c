#include <stdio.h>
#include <math.h>
#include <time.h>

#define N 100000000  // Number of intervals (large for performance analysis)
#define A 0.0        // Lower bound
#define B 1.0        // Upper bound

// Function to integrate (Example: f(x) = x^2)
double f(double x) {
    return x * x;
}

// Trapezoidal Rule (Sequential)
double integrate_trapezoidal() {
    double sum = 0.0;
    double dx = (B - A) / N;

    for (int i = 0; i < N; i++) {
        double x1 = A + i * dx;
        double x2 = A + (i + 1) * dx;
        sum += (f(x1) + f(x2)) / 2.0 * dx;
    }
    return sum;
}
