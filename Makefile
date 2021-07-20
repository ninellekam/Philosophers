NAME 	=		philo
SRCS 	=		src/eat_forks_sleep.c\
				src/finish.c\
				src/init.c\
				src/utilites.c\
				src/threads.c

OBJS 	=		${SRCS:.c=.o}
FLAGS 	=		 -Wall -Wextra -Werror
CC 		=		gcc

all:	$(OBJS)
		@$(CC) $(OBJS) $(FLAGS) -o $(NAME)

clean:		
		@$(RM) $(OBJS)

fclean:	clean
		@rm -rf $(NAME)
		@rm *.o

re:		@fclean all

.PHONY: all clean fclean re run