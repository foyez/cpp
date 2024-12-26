NAME = rush-02

CFLAGS = -Wall -Wextra -Werror
CC = cc

SRC = src
INCLUDE = include
OBJ = obj

# list all files matching pattern recursively
# e.g. List all *.c files in src/ folder
rfindfiles = $(shell find $(1) -type f -name '$(2)')

# Find all .c and .h files
# e.g. src/**/*.c, includes/**/*.h
sources = $(call rfindfiles,$(SRC),*.c)
headers = $(call rfindfiles,$(INCLUDE),*.h)

# Generate object file path for each source file
# e.g. src/main.c src/dict/dict.c => obj/main.o obj/dict/dict.o
objects = $(sources:$(SRC)/%.c=$(OBJ)/%.o)

# create object files directory if it doesn't exist
# e.g. src/dict/dict.c (src/dict/dict.h) => obj/dict/dict.o
$(OBJ)/%.o: $(SRC)/%.c $(headers)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

# compile the program
# e.g. obj/main.o obj/dict/dict.o => rush-02
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
