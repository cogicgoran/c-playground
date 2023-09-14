// Program replaces each tab with fixed amount of spaces.
#include <stdio.h>

#define TAB_SPACES 2
#define CHAR_LIMIT 30

void get_line(char line[], int limit);
void get_with_spaces(char input[], char output[]);

int main()
{
    int c;
    char input[CHAR_LIMIT];
    char output[CHAR_LIMIT * 2];
    get_line(input, CHAR_LIMIT);
    get_with_spaces(input, output);
    printf("%s\n", output);
}

void get_with_spaces(char input[], char output[])
{
    int i = 0;
    int j = 0;
    while (input[i] != '\0')
    {
        if (input[i] == '\t')
        {
            output[j] = output[j + 1] = ' ';
            j += 2;
        }
        else
        {
            output[j] = input[i];
            j++;
        }
        i++;
    }
    output[j] = '\0';
}

void get_line(char line[], int limit)
{
    char c;
    int i;
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; i++)
    {
        line[i] = c;
    }
    line[i] = '\0';
}