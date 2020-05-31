#include <stdio.h>

void alloctest(void)
{
	printf("implement page allocation test!!!\n");

	
	/* SimHongSub : First Fit, Next Fit test code */
	/*size_t page = palloc_get_multiple(0, 2);

	palloc_get_status(0);

	palloc_free_multiple(page, 1);

	palloc_get_status(0);

	size_t page2 = palloc_get_multiple(0, 1);

	palloc_get_status(0);*/

	/* SimHongSub : Best Fit test code */
	/*palloc_get_status(0);

	size_t page = palloc_get_multiple(0, 4);

	palloc_get_status(0);

	palloc_free_multiple(page, 3);

	palloc_get_status(0);

	size_t page2 = palloc_get_multiple(0, 4);

	palloc_get_status(0);
	
	palloc_free_multiple(page2, 2);

	palloc_get_status(0);

	size_t page3 = palloc_get_multiple(0, 4);

	palloc_get_status(0);

	palloc_free_multiple(page3, 2);

	palloc_get_status(0);

	size_t page4 = palloc_get_multiple(0, 1);

	palloc_get_status(0);*/

	/* SimHongSub : Buddy System test code */
	palloc_get_status(0);

	size_t page = palloc_get_multiple(0, 4);

	palloc_get_status(0);

	palloc_free_multiple(page, 3);

	palloc_get_status(0);

	size_t page2 = palloc_get_multiple(0, 3);

	palloc_get_status(0);
	
	palloc_free_multiple(page2, 2);

	palloc_get_status(0);

	size_t page3 = palloc_get_multiple(0, 1);

	palloc_get_status(0);


}
