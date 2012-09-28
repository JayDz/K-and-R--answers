#include <stdio.h>

float get_celsius(float fahr);

main()
{
	float fahr, celsius;
	float lower, upper, step;

	lower = 0;
	upper = 300;
	step  = 20;

	fahr = lower;
	while (fahr <= upper) {
		celsius = get_celsius(fahr);
		
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}

float get_celsius(float fahr)
{
	return (5.0/9.0) * (fahr-32.0);
}
