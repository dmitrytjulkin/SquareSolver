#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <float.h>

/*this program solves quadratic equation*/

int FinishProgram ();
int SolveQuadraticEquation (double, double, double, double*, double*);
void ChooseCase (int, double, double);
int DoubleComparison (double, double);
int InputCoefficients ();
void CleanTheBuffer ();

const int INF = -1;

int main ()
{
    printf("You are solving the quadratic equation ax2 + bx + c = 0.\n");
    printf("Please, enter the coefficients a, b, c:\n");
    InputCoefficients();
    printf("You've finished the program\n");
    return 0;
}

int InputCoefficients ()
{
    double a = 0, b = 0, c = 0;  /*coefficients*/
    double x1 = 0, x2 = 0;   /*roots*/
    int i = 1;
    while (i != 0){
        if (scanf ("%lf", &a) != 1 || scanf ("%lf", &b) != 1 || scanf ("%lf", &c) != 1){    /*in case if user made a mistake*/
            printf("Incorrect input, try again:\n");
            printf("Do you want to finish?\nYES/NO\n");
            if (FinishProgram() == 1)
                return 0;
            continue;
        } else {    /*if user input coefficients properly*/
            int NumOfRoots = 0;
            NumOfRoots = SolveQuadraticEquation(a, b, c, &x1, &x2);
            ChooseCase(NumOfRoots, x1, x2);
        }
    }
    return 0;
}

int FinishProgram ()
{
    char UsersAnswer[100] = " ";
    char ans1[] = "YES", ans2[] = "NO";
    int AnsMatches = 0;
    while (AnsMatches == 0){
        CleanTheBuffer();
        scanf("%s", UsersAnswer);
        if (strcmp(UsersAnswer, ans1) == 0)
            return 1;
        else if (strcmp(UsersAnswer, ans2) == 0){
            printf("Please, enter the coefficients a, b, c:\n");
            return 0;
        }
        printf("Incorrect input, try again.\n");
        printf("Do you want to finish?\n");
        printf("(only YES or NO answers)\n");
    }
    return 0;
}

int SolveQuadraticEquation (double a, double b, double c, double *x1, double *x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);

    int NumOfRoots;
    if (DoubleComparison (a, 0) == 1){    /*linear equation*/
        if (DoubleComparison (b, 0) == 1){
            if (DoubleComparison (c, 0) == 1)
                NumOfRoots = INF;
            else
                NumOfRoots = 0;
        } else {    /*b != 0*/
            *x1 = *x2 = -c / b;
            NumOfRoots = 1;
        }
    } else {    /*a != 0*/
        double discriminant = b*b - 4*a*c;
        if (discriminant < 0)
            NumOfRoots = 0;
        else if (DoubleComparison (discriminant, 0) == 1) {
            NumOfRoots = 1;
            *x1 = *x2 = -b / (2*a);
        } else {
            NumOfRoots = 2;
            *x1 = (-b - sqrt(discriminant)) / (2*a);
            *x2 = (-b + sqrt(discriminant)) / (2*a);
        }
    }
    return NumOfRoots;
}

void ChooseCase (int NumOfRoots, double x1, double x2){
    if (NumOfRoots == INF)
        printf("This equation has infinite roots.\n");
    else if (NumOfRoots == 0)
        printf("This equation has no roots.\n");
    else if (NumOfRoots == 1)
        printf("This equation has one root: x = %.6lf.\n", x1);
    else
        printf("This equation has two roots: x1 = %.6lf, x2 = %.6lf.\n", x1, x2);
}

int DoubleComparison (double a, double b)
{
    double diff = fabs(a - b);
    a = fabs(a);
    b = fabs(b);
    double largest = (b > a) ? b : a;
    if(diff <= largest * FLT_EPSILON)
        return 1;
    else
        return 0;
}

void CleanTheBuffer ()
{
    while(getchar() != '\n');
}
