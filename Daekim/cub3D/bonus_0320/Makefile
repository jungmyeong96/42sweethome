# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/22 14:50:24 by daekim            #+#    #+#              #
#    Updated: 2021/03/16 18:57:43 by daekim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =		cub3D

LIBFT =		libft/libft.a

MLX = 		mlx/libmlx.dylib

SRCS =		start.c ft_save.c ft_free.c ft_shadow.c \
			ft_get_data1.c ft_utils.c ft_get_data2.c ft_butpress.c \
			ft_keydir.c ft_cal_fc.c ft_map.c ft_cal_sp.c ft_mouse.c \
			ft_cal_w1.c ft_move1.c ft_cal_w2.c ft_move2.c \
			ft_cal_wfc.c ft_move3.c ft_char_n_sp.c ft_perf.c ft_dir.c \
			ft_press.c ./gnl/get_next_line.c ./gnl/get_next_line_utils.c \
			ft_draw_n_tex_in.c ft_yorn.c \
			ft_hp_bar.c ft_info.c ft_minimap.c ft_stage.c \

OBJS =		$(SRCS:.c=.o)

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror -O3 -fsanitize=address

MLXFLAGS =	-framework OpenGL -framework Appkit

INSTALL = 	install_name_tool -change libmlx.dylib $(MLX) $(NAME)

all :		$(NAME)

$(NAME) :	$(OBJS) $(LIBFT) $(MLX)
			cp $(MLX) ./
			cp $(LIBFT) ./
			$(CC) $(CFLAGS) -L./mlx -lmlx $(MLXFLAGS) -L./libft -lft -o $(NAME) $(OBJS)

$(LIBFT) :		
			$(MAKE) -C ./libft all

$(MLX) :
			$(MAKE) -C ./mlx all

clean :
			rm -f $(OBJS)
			$(MAKE) -C ./libft clean
			$(MAKE) -C ./mlx clean

fclean :	clean
			rm -f libft.a libmlx.dylib
			$(MAKE) -C ./libft fclean
			rm -f $(NAME)

re : 		fclean all

.PHONY :	all clean fclean re
