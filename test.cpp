#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <float.h>

#include "solve.h"

int TestMyProgram(CoefsNRoots param []);

void RunAllTests()
{
    CoefsNRoots param[] = {{.coefficients.a = 1, .coefficients.b = 0, .coefficients.c = -4,
                            .roots.x1 = -2, .roots.x2 = 2, .numOfRoots = 2}};

    size_t size = sizeof (param) / sizeof (param[0]);
    int passed = 0;

    for (size_t i = 0; i < size; i++)
        passed += TestMyProgram(&param [i]);

    printf("There are %d/%zu passed tests.\n", passed, size);

}

// x1 = rand
// x2 = rand

// one root
// zero root disc < 0
//
// x1 = a + ib
// x2 = a - ib
// (x-x1)(x-x2) = (x-a-ib)(x-a+ib) = x^2 + x*(-a+ib-a-ib) + (aa+aib-aib+bb)
// = x^2 - 2a * x + (aa+bb)
//
// fopen("text.txt", )
// scanf  -> fscanf
// printf -> fprintf
// fclose()
//
//

int TestMyProgram(CoefsNRoots param [])
{
    double x1Real = 0, x2Real = 0;
    int numOfRootsReal = SolveEquation(param->coefficients, &param->roots);

    if(!(CheckDoubleEquality(x1Real, param->roots.x1) && CheckDoubleEquality(x2Real, param->roots.x2) && numOfRootsReal == param->numOfRoots)) {

        printf ("FAILED: input: (a, b, c) = (%lg, %lg, %lg),\n"
                "output: (x1, x2, numOfRoots) = (%lg, %lg, %d),\n"
                "expected: (x1, x2, numOfRoots) = (%lg, %lg, %d)\n\n",

                param->coefficients.a, param->coefficients.b, param->coefficients.c,
                       x1Real,          x2Real,          numOfRootsReal,
                param->roots.x1, param->roots.x2, param->numOfRoots);

        return 0;
    }
    return 1;
}
