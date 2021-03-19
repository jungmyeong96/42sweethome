/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hp_bar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:48:57 by daekim            #+#    #+#             */
/*   Updated: 2021/03/16 06:46:18 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	put_in_buf(t_info *p, t_img *img)
{
	int	y;
	int	x;
	int	z;

	z = 0;
	y = 0;
	while (y < img->img_h + p->data.win_h / 2)
	{
		y = p->data.win_h * 0.02 + z;
		x = 0;
		while (x < img->img_w && z < img->img_h)
		{
			if (p->texture[7][img->img_w * z + x] != -16777216)
				p->buf[y][x] = p->texture[7][img->img_w * z + x];
			x++;
		}
		z++;
	}
}

void	show_hp(t_info *p, t_img *img, char *path)
{
	int		x;
	int		y;

	img->img_p = mlx_xpm_file_to_image(p->mlx_p,
			path, &img->img_w, &img->img_h);
	img->data = (int *)mlx_get_data_addr(img->img_p,
			&img->bpp, &img->size_l, &img->endian);
	tex_wh(p, 7, img);
	y = -1;
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
			p->texture[7][img->img_w * y + x] =
				img->data[img->img_w * y + x];
	}
	mlx_destroy_image(p->mlx_p, img->img_p);
	put_in_buf(p, img);
	if (p->hp <= 0)
		show_yorn(p, img, "tex/game_over_m2.xpm");
}

void	check_hurt(t_info *p)
{
	t_img i;

	if (p->hurt)
	{
		p->hp--;
		p->hurt = 0;
	}
	if (p->hp == 5)
		show_hp(p, &i, "tex/hp5.xpm");
	else if (p->hp == 4)
		show_hp(p, &i, "tex/hp4.xpm");
	else if (p->hp == 3)
		show_hp(p, &i, "tex/hp3.xpm");
	else if (p->hp == 2)
		show_hp(p, &i, "tex/hp2.xpm");
	else if (p->hp == 1)
		show_hp(p, &i, "tex/hp1.xpm");
	else if (p->hp <= 0)
		show_hp(p, &i, "tex/hp3.xpm");
}

void	pop_up(t_info *p)
{
	check_hurt(p);
	minimap(p);
}
