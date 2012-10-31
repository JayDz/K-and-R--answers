#include <stdio.h>
#define swap(t,x,y) \
	t temp = (x);   \
	(x) = (y);      \
	(y) = temp      \

int main(void)
{
	int x = 10;
	int y = 20;

	printf("x: %d\ty: %d\n", x,y);
	swap(int,x,y);
	printf("x: %d\ty: %d\n", x,y);

	return 0;
}
