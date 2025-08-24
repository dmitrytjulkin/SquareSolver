#include <stdio.h>
#include <string.h>
#include <float.h>
#include <math.h>

int FinishProgram ();
void CleanTheBuffer ();

int main() {
    if (FinishProgram() == 1)
        printf ("you've finished\n");
    else if (FinishProgram() == 0)
        printf ("enter the coefficients\n");
    else
        printf ("error, u r an idiot.\n");
}

int FinishProgram ()
{
    int UsersAnswer = -1;
    int AnsMatches = 0;

    while (AnsMatches == 0) {

        if (scanf ("%d", &UsersAnswer) == 1 && (UsersAnswer == 0 || UsersAnswer == 1) && getchar() == '\n')
            return UsersAnswer;
        CleanTheBuffer();
        printf("Incorrect input, try again.\n"
                "Do you want to finish?\n"
                "(input 1 if you want to End the program and 0 if you want to continue)\n");
    }

    return 0;
}

void CleanTheBuffer ()
{
    while(getchar() != '\n');
}
