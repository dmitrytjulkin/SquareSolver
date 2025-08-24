#include <stdio.h>

void RunTest()
{
    int passed = 0;
    passed += TestMyProgram(1, 2, 1, -1, -1, 1);
    printf("There are %d out of 1 passed tests", passed);
}

int TestMyProgram(double a, double b, double c, double x1Ref, double x2Ref, int numOfRootsRef)
{
    double x1 = 0, x2 = 0;
    int numOfRoots = SolveEquation(a, b, c, &x1, &x2);

    if(!(CheckDoubleEquality(x1, x1Ref) && CheckDoubleEquality(x2, x2Ref) && numOfRoots == numOfRootsRef)) {

        printf ("FALED: input: (a, b, c) = (%lf, %lf, %lf),\n"
                "output: (x1, x2, numOfRoots) = (%lf, %lf, %d),\n"
                "expected: (x1, x2, numOfRoots) = (%lf, %lf, %d)\n",

                a, b, c, x1, x2, numOfRoots, x1Ref, x2Ref, numOfRootsRef);

        return 0;
    }
    return 1;
}
