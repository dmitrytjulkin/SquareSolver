#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>

#include "solve.h"

// static
RootsNumber SolveQuadraticEquation (CoefficientsData coefficients, RootsData* roots);
RootsNumber SolveLinearEquation (double b, double c, RootsData* roots);
bool IsZero (double a);
void AbsIfZero(double* x);
void AssertRootsNaN(double x1, double x2);

RootsNumber SolveEquation (CoefficientsData coefficients, RootsData* roots)
{
// assert
    assert (isfinite (coefficients.a));
    assert (isfinite (coefficients.b));
    assert (isfinite (coefficients.c));

    AssertRootsNaN (roots->x1, roots->x2);

    RootsNumber numOfRoots = NO_ROOTS;

    if (IsZero(coefficients.a)) {

        numOfRoots = SolveLinearEquation(coefficients.b, coefficients.c, roots);

    } else {

        numOfRoots = SolveQuadraticEquation(coefficients, roots);

    }

    return numOfRoots;
}

RootsNumber SolveLinearEquation (double b, double c, RootsData* roots)
{
    assert (isfinite (b));
    assert (isfinite (c));

    AssertRootsNaN (roots->x1, roots->x2);

    RootsNumber numOfRoots = NO_ROOTS;

    if (IsZero(b)) {

        if (IsZero(c))

            numOfRoots = INF_ROOTS;
            // return INF_ROOTS;

        else {

            roots->x1 = NOT_A_ROOT;
            roots->x2 = NOT_A_ROOT;
            numOfRoots = NO_ROOTS;

        }
    } else {

        roots->x1 = roots->x2 = -c / b;

        numOfRoots = ONE_ROOT;
    }

    return numOfRoots;
}

RootsNumber SolveQuadraticEquation (CoefficientsData coefficients, RootsData* roots)
{
    assert (isfinite (coefficients.a));
    assert (isfinite (coefficients.b));
    assert (isfinite (coefficients.c));

    AssertRootsNaN (roots->x1, roots->x2);

    RootsNumber numOfRoots = NO_ROOTS;
    double discriminant = coefficients.b * coefficients.b - 4 * coefficients.a * coefficients.c;

    if (discriminant < 0){

        roots->x1 = NOT_A_ROOT;
        roots->x2 = NOT_A_ROOT;
        numOfRoots = NO_ROOTS;

    }
    else if (IsZero(discriminant)) {

        numOfRoots = ONE_ROOT;

        roots->x1 = roots->x2 = - coefficients.b / (2 * coefficients.a);

    } else {

        numOfRoots = TWO_ROOT;

        roots->x1 = (-coefficients.b - sqrt(discriminant)) / (2 * coefficients.a);
        roots->x2 = (-coefficients.b + sqrt(discriminant)) / (2 * coefficients.a);
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
// 0
    if (IsZero(*x))

        *x = fabs(*x);
}

void AssertRootsNaN(double x1, double x2)
{
    assert (x1 != NAN);
    assert (x2 != NAN);
}
