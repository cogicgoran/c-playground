#include <stdio.h>

int main()
{
    int c;
    int prev_char = -1;
    while ((c = getchar()) != EOF)
    {
        if ((c == 32 || c == '\n' || c == '\t') && (prev_char == 32 || prev_char == '\n' || prev_char == '\t'))
        {
            continue;
        }
        else if (c == 32 || c == '\n' || c == '\t')
        {
            prev_char = c;
            putchar(' ');
            continue;
        }
        else
        {
            prev_char = c;
            putchar(c);
        }
    }
}