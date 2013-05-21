#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "sort_insert.h"

#define TEST_NUM 100000

int main(int argc, const char *argv[])
{
	int *b = NULL;
	unsigned int i = 0;
	struct timeval time1, time2;

	b = (int*)malloc(sizeof(int)*TEST_NUM);
	if (!b) {
		printf("malloc failed!\n");
		return -1;
	}

	for (i = 0; i < TEST_NUM; i++) {
		b[i] = random();
	}

	gettimeofday(&time1, NULL);
	insert_ascending(b, TEST_NUM);
	gettimeofday(&time2, NULL);
	printf("time escaped: %u\n", (unsigned int)(time2.tv_usec - time1.tv_usec));
	printf("time escaped: %u\n", (unsigned int)(time2.tv_sec - time1.tv_sec));

//	for (i = 0; i < TEST_NUM; i++) {
//		if (i%5 == 0)
//			printf("\n");
//		printf("%d\t", b[i]);
//	}
	printf("\n");
//	insert_descending(b, TEST_NUM);
	
	free(b);
	return 0;
}
