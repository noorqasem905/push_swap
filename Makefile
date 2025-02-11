CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = push_swap
SRCS =	src/push_swap.c 		\
		src/utils.c				\
		src/sorting_tools.c		\
		src/get_cost.c			\
		src/handling.c			\
		src/prepare_sorting.c	\
		src/setup_list.c		\
		src/setup_sorting.c
all: $(NAME)

CC = @cc
RM = @rm -f

OBJS =  $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@make -s -C libft
	@cc $(CFLAGS) $(SRCS) -o $(NAME) -Llibft -lft -g

clean:
	@rm -f $(OBJS)
	@make clean -s -C libft
fclean: clean
	@make fclean -s -C libft
	@rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
