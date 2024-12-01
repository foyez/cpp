NAME = rush-02

CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = src
INCLUDE = include
OBJ = obj

# list all files matching pattern recursively
rfindfiles = $(shell find $(1) -type f -name '$(2)')

# Find all .c and .h files
sources := $(call rfindfiles,$(SRC),*.c)
headers := $(call rfindfiles,$(INCLUDE),*.h)

# Convert c files to o files
objects := $(sources:$(SRC)/%.c=$(OBJ)/%.o)

# create object files directory if it doesn't exist
$(OBJ)/%.o: $(SRC)/%.c $(headers)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

# compile the program
$(NAME): $(objects)
	$(CC) $(CFLAGS) -o $(NAME) $(objects)

# Clean up object files
clean:
	rm -rf $(OBJ)

# Clean up everything (object files and binary)
fclean: clean
	rm -f $(NAME)

# Rule to remake everything
re: fclean $(NAME)

# Phony targets
.PHONY: all clean fclean re
