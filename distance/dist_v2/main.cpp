#include "aux_functions.cpp"
#include <stdlib.h> // dynamic memory management

#define N 20000000  // constant, large array len

// Auto run main method
int main()
{
    float *in = (float*) calloc(N, sizeof(float));  //allocate N elements of size float and initialize to 0
    float *out = (float*) calloc(N, sizeof(float));
    const float ref = 0.5f;

    for(int i = 0; i < N; i++)
    {
        in[i] = scale(i, N);
    }

    distanceArray(out, in, ref, N);

    // Release the heap memory after we are done using it
    free(in);
    free(out);
    
    return 0;
}
