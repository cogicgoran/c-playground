#include <stdio.h>
#define MAXLINE 100

void get_line(char line[], int limit);
void reverse_line(char input[], char output[]);
int str_length(char text[]);

int main()
{
    char input[MAXLINE];
    char output[MAXLINE];

    get_line(input, MAXLINE);
    reverse_line(input, output);
    printf("\nReversed string: %s\n", output);

    return 0;
}

int str_length(char text[])
{
    int i = 0;
    while (text[i] != '\0')
    {
        i++;
    }
    return i;
}

void reverse_line(char input[], char output[])
{
    int i = 0;
    int j;
    int len = str_length(input);
    for (i = len - 1, j = 0; i >= 0; i--, j++)
    {
        output[j] = input[i];
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