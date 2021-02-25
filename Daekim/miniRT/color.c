/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:30:09 by daekim            #+#    #+#             */
/*   Updated: 2021/02/25 18:38:35 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		ray_color(t_vec orig, t_vec dir)
{
	double	t;
	t_vec 	unit_dir;
	t_vec	col1;
	t_vec	col2;
	
	unit_dir = unit_vec(dir);
	t = 0.5 * (unit_dir.y + 1.0);
	col1 = v_cre(1.0, 1.0, 1.0);
	col2 = v_cre(0.5, 0.7, 1.0);
	return (v_add(v_mul2(1.0 - t, col1), v_mul2(t, col2)));
}

void		write_color(t_mlx *app, t_vec c)
{
	int		ir;
	int		ig;
 	int		ib;	

	ig = 255.999 * c.x;
	ig = 255.999 * c.y;
	ib = 255.999 * c.z;

	app->color.x = ir * 256 * 256;
	app->color.y = ig * 256;
	app->color.z = ib;
	app->p_color = app->color.x + app->color.y + app->color.z;
}

void		out_color(t_mlx *app, t_img *img, t_cam c)
{
	int		i;
	int		j;
	double	u;
	double	v;
	t_vec	a;
	t_vec	b;
	t_vec	pixel_color;

	j = -1;
	while (++j < img->img_h - 1)
	{
		i = -1;
		while (++i < img->img_w - 1)
		{	
			u = (double)i / (img->img_w - 1);
			v = (double)(img->img_h - 1 - (double)j) / (img->img_h - 1);
			a = c.origin;
			b = v_add(c.lower_left_corner, v_add(v_mul2(u, c.horizontal),
						v_mul2(v, v_sub(c.vertical, c.origin))));
			pixel_color = ray_color(a, b);
			write_color(app, pixel_color);
			mlx_pixel_put(app->mlx_p, app->win_p, i, j, app->p_color);
			app->data[j * img->img_w + i] = app->p_color;
		}
	}
}
