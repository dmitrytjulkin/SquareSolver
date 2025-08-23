#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>
#include <float.h>

// this program solves the quadratic equation


int InputCoefficients ();
int SolveEquation (double a, double b, double c, double* x1, double* x2);
int QuadraticEquation (double a, double b, double c, double* x1, double* x2);
int LinearEquation (double b, double c, double* x1, double* x2);
int FinishProgram ();
void ChooseCase (int NumOfRoots, double x1, double x2);
void CleanTheBuffer ();
bool DoubleComparison (double a, double b);

enum RootsNumber {
    NO_ROOTS = 0,
    INF = -1,
    ONE_ROOT = 1,
    TWO_ROOT = 2
};

int main ()
{
    printf("You are solving the quadratic equation ax2 + bx + c = 0.\n");
    printf("Please, enter the coefficients a, b, c:\n");

    InputCoefficients();

    // Solve(); // TODO: change InputCoefficients()

    // PrintAnswer();

    printf("You've finished the program.\n");

    return 0;
}

int InputCoefficients ()
{
    double a = 0, b = 0, c = 0;  //coefficients
    double x1 = 0, x2 = 0;   //roots

    while (true) {
        if (scanf ("%lf", &a) != 1 || scanf ("%lf", &b) != 1 || scanf ("%lf", &c) != 1 || getchar() != '\n') {
        //in case if user made a mistake

            printf("Incorrect input, try again:\n");
            printf("Do you want to finish?\nYES/NO\n");

            if (FinishProgram() == 1)
                return 0;

            continue;
        } else {    //if user input coefficients properly

            int NumOfRoots = 0;

            NumOfRoots = SolveEquation(a, b, c, &x1, &x2);

            ChooseCase(NumOfRoots, x1, x2);
        }
    }

    return 0;
}

int FinishProgram ()
{
    char UsersAnswer[4] = {};
    char ans1[] = "YES", ans2[] = "NO";
    int AnsMatches = 0;
    // TODO: codestyle
    while (AnsMatches == 0) {
        CleanTheBuffer();
        scanf("%3s", UsersAnswer);
        if (strcmp(UsersAnswer, ans1) == 0)
            return 1;
        else if (strcmp(UsersAnswer, ans2) == 0) {
            printf("Please, enter the coefficients a, b, c:\n");
            return 0;
        }
        printf("Incorrect input, try again.\n");
        printf("Do you want to finish?\n");
        printf("(only YES or NO answers)\n");
    }
    return 0;
}

int SolveEquation (double a, double b, double c, double *x1, double *x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);

    int NumOfRoots = 0;
    if (DoubleComparison (a, 0) == 1) {
        NumOfRoots = LinearEquation(b, c, &*x1, &*x2);  //can i improve?
    } else {
        NumOfRoots = QuadraticEquation(a, b, c, &*x1, &*x2);
    }
    return NumOfRoots;
}

int LinearEquation (double b, double c, double* x1, double* x2)
{
    int NumOfRoots = 0;
    if (DoubleComparison (b, 0) == 1) {
        if (DoubleComparison (c, 0) == 1)
            NumOfRoots = INF;
        else
            NumOfRoots = NO_ROOTS;
    } else {
        *x1 = *x2 = -c / b;
        NumOfRoots = ONE_ROOT;
    }
    return NumOfRoots;
}

int QuadraticEquation (double a, double b, double c, double *x1, double *x2)
{
    int NumOfRoots = 0;
    double discriminant = b*b - 4*a*c;
    if (discriminant < 0)
        NumOfRoots = NO_ROOTS;
    else if (DoubleComparison (discriminant, 0) == 1) {
        NumOfRoots = ONE_ROOT;
        *x1 = *x2 = -b / (2*a);
    } else {
        NumOfRoots = TWO_ROOT;
        *x1 = (-b - sqrt(discriminant)) / (2*a);
        *x2 = (-b + sqrt(discriminant)) / (2*a);
    }
    return NumOfRoots;
}

void ChooseCase (int NumOfRoots, double x1, double x2) {
    if (NumOfRoots == INF)
        printf("This equation has infinite roots.\n");
    else if (NumOfRoots == NO_ROOTS)
        printf("This equation has no roots.\n");
    else if (NumOfRoots == ONE_ROOT)
        printf("This equation has one root: x = %.6lf.\n", x1);
    else
        printf("This equation has two roots: x1 = %.6lf, x2 = %.6lf.\n", x1, x2);
}

bool DoubleComparison (double a, double b)
{
    double diff = fabs(a - b);
    a = fabs(a);
    b = fabs(b);
    double largest = (b > a) ? b : a;
    if(diff <= largest * FLT_EPSILON)
        return true;
    else
        return false;
}

void CleanTheBuffer ()
{
    while(getchar() != '\n');
}
