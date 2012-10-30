#include <ctype.h>
#include <stdio.h>
#include <math.h>

double atof(char s[]);

int main(void)
{
	char s[] = "15.124e-7";
	printf("%g\n", atof(s));
	return 0;
}

double atof(char s[])
{
	double val, power, ret, exp;
	int i, sign, neg_exp;
	
	for (i = 0; isspace(s[i]); i++);

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	ret = sign * val / power;

	neg_exp = 0;
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	if (s[i] == '+')
		i++;
	if (s[i] == '-') {
		neg_exp = 1;
		i++;
	}

	for (exp = 0.0; isdigit(s[i]); i++)
		exp = 10.0 * exp + (s[i] - '0');
	
	if (neg_exp) exp *= -1;
	return ret * pow(10, exp);
}
