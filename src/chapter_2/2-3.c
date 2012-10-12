#include <string.h>
#include <stdio.h>

int power(int base, int exp);
int htoi(char s[]);

int main(void)
{
	char str[] = "beef";
	char str2[] = "0x1222";
	char str3[] = "0xF";
	char str4[] = "8a";

	printf("%s is the integer value %d\n", str, htoi(str));
	printf("%s is the integer value %d\n", str2, htoi(str2));
	printf("%s is the integer value %d\n", str3, htoi(str3));
	printf("%s is the integer value %d\n", str4, htoi(str4));
	return 0;
}

int power(int base, int exp)
/* power function that ignores negative and fractional exponents. */
{
	if (exp == 0) return 1;
	int result = base;
	int i;
	for (i = 1; i < exp; ++i)
		result *= base;

	return result;
}

int htoi(char s[])
{
	int len = strlen(s);
	int result = 0;
	int i, j;

	j = 0;
	for (i = len-1; i >= 0; --i) {
		if ((s[i] != 'x') && (s[i] != 'X')) {
			int val;

			if (s[i] >= '0' && s[i] <= '9')
				val = s[i] - '0';
			else
			if (s[i] >= 'A' && s[i] <= 'F')
				val = s[i] - 55;
			else
			if (s[i] >= 'a' && s[i] <= 'f')
				val = s[i] - 87;
			else //invalid digit.
				return 0;
		
			result += val * power(16,j);
			++j;
		}
		else
			return result;
	}
	return result;
}
