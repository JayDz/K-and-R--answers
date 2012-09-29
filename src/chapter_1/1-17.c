#include <stdio.h>
#define REQUIRE 80
#define MAXLINE 1000

int get_line(char line[], int maxline); /* use get_line to avoid collision with std getline */

main()
{
	char line[MAXLINE];
	int size;

	while ((size = get_line(line, MAXLINE)) > 0)
		if (size > REQUIRE)
			printf("%s", line);
	
	return 0;
}

int get_line(char s[], int lim)
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF && c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}
