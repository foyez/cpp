#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Updated get_number_word function
int	get_number_word(int number, const char *filePath, char *output,
		size_t outputSize)
{
	int		fd;
	ssize_t	bytesRead;
	size_t	bufferIndex;
	char	key[10];
	char	*wordStart;

	char buffer[256]; // Buffer to hold a single line of the file
	fd = open(filePath, O_RDONLY);
	if (fd == -1)
	{
		perror("Error opening file");
		return (-1); // Indicate failure
	}
	bufferIndex = 0;
	// Read the file line by line
	while ((bytesRead = read(fd, buffer + bufferIndex, 1)) > 0)
	{
		if (buffer[bufferIndex] == '\n' || bufferIndex == sizeof(buffer) - 2)
		{
			// Null-terminate the line
			buffer[bufferIndex + 1] = '\0';
			// Check if the line starts with the desired number
			sprintf(key, "%d: ", number); // Format "67: "
			if (strncmp(buffer, key, strlen(key)) == 0)
			{
				// Extract the word after ": "
				wordStart = buffer + strlen(key);
				strncpy(output, wordStart, outputSize - 1);
				output[outputSize - 1] = '\0'; // Ensure null termination
				output[strcspn(output, "\n")] = '\0';
				// Remove newline character
				close(fd);
				return (0); // Success
			}
			// Reset the buffer index for the next line
			bufferIndex = 0;
		}
		else
		{
			bufferIndex++;
		}
	}
	close(fd);
	return (-1); // Not found
}

void	print_number_words(int number)
{
	const char	*file_path = "dict/en.dict";
	char		tensWord[100] = {0};
	char		unitsWord[100] = {0};

	if (number < 0 || number > 99)
	{
		printf("Only numbers between 0 and 99 are supported.\n");
		return ;
	}
	int tens = number / 10 * 10; // Tens place (e.g., 67 -> 60)
	int units = number % 10;     // Units place (e.g., 67 -> 7)
	// Get the words for tens and units
	if (tens > 0 && get_number_word(tens, file_path, tensWord,
			sizeof(tensWord)) == -1)
	{
		printf("Failed to find word for %d\n", tens);
		return ;
	}
	if (units > 0 && get_number_word(units, file_path, unitsWord,
			sizeof(unitsWord)) == -1)
	{
		printf("Failed to find word for %d\n", units);
		return ;
	}
	if (tensWord[0] && unitsWord[0])
	{
		printf("%s %s\n", tensWord, unitsWord); // Print "sixty seven"
	}
	else if (tensWord[0])
	{
		printf("%s\n", tensWord); // Handle numbers like "60"
	}
	else if (unitsWord[0])
	{
		printf("%s\n", unitsWord); // Handle numbers like "7"
	}
	else
	{
		printf("Number not found in dictionary.\n");
	}
}

// #include <fcntl.h>
// #include <stdio.h>
// #include <unistd.h>

// void	ft_putdicterr(void);

// void	read_dict(int nbr)
// {
// 	const char	*file_path = "dict/en.dict";
// 	int			fd;
// 	char		buffer[1024];
// 	ssize_t		bytes_read;

// 	fd = open(file_path, O_RDONLY);
// 	if (fd == -1)
// 		// return (ft_putdicterr(), "");
// 		ft_putdicterr();
// 	while ((bytes_read = read(fd, buffer, sizeof(buffer) - 1)) > 0)
// 	{
// 		buffer[bytes_read] = '\0';
// 		printf("%s", buffer);
// 	}
// 	if (bytes_read == -1)
// 		// return (ft_putdicterr(), "");
// 		ft_putdicterr();
// 	if (close(fd) == -1)
// 		// return (ft_putdicterr(), "");
// 		ft_putdicterr();
// 	// return (buffer);
// }
