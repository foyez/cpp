NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c srcs/ft_swap.c
OBJS = $(SRCS:.c=.o)
INCS = includes

.o: .c
	$(CC) $(CFLAGS) -I$(INCS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)
	ranlib $(NAME)

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re