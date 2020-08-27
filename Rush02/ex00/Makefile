SRC		= main.c solve.c solve2.c solve3.c parsing.c utils.c utils2.c

OBJS	= ${SRC:.c=.o}

NAME	= rush-02

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
