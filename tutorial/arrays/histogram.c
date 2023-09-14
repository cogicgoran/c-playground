#include <stdio.h>
#define IN 1
#define OUT 0
#define ARR_LEN 10

int main()
{
    int strLengths[ARR_LEN], c, state; // Words with >10 letter will go to count 10
    int current_word_length = 0;
    state = OUT;

    for (int i = 0; i < ARR_LEN; i++)
    {
        strLengths[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            state = OUT;
            if (current_word_length > 0)
            {
                if (current_word_length >= ARR_LEN)
                {
                    current_word_length = ARR_LEN;
                }
                strLengths[current_word_length - 1]++;
                current_word_length = 0;
            }
        }
        else
        {
            state = IN;
            current_word_length++;
        }
    }

    printf("\n");
    for (int i = 0; i < ARR_LEN; i++)
    {
        printf("%2d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < ARR_LEN; i++)
    {
        printf("%2d ", strLengths[i]);
    }
    printf("\n");
}