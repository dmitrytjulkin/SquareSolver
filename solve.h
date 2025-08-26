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


struct CoefficientsData
{
    double a, b, c;
};

struct RootsData
{
    double x1, x2;
};

RootsNumber SolveEquation (CoefficientsData coefficients, RootsData* roots);
bool CheckDoubleEquality (double a, double b);
void AbsIfZero (double* x);

UsersDesire InputCoefficients (CoefficientsData* coefficients);
void CleanTheBuffer ();

int FinishProgram ();
void PrintCase (RootsNumber numOfRoots, RootsData roots);

void RunAllTests();

