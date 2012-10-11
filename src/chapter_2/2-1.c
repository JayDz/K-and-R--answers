#include <float.h>
#include <limits.h>
#include <stdio.h>

int main(void)
{
	/* direct computation */
	long size = 0;

	char schar = 0;
	unsigned char uchar = 0;

	short sshort = 0;
	unsigned short ushort = 0;

	int sint = 0;
	unsigned uint = 0;

	long slong = 0;
	unsigned long ulong = 0;
	
	printf("Direct computation of value limits.\n");
	
	while (--schar < 0);
	printf("The maximum value for a signed char object is: %d\n", schar);
	
	schar = 0;
	while (++schar > 0);
	printf("The minimum value for an signed char object is: %d\n", schar);

	while (--uchar < 0);
	printf("The maximum value for an unsigned char object is: %d\n", uchar);

	while (--sshort < 0);
	printf("The maximum value for a signed short object is: %d\n", sshort);

	sshort = 0;
	while (++sshort > 0);
	printf("The minimum value for a signed short objeect is: %d\n", sshort);

	while (--ushort < 0);
	printf("The maximum value for an unsigned short object is: %d\n", ushort);

	while (--sint < 0);
	printf("The maximum value for a signed int object is: %d\n", sint);
	
	sint = 0;
	while (++sint > 0);
	printf("The minimum value for a signed int object is: %d\n", sint);

	while (--uint < 0);
	printf("The maximum value for an unsigned int object is: %u\n", uint);

	while (--slong < 0);
	printf("The maximum value for a signed long object is: %ld\n", slong);

	slong = 0;
	while (++slong > 0);
	printf("The minimum value for a signed long objeect is: %ld\n", slong);

	while (--ulong < 0);
	printf("The maximum value for an unsigned int object is: %lu\n", ulong);

	/* header file value data */
	printf("Value limits defined by standard header files.\n");

	printf("Minimum value for an object of type signed char\t %d\n", SCHAR_MIN);
	printf("Maximum value for an object of type signed char\t %d\n", SCHAR_MAX);
	printf("Maximum value for an object of type unsigned char\t %d\n", UCHAR_MAX);
	printf("Minimum value for an object of type char\t %d\n", CHAR_MIN);
	printf("Maximum value for an object of type char\t %d\n", CHAR_MAX);
	printf("Minimum value for an object of type short int\t %d\n", SHRT_MIN);
	printf("Maximum value for an object of type short int\t %d\n", SHRT_MAX);
	printf("Maximum value for an object of type unsigned short\t %d\n", USHRT_MAX);
	printf("Minimum value for an object of type int\t %d\n", INT_MIN);
	printf("Maximum value for an object of type int\t %d\n", INT_MAX);
	printf("Maximum value for an object of type unsigned int\t %u\n", UINT_MAX);
	printf("Maximum value for an object of type long int\t %ld\n", LONG_MAX);
	printf("Minimum value for an object of type long int\t %ld\n", LONG_MIN);
	printf("Maximum value for an object of type unsigned long int\t %lu\n", ULONG_MAX);
		
	return 0;
}
