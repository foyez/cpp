NAME = libft.a

SRCS = srcs
INCS = includes
OBJ = obj

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCS)

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

# List all files matching the pattern recursively
# rfiles = $(shell find $(1) -type f -name '$(2)')
# List all .c and .h files
# e.g. srcs/**/*.c, includes/**/*.h
# sources = $(call rfiles,$(SRCS),*.c)
# headers = $(call rfiles,$(INCS),*.h)

sources = $(SRCS)/ft_putchar.c $(SRCS)/ft_putstr.c $(SRCS)/ft_strcmp.c \
		  $(SRCS)/ft_strlen.c $(SRCS)/ft_swap.c
headers = $(INCS)/ft.h

# Convert .c filenames into .o filenames
# e.g. srcs/ft_putchar.c → obj/ft_putchar.o
objects = $(sources:$(SRCS)/%.c=$(OBJ)/%.o)

all: $(NAME)

# Create obj/ directory if it doesn't exist
# Compile each .c file to .o file into obj/
# e.g. srcs/ft_putstr.c (includes/ft.h) → obj/ft_putstr.o
$(OBJ)/%.o: $(SRCS)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile binary from all .o files
# e.g. obj/ft_putchar.o obj/ft_putstr.o → libft.a
$(NAME): $(objects)
	ar rcs $(NAME) $(objects)
# $(CC) $(CFLAGS) -o $(NAME) $(objects)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	@echo "Running norminette..."
	$(NORM) $(NORM_FLAGS) $(sources) $(headers)

.PHONY: all clean fclean re norm