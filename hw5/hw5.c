#include <stdio.h>
#include <immintrin.h>

typedef struct {
    double real;
    double img;
} complex_num;


void multiply(complex_num x, complex_num y, complex_num *z)
{
    __m128d num1, num2, num3, num4;
    // Copies a single element into the vector
    //   num1:  [x.real, x.real]
    num1 = _mm_load1_pd(&x.real);
    // Move y elements into a vector
    //   num2: [y.img, y.real]
    num2 = _mm_set_pd(y.img, y.real);
    // Multiplies vector elements
    //   num3: [(x.real*y.img), (x.real*y.real)]
    num3 = _mm_mul_pd(num2, num1);
    //   num1: [x.img, x.img]
    num1 = _mm_load1_pd(&x.img);
    // Swaps the vector elements.
    //   num2: [y.real, y.img]
    num2 = _mm_shuffle_pd(num2, num2, 1);
    //   num2: [(x.img*y.real), (x.img*y.img)]
    num2 = _mm_mul_pd(num2, num1);
    num4 = _mm_add_pd(num3, num2);
    num3 = _mm_sub_pd(num3, num2);
    //   Constructs a 128-bit floating-point vector of [2 x double] 
    //   from two 128-bit vector parameters of [2 x double], using the immediate-value parameter as a specifier.
    num4 = _mm_shuffle_pd(num3, num4, 2);
    // Stores the elements of num4 into z
    _mm_storeu_pd((double *)z, num4);
}

int main()
{
    complex_num a, b, c;
    // Initialize complex numbers
    a.real =  3;
    a.img  =  2;
    b.real =  5;
    b.img  = -4;
    multiply(a, b, &c);
    printf("Complex Product(SSE2): %2.2f+ %2.2fi\n", c.real, c.img);
    return 0;
}