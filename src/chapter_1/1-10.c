#include <stdio.h>
#define YES 1
#define NO 0
main()
{
	int c;
	int skip = NO;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			skip = YES;
			printf("\\t");
		}
		if (c == '\b') {
			skip = YES;
			printf("\\b");
		}
		if (c == '\\') {
			skip = YES;
			printf("\\");
		}
		if (skip == NO)
			putchar(c);

		skip = NO;
	}
}
