#include "aux_functions.h"
#include <stdio.h>  // for printf
#include <math.h>  // for sqrt

// converts int to evenly spaced floats 
// ie) .1, .2, ..., .5, ..., .9
float scale(int i, int n)
{
    return ((float) i) / (n - 1);
}


// Computes distance between 2 points on a line
float distance(float x1, float x2)
{
    return sqrt((x2 - x1) * (x2 - x1));
}

// Loops thru each element of array and calculates distance
void distanceArray(float *out, float *in, float ref, int n)
{
    for(int i = 0; i < n; i++)
    {
        out[i] = distance(in[i], ref);
        // printf("%f\n", out[i]);
    }
}

