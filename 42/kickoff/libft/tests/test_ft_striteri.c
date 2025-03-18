#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>

#include <string.h>
#include <ctype.h>
#include "../libft.h"  // Ensure this points to your `libft.h`

// Function to apply for testing
static void to_upper_if_even(unsigned int i, char *c)
{
	if (i % 2 == 0)
		*c = toupper(*c);
}

void test_ft_striteri(void **state)
{
	(void)state;

	// 🟢 **Test: Normal string transformation**
	{
		char str[] = "hello world";

		ft_striteri(str, to_upper_if_even);
		assert_string_equal(str, "HeLlO WoRlD");
	}

	// 🟢 **Test: Empty string (should remain unchanged)**
	{
		char str[] = "";

		ft_striteri(str, to_upper_if_even);
		assert_string_equal(str, "");  // No change expected
	}

	// 🟢 **Test: String with only spaces**
	{
		char str[] = "    ";

		ft_striteri(str, to_upper_if_even);
		assert_string_equal(str, "    ");  // No change expected
	}

	// 🟢 **Test: NULL string input (should do nothing)**
	{
		ft_striteri(NULL, to_upper_if_even);  // Should not crash
	}

	// 🟢 **Test: NULL function pointer (should do nothing)**
	{
		char str[] = "test";

		ft_striteri(str, NULL);  // Should do nothing
		assert_string_equal(str, "test");  // Must remain the same
	}

	// 🟢 **Test: Only one character**
	{
		char str[] = "a";

		ft_striteri(str, to_upper_if_even);
		assert_string_equal(str, "A");  // First character should be uppercase
	}

	// 🟢 **Test: Already uppercase**
	{
		char str[] = "HELLO";

		ft_striteri(str, to_upper_if_even);
		assert_string_equal(str, "HELLO");  // Should remain unchanged
	}

	// 🟢 **Test: String with numbers and symbols**
	{
		char str[] = "a1b2c3d4";

		ft_striteri(str, to_upper_if_even);
		assert_string_equal(str, "A1B2C3D4");  // Letters at even positions should be uppercase
	}
}
