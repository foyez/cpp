#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_WORD_LEN 50
#define MAX_MAPPINGS 100

// Structure to map numbers to words
typedef struct
{
	long long		number;
	char			word[MAX_WORD_LEN];
}					NumWordMap;

// Function to load mappings from the file
int	load_mappings(const char *filename, NumWordMap *mappings)
{
	int		fd;
	char	buffer[4096];
	ssize_t	bytes_read;
	int		mapping_count;
	char	*line_start;
	char	*colon;
	int		j;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error opening file\n", 19);
		return (-1);
	}
	bytes_read = read(fd, buffer, sizeof(buffer) - 1);
	if (bytes_read < 0)
	{
		write(2, "Error reading file\n", 19);
		close(fd);
		return (-1);
	}
	buffer[bytes_read] = '\0';
	close(fd);
	// Parse the buffer
	mapping_count = 0;
	line_start = buffer;
	for (ssize_t i = 0; i <= bytes_read; ++i)
	{
		if (buffer[i] == '\n' || buffer[i] == '\0')
		{
			buffer[i] = '\0'; // Null-terminate the line
			colon = NULL;
			for (char *p = line_start; *p; ++p)
			{
				if (*p == ':')
				{
					colon = p;
					break ;
				}
			}
			if (colon)
			{
				*colon = '\0'; // Split number and word
				mappings[mapping_count].number = atoll(line_start);
				char *word_start = colon + 2; // Skip ": "
				j = 0;
				while (*word_start && j < MAX_WORD_LEN - 1)
				{
					mappings[mapping_count].word[j++] = *word_start++;
				}
				mappings[mapping_count].word[j] = '\0';
				mapping_count++;
			}
			line_start = buffer + i + 1;
		}
	}
	return (mapping_count);
}

// Function to find the word for a number
const char	*find_word(NumWordMap *mappings, int mapping_count, long long num)
{
	for (int i = 0; i < mapping_count; ++i)
	{
		if (mappings[i].number == num)
		{
			return (mappings[i].word);
		}
	}
	return (NULL);
}

unsigned long long	powers_of_ten[] = {
	1,                // 10^0
	10,               // 10^1
	100,              // 10^2
	1000,             // 10^3 (thousand)
	1000000,          // 10^6 (million)
	1000000000,       // 10^9 (billion)
	1000000000000,    // 10^12 (trillion)
	1000000000000000, // 10^15 (quadrillion)
};

void	print_number_in_words(NumWordMap *mappings, int mapping_count,
		long long num)
{
	const char	*word = NULL;
	int			is_first;
	long long	divisor;
	long long	count;
	long long	teen_number;

	if (num == 0)
	{
		word = find_word(mappings, mapping_count, 0);
		if (word)
		{
			write(1, word, MAX_WORD_LEN);
			write(1, "\n", 1);
		}
		return ;
	}
	is_first = 1;
	for (int i = 7; i >= 0; --i)
	{
		divisor = powers_of_ten[i];
		count = num / divisor;
		num %= divisor;
		if (count > 0)
		{
			if (!is_first)
			{
				write(1, " ", 1); // Add a space before the next word
			}
			is_first = 0;
			if (divisor >= 100)
			{
				// Handle thousands and hundreds
				word = find_word(mappings, mapping_count, count);
				if (word)
				{
					write(1, word, MAX_WORD_LEN);
				}
				word = find_word(mappings, mapping_count, divisor);
				if (word)
				{
					write(1, " ", 1);
					write(1, word, MAX_WORD_LEN);
				}
			}
			else if (divisor == 10 && count == 1)
			{
				// Handle special case for numbers 11-19
				teen_number = count * 10 + num;
				// Combine tens and units
				word = find_word(mappings, mapping_count, teen_number);
				if (word)
				{
					write(1, word, MAX_WORD_LEN);
				}
				return ; // Processing complete
			}
			else if (divisor == 10)
			{
				// Handle tens (20, 30, ...)
				word = find_word(mappings, mapping_count, count * 10);
				if (word)
				{
					write(1, word, MAX_WORD_LEN);
				}
			}
			else
			{
				// Handle units
				word = find_word(mappings, mapping_count, count);
				if (word)
				{
					write(1, word, MAX_WORD_LEN);
				}
			}
		}
	}
	write(1, "\n", 1);
}

int	main(void)
{
	NumWordMap	mappings[MAX_MAPPINGS];
	int			mapping_count;
	long long	input_number;

	// Load mappings
	mapping_count = load_mappings("numbers.dict", mappings);
	if (mapping_count < 0)
	{
		return (1);
	}
	// Input number
	// input_number = 1234567890;
	// print_number_in_words(mappings, mapping_count, input_number);
	// input_number = 5012;
	// print_number_in_words(mappings, mapping_count, input_number);
	input_number = 4103;
	print_number_in_words(mappings, mapping_count, input_number);
	return (0);
}
