/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:18:11 by daekim            #+#    #+#             */
/*   Updated: 2021/03/02 04:17:14 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

typedef struct	s_img
{
	void		*img_p;
	int			*data;
	int			img_w;
	int			img_h;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_cal2
{
	double		rayX0;
	double		rayY0;
	double		rayX1;
	double		rayY1;
	int			per;
	double		row;
	double		f_stepX;
	double		f_stepY;
	double		floorX;
	double		floorY;
	int			cellX;
	int			cellY;
	int			tx;
	int			ty;
	int			f_tex;
	int			c_tex;
	int			color_f;
	int			ch_pat;
}				t_cal2;

typedef struct	s_cal
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
	int			line_h;
	int			draw_st;
	int			draw_en;
	int			color;
	double		step;
	int			tex_n;
	double		wallX;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
}				t_cal;

typedef struct	s_s
{
	double		x;
	double		y;
	int			tex;
}				t_s;

typedef struct	s_sprite
{
	double		Zbuf[win_w];
	int			sp_ord[num_sp];
	double		sp_dis[num_sp];
	double		spX;
	double		spY;
	double		mat;
	double		transX;
	double		transY;
	int			screenX;
	int			sp_h;
	int			sp_w;
	int			dr_stY;
	int			dr_enY;
	int			dr_stX;
	int			dr_enX;
	int			tex_x;
	int			tex_y;
	int			d;
	int			color3;
	int			uDiv;
	int			vDiv;
	double		v_move;
	int			move_sc;
}				t_spr;
/*
typedef struct	s_data
{
	int			fd;
	char		*line;
	char		**map;
	int			win_w;
	int			win_h;
	char		*path;
}				t_data;
*/
typedef struct	s_info
{
	void		*mlx_p;
	void		*win_p;
	double		posX;
	double		posY;
	double		posZ;
	double		dirX;
	double		dirY;
	double		planeX;
	double		planeY;
	double		o_dirX;
	double		o_planeX;
	double		move;
	double		rot;
	int			buf[win_h][win_w];
	int			texture[11][tex_w * tex_h];
	int			*key_p;
	t_cal		cal;
	t_cal2		cal2;
	t_spr		sp;
	t_img		img;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_a;
	int			key_e;
	int			key_q;
	int			key_al;
	int			key_ar;
	char		key_ws;
	char		key_ad;
	char		key_qe;
	char		key_A;
	int			key_set;
//	t_data		data;
}				t_info;
