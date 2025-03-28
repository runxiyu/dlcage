#include <stdio.h>
#include "ghost.h"

static int shared_state = 0;

void increment(void)
{
	printf("before: %d\n", shared_state);
	shared_state++;
	printf("after: %d\n", shared_state);
}
