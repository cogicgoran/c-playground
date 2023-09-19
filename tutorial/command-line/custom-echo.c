#include <stdio.h>

int main(int argument_count, char **argv)
{
    printf("%d\n", argument_count);
    printf("%s\n", argv[0]);
    int arg_step;
    for (arg_step = 1; arg_step < argument_count; arg_step++)
    {
        if (arg_step != 1)
        {
            printf(" ");
        }
        printf("%s", argv[arg_step]);
    }
}