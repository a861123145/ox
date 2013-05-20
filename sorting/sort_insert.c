#include <stdio.h>
typedef int bool;
#define true 1
#define false 0

int insert(int* array, unsigned int size, bool ascending)
{
	unsigned int i, j;
	int min, max;

	if (size <= 1)
	{
		printf("sort error: no enought number.\n");
		return -1;
	}

	for (i = 0; i < size; i++)
	{
		if (ascending) {
			for (j = i; j > 0; j--)
			{
				min = array[j];
				if (min < array[j-1])
				{
					array[j] = array[j-1];
					array[j-1] = min;
				}
			}
		} else {
			for (j = i; j > 0; j--)
			{
				max = array[j];
				if (max > array[j-1])
				{
					array[j] = array[j-1];
					array[j-1] = max;
				}
			}
		}
	}

	return 0;
}

int main(int argc, const char *argv[])
{
	int a[5] = {3, 2, 5, 0, 1};

	insert(a, sizeof(a)/sizeof(a[0]), true);
	printf("%d, %d, %d, %d, %d\n", a[0], a[1], a[2], a[3], a[4]);
	insert(a, sizeof(a)/sizeof(a[0]), false);
	printf("%d, %d, %d, %d, %d\n", a[0], a[1], a[2], a[3], a[4]);
	
	return 0;
}
