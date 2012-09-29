#include <stdio.h>
#define MAXLINE 1000

int get_line(char line[], int maxline); /* use get_line to avoid collision with std getline */
int str_length(char line[]);
void reverse(char line[]);

main()
{
	char line[MAXLINE];
	int size;

	while ((get_line(line, MAXLINE)) > 0) {
		reverse(line);
		printf("%s", line);
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

	s[i] = '\0';
	return i;
}

int str_length(char line[])
{
	int len = 0;
	while (line[len] != '\0') 
		++len;
	return len;
}

void reverse(char line[])
{
	int j = str_length(line)-1;
	int i;

	if (line[j] == '\n') 
		--j;
	for (i = 0; i < j; ++i) {
		char temp = line[i];
		line[i] = line[j];
		line[j] = temp;
		--j;
	}
}
