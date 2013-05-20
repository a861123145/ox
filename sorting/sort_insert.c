#include <stdio.h>

int insert(int* array, unsigned int size)
{
	unsigned int i, j;
	int temp;

	for (i = 0; i < size; i++)
		for (j = i - 1; j >= 0; j--)
		{
			temp = array[i];
			if (temp < array[j])
			{
				array[i] = array[j];
				array[j] = temp;
			}
		}

	return 0;
}

int main(int argc, const char *argv[])
{
	int a[5] = {3, 2, 5, 0, 1};

	insert(a, sizeof(a)/sizeof(a[0]));

	printf("%u\n", sizeof(a)/sizeof(a[0]));
	printf("%d, %d, %d, %d, %d\n", a[0], a[1], a[2], a[3], a[4]);
	
	return 0;
}
