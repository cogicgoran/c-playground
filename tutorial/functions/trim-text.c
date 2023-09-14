#include <stdio.h>

#define MAXLINE 4

void get_line(char line[], int limit);
void trim(char input[], char output[]);
int str_length(char text[]);

int main()
{
    char input[MAXLINE];
    char output[MAXLINE];

    get_line(input, MAXLINE);
    trim(input, output);
    printf("Trimmed: '%s'", output);
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

void trim(char input[], char output[])
{
    int len = str_length(input);
    int i = 0;
    int is_pre_empty = 1;
    int pre_empty_count = 0;
    int post_empty_count = 0;
    while (input[i] != '\0')
    {
        // Trim start logic
        if (is_pre_empty == 1)
        {
            if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
            {
                pre_empty_count++;
            }
            else
            {
                is_pre_empty = 0;
            }
        }
        // Trim end logic
        if (input[i] == ' ' || input[i] == '\t' || input[i] == '\n')
        {
            post_empty_count++;
        }
        else
        {
            post_empty_count = 0;
        }
        i++;
    }
    // printf("\nPRE_EMPTY=%d POST_EMPTY=%d LEN=%d", pre_empty_count, post_empty_count, len);
    for (i = pre_empty_count; i < len - post_empty_count; i++)
    {
        output[i - pre_empty_count] = input[i];
    }
    output[i - pre_empty_count] = '\0';
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