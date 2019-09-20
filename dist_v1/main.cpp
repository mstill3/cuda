#include <stdio.h> // for printf
#include <math.h>  // math lib
#define N 64       // constant, array len

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


// Auto run main method
int main()
{
    // create array on N floats each with value 0.0
    float out[N] = {0.0f};

    //reference point to be measured from
    float ref = 0.5f;

    for(int i = 0; i < N; i++)
    {
        float x = scale(i, N);
        out[i] = distance(x, ref);
        printf("%f\n", out[i]);
    }

    return 0;
}
