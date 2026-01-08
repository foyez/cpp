# ===Colors===
PURPLE  = \033[95m
GREEN   = \033[92m
RED     = \033[91m
YELLOW  = \033[33m
RESET   = \033[0m

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

# === Config ===
CC            = cc
CFLAGS        = -Wall -Wextra -Werror -I$(INC_DIR)
DEBUG_CFLAGS	= $(CFLAGS) -g -fsanitize=address
VALGRIND_ARGS = \
	--leak-check=full --show-leak-kinds=all --track-origins=yes \
	--trace-children=yes -s
NAME          = philo
SRC_DIR       = src
INC_DIR       = include
OBJ_DIR       = obj

# === Norminette ===
NORM  = norminette

# === Files ===
HEADER_FILES    = philo.h
HEADER_PATHS    = $(addprefix $(INC_DIR)/, $(HEADER_FILES))
SRC_FILES       = \
	args_parser.c init.c simulation.c simulation_utils.c \
	philo_actions.c utils.c
SRC_PATHS       = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJ_PATHS       = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:%.c=%.o))
MAIN_FILE       = main.c
MAIN_PATH       = $(addprefix $(SRC_DIR)/, $(MAIN_FILE))
MAIN_OBJ_PATH   = $(addprefix $(OBJ_DIR)/, $(MAIN_FILE:%.c=%.o))

# === Rules ===
all: $(NAME)

$(NAME): $(OBJ_PATHS) $(MAIN_OBJ_PATH)
	$(call print_compile,$(NAME))
	@$(CC) $(CFLAGS) $(OBJ_PATHS) $(MAIN_OBJ_PATH) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADER_PATHS)
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(call print_red,Cleaning objects...)
	@rm -rf $(OBJ_DIR)

fclean: clean
	$(call print_red,Cleaning files...)
	@rm -rf $(NAME) $(NAME).dSYM

re: fclean all

norm:
	$(call print_green,Running norminette...)
	@$(NORM) $(SRC_PATHS) \
		$(MAIN_PATH) $(HEADER_PATHS)

run: $(NAME)
	@./$(NAME) $(ARGS)

debug: fclean
	$(call print_green,Running debugging using lldb...)
	@$(MAKE) CFLAGS="$(DEBUG_CFLAGS)" all
	@dsymutil $(NAME)
	lldb ./$(NAME)

dv: fclean
	$(call print_green,Running valgrind...)
	@docker run -it --rm \
		-v $(shell pwd):/valgrind \
		-w /valgrind \
		valgrind:1.0 \
		sh -c '\
			make -s CFLAGS="$(DEBUG_CFLAGS)" all && \
			valgrind $(VALGRIND_ARGS) ./$(NAME) $(ARGS) \
		'

.PHONY: all clean fclean re norm run debug dv
