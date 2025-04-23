# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kaahmed <kaahmed@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/23 23:30:17 by kaahmed           #+#    #+#              #
#    Updated: 2025/04/23 23:48:28 by kaahmed          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libgnl.a
BINARY = test_main.out

OBJ_DIR = obj

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
VALGRIND_ARGS = --leak-check=full --show-leak-kinds=all --track-origins=yes -s

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

SRC_FILES = get_next_line.c get_next_line_utils.c
HEADER_FILES = get_next_line.h

OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

all: $(NAME)

bonus: all

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(BINARY)

re: fclean all

norm:
	@echo "Running norminette..."
	$(NORM) $(NORM_FLAGS) $(SRC_FILES) $(HEADER_FILES)

build: $(NAME)
	$(CC) tests/test_main.c $(NAME) -o $(BINARY)
	
run: build
	@echo "Running the app..."
	./$(BINARY)
	
debug: fclean
	$(MAKE) all
	@echo "Running debugging using lldb"
	$(CC) -I $(INC_DIR) -g tests/test_main.c $(NAME) -o $(BINARY)
	lldb ./$(BINARY)

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
		valgrind $(VALGRIND_ARGS) ./$(BINARY) \
	'

.PHONY: all clean fclean re norm build run debug valgrind