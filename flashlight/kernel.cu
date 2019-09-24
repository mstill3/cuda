#include "kernel.h"

#define TX 32          // constant, num threads per block along x axis
#define TY 32          // constant, num threads per block along y axis


// Returns val of element unless greater than 255 then just returns 255
__device__
unsigned char clip(int n) 
{ 
    return n > 255 ? 255 : (n < 0 ? 0 : n); 
}

__global__
void distanceKernel(uchar4 *d_out, int w, int h, int2 pos) 
{
    const int c = blockIdx.x*blockDim.x + threadIdx.x;
    const int r = blockIdx.y*blockDim.y + threadIdx.y;
    const int i = c + r * w;   // 1D indexing

    if ((c >= w) || (r >= h))
    { 
        return; // Check if within image bounds
    }

    // compute distance (in pixel spacings)
    const int dist = sqrtf((c - pos.x)*(c - pos.x) + 
                           (r - pos.y)*(r - pos.y));

    // convert distance to intensity value on interval (0, 255)
    const unsigned char intensity = clip(255 - dist);

    d_out[i].x = intensity;   // red channel 
    d_out[i].y = intensity;   // green channel 
    d_out[i].z = 0;           // blue channel 
    d_out[i].w = 255;         // fully opaque 
}

void kernelLauncher(uchar4 *d_out, int w, int h, int2 pos) 
{
    const dim3 blockSize(TX, TY);
    const dim3 gridSize = dim3((w + TX - 1)/TX, (h + TY - 1)/TY);
    distanceKernel<<<gridSize, blockSize>>>(d_out, w, h, pos);
}
