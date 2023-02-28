# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hguillau <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 14:08:24 by hguillau          #+#    #+#              #
#    Updated: 2023/02/28 17:45:21 by hguillau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS1		=		client.c			\
					utils.c				\

SRCS2		=		server.c			\
					utils.c				\

OBJS1		=		${SRCS1:.c=.o}

OBJS2		=		${SRCS2:.c=.o}

NAME1		=		client

NAME2		=		server

CC			=		gcc

RM			=		rm -f

CFLAGS		=		-Wall -Wextra -Werror #-g -fsanitize=address

${NAME2}:		${OBJS2}
				${CC} ${CFLAGS} -o ${NAME2} ${OBJS2}

${NAME1}:		${OBJS1}
				${CC} ${CFLAGS} -o ${NAME1} ${OBJS1}

all:			${NAME1} ${NAME2}

clean:
				${RM} ${OBJS1} ${OBJS2}

fclean:			clean
				${RM} ${NAME1} ${NAME2}

re:				fclean all

.PHONY:			all clean fclean re
