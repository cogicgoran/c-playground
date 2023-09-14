#include <stdio.h>

int main()
{
    int line_count = 0;
    int blank_count = 0;
    int tab_count = 0;
    char c;

    while ((c = getchar()) != EOF)
    {
        if (c == 32)
            ++blank_count;
        if (c == '\n')
            ++line_count;
        if (c == '\t')
            ++tab_count;
        
        printf("Total blanks: %d\n", blank_count);
        printf("Total tabs: %d\n", tab_count);
        printf("Total lines: %d\n", line_count);
    }
}