#include <stdio.h>

void alloctest(void)
{
	printf("implement page allocation test!!!\n");

	/* SimHongSub : Test code */
	printf("\nInitial state\n");
	palloc_get_status(0);

	size_t page = palloc_get_multiple(0, 4);

	printf("\nAllocate page cnt 4 state\n");
	palloc_get_status(0);

	palloc_free_multiple(page, 3);

	printf("\nFree page cnt 3 state\n");
	palloc_get_status(0);

	size_t page2 = palloc_get_multiple(0, 3);

	printf("\nAllocate page cnt 3 state\n");
	palloc_get_status(0);
	
	palloc_free_multiple(page2, 2);

	printf("\nFree page cnt 2 state\n");
	palloc_get_status(0);

	size_t page3 = palloc_get_multiple(0, 1);

	printf("\nAllocate page cnt 1 state\n");
	palloc_get_status(0);
}


