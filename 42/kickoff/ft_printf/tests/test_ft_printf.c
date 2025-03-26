#include "test_ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(void)
{
	// No format
	// TEST("[\001\002\007\v\010\f\r\n]", "\001\002\007\v\010\f\r\n");

	// // Character test
	// TEST("[%c]", "%c", 'A');                     // Single character
	// TEST("[%5c]", "%5c", 'B');                   // Right-aligned with width
	// TEST("[%-5c]", "%-5c", 'C');                 // Left-aligned with width
	// // TEST("[%05c]", "%05c", 'A');                 // Zero-padded character
	// // TEST("[% c]", "% c", 'A');                   // space character
	// // TEST("[%+5c]", "%+5c", 'A');                 // plus sign character
	// // TEST("[%#5c]", "%#5c", 'A');                 // hash sign character

	// // Percent test
	// TEST("[%%]", "%%");                          // Just a percent sign
	// TEST("[%5%]", "%5%");                        // Right-aligned percent
	// TEST("[%-5%]", "%-5%");                      // Left-aligned percent
	// TEST("[%05%]", "%05%");                      // Zero-padded percent
	// TEST("[% %]", "% %");                        // space percent
	// TEST("[%+5%]", "%+5%");                      // plus sign percent
	// TEST("[%#5%]", "%#5%");                      // hash sign percent

	// // String test
	// TEST("[%10s]", "%10s", "Hi");                // Right-aligned string
	// TEST("[%-10s]", "%-10s", "Hello");           // Left-aligned string
	// TEST("[%10.3s]", "%10.3s", "HelloWorld");    // Width and precision
	// TEST("[%.3s]", "%.3s", "Hello");             // Precision only
	// TEST("[%10s]", "%10s", (char *)NULL);        // Right-aligned NULL string
	// TEST("[%-10.3s]", "%-10.3s", (char *)NULL);        // Left-aligned and precision NULL string
	// TEST("[%2.3s]", "%2.3s", "Hello");
	// TEST("[%2.0s]", "%2.0s", "Hello");
	// TEST("[%010s]", "%010s", "Hello");

	// // Pointer test
	// int num = 42;
	// void *ptr1 = &num;    // Valid pointer
	// void *ptr2 = NULL;    // NULL pointer
	// void *ptr3 = (void *)0x1234; // Manually assigned address (not recommended in real cases)
	// // Basic pointer test
	// TEST("[%p]", "%p", ptr1);              // Standard case
	// TEST("[%20p]", "%20p", ptr1);          // Right-aligned with width
	// TEST("[%-20.3p]", "%-20.3p", ptr1);        // Left-aligned with width
	// TEST("[%#20p]", "%#20p", ptr1);        // Alternative form (though ignored in standard printf)
	// // NULL pointer test
	// TEST("[%p]", "%p", ptr2);              // NULL pointer case
	// // Edge cases
	// TEST("[%10p]", "%10p", (void *)0);         // Zero pointer (equivalent to NULL)
	// TEST("[%p]", "%p", ptr3);              // Arbitrary address

	// // Integer tests (%d and %i are the same)
	// // Basic tests
	// TEST("[%d] -> 42", "%d", 42);
	// TEST("[%d] -> -42", "%d", -42);
	// TEST("[%d] -> 0", "%d", 0);
	// TEST("[%d] -> INT_MAX", "%d", 2147483647);
	// TEST("[%d] -> INT_MIN", "%d", -2147483648);
	// // Width tests
	// TEST("[%10d] -> 42", "%10d", 42);   // Right-aligned, padded with spaces
	// TEST("[%10d] -> -42", "%10d", -42); // Right-aligned, padded with spaces
	// TEST("[%10d] -> 0", "%10d", 0);     // Right-aligned zero
	// TEST("[%-10d] -> 42", "%-10d", 42); // Left-aligned
	// TEST("[%-10d] -> -42", "%-10d", -42);
	// // Zero padding tests
	// TEST("[%010d] -> 42", "%010d", 42);   // Zero-padded
	// TEST("[%010d] -> -42", "%010d", -42); // Zero-padded negative
	// TEST("[%-010d] -> 42", "%010d", 42); // Zero-padded left-aligned
	// // space tests
	// TEST("[% 10d] -> -42", "% 10d", -42); // Zero-padded negative
	// // Precision tests
	// TEST("[%.5d] -> 42", "%.5d", 42);   // Precision larger than number
	// TEST("[%.5d] -> -42", "%.5d", -42); // Precision larger than negative number
	// TEST("[%.5d] -> 0", "%.5d", 0);     // Precision with zero
	// TEST("[%10.5d] -> 42", "%10.5d", 42);   // Width & precision
	// TEST("[%10.5d] -> -42", "%10.5d", -42); // Width & precision
	// // Precision zero tests
	// TEST("[%.0d] -> 0", "%.0d", 0);     // Empty string for zero with precision 0
	// TEST("[%10.0d] -> 0", "%10.0d", 0); // Width with precision zero
	// // Sign tests
	// TEST("[%+d] -> 42", "%+d", 42);   // Explicit +
	// TEST("[%+d] -> -42", "%+d", -42); // Explicit + (should be ignored for negatives)
	// TEST("[% d] -> 42", "% d", 42);   // Space flag
	// TEST("[% d] -> -42", "% d", -42); // Space flag (ignored for negatives)
	// TEST("%03.d, %02.d, %01.d, %01.d, %01.d, %01.d, %01.d, %01.d", "%03.d, %02.d, %01.d, %01.d, %01.d, %01.d, %01.d, %01.d", 0, 5, -1, -10, 100, -1862, INT_MIN, INT_MAX);


	// Unsigned integer test
	// TEST("[%u] -> 42", "%u", 42);
	// TEST("[%u] -> 0", "%u", 0);
	// TEST("[%u] -> 4294967295U", "%u", 4294967295U);  // Max unsigned int (32-bit)
	// TEST("[%5u] -> 42", "%5u", 42);  // Width smaller than number
	// TEST("[%10u] -> 42", "%10u", 42);  // Width larger than number
	// TEST("[%-10u] -> 42", "%-10u", 42);  // Left-align
	// TEST("[%010u] -> 42", "%010u", 42);  // Zero-padding
	// TEST("[%.5u] -> 42", "%.5u", 42);  // Precision larger than number
	// TEST("[%10.5u] -> 42", "%10.5u", 42);  // Width + Precision
	// TEST("[%.0u] -> 0", "%.0u", 0);  // Precision with zero
	// TEST("[%10.0u] -> 0", "%10.0u", 0);  // Width + Zero Precision


	// Hexadecimal tests
	// Basic cases
	// TEST("[%x] -> 42", "%x", 42);
	// TEST("[%X] -> 42", "%X", 42);
	// TEST("[%x] -> 0", "%x", 0);
	// TEST("[%X] -> 0", "%X", 0);
	// // Width handling
	// TEST("[%10x] -> 42", "%10x", 42);
	// TEST("[%10X] -> 42", "%10X", 42);
	// TEST("[%1x] -> 42", "%1x", 42);
	// TEST("[%5x] -> 0", "%5x", 0);  
	// // Zero paddign
	// TEST("[%010x] -> 42", "%010x", 42);
	// TEST("[%010X] -> 42", "%010X", 42);
	// TEST("[%05x] -> 0", "%05x", 0);
	// TEST("[%05d] -> 0", "%05d", 0);
	// // Precision handling
	// TEST("[%.5x] -> 42", "%.5x", 42);
	// TEST("[%.3x] -> 42", "%.3x", 42);
	// TEST("[%.0x] -> 0", "%.0x", 0);  // Edge case: `%x` with `.0` should print nothing
	// // Zero Padding Ignored When Precision is Set
	// TEST("[%010.5x] -> 42", "%010.5x", 42);  
	// TEST("[%08.4x] -> 42", "%08.4x", 42);  
	// TEST("[%010.0x] -> 42", "%010.0x", 42);  
	// // Left align
	// TEST("[%-10x] -> 42", "%-10x", 42);
	// TEST("[%-10X] -> 42", "%-10X", 42);
	// // Alter form
	// TEST("[%#x] -> 42", "%#x", 42);  
	// TEST("[%#X] -> 42", "%#X", 42);  
	// TEST("[%#10x] -> 42", "%#10x", 42);
	// TEST("[%#010x] -> 42", "%#010x", 42);  
	// TEST("[%#08.4x] -> 42", "%#08.4x", 42);
	// // Large and edge values
	// TEST("[%x] -> UINT_MAX", "%x", 4294967295U);  
	// TEST("[%X] -> UINT_MAX", "%X", 4294967295U);  
	// TEST("[%10x] -> UINT_MAX", "%10x", 4294967295U);  
	// TEST("[%#x] -> UINT_MAX", "%#x", 4294967295U);  
	// TEST("[%#10x] -> UINT_MAX", "%#10x", 4294967295U);  
	// TEST("[ %#x ] -> 0", " %#x ", 0);
	TEST("complex","%#5x", 0);

	// // Mixed tests
	// TEST("%s %d letter(s) of alphabet?", "%s %d letter(s) of alphabet?", "First", 2);

	return (0);
}
