# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 14:50:24 by daekim            #+#    #+#              #
#    Updated: 2021/01/28 22:58:39 by daekim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

CC =		gcc

CFLAGS =	-Wall -Werror -Wextra 

SRCS =		ft_printf.c printf_opt.c \
			put_pcsp.c put_diux.c \
			conv_num.c str_print.c \
			libft/ft_strdup.c libft/ft_strlen.c libft/ft_calloc.c \

OBJS =		$(SRCO: .c=.o)

all :		$(NAME)

$(NAME) :	#(OBJS)
			ar rc $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean :
			rm -f $(OBJS)

fclean :	clean
			rm -f $(NAME)

re : 		fclean all
