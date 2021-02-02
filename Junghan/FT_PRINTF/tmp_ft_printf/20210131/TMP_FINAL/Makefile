# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 16:07:58 by junghan           #+#    #+#              #
#    Updated: 2021/01/31 15:14:38 by junghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_parse_arg.c ft_manage_spec.c \
	   ft_init_info.c ft_check_info.c ft_chg_to_hex.c \
	   ft_apply_to_spec.c ft_apply_to_spec2.c

LIBFT = libft

LIBFT_LIB = libft.a

INCS = .

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o) -I$(INCS)

$(NAME):$(OBJS)
	make all -C $(LIBFT)/
	cp ./$(LIBFT)/$(LIBFT_LIB) $(NAME)
	$(LIBC) $(NAME) $(OBJS)

all : $(NAME)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT)
	
fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: libft clean fclean all re
