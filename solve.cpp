#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>

#include "solve.h"

RootsNumber SolveQuadraticEquation (double a, double b, double c, double* x1, double* x2);
RootsNumber SolveLinearEquation (double b, double c, double* x1, double* x2);
bool IsZero (double a);
void AbsIfZero(double* x);

RootsNumber SolveEquation (double a, double b, double c, double* x1, double* x2)
{
    assert (isfinite (a));
    assert (isfinite (b));
    assert (isfinite (c));

    assert (x1 != NULL);
    assert (x2 != NULL);

    RootsNumber numOfRoots = NO_ROOTS;

    if (IsZero(a)) {

        numOfRoots = SolveLinearEquation(b, c, x1, x2);

    } else {

        numOfRoots = SolveQuadraticEquation(a, b, c, x1, x2);

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

void AbsIfZero (double* x)
{
    if (IsZero(*x))

        *x = fabs(*x);
}
