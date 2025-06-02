# === Config ===
NAME        = pipex
SRC_DIR     = src
INC_DIR     = include
OBJ_DIR     = obj

BONUS_NAME	= pipex_bonus
BONUS_SRC_DIR = src/bonus
BONUS_OBJ_DIR = $(OBJ_DIR)/bonus

LIBUTILS_DIR		= lib
LIBUTILS_NAME		= libutils.a
LIBUTILS				= $(LIBUTILS_DIR)/$(LIBUTILS_NAME)

CC						= cc
CFLAGS				= -Wall -Wextra -Werror -g -I $(INC_DIR)
VALGRIND_ARGS = \
	--leak-check=full --show-leak-kinds=all --track-origins=yes 
	--trace-children=yes -s

NORM        = norminette
NORM_FLAGS  = -R CheckForbiddenSourceHeader -R CheckDefine

# ===Files===
HEADER_FILES	= pipex.h
HEADER_PATHS	= $(addprefix $(INC_DIR)/, $(HEADER_FILES))
SRC_FILES			= \
	split_shell_args.c get_cmd_path.c utils.c \
	shell_args_utils.c
SRC_PATHS			= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_FILES			= $(SRC_FILES:%.c=%.o)
OBJ_PATHS			= $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))

MAIN_FILE 		= main.c
MAIN_PATH			= $(addprefix $(SRC_DIR)/, $(MAIN_FILE))
MAIN_OBJ_FILE	= $(MAIN_FILE:%.c=%.o)
MAIN_OBJ_PATH	= $(addprefix $(OBJ_DIR)/, $(MAIN_OBJ_FILE))

HEADER_BONUS_FILES	= pipex_bonus.h
HEADER_BONUS_PATHS	= $(addprefix $(INC_DIR)/, $(HEADER_BONUS_FILES))
BONUS_FILES			= \
	main_bonus.c split_shell_args_bonus.c get_cmd_path_bonus.c \
	heredoc.c shell_args_utils_bonus.c process_bonus.c \
	utils_bonus.c utils_error_bonus.c
BONUS_PATHS			= $(addprefix $(BONUS_SRC_DIR)/, $(BONUS_FILES))
BONUS_OBJ_FILES	= $(BONUS_FILES:%.c=%.o)
BONUS_OBJ_PATHS	= $(addprefix $(BONUS_OBJ_DIR)/, $(BONUS_OBJ_FILES))

# ===Colors===
PURPLE	= \033[95m
GREEN		= \033[92m
RED 		= \033[91m
YELLOW	= \033[33m
RESET		= \033[0m

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
$(NAME): $(OBJ_PATHS) $(MAIN_OBJ_PATH) $(LIBUTILS)
	$(call print_compile,$(NAME))
	@$(CC) $(CFLAGS)  $(OBJ_PATHS) $(MAIN_OBJ_PATH) $(LIBUTILS) \
		-o $(NAME)

$(LIBUTILS):
	@$(MAKE) -C $(LIBUTILS_DIR) --silent

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_PATHS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ_PATHS) $(LIBUTILS)
	$(call print_compile,$(BONUS_NAME))
	@$(CC) $(CFLAGS) $(BONUS_OBJ_PATHS) $(LIBUTILS) -o $(BONUS_NAME)
	@cp $(BONUS_NAME) $(NAME)

$(BONUS_OBJ_DIR)/%.o: $(BONUS_SRC_DIR)/%.c $(HEADER_BONUS_PATHS)
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
	@$(NORM) $(NORM_FLAGS) $(SRC_PATHS) \
	$(MAIN_PATH) $(HEADER_PATHS) $(BONUS_PATHS) $(HEADER_BONUS_PATHS)
	
run: $(NAME)
	@./$(NAME)
	
debug: fclean all
	$(call print_green,Running debugging using lldb...)
	@dsymutil $(NAME)
	lldb ./$(NAME)

dv: fclean
	$(call print_green,Running valgrind...)
	@docker run -it --rm \
		-v $(shell pwd):/valgrind \
		-w /valgrind \
		valgrind:1.0 \
		sh -c '\
			make -s bonus && \
			valgrind $(VALGRIND_ARGS) ./$(BONUS_NAME) tests/input.txt ls fs tests/output.txt \
		'

.PHONY: all clean fclean re bonus norm run debug dv