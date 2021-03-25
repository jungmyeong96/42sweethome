/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_attack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 03:48:57 by daekim            #+#    #+#             */
/*   Updated: 2021/03/16 06:46:18 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		attack_sp(t_info *p, t_spr *s, int tex)
{
	int st;
	int y;
	st = s->dr_st_x - 1;
	while (++st < s->dr_en_x && tex != 0)
	{
		if (s->trans_y > 0 && st > 0 && st < p->data.win_w &&
				s->trans_y < s->zbuf[st])
		{
			y = s->dr_st_y - 1;
			while (++y < s->dr_en_y)
			{
				if (p->skill_t != 0 && st == p->data.win_w / 2 &&
						y == p->data.win_h / 2)
					if ((s->color3 != -16777216))
						return (1);
			}
		}
	}
	return (0);
}

void	sp_or_dam(t_info *p, t_spr *s, int tex)
{
	if (attack_sp(p, s, tex) && tex == 12)
		;
	else
		sp_cal2(p, s, tex);
}

void	attack(t_info *p, t_img *img, char *path)
{
	int		x;
	int		y;

	img->img_p = mlx_xpm_file_to_image(p->mlx_p,
			path, &img->img_w, &img->img_h);
	img->data = (int *)mlx_get_data_addr(img->img_p,
			&img->bpp, &img->size_l, &img->endian);
	tex_wh(p, 16, img);
	y = -1;
	while (++y < img->img_h)
	{
		x = -1;
		while (++x < img->img_w)
			p->texture[16][img->img_w * y + x] =
				img->data[img->img_w * y + x];
	}
	mlx_destroy_image(p->mlx_p, img->img_p);
	p->skill_t++;
	if (p->skill_t == 12)
	{
		p->skill1 = 0;
		p->skill_t = 0;
	}
	put_in_weapon(p, img, 16);
}

int			click(int b, int x, int y, t_info *p)
{
	x = 0;
	y = 0;
	if (b == 1 && p->key_p == 1)
		p->skill1 = 1;
	return (0);
}
