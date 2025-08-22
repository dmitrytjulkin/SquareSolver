#include <stdio.h>
#include <math.h>
/*this program solve quadratic equation*/
int SolveQuadraticEquation(float, float, float, float*, float*);
void ChooseCase(int, float, float);

const int INF = -1;

int main ()
{
    printf("You are solving the quadratic equation ax2 + bx + c = 0.\n");
    printf("Please, enter the coefficients\n");
    float a = 0, b, c;  /*coefficients*/
    float x1, x2;   /*roots*/
    a = b = c = x1 = x2 = 0;
    scanf("%f %f %f", &a, &b, &c);
    int NumOfRoots;
    NumOfRoots = SolveQuadraticEquation(a, b, c, &x1, &x2);
    ChooseCase(NumOfRoots, x1, x2);
    return 0;
}

int SolveQuadraticEquation(float a, float b, float c, float *x1, float *x2)
{
    int NumOfRoots;
    if (a == 0){    /*linear equation*/
        if (b == 0){
            if (c == 0)
                NumOfRoots = INF;    /*infinite roots*/
            else
                NumOfRoots = 0;
        } else {    /*b != 0*/
            *x1 = *x2 = -c / b;
            NumOfRoots = 1;
        }
    } else {    /*a != 0*/
        int d = b*b - 4*a*c;    /*discriminant*/
        if (d < 0)
            NumOfRoots = 0;
        else if (d == 0) {
            NumOfRoots = 1;
            *x1 = *x2 = -b / (2*a);
        } else {
            NumOfRoots = 2;
            *x1 = (-b - sqrt(d)) / (2*a);
            *x2 = (-b + sqrt(d)) / (2*a);
        }
    }
    return NumOfRoots;
}

void ChooseCase(int NumOfRoots, float x1, float x2){
    // switch
    if (NumOfRoots == INF)
        printf("This equation has infinite roots\n");
    else if (NumOfRoots == 0)
        printf("This equation has no roots\n");
    else if (NumOfRoots == 1)
        printf("This equation has one root: x = %.6f", x1);
    else
        printf("Tis equation has two roots: x1 = %.6f, x2 = %.6f", x1, x2);
}
