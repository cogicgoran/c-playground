#include <stdio.h>

int strindex(char original[], char toFind[]);

int main()
{
    char t1[] = "Hero";
    char t2[] = "dderefewfwer";
    printf("%d\n", strindex(t1, t2));
}

int strindex(char original[], char toFind[])
{
    int i, j, isMatch;
    i = 0;
    while (original[i] != '\0')
    {
        j = 0;
        isMatch = 1;
        while (toFind[j] != '\0')
        {
            if (toFind[j] != original[i + j])
            {
                isMatch = 0;
                break;
            }
            j++;
        }
        if (isMatch)
        {
            return i;
        }
        i++;
    }
    return isMatch = -1;
}