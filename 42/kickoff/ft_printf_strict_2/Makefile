CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a
INCLUDES = -I$(LIBFT_DIR) -I.
REMOVE = rm -rf

MY_C_SOURCES =	ft_printf.c \
				ft_printf_int_handling.c \
				ft_printf_ptr_handling.c \
				ft_printf_text_handling.c \
				ft_printf_uint_handling.c
MY_OBJECTS = $(MY_C_SOURCES:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(MY_OBJECTS) $(LIBFT)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(MY_OBJECTS)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	$(REMOVE) $(MY_OBJECTS)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(REMOVE) $(NAME)

re: fclean all

.PHONY: clean fclean all re