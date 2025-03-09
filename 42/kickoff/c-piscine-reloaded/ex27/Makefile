NAME = ft_display_file

SRC = src
INC = include
OBJ = obj

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC)

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

# List all files matching the pattern recursively
rfiles = $(shell find $(1) -type f -name '$(2)')

# List all .c and .h files
# e.g. src/**/*.c, include/**/*.h
sources = $(call rfiles,$(SRC),*.c)
headers = $(call rfiles,$(INC),*.h)

# Convert .c filenames into .o filenames (pattern substitution)
# From sources list, replace $(SRC)/%.c with $(OBJ)/%.o
# e.g. srcs/ft_putchar.c → obj/ft_putchar.o
objects = $(sources:$(SRC)/%.c=$(OBJ)/%.o)

all: $(NAME)

# Create obj/ directory if it doesn't exist
# Compile each .c file to .o file into obj/
# e.g. srcs/ft_putstr.c (includes/ft.h) → obj/ft_putstr.o
$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile binary from all .o files
# e.g. obj/ft_putchar.o obj/ft_putstr.o → ft_display_file
$(NAME): $(objects)
	$(CC) $(CFLAGS) -o $(NAME) $(objects)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	@echo "Running norminette..."
	$(NORM) $(NORM_FLAGS) $(sources) $(headers)

.PHONY: all clean fclean re norm