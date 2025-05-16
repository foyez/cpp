NAME						= libutils.a
COMB_DIR				= tmp_comb

# ft_printf library
FT_PRINTF_NAME	= libftprintf.a
FT_PRINTF_DIR		= ft_printf
FT_PRINTF				= $(FT_PRINTF_DIR)/$(FT_PRINTF_NAME)

# gnl library
GNL_NAME				= libftgnl.a
GNL_DIR					= get_next_line
GNL							= $(GNL_DIR)/$(GNL_NAME)

# ===Colors===
PURPLE		:= \033[95m
GREEN		:= \033[92m
RED 		:= \033[91m
RESET		:= \033[0m

define print_green
	@printf "$(GREEN)$(1)\n$(RESET)"
endef

# $(1): Output archive (e.g., lib/libutils.a)
# $(2): Archive to merge (e.g., lib/libft.a)
# $(3): Directory name (e.g., tmp_comb/)
define merge_libs
	$(call print_green,Merging $(2) into $(1)...)
	@mkdir -p $(3)

	@cd $(3) && ar x ../$(2)
	@ar t $(2) > $(3)/object.list

	@cd $(3) && while read f; do ar r ../$(1) "$$f"; done < object.list
	@ranlib $(1)
	@rm -rf $(3)
endef

all: $(NAME)

$(NAME): $(FT_PRINTF) $(GNL)
	$(call print_green,Creating $@ by merging $^...)
	@cp $(FT_PRINTF) $(NAME)

	$(call merge_libs,$(NAME),$(GNL),$(COMB_DIR))

$(FT_PRINTF):
	@$(MAKE) -C $(FT_PRINTF_DIR)

$(GNL):
	@$(MAKE) -C $(GNL_DIR)

clean:
	@$(MAKE) -C $(FT_PRINTF_DIR) clean
	@$(MAKE) -C $(GNL_DIR) clean

fclean:
	@$(MAKE) -C $(FT_PRINTF_DIR) fclean
	@$(MAKE) -C $(GNL_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re