// A number that is a power of 2 has exactly one bit set in binary.
// e.g. 2 = 10, 4 = 100, 8 = 1000
// Subtracting 1 from such a number flips all the bits after the set bit (inclusive).
// e.g. 1 = 01, 3 = 011, 7 = 0111
// So n & (n - 1) will be 0 only when n is a power of 2.
// We also check n != 0 because 0 & (0 - 1) is 0, but 0 is not a power of 2.
int	    is_power_of_2(unsigned int n)
{
	return n != 0 && (n & (n - 1)) == 0;
}


#include <stdio.h>
int main()
{
	printf("%d", is_power_of_2(16));
}
