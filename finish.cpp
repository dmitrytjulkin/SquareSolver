#include <stdio.h>

#include "solve.h"

const int FIN = 1;
const int CONTIN = 0;

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

void PrintCase (RootsNumber numOfRoots, double x1, double x2) {
    if (numOfRoots == INF_ROOTS)

        printf("This equation has infinite roots.\n");

    else if (numOfRoots == NO_ROOTS)

        printf("This equation has no roots.\n");

    else if (numOfRoots == ONE_ROOT) {

            AbsIfZero(&x1);

            printf("This equation has one root: x = %.6lg.\n", x1);

    } else {

        AbsIfZero(&x1);
        AbsIfZero(&x2);

        printf("This equation has two roots: x1 = %.6lg, x2 = %.6lg.\n", x1, x2);

    }
}
