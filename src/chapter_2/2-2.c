#include <stdio.h>

#define MAXLINE 10
#define YES 1
#define NO 0

int main(void)
{
	int run = YES;
	char s[MAXLINE];
	char c;
	int i;

	i = 0;
	c = getchar();
	while (run == YES) {
		if (!(i < MAXLINE - 1))
			run = NO;
		else
		if (c == '\n')
			run = NO;
		else
		if (c == EOF)
			run = NO;
		else
			s[i] = c;

		if (run == YES) {
			c = getchar();
			++i;
		}
	}

	s[i] = '\0';
	printf("%s\n", s);
	
	return 0;
}
