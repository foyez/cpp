# === Config ===
NAME        = push_swap
SRC_DIR     = src
INC_DIR     = include
OBJ_DIR     = obj

BONUS_NAME	= checker
BONUS_DIR		= bonus

LIBUTILS_DIR   = lib
LIBUTILS_NAME  = libutils.a
LIBUTILS			= $(LIBUTILS_DIR)/$(LIBUTILS_NAME)

CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g -I $(INC_DIR)
VALGRIND_ARGS	= --leak-check=full --show-leak-kinds=all --track-origins=yes -s

NORM        = norminette
NORM_FLAGS  = -R CheckForbiddenSourceHeader -R CheckDefine

# ===Files===
HEADER_FILES = push_swap.h
HEADER_PATHS = $(addprefix $(INC_DIR)/, $(HEADER_FILES))
SRC_FILES = \
	algorithm/sort.c algorithm/rotations.c algorithm/cost_calc.c \
	algorithm/median.c
SRC_PATHS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_FILES = $(SRC_FILES:%.c=%.o)
OBJ_PATHS = $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

COMMON_FILES = \
	check_args/parse_args.c check_args/validate_args.c \
	operation/swap.c operation/push.c operation/rotate.c \
	operation/reverse_rotate.c operation/util.c utils/sort_utils.c \
	utils/stack.c utils/utils.c utils/stack_utils.c
COMMON_PATHS = $(addprefix $(SRC_DIR)/, $(COMMON_FILES))
COMMON_OBJ_FILES = $(COMMON_FILES:%.c=%.o)
COMMON_OBJ_PATHS = $(addprefix $(OBJ_DIR)/, $(COMMON_OBJ_FILES))

MAIN_FILE 		= main.c
MAIN_PATH		= $(addprefix $(SRC_DIR)/, $(MAIN_FILE))
MAIN_OBJ_FILE	= $(MAIN_FILE:%.c=%.o)
MAIN_OBJ_PATH	= $(addprefix $(OBJ_DIR)/, $(MAIN_OBJ_FILE))

BONUS_FILES		= main.c checker.c
BONUS_PATHS		= $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))
BONUS_OBJ_FILES	= $(BONUS_FILES:%.c=%.o)
BONUS_OBJ_PATHS	= $(addprefix $(OBJ_DIR)/$(BONUS_DIR)/, $(BONUS_OBJ_FILES))

# ===Colors===
PURPLE		:= \033[95m
GREEN		:= \033[92m
RED 		:= \033[91m
RESET		:= \033[0m

# ===Functions===
define print_compile
	@printf "\n$(PURPLE)"; \
	printf "  ██████╗\n"; \
	printf "  ██╔═══ \n"; \
	printf "  ██║    \n"; \
	printf "  ██║    \n"; \
	printf "  ██████║\n"; \
	printf "  ╚═════╝\n"; \
	printf "Creating $(1)...\n"; \
	printf "$(RESET)"
endef

define print_green
	@printf "$(GREEN)$(1)\n$(RESET)"
endef

define print_red
	@printf "$(RED)$(1)\n$(RESET)"
endef

# ===Rules===
all: $(NAME)

# Always link .o first, then libraries (.a) later
$(NAME): $(OBJ_PATHS) $(COMMON_OBJ_PATHS) $(MAIN_OBJ_PATH) $(LIBUTILS)
	$(call print_compile,$(NAME))
	@$(CC) $(CFLAGS) \
		$(OBJ_PATHS) $(COMMON_OBJ_PATHS) $(MAIN_OBJ_PATH) $(LIBUTILS) \
		-o $(NAME)

$(LIBUTILS):
	@$(MAKE) -C $(LIBUTILS_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_PATHS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ_PATHS) $(COMMON_OBJ_PATHS) $(LIBUTILS)
	$(call print_compile,$(BONUS_NAME))
	@$(CC) $(CFLAGS) $(BONUS_OBJ_PATHS) $(COMMON_OBJ_PATHS) $(LIBUTILS) -o $(BONUS_NAME)

$(OBJ_DIR)/$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(call print_red,Cleaning objects...)
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBUTILS_DIR) clean

fclean: clean
	$(call print_red,Cleaning files...)
	@rm -rf $(NAME) $(BONUS_NAME) $(NAME).dSYM $(TEST_NAME) $(TEST_NAME).dSYM
	@$(MAKE) -C $(LIBUTILS_DIR) fclean

re: fclean all

norm:
	$(call print_green,Running norminette...)
	@$(NORM) $(NORM_FLAGS) $(SRC_PATHS) $(COMMON_PATHS) \
	$(MAIN_PATH) $(HEADER_PATHS) $(BONUS_PATHS) $(BONUS_DIR)/checker.h
	
run: $(NAME)
	@./$(NAME)
	
debug: fclean all
	$(call print_green,Running debugging using lldb...)
	lldb ./$(NAME)

valgrind: fclean
	$(call print_green,Running valgrind...)
	@docker run -it --rm \
		-v $(shell pwd):/valgrind \
		-w /valgrind \
		valgrind:1.0 \
		sh -c '\
			make -s all && \
			valgrind $(VALGRIND_ARGS) ./$(NAME) "1 2" 5 "-2 -30 50" \
		'

# === Test Config ===
TEST_NAME		= test_push_swap
TEST_DIR		= tests
TEST_SRC_FILES	= test_main.c
TEST_OBJ_FILES	= $(TEST_SRC_FILES:%.c=%.o)
TEST_OBJ_PATHS	= $(addprefix $(OBJ_DIR)/$(TEST_DIR)/, $(TEST_OBJ_FILES))

# === Test Rules ===
test: fclean $(OBJ_PATHS) $(TEST_OBJ_PATHS) $(LIBUTILS)
	$(call print_green,Building tests...)
	@$(CC) $(CFLAGS) $(OBJ_PATHS) $(TEST_OBJ_PATHS) $(LIBUTILS) -o $(TEST_NAME)
	./$(TEST_NAME)

$(OBJ_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.c $(HEADER_PATHS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@


.PHONY: all clean fclean re bonus norm run debug valgrind test