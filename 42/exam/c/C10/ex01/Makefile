NAME = ft_cat

SRC = src
INCLUDE = includes
OBJ = obj

CC = cc
CFLAGS = -Wall -Wextra -Werror -I $(INCLUDE)

NORM = norminette
NORM_FLAGS = -R CheckForbiddenSourceHeader -R CheckDefine

rfiles = $(shell find $(1) -type f -name '$(2)')

sources = $(call rfiles,$(SRC),*.c)
# headers = $(call rfiles,$(INCLUDE),*.h)
objects = $(sources:$(SRC)/%.c=$(OBJ)/%.o)

all: $(NAME)

$(OBJ)/%.o: $(SRC)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(objects)
	$(CC) $(CFLAGS) -o $(NAME) $(objects)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	@echo "Running norminette..."
	$(NORM) $(NORM_FLAGS) $(sources) $(headers)

.PHONY: all clean fclean re norm
