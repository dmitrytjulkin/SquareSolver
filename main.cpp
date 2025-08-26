#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>

#include "solve.h"

// this program solves the quadratic equation
// TODO double accuracy
// TODO make UnitTest for 0 and inf roots

int main ()
{
    printf("You are solving the quadratic equation ax^2 + bx + c = 0.\n");
    CoefficientsData coefficients = {.a = 0, .b = 0, .c = 0};
    RootsData roots = {.x1 = 0, .x2 = 0};

    while (true) {
        int usersWish = InputCoefficients(&coefficients);

        if (usersWish == WANT_TO_FINISH) {

            printf("You've finished the program.\n");

            break;

        } else if (usersWish == WANT_TO_CORRECT)

            continue;

        else {

            RootsNumber numOfRoots = SolveEquation(coefficients, &roots);

            PrintCase(numOfRoots, roots);
        }
    }

    // RunAllTests();

    printf("COMMIT GITHUB!\n");
    return 0;
}
