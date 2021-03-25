# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/22 16:07:58 by junghan           #+#    #+#              #
#    Updated: 2021/03/25 05:04:54 by junghan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRCS = ft_fc_draw.c ft_make_shadow.c  ft_main_loop.c \
	   ft_calc_sprite.c	ft_free_alloc.c ft_mlx_funcs.c \
	   ft_calc_sprite2.c ft_get_args.c ft_mouse.c \
	   ft_calc_wall.c ft_init.c ft_parse_map.c \
	   ft_calc_wall2.c ft_key_update.c ft_read_mapinfo.c \
	   ft_check_map.c ft_key_update2.c ft_rgb_texture.c \
	   ft_cub_utill.c ft_key_update3.c ft_save_bmp.c \
	   ft_cub_utill2.c ft_pop_up.c ft_minimap.c ft_stage.c\
	   ft_texalloc.c ft_yorn.c ft_alloc.c ft_sp_texture.c \
	   ../gnl/get_next_line.c ../gnl/get_next_line_utils.c \


LIBFT = ../libft

LIBFT_LIB = libft.a

MLX = ../mlx

MLX_LIB = libmlx.dylib

INCS = -I ../libft -I ../gnl -I ../mlx

OBJS = $(SRCS:.c=.o)

MLXFLAGS = -L. -lmlx -framework OpenGL -framework Appkit -L. -lft

RM = rm -f

LIBC = ar rc

CC = gcc

CFLAGS = -Wall -Wextra -Werror -O3 -g3 -fsanitize=address

$(NAME): $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	$(CC) $(CFLAGS) $(MLXFLAGS) -o $(NAME) $(OBJS) $(INCS)

$(LIBFT_LIB):
	make all -C $(LIBFT)
	cp ./$(LIBFT)/$(LIBFT_LIB) ./

$(MLX_LIB):
	make all -C $(MLX)
	cp ./$(MLX)/$(MLX_LIB) ./

all : $(NAME)

clean:
	$(RM) $(OBJS) $(LIBFT_LIB) $(MLX_LIB)
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	
fclean: clean
	$(RM) $(NAME) $(LIBFT_LIB) $(MLX_LIB)
	make fclean -C $(LIBFT)

re: fclean all

.PHONY: libft clean fclean all re
