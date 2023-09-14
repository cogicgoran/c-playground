#include <stdio.h>

int main()
{
    char c;

    while ((c = getchar()) != EOF)
    {
        printf("EOF = %d\n", EOF);
        putchar(c);
    }
}