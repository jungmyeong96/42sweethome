# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 16:07:58 by junghan           #+#    #+#              #
#    Updated: 2021/01/29 14:04:06 by junghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_parse_arg.c ft_manage_spec.c \
	   ft_init_info.c ft_check_info.c ft_chg_to_hex.c \
	   ft_apply_to_spec.c ft_apply_to_spec2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

$(NAME):$(OBJS) libft
	ar rcs $(NAME) $(OBJS)

libft:
	$(MAKE) -C ./LIBFT all

clean:
	$(MAKE) -C ./LIBFT clean
	rm -f $(OBJS) $(B_OBJS)
	
fclean:
	$(MAKE) -C ./LIBFT fclean
	rm -f $(NAME)

re: fclean all

.PHONY: libft clean fclean all re
