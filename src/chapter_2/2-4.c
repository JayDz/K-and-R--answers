#include <stdio.h>
#define YES 1
#define NO 0

void squeeze(char s[], char c[])
{
	int i, j;

	for (i = j = 0; s[i] != '\0'; i++) {
		int k;
		int replace = NO;
		for (k = 0; c[k] != '\0'; k++)
			if (s[i] == c[k])
				replace = YES;
		if (replace == NO)
			s[j++] = s[i];
	}
	s[j] = '\0';
}

int main(void)
{
	char str[] = "Prentice";
	char replace[] = "eni";

	squeeze(str, replace);

	printf("%s\n", str);
	return 0;
}
