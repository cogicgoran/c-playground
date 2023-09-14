/* This program lists temperatures in fahrenheit system and corresponding celsius values*/
#include <stdio.h>

float convertFahrToCelsius(float temp_fahr)
{
    return 5.0 * (temp_fahr - 32.0) / 9.0;
}

int main()
{
    printf("%12s %12s\n", "Fahrenheit", "Celsius");
    float temp_fahr = 0;
    float celsius;
    float upper = 300;

    while (temp_fahr <= upper)
    {
        printf("%12.0f %12.1f\n", temp_fahr, convertFahrToCelsius(temp_fahr));
        temp_fahr = temp_fahr + 10;
    }
}
