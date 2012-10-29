#include <stdio.h>
#define MAX 100

void escape(char s[], char t[])
/* Assumption is made that t array is large enough. */
{
	int i = 0;
	int j = 0;
	while (s[j] != '\0') {
		switch(s[j]) {
		case '\n':
			t[i++] = '\\';
			t[i]   = 'n';
			break;
		case '\t':
			t[i++] = '\\';
			t[i]   = 't';
			break;
		default:
			t[i] = s[j];
			break;
		}
		++i;
		++j;
	}
	t[i] = '\0';
}

void capture(char s[], char t[])
{
	int i = 0;
	int j = 0;
	while (s[j] != '\0') {
		switch(s[j]) {
		case '\\':
			if (s[j+1] == 'n') {
				t[i] = '\n';
				++j;
				break;
			}
			else if (s[j+1] == 't') {
				t[i] = '\t';
				++j;
				break;
			}
		default:
			t[i] = s[j];
			break;
		}
		++i;
		++j;
	}
	t[i] = '\0';
}

int main(void)
{
	char str[MAX];
	char str2[MAX+MAX];
	
	int i = 0;
	char ch;
	while ((ch = getchar()) != EOF)
		str[i++] = ch;
	str[i] = '\0';
	
	putchar('\n');
	escape(str,str2);
	printf("Using escape(): %s\n", str2);
	capture(str2,str);
	printf("Using capture(): %s\n", str);
	return 0;
}
