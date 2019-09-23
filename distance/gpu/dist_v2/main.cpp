#include "kernel.h"
#include <stdlib.h> // dynamic memory management

#define N 64        // constant, large array len


// converts int to evenly spaced floats 
// ie) .1, .2, ..., .5, ..., .9
float scale(int i, int n)
{
    return ((float) i) / (n - 1);
}

// Auto run main method
int main()
{
    const float ref = 0.5f;
    float *in = (float*) calloc(N, sizeof(float));  //allocate N elements of size float and initialize to 0
    float *out = (float*) calloc(N, sizeof(float));

    // compute scaled input vals
    for(int i = 0; i < N; i++)
    {
        in[i] = scale(i, N);
    }

    // compute distances for entire array
    distanceArray(out, in, ref, N);

    // Release the heap memory after we are done using it
    free(in);
    free(out);
    
    return 0;
}
