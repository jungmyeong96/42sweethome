/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:22:19 by daekim            #+#    #+#             */
/*   Updated: 2021/02/27 09:25:35 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define X_KEY_PRESS	2
# define X_KEY_release	3
# define X_KEY_EXIT		17

# define mapWidth		24
# define mapHeight		24
# define win_w			640
# define win_h			480
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


# include "struct.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <math.h>

int			k_press(int key, t_info *p);
void		calc_wa(t_info *p);
void		verLine(t_info *p, int x, int st, int en, int color);
void		color_wall(t_info *p);
void		cal_in(t_info *p, t_cal *c, t_spr *sp, int x);
void		draw(t_info *p);
void		tex_wall(t_info *p);
void		calc_fl(t_info *p);
void		calc_sp(t_info *p);
int			worldMap[mapWidth][mapHeight];
//double		sprite[num_sp][3];
void		in_sprite(t_info *p);
t_s			sprite[num_sp];


#endif
