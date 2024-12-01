NAME = rush-02

CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = src
INCLUDE = include
OBJ = $(SRC:.c=.o)

# list all files matching pattern recursively
rfindfiles = $(shell find $(1) -type f -name '$(2)')

# Find all .c and .h files
sources := $(call rfindfiles,$(SRC),*.c)
headers := $(call rfindfiles,$(INCLUDE),*.h)

# Convert c files to o files
objects := $(sources:$(SRC)/%.c=$(OBJ)/%.o)

# create object files directory if it doesn't exist
$(OBJ)/%.o: $(SRC)/%.c $(headers)
	@mkdir -p $(OBJ)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

# Compile binary from all o files
$(NAME): $(objects)
	$(CC) $(CFLAGS) -o $(NAME) $(objects)

# create object files
$(OBJ)/%.o: $(SRC)/%.c $(INCLUDE)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -rf $(OBJ)

# Clean up everything (object files and binary)
fclean: clean
	rm -f $(NAME)

# remake everything
re: fclean $(NAME)

.PHONY: all clean fclean re
