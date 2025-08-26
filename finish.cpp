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

void PrintCase (RootsNumber numOfRoots, RootsData roots) {
    if (numOfRoots == INF_ROOTS)

        printf("This equation has infinite roots.\n");

    else if (numOfRoots == NO_ROOTS)

        printf("This equation has no roots.\n");

    else if (numOfRoots == ONE_ROOT) {

            AbsIfZero(&roots.x1);

            printf("This equation has one root: x = %.6lg.\n", roots.x1);

    } else {

        AbsIfZero(&roots.x1);
        AbsIfZero(&roots.x2);

        printf("This equation has two roots: x1 = %.6lg, x2 = %.6lg.\n", roots.x1, roots.x2);

    }
}
