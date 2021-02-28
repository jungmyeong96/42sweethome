/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 22:49:28 by daekim            #+#    #+#             */
/*   Updated: 2021/02/27 08:56:29 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		in_sp(t_info *p, int *tex, char *path, t_img *i)
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
		{
			tex[i->img_w * y + x] = i->data[i->img_w * y + x];
		}
	}
	mlx_destroy_image(p->mlx_p, i->img_p);
}

void		in_sprite(t_info *p)
{
	t_img	i;

	in_sp(p, p->texture[8], "pics/barrel.xpm", &i);
	in_sp(p, p->texture[9], "pics/pillar.xpm", &i);
	in_sp(p, p->texture[10], "pics/greenlight.xpm", &i);
}
