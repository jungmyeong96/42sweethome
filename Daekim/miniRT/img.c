/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 18:11:27 by daekim            #+#    #+#             */
/*   Updated: 2021/02/25 18:25:19 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		sky(t_mlx *app, t_img *img, t_cam c)
{
	c.view_h = 2.0;
	c.view_w = c.view_w * img->rate;
	c.focal_len = 1.0;
	
	c.origin = v_cre(0.0, 0.0, 0.0);
	c.horizontal = v_cre(c.view_w, 0.0, 0.0);
	c.vertical = v_cre(0.0, c.view_h, 0.0);
	c.focal = v_cre(0.0, 0.0, c.focal_len);
	c.lower_left_corner = v_sub(c.origin, v_add(v_add(v_div(2, c.horizontal),
					v_div(2, c.vertical)), c.focal));
	
	out_color(app, img, c);
}

void		gradation(t_mlx *app, t_img *img)
{
	t_vec	color;
	int		i;
	int		j;
	int		c;

	j = -1;
	while (++j < img->img_h)
	{
		i = -1;
		while (++i < img->img_w)
		{
			double r = (double)i / (img->img_w - 1);
			double g = (img->img_h - (double)j - 1) / (img->img_h - 1);
			double b = 0.25;
			int	ir = 255.999 * r;
			int	ig = 255.999 * g;
			int	ib = 255.999 * b;

			color.x = ir * 256 * 256;
			color.y = ig * 256;
			color.z = ib;
			c = color.x + color.y + color.z;
			app->data[j * img->img_w  + i] = mlx_get_color_value(app->mlx_p, c);
		}
	}
}
