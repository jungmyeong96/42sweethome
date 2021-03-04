/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_f1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 05:00:28 by daekim            #+#    #+#             */
/*   Updated: 2021/02/28 18:50:03 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		c_base2(t_info *p, t_cal2 *c, int y)
{
	int		x;

	x = -1;
	while (++x < win_w)
	{
		c->cellX = (int)(c->floorX);
		c->cellY = (int)(c->floorY);
		c->tx = (int)(tex_w * (c->floorX - c->cellX)) & (tex_w - 1);
		c->ty = (int)(tex_h * (c->floorY - c->cellY)) & (tex_h - 1);
		c->floorX += c->f_stepX;
		c->floorY += c->f_stepY;
		c->ch_pat = ((int)(c->cellX + c->cellY)) & 1;
		if (c->ch_pat == 0)
			c->f_tex = 3;
		else
			c->f_tex = 4;
			c->c_tex = 6;
		c->color_f = p->texture[c->f_tex][tex_w * c->ty + c->tx];
		c->color_f = (c->color_f >> 1) & 8355711;
		p->buf[y][x] = c->color_f;
		c->color_f = p->texture[c->c_tex][tex_w * c->ty + c->tx];
		c->color_f = (c->color_f >> 1) & 8355711;
		p->buf[win_h - y - 1][x] = c->color_f;
	}
}

void		c_base1(t_info *p, t_cal2 *c, int y)
{
	c->rayX0 = p->dirX - p->planeX;
	c->rayY0 = p->dirY - p->planeY;
	c->rayX1 = p->dirX + p->planeX;
	c->rayY1 = p->dirY + p->planeY;
	c->per = y - win_h / 2;
	p->posZ = 0.5 * win_h;
	c->row = p->posZ / c->per;
	c->f_stepX = c->row * (c->rayX1 - c->rayX0) / win_w;
	c->f_stepY = c->row * (c->rayY1 - c->rayY0) / win_w;
	c->floorX = p->posX + c->row * c->rayX0;
	c->floorY = p->posY + c->row * c->rayY0;
}

void		calc_fl(t_info *p)
{
	int		y;

	y = win_h / 2 + 1;
	while (y < win_h)
	{
		c_base1(p, &p->cal2, y);
		c_base2(p, &p->cal2, y);
		y++;
	}
}
