NAME = libft.a

SRC = src
OBJ = obj
INCLUDE = include

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

sources = src/ctype/ft_isalpha.c src/ctype/ft_isdigit.c src/ctype/ft_isalnum.c \
					src/ctype/ft_isascii.c src/ctype/ft_isprint.c src/ctype/ft_tolower.c \
					src/ctype/ft_toupper.c
objects = $(sources:$(SRC)/%.c=$(OBJ)/%.o)

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(objects)
	ar rcs $(NAME) $(objects)

all: $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	@echo "Running norminette..."
	$(NORM) $(NORM_FLAGS) $(sources)

.PHONY: all clean fclean re