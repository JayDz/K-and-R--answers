#include <stdio.h>

main()
{
	int c;
	int nb;
	int nt;
	int nl;

	nb = 0;
	nt = 0;
	nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == ' ')
			++nb;
		if (c == '\t')
			++nt;
		if (c == '\n')
			++nl;
	}

	printf("\nBlank count is: %d\n", nb);
	printf("Tab count is: %d\n", nt);
	printf("Newline count is: %d\n", nl);
}
