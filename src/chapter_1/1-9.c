#include <stdio.h>
#define YES 1
#define NO 0
main()
{
	int c;
	int prev_c;
	int skip;

	prev_c = 0;
	skip = NO;
	while ((c = getchar()) != EOF) {
		if (c == '\t')
			c = ' ';
		
		if (c == ' ')
			if (prev_c == c)
				skip = YES;
	
		if (skip == NO)
			putchar(c);

		skip = NO;
		prev_c = c;
	}	
}
