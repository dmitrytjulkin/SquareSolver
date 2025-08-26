enum RootsNumber
{
    INF_ROOTS = -1,
    NO_ROOTS = 0,
    ONE_ROOT = 1,
    TWO_ROOT = 2
};

enum UsersDesire
{
    WANT_TO_SOLVE,
    WANT_TO_FINISH,
    WANT_TO_CORRECT,
};

const double NOT_A_ROOT = -1;

struct CoefficientsData
{
    double a, b, c;
};

struct RootsData
{
    double x1, x2;
};

struct CoefsNRoots
{
    CoefficientsData coefficients;
    RootsData roots;
    int numOfRoots;
};

RootsNumber SolveEquation (CoefficientsData param.coefficients, RootsData (param->roots));
bool CheckDoubleEquality (double a, double b);
void AbsIfZero (double* x);

UsersDesire InputCoefficients (CoefficientsData param->coefficients);
void CleanTheBuffer ();

int FinishProgram ();
void PrintCase (RootsNumber param.numOfRoots, RootsData param.roots);

void RunAllTests();

