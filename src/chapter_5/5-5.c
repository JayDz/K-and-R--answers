#include <stdio.h>

char* strncat2(char*, char*, int);
char* strncpy2(char*, char*, int);
int strncmp2(char*, char*, int);

//test functions
void test_strncat2();
void test_strncmp2();
void test_strncpy2();

int main(void)
{
	test_strncat2();
	test_strncmp2();
	test_strncpy2();
	return 0;
}

char* strncat2(char* s, char* t, int n)
{
	char* ret = s;
	while (*s) s++;
	while ((n > 0) && (*s++ = *t++));
	*s = '\0';
	return ret;
}

char* strncpy2(char* s, char* t, int n)
{
	char* ret = s;
	while ((n > 0) && (*s++ = *t++))
		n--;
	while (n > 0) {
		*s++ = '\0';
		n--;
	}
	return ret;
}

int strncmp2(char* s, char* t, int n)
{
	while ((*s == *t) && (n-1 > 0)) {
		if (*s == '\0')
			return 0;
		s++;
		t++;
		n--;
	}
	return *s - *t;
}

//test function definitions

void test_strncat2()
{
	char str1[50] = "Hello ";
	char str2[] = "world!";
	
	printf("strncat2() test:\n");
	printf("Expected result: Hello world!\n");
	printf("Actual result: %s\n", strncat2(str1,str2,6));
	
	printf("\nExpected result: Hello world! You're beautiful.\n");
	printf("Actual result: %s\n", strncat2(str1," You're beautiful.",100));
	printf("*******************************************************\n");
}

void test_strncmp2()
{
	printf("strncmp2() test:\n");
	printf("Expected result: positive integer\n");
	printf("Actual result: %d\n", strncmp2("cool","coal",3));

	printf("Expected result: zero\n");
	printf("Actual reslut: %d\n", strncmp2("cool","cool",100));
	printf("*******************************************************\n");
}

void test_strncpy2()
{
	char str1[] = "AAAAABCCCCCC";
	char str2[] = "Hello World!";
	char str3[] = "AAAAABCCCCCC";

	printf("strncpy2() test:\n");
	printf("Expected result: Hello World!\n");
	printf("Actual result: %s\n", strncpy2(str1,str2,14));

	printf("Expected result: AAAAA world!\n");
	printf("Actual result: %s\n", strncpy2(str1,str3,5));
	
	printf("Expected result: SEGFAULT\n");
	printf("Actual result: %s\n", strncpy2(str1,str2,1000));
	printf("*******************************************************\n");
}
