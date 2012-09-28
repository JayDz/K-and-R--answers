#include <stdio.h>
#define MAX 256
#define READABLE_BEGIN 32
#define READABLE_END 127

main()
{
	int characters[MAX];
	int i;
	int c;

	for (i = 0; i < MAX; ++i)
		characters[i] = 0;

	while ((c = getchar()) != EOF) 
		++characters[c];

	for (i = READABLE_BEGIN; i < READABLE_END; ++i) {
		int n = characters[i];
		if (n > 0) {
			printf("%c: ", i);
			while (n > 0) {
				putchar('*');
				--n;
			}
			putchar('\n');
		}
	}
}
