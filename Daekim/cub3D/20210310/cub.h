/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:22:19 by daekim            #+#    #+#             */
/*   Updated: 2021/03/10 04:17:47 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define X_KEY_PRESS	2
# define X_KEY_RELEASE	3
# define X_BUT_PRESS	4
# define X_KEY_EXIT		17

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

int			ft_press(t_info *p);
int			butpress(int key, t_info *p);
int			k_press(t_info *p);
int			key_press_aa(int key, t_info *p);
int			key_release_aa(int key, t_info *p);
void		key_save(int *in_key, char *save_key, int i, char j);

void		calc_fl(t_info *p);
void		calc_sp(t_info *p);
void		calc_wa(t_info *p);
void		cal_in(t_info *p, t_cal *c, t_spr *sp, int x);
void		draw(t_info *p);
void		sort_sp(double *tap1, int *tap2, int size);
void		tex_in(t_info *p, int n, char *path, t_img *i);

void		putstr_err(char *str);
void		maping(t_info *p);
void		get_file(t_info *p);
int			format(char *s1, char *s2);
void		free_one(char *str);
void		free_dou(char **str);
void		check_char(int c);
void		start_dir(t_info *p, char c, int y, int x);
int			get_next_line(int fd, char **line);
void		get_sp(t_info *p, char **d);

void		col_or_xpm(t_info *p, char *d, int n);
void		fc_color(t_info *p, char *rgb_data, int n);
void		tex_data(t_info *p, char *xpm_p, int n);
void		screen_size(t_info *p, char *w, char *h);
void		save_bmp(t_info *p);
void		buf_mal(t_info *p);
int			is_space(char *d, t_info *p);

int		mouse_move(int x, int y, t_info *p);

#endif
