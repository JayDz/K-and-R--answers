#include <stdio.h>

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	mid = (low+high) / 2;
	while ((low <= high) && (v[mid] != x)) {
		if (x < v[mid])
			high = mid + 1;
		else
			low = mid + 1;
		mid = (low+high) / 2;
	}
	return (v[mid] == x)? mid : -1;
}

int main(void)
{
	int v[] = {1,2,3,4,5};
	int ret = binsearch(4,v,5);

	printf("%d\n", ret);
}
