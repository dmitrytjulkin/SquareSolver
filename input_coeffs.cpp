#include <stdio.h>
#include <assert.h>
#include <math.h>

#include "solve.h"

UsersDesire InputCoefficients (CoefficientsData* coefficients)
{
    assert (isfinite (coefficients->a));
    assert (isfinite (coefficients->b));
    assert (isfinite (coefficients->c));

    printf("Please, enter the coefficients a, b, c:\n");

    if (scanf ("%lg", &(coefficients->a)) == 1 && scanf ("%lg", &(coefficients->b)) == 1 && scanf ("%lg", &(coefficients->c)) == 1 && getchar() == '\n') {

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

void CleanTheBuffer ()
{
    while(getchar() != '\n');
}
