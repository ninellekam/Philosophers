NAME =		philo
SRCS =		src/eat_forks_sleep.c

OBJS =		${SRCS:.c=.o}		
FLAGS =		 -g -MMD -pthread
CC =		gcc

%.o: %.c
			$(CC) $(FLAGS) -c $< -o $@

$(NAME):	${OBJS} 
			$(CC) $(OBJS)  -o $(NAME)

all:		$(NAME)

clean:		
			$(RM) $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

norm:		fclean
			norminette ./*.c 

run:		
			make re
			make clean
			./phil 5 800 200 200


.PHONY: all clean fclean re run bonus a