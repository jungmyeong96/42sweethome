/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:19:11 by junghan           #+#    #+#             */
/*   Updated: 2021/03/12 03:49:43 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TEXWID 64
#define TEXHEI 64
#define MAPWID 24
#define MAPHEI 24
#define UDIV 1
#define VDIV 1

typedef struct	s_img
{
	void	*img;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;
}				t_img;

typedef struct s_fcrgb
{
	int			c_rgb;
	int			f_rgb;
	int			color_f;
	int			color_c;
}				t_fcrgb;


typedef struct s_floor
{
	float	ray_dirx1;
	float	ray_diry1;
	float	ray_dirx2;
	float	ray_diry2;
	float	row_dist;
	float	floorstep_x;
	float	floorstep_y;
	float	floor_x;
	float	floor_y;
	int		cell_x;
	int		cell_y;
	int 	tex_x;
	int		tex_y;
	int		check_pat;
	int		f_tex;
	int		c_tex;
	int		color;
}				t_floor;

typedef struct s_wall
{
	double	cam_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	sidedist_x;
	double	sidedist_y;
	double	deltadist_x;
	double	deltadist_y;
	double	perpwall_d;
	int		step_x;
	int		step_y;
	int		hit; 
	int		side;
	int		line_hei;
	int		drawstart;
	int		drawend;
	int		tex_num;
	double	wall_tmp; 
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;
	double	distw;
	double	distp;
	double	cur_d;
	double	weight;
	double	cur_fx;
	double	cur_fy;
	double	floor_xw;
	double	floor_yw;
	int		floor_xt;
	int		floor_yt;
}			t_wall;

typedef struct	s_sprite
{
	double	sprite_x;
	double	sprite_y;
	double	invdet; 
	double	transf_x;
	double	transf_y; 
	int		sprite_scr_x;
	int		vmove_scr;
	int		sprite_hei; 
	int		drawstart_x;
	int		drawstart_y;
	int		drawend_x;
	int		drawend_y;
	int		sprite_wid;
	int		tex_x;
	int		tex_Y;//
	int		di; 
	int		color;
	double	vmove;
	int		*sprite_ord;
	double	*sprite_dist;
}		t_sprite;

typedef struct	s_s
{
	double		x;
	double		y;
	int			tex;
}				t_s;

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

typedef struct	s_keys
{
	int		key_a;
	int		key_w;
	int		key_s;
	int		key_d;
	int		key_right;
	int		key_left;
	int		key_p;
	int		key_r;
	int		key_f;
	int		key_up;
	int		key_down;
	int		key_ws;
	int		key_sw;
	int		key_ad;
	int		key_da;
	int		key_qe;
	int		key_eq;
	int		key_esc;
	int		zero_p;
	int		zero_p2;
	int		move_p;
	double	move_speed;
	double	rot_speed;
}				t_keys;

typedef struct	s_info
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	void	*mlx;
	void	*win;
	t_keys	keys;
	t_img	img;
	int		fd;
	int		win_wid;
	int		win_hei;
	char	**map;
	int		**buf;
	int		sp_count;
	int		is_save;
	int		map_lines;
	t_save	save;
	t_fcrgb	fcrgb;
	t_sprite	sprite;
	t_floor		floor;
	double	*z_buffer;
	t_s		*sprite_arr;
	int		*check_ele;
	int		mou_lr;
	int		mou_ud;
	int		point;
	float	pos_z;
	double	pitch;
	int		texture[11][TEXHEI * TEXWID];
}				t_info;
