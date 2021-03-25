/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_sprite2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:28:17 by junghan           #+#    #+#             */
/*   Updated: 2021/03/25 05:15:41 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_color_in_spbuf(t_sprite *sprite, t_info *info, int x, int tex)
{
	int		y;

	y = sprite->drawstart_y - 1;
	while (++y < sprite->drawend_y)
	{
		sprite->di = (y - sprite->vmove_scr)
			* 256 - info->win_hei * 128 +
			sprite->sprite_hei * 128;
		sprite->tex_y = ((sprite->di * info->texwh[tex].tex_h)
				/ sprite->sprite_hei) / 256;
		sprite->color = info->texture[tex][info->texwh[tex].tex_w *
			sprite->tex_y + sprite->tex_x];
		info->sp_h = sprite->drawend_y - sprite->drawstart_y;
		sprite_shadow(info, sprite);
		if ((sprite->color & 0x00FFFFFF) != 0)
			info->buf[y][x] = sprite->color;
	}
}

void	put_in_spritebuf(t_sprite *sprite, t_info *info, int tex)
{
	int		x;

	x = sprite->drawstart_x - 1;
	while (++x < sprite->drawend_x)
	{
		sprite->tex_x = (int)(256 * (x - (-sprite->sprite_wid
						/ 2 + sprite->sprite_scr_x))
				* info->texwh[tex].tex_w / sprite->sprite_wid) / 256;
		if (sprite->transf_y > 0 && x > 0 && x < info->win_wid
				&& sprite->transf_y < info->z_buffer[x])
			put_color_in_spbuf(sprite, info, x, tex);
	}
}

void	sort_obj(double *old1, int *old2, int amount)
{
	int		a;
	double	temp1;
	int		temp2;

	a = -1;
	while (++a < amount - 1)
		if (old1[a] > old1[a + 1])
		{
			temp1 = old1[a];
			old1[a] = old1[a + 1];
			old1[a + 1] = temp1;
			temp2 = old2[a];
			old2[a] = old2[a + 1];
			old2[a + 1] = temp2;
			sort_obj(old1, old2, amount);
		}
}

void	sort_sprite(t_info *info, int *obj, double *dist, int amount)
{
	int		i;
	double	tmp1[amount];
	int		tmp2[amount];

	i = 0;
	while (i < amount)
	{
		tmp1[i] = dist[i];
		tmp2[i] = obj[i];
		i++;
	}
	sort_obj(tmp1, tmp2, amount);
	i = 0;
	while (i < amount)
	{
		dist[i] = tmp1[info->sp_count - i - 1];
		obj[i] = tmp2[info->sp_count - i - 1];
		i++;
	}
}
