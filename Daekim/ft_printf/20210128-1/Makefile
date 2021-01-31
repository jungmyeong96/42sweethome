# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 14:50:24 by daekim            #+#    #+#              #
#    Updated: 2021/01/22 21:35:31 by daekim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

CC =		gcc

CFLAGS =	-Wall -Werror -Wextra 

SRCS =		ft_printf.c \

OBJS =		*(SRCO: .c=.o)

all :		$(NAME)

$(NAME) :	#(OBJS)
			ar rc $(NAME) $(OBJS)

clean :
			rm -f $(OBJS)

fclean :	clean
			rm -f $(NAME)

re : 		fclean all
