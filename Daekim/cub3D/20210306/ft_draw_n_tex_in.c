/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_n_tex_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 22:49:28 by daekim            #+#    #+#             */
/*   Updated: 2021/03/06 04:47:11 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		tex_in(t_info *p, int *tex, char *path, t_img *i)
{
	int		x;
	int		y;

	i->img_p = mlx_xpm_file_to_image(p->mlx_p, path, &i->img_w, &i->img_h);
	i->data = (int *)mlx_get_data_addr(i->img_p, &i->bpp, &i->size_l,
			&i->endian);
	y = -1;
	while (++y < i->img_h)
	{
		x = -1;
		while (++x < i->img_w)
			tex[i->img_w * y + x] = i->data[i->img_w * y + x];
	}
	mlx_destroy_image(p->mlx_p, i->img_p);
}

void		draw(t_info *p)
{
	int		x;
	int		y;

	y = -1;
	while (++y < p->data.win_h)
	{
		x = -1;
		while (++x < p->data.win_w)
		{
			p->img.data[y * p->data.win_w + x] = p->buf[y][x];
			p->buf[y][x] = 0;
		}
	}
	mlx_put_image_to_window(p->mlx_p, p->win_p, p->img.img_p, 0, 0);
}
