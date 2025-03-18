NAME = libft.a
TEST_BINARY = test_binary

OBJ_DIR = obj
TEST_DIR = tests

CC = cc
CFLAGS = -Wall -Wextra -Werror
CMOCKA_FLAGS = `pkg-config --cflags --libs cmocka`

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

SRC_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
			ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
			ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c \
			ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
			ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c
SRC_BONUS_FILES = ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c \
				  ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c \
				  ft_lstmap_bonus.c
HEADER_FILES = libft.h

OBJ_FILES = $(SRC_FILES:%.c=$(OBJ_DIR)/%.o)
OBJ_BONUS_FILES = $(SRC_BONUS_FILES:%.c=$(OBJ_DIR)/%.o)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ_FILES)
	ar rcs $(NAME) $(OBJ_FILES)

# Command to compile the test suite
$(TEST_BINARY): $(TEST_DIR)/testsuite.c $(NAME) bonus
	$(CC) $(CFLAGS) $(TEST_DIR)/testsuite.c -o $(TEST_BINARY) $(CMOCKA_FLAGS) \
	-L. -lft

# Target to run tests
test: $(TEST_BINARY)
	@echo "Running tests..."
	./$(TEST_BINARY)

all: $(NAME)

bonus: $(OBJ_FILES) $(OBJ_BONUS_FILES)
	ar rcs $(NAME) $(OBJ_FILES) $(OBJ_BONUS_FILES)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME) $(TEST_BINARY)

re: fclean all

norm:
	@echo "Running norminette..."
	$(NORM) $(NORM_FLAGS) $(SRC_FILES) $(SRC_BONUS_FILES) $(HEADER_FILES)

.PHONY: all clean fclean re bonus norm test