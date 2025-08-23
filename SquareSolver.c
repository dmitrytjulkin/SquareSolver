#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <string.h>

/*this program solve quadratic equation*/
int FinishProgram();
int SolveQuadraticEquation(double, double, double, double*, double*);
void ChooseCase(int, double, double);

const int INF = -1;

int main ()
{
    printf("You are solving the quadratic equation ax2 + bx + c = 0.\n");
    printf("Please, enter the coefficients a, b, c:\n");
    double a = 0, b = 0, c = 0;  /*coefficients*/
    double x1 = 0, x2 = 0;   /*roots*/
    int i = 1;
    while (i != 0){
        if (scanf ("%lf", &a) != 1 || scanf ("%lf", &b) != 1 || scanf ("%lf", &c) != 1){
            printf("Incorrect input, try again:\n");
            printf("Do you want to finish?\n YES/NO\n");
            while(getchar() != '\n');
            if (FinishProgram() == 1){
                printf("You've finished the program.\n");
                break;
            }
            continue;
        } else {
            int NumOfRoots = 0;
            NumOfRoots = SolveQuadraticEquation(a, b, c, &x1, &x2);
            ChooseCase(NumOfRoots, x1, x2);
        }
    }
    return 0;
}

int FinishProgram()
{
    char UsersAnswer[100] = " ";
    char ans1[] = "YES", ans2[] = "NO";
    int AnsMatches = 0;
    while (AnsMatches == 0){
        scanf("%s", UsersAnswer);
        if (strcmp(UsersAnswer, ans1) == 0)
            return 1;
        else if (strcmp(UsersAnswer, ans2) == 0){
            printf("Please, enter the coefficients a, b, c:\n");
            return 0;
        }
        printf("Incorrect input, try again:\n");
        while(getchar() != '\n');
    }
}

int SolveQuadraticEquation(double a, double b, double c, double *x1, double *x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);

    int NumOfRoots;
    if (a == 0){    /*linear equation*/
        if (b == 0){
            if (c == 0)
                NumOfRoots = INF;
            else
                NumOfRoots = 0;
        } else {    /*b != 0*/
            *x1 = *x2 = -c / b;
            NumOfRoots = 1;
        }
    } else {    /*a != 0*/
        int discriminant = b*b - 4*a*c;
        if (discriminant < 0)
            NumOfRoots = 0;
        else if (discriminant == 0) {
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

void ChooseCase(int NumOfRoots, double x1, double x2){
    if (NumOfRoots == INF)
        printf("This equation has infinite roots.\n");
    else if (NumOfRoots == 0)
        printf("This equation has no roots.\n");
    else if (NumOfRoots == 1)
        printf("This equation has one root: x = %.6lf.\n", x1);
    else
        printf("This equation has two roots: x1 = %.6lf, x2 = %.6lf.\n", x1, x2);
}
