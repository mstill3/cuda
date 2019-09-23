#include <stdio.h>    // for printf
// #include <math.h>  // math lib already included 

#define N 64          // constant, array len
#define TPB 32        // constant, threads per block

// converts int to evenly spaced floats 
// ie) .1, .2, ..., .5, ..., .9
__device__ float scale(int i, int n)
{
    return ((float) i) / (n - 1);
}


// Computes distance between 2 points on a line
__device__ float distance(float x1, float x2)
{
    return sqrt((x2 - x1) * (x2 - x1));
}


__global__ void distanceKernal(float *d_out, float ref, int len)    
{
    const int i = blockIdx.x * blockDim.x + threadIdx.x;
    const float x = scale(i, len);
    d_out[i] = distance(x, ref);
    printf("i = %2d: dist from %f to %f is %f.\n", i, ref, x, d_out[i]);
}

// Auto run main method
int main()
{
    // reference point to be measured from
    const float ref = 0.5f;

    // declare pointeer to array of floats
    float *d_out;

    // allocate device memory tostore output array
    cudaMalloc(&d_out, N * sizeof(float));

    // launch kernal to copute and store distance values
    distanceKernal<<<N/TPB, TPB>>>(d_out, ref, N);    

    // free memory
    cudaFree(d_out);

    return 0;
}
