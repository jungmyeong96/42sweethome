# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 14:50:24 by daekim            #+#    #+#              #
#    Updated: 2021/01/30 17:34:11 by daekim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		libftprintf.a

CC =		gcc

CFLAGS =	-Wall -Werror -Wextra 

INC_L =		-I./includes

LIB =		-L./libft -lft

SRCS =		ft_printf.c printf_opt.c \
			put_pcsp.c put_diux.c \
			conv_num.c str_print.c \
			libft/ft_strdup.c libft/ft_calloc.c libft/ft_bzero.c\
			libft/ft_strlen.c libft/ft_toupper.c \

OBJS =		$(SRCS:.c=.o)

all :		$(NAME)

$(NAME) :	$(OBJS) libft
			ar rcs $(NAME) $(OBJS)

.o.c :		
			$(CC) $(CFLAGS) $(INC_L) -c $< -o $(<:.c=.o)
			
libft :
			$(MAKE) -C ./libft all 

clean :
			$(MAKE) -C ./libft clean
			rm -f $(OBJS)

fclean :	clean
			rm -f $(NAME)
			$(MAKE) -C ./libft fclean

re : 		fclean all

.PHONY :	all clean fclean re libft 
