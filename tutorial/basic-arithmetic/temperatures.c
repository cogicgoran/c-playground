/* This program lists temperatures in fahrenheit system and corresponding celsius values*/
#include <stdio.h>

int main()
{
	printf("%12s %12s\n", "Fahrenheit", "Celsius");
	float temp_fahr = 0;
	float celsius;
	float upper = 300;

	while (temp_fahr <= upper)
	{
		celsius = 5 * (temp_fahr - 32) / 9;
		printf("%12.0f %12.1f\n", temp_fahr, celsius);
		temp_fahr = temp_fahr + 10;
	}
}
