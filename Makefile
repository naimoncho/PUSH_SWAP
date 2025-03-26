NAME = push_swap

# COLORS
RED		=	\033[91;1m
GREEN	=	\033[92;1m
CLEAR	=	\033[0m

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address
CC = cc
RM = rm -f

LIBFTA = libft/libft.a

SRCS = main.c push.c reverse_rotate.c rotate.c swap.c stack_init.c alg_stack.c cost_set.c stack_utils.c find_sort.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make all -sC ./libft
	@echo "$(GREEN)Compiling Libft.$(CLEAR)"
	@$(CC) $(CFLAGS) $(OBJS) -I ../push_swap.h $(LIBFTA) -o $(NAME)
	@echo "$(GREEN)Push Swap Compiled.$(CLEAR)"

clean:
	@$(RM) $(OBJS)
	@make clean -sC libft
	@echo "$(RED)All Objs Deleted.$(CLEAR)"

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFTA)
	@echo "$(RED)Everything Deleted.$(CLEAR)"

re: fclean all

.PHONY: all clean fclean re
