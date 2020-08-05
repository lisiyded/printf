# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: spowers <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/05 22:02:17 by spowers           #+#    #+#              #
#    Updated: 2020/08/05 22:02:22 by spowers          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_convert_utils.c ft_convert_utils2.c ft_convert.c \
 	   ft_flags_printf.c  ft_lst_printf.c     ft_printf_utils.c \
	   ft_printf_utils2.c ft_printf_utils3.c  ft_printf.c

DEP = ft_printf.h

OBJS = ${SRCS:.c=.o}

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

LIB = ar rc

.c.o : ${DEP}
		gcc ${CFLAGS} -c $< -o ${<:.c=.o}

all : 		${NAME}

${NAME}:	${OBJS}
			${LIB} ${NAME} ${OBJS}

clean :
			${RM} ${OBJS}
fclean :	clean
			${RM} ${NAME}

re :		fclean all
