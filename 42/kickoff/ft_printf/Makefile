NAME = libftprintf.a
BINARY = test_main.out
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
LIBFT_NAME = libft.a
LIBFT_DIR = $(abspath ../libft)
LIBFT = $(LIBFT_DIR)/$(LIBFT_NAME)

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

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	@cp $(LIBFT) $(NAME)
	@ar rcs $(NAME) $(OBJ_FILES)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_FILES)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -rf $(NAME) $(BINARY) $(BINARY).dSYM
	@make fclean -C $(LIBFT_DIR)

re: fclean all

norm:
	@echo "Running norminette..."
	$(NORM) $(NORM_FLAGS) $(SRC_FILES) $(HEADER_FILES)

build: $(NAME)
	$(CC) -I $(INC_DIR) tests/test_main.c $(NAME) -o $(BINARY)
	
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