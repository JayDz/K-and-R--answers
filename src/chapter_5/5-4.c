#include <ctype.h>
#include <stdio.h>

int strend(char*, char*);

int main(void)
{
	char str[] = "poorly tested software is dangerous.";
	char src[] = "dangerous";

	printf("%d\n", strend(str,src));
	return 0;
}

int strend(char* s, char* t)
{
	char* end = 0;

	while (*s) s++;
	s--;
	
	if (ispunct(*s))
		s--;
	end = s;

	while (!isspace(*s))
		s--;
	s++;
	
	for (;;) {
		if (s > end && *t == '\0')
			return 1;
		
		if (*s != *t) break;
		s++;
		t++;
	}
	return 0;
}
