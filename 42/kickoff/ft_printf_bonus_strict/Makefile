# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/19 21:57:58 by kaahmed           #+#    #+#              #
#    Updated: 2025/04/21 17:02:45 by kaahmed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
NAME_LIBFT = libft.a

SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
LIBFT_DIR = libft

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INC_DIR)

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

SRC_FILES = $(SRC_DIR)/ft_printf.c
HEADER_FILES = $(INC_DIR)/ft_printf.h

OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(NAME_LIBFT) $(OBJ_FILES) $(HEADER_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

$(NAME_LIBFT):
	make -C $(LIBFT_DIR)
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

testlib: $(NAME)
	@echo "Compiling and running..."
	$(CC) -I $(INC_DIR) -Wno-format tests/testlib.c -L. -lftprintf -o myprogram.out
	./myprogram.out

norm:
	@echo "Running norminette..."
	$(NORM) $(NORM_FLAGS) $(SRC_FILES) $(HEADER_FILES)

.PHONY: all clean fclean re testlib test norm