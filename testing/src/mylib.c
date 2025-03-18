// #include "mylib.h"
#include <stdlib.h>

int *allocate_array(size_t size) {
    int *ptr = (int *)malloc(size * sizeof(int));
	if (!ptr)
		return NULL;
	return ptr;
}
