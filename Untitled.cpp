#include <stdio.h>
#include <string.h>
#include <float.h>
#include <math.h>

int FinishProgram();

int main() {
    float a = 10, b = 5;
    float diff = fabs(a - b);
    a = fabs(a);
    b = fabs(b);
    float largest = (b > a) ? b : a;
    if(diff <= largest * FLT_EPSILON)
        printf("kaif\n");
    else
        printf("nekaif((\n");
}

