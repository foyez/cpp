#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <string.h>  // For memset and memcmp
#include "../libft.h"  // Ensure this includes ft_bzero's declaration

void test_ft_bzero(void **state)
{
	// Test Case 1: Basic test to ensure buffer is zeroed
	{
		(void)state;  // Unused parameter
		char buffer[10] = "abcdefghi";  // Non-zeroed buffer

		ft_bzero(buffer, 5);  // Zero out first 5 bytes
		assert_memory_equal(buffer, "\0\0\0\0\0fghi", 10);
	}

	// Test Case 2: Zero-size buffer should remain unchanged
	{
		(void)state;
		char buffer[5] = "hello";
		char expected[5] = "hello";  // Should remain unchanged

		ft_bzero(buffer, 0);
		assert_memory_equal(buffer, expected, 5);
	}

	// Test Case 3: Full buffer zeroing
	{
		(void)state;
		char buffer[10] = "abcdefghij";

		ft_bzero(buffer, 10);
		assert_memory_equal(buffer, "\0\0\0\0\0\0\0\0\0\0", 10);
	}

	// Test Case 4: Ensuring the pointer remains the same
	{
		(void)state;
		char buffer[10] = "abcdefghi";

		char *original_address = buffer;
		ft_bzero(buffer, 10);
		assert_ptr_equal(buffer, original_address);
	}
}

