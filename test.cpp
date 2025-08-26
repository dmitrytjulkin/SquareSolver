#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>

#include "solve.h"

struct TestData
{
    double a, b, c;
    double x1Ref, x2Ref;
    int numOfRootsRef;
};

int TestMyProgram(TestData test);

void RunAllTests()
{
    int passed = 0;
    TestData tests [] = {{.a = 1, .b = 0, .c = -4, .x1Ref = -2, .x2Ref = 2, .numOfRootsRef = 2},
                        {.a = 1, .b = 2, .c = 1, .x1Ref = -1, .x2Ref = -1, .numOfRootsRef = 1},
                        {.a = 1, .b = 0, .c = -1, .x1Ref = -1, .x2Ref = 1, .numOfRootsRef = 2}};
    size_t size = sizeof (tests) / sizeof (tests[0]);
    for (size_t i = 0; i < size; i++)
        passed += TestMyProgram(tests [i]);
    printf("There are %d/%zu passed tests.\n", passed, size);

}

int TestMyProgram(TestData test)
{
    double x1 = 0, x2 = 0;
    int numOfRoots = SolveEquation(test.a, test.b, test.c, &x1, &x2);

    if(!(CheckDoubleEquality(x1, test.x1Ref) && CheckDoubleEquality(x2, test.x2Ref) && numOfRoots == test.numOfRootsRef)) {

        printf ("FAILED: input: (a, b, c) = (%lg, %lg, %lg),\n"
                "output: (x1, x2, numOfRoots) = (%lg, %lg, %d),\n"
                "expected: (x1, x2, numOfRoots) = (%lg, %lg, %d)\n\n",

                test.a, test.b, test.c, x1, x2, numOfRoots, test.x1Ref, test.x2Ref, test.numOfRootsRef);

        return 0;
    }
    return 1;
}
