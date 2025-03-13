#include <stdlib.h>
#include <string.h>
#include <limits.h>

void *ft_calloc(size_t count, size_t size)
{
    if (count == 0 || size == 0)
        return malloc(0);  // Some implementations return NULL, but malloc(0) is safer.

    // Check for overflow in multiplication
    if (count > SIZE_MAX / size)
        return NULL;

    void *ptr = malloc(count * size);
    if (!ptr)
        return NULL;

    memset(ptr, 0, count * size);
    return ptr;
}
