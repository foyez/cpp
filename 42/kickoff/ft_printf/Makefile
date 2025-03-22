NAME = libftprintf.a

SRC = src
OBJ = obj
INCLUDE = include

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

# List all files matching the pattern recursively
rfiles = $(shell find $(1) -type f -name '$(2)')

# List all .c and .h files
# e.g. src/**/*.c, include/**/*.h
sources = $(call rfiles,$(SRC),*.c)
headers = $(call rfiles,$(INCLUDE),*.h)

# Convert .c filenames into .o filenames
# e.g. src/ft_isalpha.c → obj/ft_isalpha.o
objects = $(sources:$(SRC)/%.c=$(OBJ)/%.o)

# Compile any .c file in src/ to a .o file in obj/
# e.g. src/ft_isalpha.c → obj/ft_isalpha.o
$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile binary from all .o files
# e.g. obj/ft_isalpha.o, obj/ft_isdigit → libft.a
$(NAME): $(objects)
	ar rcs $(NAME) $(objects)

all: $(NAME)

clean:
	@echo cleaning obj/ directory...
	rm -rf $(OBJ)

fclean: clean
	@echo cleaning .o files and library file...
	rm -f $(NAME)

re: fclean all

run: $(objects)
	$(CC) $(CFLAGS) $(objects) -o myprogram.out

norm:
	@echo "Running norminette on all .c and .h files..."
	$(NORM) $(NORM_FLAGS) $(sources) $(headers)

.PHONY: all clean fclean re