#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>

#include "solve.h"
// #include "test.h"

// this program solves the quadratic equation
// TODO double accuracy
// TODO Add Structures
// TODO make UnitTest for 0 and inf roots
// TODO divide by files

int main ()
{
    printf("You are solving the quadratic equation ax^2 + bx + c = 0.\n");

    double a = 0, b = 0, c = 0;
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

            PrintCase(numOfRoots, x1, x2);
        }
    }

    // RunAllTests();

    printf("COMMIT GITHUB!\n");
    return 0;
}
