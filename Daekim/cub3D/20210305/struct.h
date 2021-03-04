/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:18:11 by daekim            #+#    #+#             */
/*   Updated: 2021/03/05 03:13:05 by daekim           ###   ########.fr       */
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
	double		ray_x0;
	double		ray_y0;
	double		ray_x1;
	double		ray_y1;
	int			per;
	double		row;
	double		f_step_x;
	double		f_step_y;
	double		floor_x;
	double		floor_y;
	int			cell_x;
	int			cell_y;
	int			tx;
	int			ty;
	int			f_tex;
	int			c_tex;
	int			color_f;
	int			ch_pat;
}				t_cal2;

typedef struct	s_cal
{
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		side_x;
	double		side_y;
	double		delta_x;
	double		delta_y;
	double		wall;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_h;
	int			draw_st;
	int			draw_en;
	int			color;
	double		step;
	int			tex_n;
	double		wall_x;
	int			tex_x;
	int			tex_y;
	double		tex_pos;
	int			c_rgb;
	int			f_rgb;
	int			color_f;
	int			color_c;
}				t_cal;

typedef struct	s_s
{
	int			x;
	int			y;
	int			tex;
}				t_s;

typedef struct	s_sprite
{
	double		*zbuf;
	int			sp_ord[num_sp];
	double		sp_dis[num_sp];
	double		sp_x;
	double		sp_y;
	double		mat;
	double		trans_x;
	double		trans_y;
	int			screen_x;
	int			sp_h;
	int			sp_w;
	int			dr_st_y;
	int			dr_en_y;
	int			dr_st_x;
	int			dr_en_x;
	int			tex_x;
	int			tex_y;
	int			d;
	int			color3;
	int			udiv;
	int			vdiv;
	double		v_move;
	int			move_sc;
}				t_spr;

typedef struct	s_data
{
	int			fd;
	char		**map;
	int			win_w;
	int			win_h;
	char		*path;
}				t_data;

typedef struct		s_save
{

	int				size_b;
	char			*bmp;
	unsigned char	header[14];
	unsigned char	data[40];
	unsigned char	pad[3];
	int				color_b;
	int				fd_b;
}					t_save;


typedef struct	s_info
{
	void		*mlx_p;
	void		*win_p;
	double		pos_x;
	double		pos_y;
	double		pos_z;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		o_dir_x;
	double		o_plane_x;
	double		move;
	double		rot;
	int			**buf;
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
	char		key_aa;
	int			key_set;
	t_data		data;
	t_s			*sprite;
	int			sp_count;
	int			is_save;
	t_save		save;
}				t_info;
