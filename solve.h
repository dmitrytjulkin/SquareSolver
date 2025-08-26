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
    int nRoots;
};

RootsNumber SolveEquation (double a, double b, double c, double* x1, double* x2);
bool CheckDoubleEquality (double a, double b);
void AbsIfZero (double* x);

UsersDesire InputCoefficients (double* a, double* b, double* c);
void CleanTheBuffer ();

int FinishProgram ();
void PrintCase (RootsNumber numOfRoots, double x1, double x2);


