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
