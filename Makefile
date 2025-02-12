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
SRCS_BONUS = src_bonus/checker_bonus.c	\
			 src_bonus/utils.c			\
			 src_bonus/handling.c		\
			 src_bonus/setup_list.c		\
			 src_bonus/sorting_tools.c
all: $(NAME)

CC = cc
RM = rm -f

OBJS =  $(SRCS:.c=.o)
OBJSB =  $(SRCS_BONUS:.c=.o)

$(NAME): $(OBJS) $(OBJSB)
	make -C libft
	cc $(CFLAGS) $(SRCS) -o $(NAME) -Llibft -lft -g
	cc $(CFLAGS) $(SRCS_BONUS) -o checker -Llibft -lft -g
clean:
	rm -f $(OBJS) $(OBJSB)
	make clean -C libft
fclean: clean
	make fclean -C libft
	rm -f $(NAME)
re: fclean all

.PHONY: all clean fclean re
