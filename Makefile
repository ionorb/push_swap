NAME		= 	push_swap.a

SRCS		= 	display.c ft_atoi.c initialize.c main.c operations.c parsing.c\
				sort_big.c sort_small.c stack_utils.c utils.c

OBJS		= 	$(SRCS:.c=.o)

CC			= 	gcc

CCFLAGS 	= 	-Wall -Wextra -Werror

.c.o:
		$(CC) $(CCFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

bonus:		$(BONUS_OBJS)
			ar rcs $(NAME) $(BONUS_OBJS)

all:		$(NAME)

clean:
		rm -f $(OBJS) $(BONUS_OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
