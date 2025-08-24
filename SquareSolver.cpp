#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>
// #include "Test4SquareSolver.cpp"

// this program solves the quadratic equation

enum RootsNumber
{
    NO_ROOTS = 0,
    INF_ROOTS = -1,
    ONE_ROOT = 1,
    TWO_ROOT = 2
};

enum UsersDesire
{
    WANT_TO_FINISH = 1,
    WANT_TO_CORRECT = 0,
    WANT_TO_SOLVE = 2
};

const int FIN = 1;
const int CONTIN = 0;

void Solve();
UsersDesire InputCoefficients (double* a, double* b, double* c);
RootsNumber SolveEquation (double a, double b, double c, double* x1, double* x2);
RootsNumber SolveQuadraticEquation (double a, double b, double c, double* x1, double* x2);
RootsNumber SolveLinearEquation (double b, double c, double* x1, double* x2);
int FinishProgram ();
void RunTest();
int TestMyProgram(double a, double b, double c, double x1Ref, double x2Ref, int numOfRootsRef);
void ChooseCase (RootsNumber numOfRoots, double x1, double x2);
void CleanTheBuffer ();
bool CheckDoubleEquality (double a, double b);
bool IsZero (double a);

int main ()
{
    printf("You are solving the quadratic equation ax2 + bx + c = 0.\n");

     Solve();

    // RunTest();

    return 0;
}

void Solve()
{
    double a = 0, b = 0, c = 0;  //coefficients
    double x1 = 0, x2 = 0;   //roots

    while (true) {
        int usersWish = InputCoefficients(&a, &b, &c);

        if (usersWish == WANT_TO_FINISH) {

            printf("You've finished the program.\n");

            break;

        } else if (usersWish == WANT_TO_CORRECT)

            continue;

        else {

            RootsNumber numOfRoots = SolveEquation(a, b, c, &x1, &x2);

            ChooseCase(numOfRoots, x1, x2);
        }
    }
}

UsersDesire InputCoefficients (double* a, double* b, double* c)
{
    printf("Please, enter the coefficients a, b, c:\n");

    if (scanf ("%lg", a) == 1 && scanf ("%lg", b) == 1 && scanf ("%lg", c) == 1 && getchar() == '\n') {

        return WANT_TO_SOLVE;
    }
    //in case if user made a mistake

    printf("Incorrect input, try again:\n"
            "Do you want to finish?\n"
            "Input 1 to end the program or 0 to continue.\n");

    CleanTheBuffer();

    if (FinishProgram() == WANT_TO_FINISH)

        return WANT_TO_FINISH;

    return WANT_TO_CORRECT;
}

int FinishProgram ()
{
    int usersAnswer = CONTIN;

    while (true) {
        if  (scanf ("%d", &usersAnswer) == 1 &&
            (usersAnswer == CONTIN || usersAnswer == FIN) &&
            getchar() == '\n')

            return usersAnswer;

        CleanTheBuffer();

        printf("Incorrect input, try again.\n"
               "Do you want to finish?\n"
               "(input 1 if you want to End the program and 0 if you want to continue)\n");
    }

}

RootsNumber SolveEquation (double a, double b, double c, double* x1, double* x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);

    RootsNumber numOfRoots = NO_ROOTS;

    if (IsZero(a)) {

        numOfRoots = SolveLinearEquation(b, c, &*x1, &*x2);  //how can i improve?

    } else {

        numOfRoots = SolveQuadraticEquation(a, b, c, &*x1, &*x2);

    }

    return numOfRoots;
}

RootsNumber SolveLinearEquation (double b, double c, double* x1, double* x2)
{
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);

    RootsNumber numOfRoots = NO_ROOTS;

    if (IsZero(b)) {

        if (IsZero(c))

            numOfRoots = INF_ROOTS;

        else

            numOfRoots = NO_ROOTS;

    } else {

        *x1 = *x2 = -c / b;

        numOfRoots = ONE_ROOT;
    }

    return numOfRoots;
}

RootsNumber SolveQuadraticEquation (double a, double b, double c, double* x1, double* x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);

    RootsNumber numOfRoots = NO_ROOTS;
    double discriminant = b * b - 4 * a * c;

    if (discriminant < 0)

        numOfRoots = NO_ROOTS;

    else if (IsZero(discriminant)) {

        numOfRoots = ONE_ROOT;

        *x1 = *x2 = - b / (2 * a);

    } else {

        numOfRoots = TWO_ROOT;

        *x1 = (-b - sqrt(discriminant)) / (2 * a);
        *x2 = (-b + sqrt(discriminant)) / (2 * a);
    }

    return numOfRoots;
}

void ChooseCase (RootsNumber numOfRoots, double x1, double x2) {
    if (numOfRoots == INF_ROOTS)

        printf("This equation has infinite roots.\n");

    else if (numOfRoots == NO_ROOTS)

        printf("This equation has no roots.\n");

    else if (numOfRoots == ONE_ROOT)

        printf("This equation has one root: x = %.6lg.\n", x1);

    else

        printf("This equation has two roots: x1 = %.6lg, x2 = %.6lg.\n", x1, x2);
}

bool CheckDoubleEquality (double a, double b)
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

bool IsZero (double a)
{
    if (CheckDoubleEquality (a, 0))

        return true;

    else

        return false;
}

void CleanTheBuffer ()
{
    while(getchar() != '\n');
}

// void RunTest()
// {
//     int passed = 0;
//     passed += TestMyProgram(1, 2, 1, -1, -1, 1);
//     printf("There are %d out of 1 passed tests", passed);
// }
//
// int TestMyProgram(double a, double b, double c, double x1Ref, double x2Ref, int numOfRootsRef)
// {
//     double x1 = 0, x2 = 0;
//     int numOfRoots = SolveEquation(a, b, c, &x1, &x2);
//
//     if(!(CheckDoubleEquality(x1, x1Ref) && CheckDoubleEquality(x2, x2Ref) && numOfRoots == numOfRootsRef)) {
//
//         printf ("FALED: input: (a, b, c) = (%lf, %lf, %lf),\n"
//                 "output: (x1, x2, numOfRoots) = (%lf, %lf, %d),\n"
//                 "expected: (x1, x2, numOfRoots) = (%lf, %lf, %d)\n",
//
//                 a, b, c, x1, x2, numOfRoots, x1Ref, x2Ref, numOfRootsRef);
//
//         return 0;
//     }
//     return 1;
// }
