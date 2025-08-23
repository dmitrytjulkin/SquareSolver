#include <stdio.h>
#include <string.h>
#include <float.h>
#include <math.h>

bool DoubleComparison (double a, double b);

int main() {
    double a = 0, b = 0;
    if (DoubleComparison(a, b))
        printf("kaif");
    else
        printf("nekaif");
}

bool DoubleComparison (double a, double b)
{
    double diff = fabs(a - b);
    a = fabs(a);
    b = fabs(b);
    double largest = (b > a) ? b : a;
    if(diff <= largest * FLT_EPSILON)
        return true; // true
    else
        return false; // false
}
