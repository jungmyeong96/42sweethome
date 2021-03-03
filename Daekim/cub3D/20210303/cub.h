/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:22:19 by daekim            #+#    #+#             */
/*   Updated: 2021/03/03 18:30:38 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define X_KEY_PRESS		2
# define X_KEY_RELEASE	3
# define X_KEY_EXIT		17


# define mapWidth		24
# define mapHeight		24
# define tex_w			64
# define tex_h			64
# define num_sp			19

# define KEY_ESC		53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LT			123	
# define KEY_RT			124


# include "struct.h"
# include "mlx/mlx.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

int			k_press(t_info *p);
void		calc_wa(t_info *p);
void		verline(t_info *p, int x, int st, int en, int color);
void		color_wall(t_info *p);
void		cal_in(t_info *p, t_cal *c, t_spr *sp, int x);
void		draw(t_info *p);
void		tex_wall(t_info *p);
void		calc_fl(t_info *p);
void		calc_sp(t_info *p);
int			worldmap[mapWidth][mapHeight];
void		in_sprite(t_info *p);
t_s			sprite[num_sp];
void		sort_double(double *tab, int size);
void		sort_int(int *tab, int size);
void		sort_sp(double *tap1, int *tap2, int size);
void		tex_in(t_info *p, int *tex, char *path, t_img *i);
void		putstr_err(char *str);
int			ft_keypress(int key, t_info *p);
int			key_press_A(int key, t_info *p);
int			key_release_A(int key, t_info *p);
void		key_save(int *in_key, char *save_key, int i, char j);
void		maping(t_info *p);
void		get_file(t_info *p);
int			format(char *s1, char *s2);
void		free_dou(char **str);
void		check_char(int c);
void		start_dir(t_info *p, char c, int y, int x);
int			get_next_line(int fd, char **line);

#endif
