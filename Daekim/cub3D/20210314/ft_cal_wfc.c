/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cal_wfc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:53:52 by daekim            #+#    #+#             */
/*   Updated: 2021/03/13 04:28:51 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		cal_first(t_info *p, t_cal *c, int x, int y)
{
	c->c_dist = (p->data.win_h - (2.0 * p->pos_z)) /
		(p->data.win_h - 2.0 * (y - p->pitch));
	c->wei = (c->c_dist - c->d_play) / (c->d_wall - c->d_play);
	c->c_fl_x = c->wei * c->fl_xw + (1.0 - c->wei) * p->pos_x;
	c->c_fl_y = c->wei * c->fl_yw + (1.0 - c->wei) * p->pos_y;
	c->fl_tex_x = (int)(c->c_fl_x * p->twh[6].tex_w) & (p->twh[6].tex_w - 1);
	c->fl_tex_y = (int)(c->c_fl_y * p->twh[6].tex_h) & (p->twh[6].tex_h - 1);
	p->buf[y][x] = p->texture[6][p->twh[6].tex_w * c->fl_tex_y + c->fl_tex_x];
	c_shadow(p, c, x, y);
}

void		cal_second(t_info *p, t_cal *c, int x, int y)
{
	c->c_dist = (p->data.win_h + (2.0 * p->pos_z)) /
		(2.0 * (y - p->pitch) - p->data.win_h);
	c->wei = (c->c_dist - c->d_play) / (c->d_wall - c->d_play);
	c->c_fl_x = c->wei * c->fl_xw + (1.0 - c->wei) * p->pos_x;
	c->c_fl_y = c->wei * c->fl_yw + (1.0 - c->wei) * p->pos_y;
	c->fl_tex_x = (int)(c->c_fl_x * p->twh[5].tex_w) & (p->twh[5].tex_w - 1);
	c->fl_tex_y = (int)(c->c_fl_y * p->twh[5].tex_h) & (p->twh[5].tex_h - 1);
	p->buf[y][x] = p->texture[5][p->twh[5].tex_w * c->fl_tex_y + c->fl_tex_x];
	f_shadow(p, c, x, y);
}

void		cal_dist_wall(t_info *p, t_cal *c, int x)
{
	int		y;

	p->cal.d_play = 0.0;
	c->d_wall = c->wall;
	if (c->draw_en < 0)
		c->draw_en = p->data.win_h;
	p->d_cent = (c->draw_en + c->draw_st) / 2;
	y = -1;
	while (++y < c->draw_st)
		cal_first(p, c, x, y);
	y = c->draw_en;
	while (++y < p->data.win_h)
		cal_second(p, c, x, y);
}

void		cal_fl_wall(t_info *p, t_cal *c, int x)
{
	if (c->side == 0 && c->raydir_x > 0)
	{
		c->fl_xw = c->map_x;
		c->fl_yw = c->map_y + c->wall_x;
	}
	else if (c->side == 0 && c->raydir_x < 0)
	{
		c->fl_xw = c->map_x + 1.0;
		c->fl_yw = c->map_y + c->wall_x;
	}
	else if (c->side == 1 && c->raydir_y > 0)
	{
		c->fl_xw = c->map_x + c->wall_x;
		c->fl_yw = c->map_y;
	}
	else
	{
		c->fl_xw = c->map_x + c->wall_x;
		c->fl_yw = c->map_y + 1.0;
	}
	cal_dist_wall(p, c, x);
}
