#include <stdio.h>
#include <string.h>

int FinishProgram();

int main() {
    printf("Do you want to finish?\nYES/NO\n");
    if (FinishProgram() == 1){
        printf("You've finished the program.\n");
    } else{
        printf("Continue.\n");
    }
}

int FinishProgram()
{
    char UsersAnswer[10] = {};
    char ans1[] = "YES", ans2[] = "NO";
    int AnsMatches = 0;
    while (AnsMatches == 0){
        scanf("%s", UsersAnswer);
        if (strcmp(UsersAnswer, ans1) == 0)
            return 1;
        else if (strcmp(UsersAnswer, ans2) == 0)
            return 0;
        printf("Incorrect input, try again:\n");
        while(getchar() != '\n');
    }
    return 0;
}
