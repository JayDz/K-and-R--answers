#include <stdio.h>

void strcat2(char*, char*);

int main(void)
{
	char str[100] = "Hello ";
	char str2[] = "world!";

	strcat2(str,str2);
	printf("%s\n", str);
	return 0;
}

void strcat2(char* s, char* t)
{
	while (*s)s++;
	while (*s++ = *t++);
}
