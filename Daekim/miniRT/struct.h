/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:33:22 by daekim            #+#    #+#             */
/*   Updated: 2021/02/24 19:54:13 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minirt.h"

typedef struct	s_vec
{
	double		x;
	double		y;
	double		z;
}				t_vec;

typedef struct	s_mlx
{
	void		*mlx_p;
	void		*win_p;
	void		*img_p;
	int			*data;
	int			bpp;
	int			size_l;
	int			endian;
	int			p_color;
	t_vec		color;
}				t_mlx;

typedef struct	s_img
{
	double		rate;
	int			img_w;
	int			img_h;
	int			sample;
	int			depth;
}				t_img;

typedef struct	s_ray
{
	t_vec		orig;
	t_vec		dir;
}				t_ray;

typedef struct	s_camera
{
	double		view_w;
	double		view_h;
	double		focal_len;
	t_vec		vertical;
	t_vec		horizontal;
	t_vec		lower_left_corner;
	t_vec		origin;
	t_vec		focal;
}				t_cam;

typedef struct	s_hit_record
{
	t_vec		p;
	t_vec		norm;
	int			*mat_ptr;
	double		t;
	int			front;
}				t_hit_re;

typedef struct	s_sphere
{
	t_vec		center;
	double		radius;
}				t_sp;

#endif
