/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:33:22 by daekim            #+#    #+#             */
/*   Updated: 2021/02/24 04:27:41 by daekim           ###   ########.fr       */
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

typedef struct	s_ray
{
	t_vec		orig;
	t_vec		dir;
}				t_ray;

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

typedef struct	s_hittable
{
	t_sp		sp[2];
//	t_vec		col[4];
}				t_hittable;

typedef struct	s_camera
{
	double		view_h;
	double		view_w;
	double		focal_len;

	t_vec		orig;
	t_vec		hori;
	t_vec		ver;
	t_vec		focal;
	t_vec		corner;
}				t_camera;

#endif
