SRC		= main.c algo.c algo2.c error_handling.c extract_first_line.c memory.c utils.c variables.c parsing_in_tab.c

OBJS	= ${SRC:.c=.o}

NAME	= BSQ

CC		= cc

RM		= rm -f

CFLAGS	= -Wall -Wextra -Werror

.c.o:
					${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
					${CC} ${CFLAGS} -o ${NAME} ${OBJS}

all:		${NAME}

clean:
					${RM} ${OBJS}

fclean:		clean
					${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all
