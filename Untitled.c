#include <stdio.h>
/*print line with more than 80 characters*/
#define MAXLINE 1000
int getlin (char c[], int);
void copy (char c[], char a[]);

int main ()
{
    int len;
    char line[MAXLINE], bigenough[MAXLINE];
    while ((len = getlin(line, MAXLINE)) > 0)
        if (len >= 80)
            printf ("%s", line);
}

int getlin(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar ()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copy(char to[], char from[])
{
    int i;
    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
