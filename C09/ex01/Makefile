# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erlajoua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/18 11:18:00 by erlajoua          #+#    #+#              #
#    Updated: 2020/08/19 12:41:45 by erlajoua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR         = ./srcs/

SRC             = ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c

SRCS = ${addprefix ${SRC_DIR}, ${SRC}}

HEADERS = ./includes

OBJS = ${SRCS:.c=.o}

NAME = libft.a

CC = gcc

CFLAGS = -Wall -Werror -Wextra

RM = rm -rf

AR = ar rc

LIB = ranlib

.c.o:
	${CC} ${CFLAGS} -c -I ${HEADERS} $< -o ${<:.c=.o}

${NAME}:    ${OBJS}
	${AR} ${NAME} ${OBJS}
	${LIB} ${NAME}

all:        ${NAME}

clean:
	${RM} ${OBJS}

fclean:     clean
	${RM} ${NAME}

re:         fclean all
