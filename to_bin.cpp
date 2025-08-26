#include <stdio.h>

struct CoefficientsData
{
    int a, b, c;
};

struct RootsData
{
    int x1, x2;
};

struct CoefsNRoots
{
    CoefficientsData coefficients;
    RootsData roots;
};

void Nothing(CoefsNRoots param);

int main()
{
    CoefficientsData coefficients = {.a = 1, .b = 3, .c = 2};
    RootsData roots = {.x1 = 15, .x2 = 10};
    CoefsNRoots param = {coefficients, roots};
    Nothing(param);
}

void Nothing(CoefsNRoots param)
{
    printf("%d, %d, %d\n", param.coefficients.a, param.coefficients.b, param.roots.x1);
}
