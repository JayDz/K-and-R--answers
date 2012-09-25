#include <stdio.h>
#define YES 1
#define NO 0

main()
{
	int c;
	int first_run = YES;
	while ((c = getchar()) != EOF) {
		if (first_run == YES) { 
			putchar('\n');
			first_run = NO;
		}
		if (c != ' ' && c != '\n' && c != '\t')
			putchar('*');
		else
			putchar('\n');
	}
	putchar('\n');
}
