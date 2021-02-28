/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 23:59:10 by daekim            #+#    #+#             */
/*   Updated: 2021/02/26 04:01:07 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct	s_img
{
	void		*img_p;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			img_w;
	int			img_h;
	int			row_count;
	int			col_count;
	int			color;
}				t_img;

typedef	struct	s_cal
{
	double		cameraX;
	double		rayDirX;
	double		rayDirY;
	int			mapX;
	int			mapY;
	double		sideX;
	double		sideY;
	double		deltaX;
	double		deltaY;
	double		wall;
	int			stepX;
	int			stepY;
	int			hit;
	int			side;
	int			tex_num;
	int			wall_x;
	int			tex_x;
	int			tex_y;
	double		step;
	double		tex_pos;
	int			line_h;
	int			draw_st;
	int			draw_en;
	int			color;
}				t_cal;

typedef struct	s_info
{
	void		*mlx_p;
	void		*win_p;
	double		posX;
	double		posY;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		oldDirX;
	double		oldPlaneX;
	double		move;
	double		rot;
	int			buf[win_h][win_w];
	int			texture[8][tex_h * tex_w];
	t_img		img;
	t_cal		cal;
}				t_info;

typedef struct	s_param
{
	int			x;
	int			y;
	char		str[3];
}				t_param;

