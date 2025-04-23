# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 21:57:58 by kaahmed           #+#    #+#              #
#    Updated: 2025/04/23 23:28:08 by kaahmed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAME_LIBFT = libft.a

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
LIBFT_DIR = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -I $(INC_DIR)
VALGRIND_ARGS = --leak-check=full --show-leak-kinds=all --track-origins=yes -s

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

SRC_FILES = $(SRC_DIR)/ft_printf.c $(SRC_DIR)/parse_flags.c $(SRC_DIR)/handle_format.c \
						$(SRC_DIR)/print_char.c $(SRC_DIR)/print_str.c $(SRC_DIR)/print_ptr.c \
						$(SRC_DIR)/print_nbr.c $(SRC_DIR)/print_unsigned.c $(SRC_DIR)/print_hex.c \
						$(SRC_DIR)/ft_put_utils.c $(SRC_DIR)/utils.c
HEADER_FILES = $(INC_DIR)/ft_printf.h

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(NAME_LIBFT) $(OBJ_FILES) $(HEADER_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(NAME_LIBFT):
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(NAME_LIBFT) .
	mv $(NAME_LIBFT) $(NAME)

all: $(NAME)

bonus: all

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	rm -f myprogram.out test_ft_printf.out

re: fclean all

norm:
	@echo "Running norminette..."
	$(NORM) $(NORM_FLAGS) $(SRC_FILES) $(HEADER_FILES)

build: $(NAME)
	$(CC) -I $(INC_DIR) tests/test_main.c -L. -lftprintf -o test_main.out
	
run: build
	@echo "Running the app..."
	./test_main.out
	
debug: fclean
	$(MAKE) all
	@echo "Running debugging using lldb"
	$(CC) -I $(INC_DIR) -g tests/test_main.c -L. -lftprintf -o test_main.out
	lldb ./test_main.out

valgrind:
	@echo "Running valgrind..."
	@docker run -it --rm \
	-v $(shell pwd):/valgrind \
	-w /valgrind \
	--name valgrind \
	valgrind:1.0 \
	sh -c '\
		make -s fclean && \
		make -s build && \
		valgrind $(VALGRIND_ARGS) ./test_main.out \
	'

.PHONY: all clean fclean re norm build run debug valgrind