/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 05:17:11 by daekim            #+#    #+#             */
/*   Updated: 2021/02/26 06:01:56 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_release	3
# define X_EVENT_KEY_EXIT		17

# define mapWidth		24
# define mapHeight		24
# define win_w			640
# define win_h			480
# define tex_w			64
# define tex_h			64

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
# include <unistd.h>

int			key_press(int key, t_info *p);
void		calc(t_info *p);
void		cal_in(t_info *p, t_cal *c, int x);
void		color_wall(t_info *p);
void		draw(t_info *p);
void		verLine(t_info *p, int x, int y1, int y2, int color);
void		tex_wall(t_info *p);

int worldMap[mapWidth][mapHeight];


#endif
