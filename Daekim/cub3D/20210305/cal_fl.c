/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_f1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 05:00:28 by daekim            #+#    #+#             */
/*   Updated: 2021/03/04 20:19:03 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		put_fc(t_info *p, t_cal2 *c, int y , int x)
{
		if (p->cal.f_rgb != 1)
		{
			c->color_f = p->texture[5][tex_w * c->ty + c->tx];
			p->buf[y][x] = c->color_f;
		}
		else if (p->cal.f_rgb == 1)
			p->buf[y][x] = p->cal.color_f;
		if (p->cal.c_rgb != 1)
		{
			c->color_f = p->texture[6][tex_w * c->ty + c->tx];
			p->buf[p->data.win_h - y - 1][x] = c->color_f;
		}
		else if (p->cal.c_rgb == 1)
			p->buf[p->data.win_h - y - 1][x] = p->cal.color_c;
}

void		c_base2(t_info *p, t_cal2 *c, int y)
{
	int		x;

	x = -1;
	while (++x < p->data.win_w)
	{
		c->cell_x = (int)(c->floor_x);
		c->cell_y = (int)(c->floor_y);
		c->tx = (int)(tex_w * (c->floor_x - c->cell_x)) & (tex_w - 1);
		c->ty = (int)(tex_h * (c->floor_y - c->cell_y)) & (tex_h - 1);
		c->floor_x += c->f_step_x;
		c->floor_y += c->f_step_y;
		c->ch_pat = ((int)(c->cell_x + c->cell_y)) & 1;
		put_fc(p, c, y, x);
	}
}

void		c_base1(t_info *p, t_cal2 *c, int y)
{
	c->ray_x0 = p->dir_x - p->plane_x;
	c->ray_y0 = p->dir_y - p->plane_y;
	c->ray_x1 = p->dir_x + p->plane_x;
	c->ray_y1 = p->dir_y + p->plane_y;
	c->per = y - p->data.win_h / 2;
	p->pos_z = 0.5 * p->data.win_h;
	c->row = p->pos_z / c->per;
	c->f_step_x = c->row * (c->ray_x1 - c->ray_x0) / p->data.win_w;
	c->f_step_y = c->row * (c->ray_y1 - c->ray_y0) / p->data.win_w;
	c->floor_x = p->pos_x + c->row * c->ray_x0;
	c->floor_y = p->pos_y + c->row * c->ray_y0;
}

void		calc_fl(t_info *p)
{
	int		y;

	y = p->data.win_h / 2 + 1;
	while (y < p->data.win_h)
	{
		c_base1(p, &p->cal2, y);
		c_base2(p, &p->cal2, y);
		y++;
	}
}
