#include <stdio.h>

int main()
{
    int fahr = 300;

    printf("%12s %12s\n", "Fahrenheit", "Celsius");
    for (; fahr >= 0; fahr -= 10)
        printf("%12d %12.1f\n", fahr, 5.0 * (fahr - 32) / 9.0);
}