#include <stdio.h>

int any(const char s1[], const char s2[])
{
	int i, k;

	for (i = 0; s1[i] != '\0'; ++i) 
		for (k = 0; s2[k] != '\0'; ++k)
			if (s1[i] == s2[k])
				return i;
	return -1;
}

int main(void)
{
	char s1[] = "Prentice Hall";
	char s2[] = "Hall";

	int index = any(s1,s2);

	if (index != -1)
		printf("The first location is %d\n", index);
	else
		printf("Location not found.\n");

	return 0;
}
