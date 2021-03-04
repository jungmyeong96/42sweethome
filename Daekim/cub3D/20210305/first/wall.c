/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:45:29 by daekim            #+#    #+#             */
/*   Updated: 2021/02/27 02:56:02 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		load_wall(t_info *p, int *tex, char *path, t_img *i)
{
	int		x;
	int		y;

	i->img_p = mlx_xpm_file_to_image(p->mlx_p, path, &i->img_w, &i->img_h);
	i->data = (int *)mlx_get_data_addr(i->img_p, &i->bpp,
			&i->size_l, &i->endian);
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

void		tex_wall(t_info *p)
{
	t_img	i;

	load_wall(p, p->texture[0], "tex/eagle.xpm", &i);
	load_wall(p, p->texture[1], "tex/redbrick.xpm", &i);
	load_wall(p, p->texture[2], "tex/purplestone.xpm", &i);
	load_wall(p, p->texture[3], "tex/greystone.xpm", &i);
	load_wall(p, p->texture[4], "tex/bluestone.xpm", &i);
	load_wall(p, p->texture[5], "tex/mossy.xpm", &i);
	load_wall(p, p->texture[6], "tex/wood.xpm", &i);
	load_wall(p, p->texture[7], "tex/colorstone.xpm", &i);
}

void		color_wall(t_info *p)
{
	int		x;
	int		y;
	int		xorc;
	int		yc;
	int		xyc;
/*	int		i;
	int		j;
	
	i = -1;
	while (++i < win_h)
	{
		j = -1;
		while (++j < win_w)
			p->buf[i][j] = 0;
	}
	i = -1;
	while (++i < 8)
	{
		j = -1;
		while (++j < tex_h * tex_w)
			p->texture[i][j] = 0;
	}*/
	x = -1;
	while (++x < tex_w)
	{
		y = -1;
		while (++y < tex_h)
		{
			xorc = (x * 256 / tex_w) ^ (y * 256 / tex_h);
			yc = y * 256 / tex_h;
			xyc = y * 128 / tex_h + x * 128 / tex_w;
			p->texture[0][tex_w * y + x] = 65536 * 254 * (x != y && x != tex_w - y);
			p->texture[1][tex_w * y + x] = xyc + 256 * xyc + 65536 * xyc;
			p->texture[2][tex_w * y + x] = 256 * xyc + 65536 * xyc; 
			p->texture[3][tex_w * y + x] = xorc + 256 * xorc + 65536 * xorc; 
			p->texture[4][tex_w * y + x] = 256 * xorc;
			p->texture[5][tex_w * y + x] = 65536 * 192 * (x % 16 && y % 16); 
			p->texture[6][tex_w * y + x] = 65536 * yc;
			p->texture[7][tex_w * y + x] = 128 + 256 * 128 + 65536 * 128;
		}
	}
}
