#include <stdio.h>

main()
{
	int c = getchar() != EOF;

	/* the output will be 1 when a character is read and 0 when Ctrl-d is pressed. */
	printf("%d\n", c);
}
