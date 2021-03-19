/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:48:57 by daekim            #+#    #+#             */
/*   Updated: 2021/03/16 06:46:18 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_yorn(t_info *p, t_img *i, int n, char *path)
{
	int	y;
	int	x;

	y = -1;
	p->yorn = 1;
	while (++y < i->img_h)
	{
		x = -1;
		while (++x < i->img_w)
		{
			if (p->texture[n][i->img_w * y + x] != -16777216)
				p->buf[y + (int)(p->data.win_h * 0.125)]
					[x + (int)(p->data.win_w * 0.125)] =
					p->texture[n][i->img_w * y + x];
		}
	}
	if (p->key_o == 1)
		next_stage(p, path);
}

void	show_yorn(t_info *p, t_img *img, char *path)
{
	int		x;
	int		y;

	img->img_p = mlx_xpm_file_to_image(p->mlx_p,
			path, &img->img_w, &img->img_h);
	img->data = (int *)mlx_get_data_addr(img->img_p,
			&img->bpp, &img->size_l, &img->endian);
	tex_wh(p, 8, img);
	y = -1;
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
			p->texture[8][img->img_w * y + x] =
				img->data[img->img_w * y + x];
	}
	mlx_destroy_image(p->mlx_p, img->img_p);
	if (p->hp <= 0)
		put_yorn(p, img, 8, "elinia.cub");
	else if (p->level_up == 1)
		put_yorn(p, img, 8, p->stage);
}

