/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weapon.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:48:57 by daekim            #+#    #+#             */
/*   Updated: 2021/03/16 06:46:18 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_in_weapon(t_info *p, t_img *img, int n)
{
	int	y;
	int	x;
	int	z;
	int	w;

	z = 0;
	y = p->data.win_h - img->img_h;
	while (y < p->data.win_h)
	{
		y = p->data.win_h - img->img_h + z;
		w = 0;
		x = p->data.win_w - img->img_w;
		while (x < p->data.win_w && z < img->img_h && w < img->img_w)
		{
			x = p->data.win_w - img->img_w + w;
			if (p->texture[n][img->img_w * z + w] != -16777216)
				p->buf[y][x] = p->texture[n][img->img_w * z + w];
			w++;
		}
		z++;
	}
	free(p->texture[n]);
	p->texture[n] = 0;
}

void	show_weapon(t_info *p, t_img *img, char *path)
{
	int		x;
	int		y;

	img->img_p = mlx_xpm_file_to_image(p->mlx_p,
			path, &img->img_w, &img->img_h);
	img->data = (int *)mlx_get_data_addr(img->img_p,
			&img->bpp, &img->size_l, &img->endian);
	tex_wh(p, 15, img);
	y = -1;
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
			p->texture[15][img->img_w * y + x] =
				img->data[img->img_w * y + x];
	}
	mlx_destroy_image(p->mlx_p, img->img_p);
	put_in_weapon(p, img, 15);
}

void		weapon(t_info *p)
{
	t_img	i;

	if (p->skill_t == 0)
		show_weapon(p, &i, p->dis_wp);
	if (p->skill1 == 1)
		attack(p, &i, "./tex/tree_st.xpm");
}
