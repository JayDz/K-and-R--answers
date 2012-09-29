#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline); /* use get_line to avoid collision with std getline */
void rm_blanks(char line[], int size);

main()
{
	char line[MAXLINE];
	int size;
	
	size = get_line(line, MAXLINE);
	while (line[size] != EOF) {
		rm_blanks(line, size);
		printf("%s", line);
		size = get_line(line, MAXLINE);
	}
	
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
	if (c == EOF)
		s[i] = EOF;
	else 
		s[i] = '\0';
	return i;
}

void rm_blanks(char line[], int size)
{
	--size;
	while (line[size] == ' ' || line[size] == '\t' || line[size] == '\n') {
		line[size] = '\0';
		--size;
	}
}
