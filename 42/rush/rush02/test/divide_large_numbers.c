#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to subtract two numbers represented as strings
void	subtract_strings(char *num1, const char *num2, char *result)
{
	int		len1;
	int		len2;
	int		carry;
	int		i;
	int		digit1;
	int		digit2;
	int		diff;
	char	temp;
	int		k;
	int		j;

	i = len1 - 1, j;
	i = len1 - 1, j = len2 - 1, k;
	len1 = strlen(num1);
	len2 = strlen(num2);
	carry = 0;
	i = len1 - 1, j = len2 - 1, k = 0;
	// Perform subtraction digit by digit
	while (i >= 0 || j >= 0 || carry)
	{
		digit1 = (i >= 0) ? num1[i] - '0' : 0;
		digit2 = (j >= 0) ? num2[j] - '0' : 0;
		diff = digit1 - digit2 - carry;
		if (diff < 0)
		{
			diff += 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		result[k++] = diff + '0';
		i--;
		j--;
	}
	result[k] = '\0';
	// Reverse the result string (subtraction happens from right to left)
	for (int i = 0, j = strlen(result) - 1; i < j; i++, j--)
	{
		temp = result[i];
		result[i] = result[j];
		result[j] = temp;
	}
}

// Helper function to compare two large numbers (strings)
int	compare_strings(const char *num1, const char *num2)
{
	int	len1;
	int	len2;

	len1 = strlen(num1);
	len2 = strlen(num2);
	// First compare lengths
	if (len1 > len2)
		return (1);
	if (len1 < len2)
		return (-1);
	// If lengths are equal, compare digit by digit
	return (strcmp(num1, num2));
}

// Function to divide a large number (num_str) by a divisor (divisor_str)
void	divide_large_numbers(const char *num_str, const char *divisor_str,
		char *quotient, char *remainder)
{
	int	len_num;
	int	len_div;
	int	remainder_len;
	int	quotient_digit;

	len_num = strlen(num_str);
	len_div = strlen(divisor_str);
	// Initialize quotient and remainder
	quotient[0] = '0';
	quotient[1] = '\0'; // Start with zero quotient
	strcpy(remainder, num_str);
	// If divisor is larger than num, quotient is 0 and remainder is num_str
	if (compare_strings(remainder, divisor_str) < 0)
	{
		return ; // No division performed
	}
	// For each digit in the dividend (num_str), process the division
	char temp[1000]; // Temporary remainder
	int q_len = 0;   // Quotient length
	for (int i = 0; i < len_num; i++)
	{
		// Append current digit of num_str to the remainder
		remainder_len = strlen(remainder);
		temp[remainder_len] = num_str[i];
		temp[remainder_len + 1] = '\0';
		// Subtract divisor from the temporary remainder until it is smaller than divisor
		if (compare_strings(temp, divisor_str) >= 0)
		{
			quotient_digit = 0;
			// Keep subtracting divisor from temp
			while (compare_strings(temp, divisor_str) >= 0)
			{
				subtract_strings(temp, divisor_str, temp);
				quotient_digit++;
			}
			// Store quotient digit
			quotient[q_len++] = quotient_digit + '0';
			quotient[q_len] = '\0'; // Null-terminate
		}
		else
		{
			// If temp is smaller than divisor, add 0 to quotient
			if (q_len > 0)
			{
				quotient[q_len++] = '0';
				quotient[q_len] = '\0';
			}
		}
	}
	// If quotient is empty, set it to "0"
	if (q_len == 0)
	{
		quotient[0] = '0';
		quotient[1] = '\0';
	}
	// Final remainder
	strcpy(remainder, temp);
}
