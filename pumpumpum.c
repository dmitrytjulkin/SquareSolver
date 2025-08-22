/**
* Program to print the longest line from input.
*/
#include <stdio.h>
#define MAXLINE 1000 /* maximum input line */

int max;
char line[MAXLINE], longest[MAXLINE];

int getrow(void);
void copy(void);

/* print longest input line */
int main()
{
    int len;
    extern int max;
    extern char longest[];

    max = 0;
    while( (len = getrow()) > 0 )
        if(len > max) {
            max = len;
            copy();
        }
    if(max > 0)
        printf("%s", longest);
    return 0;
}

/* getrow: read a line into s, return length */
int getrow(void)
{
    int c, i;
    extern char line[];

    for(i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        line[i] = c;
    if(c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/* copy: copy from into to */
void copy(void)
{
    int i;
    extern char line[], longest[];
    i = 0;
    while((longest[i] = line[i]) != '\0')
        ++i;
}
