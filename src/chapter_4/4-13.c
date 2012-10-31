#include <stdio.h>
#include <string.h>

void reverse(char [],int,int);

int main(void)
{
	char str[] = "Short string.";
	reverse(str,0,strlen(str)-1);
	printf("%s\n", str);

	return 0;
}

void reverse(char s[], int i, int j)
{
	if (i < j) {
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
		reverse(s,i,j);
	}
}
