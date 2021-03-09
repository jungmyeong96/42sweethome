/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:50:12 by daekim            #+#    #+#             */
/*   Updated: 2021/03/07 22:09:47 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		cal_wall(t_info *p, t_cal *c)
{
	c->line_h = (int)(p->data.win_h / c->wall);
	c->draw_st = -(c->line_h) / 2 + p->data.win_h / 2;
	if (c->draw_st < 0)
		c->draw_st = 0;
	c->draw_en = c->line_h / 2 + p->data.win_h / 2;
	if (c->draw_en >= p->data.win_h)
		c->draw_en = p->data.win_h - 1;
	c->tex_n = p->data.map[c->map_x][c->map_y] - 1;
	if (c->side == 0)
		c->wall_x = p->pos_y + c->wall * c->raydir_y;
	else
		c->wall_x = p->pos_x + c->wall * c->raydir_x;
	c->wall_x -= floor(c->wall_x);
	c->tex_x = (int)(c->wall_x * (double)(p->twh[0].tex_w));
	if (c->side == 0 && c->raydir_x > 0)
		c->tex_x = p->twh[0].tex_w - c->tex_x - 1;
	if (c->side == 1 && c->raydir_y < 0)
		c->tex_x = p->twh[0].tex_w - c->tex_x - 1;
}

void		cal_dda(t_info *p, t_cal *c)
{
	while (c->hit == 0)
	{
		if (c->side_x < c->side_y)
		{
			c->side_x += c->delta_x;
			c->map_x += c->step_x;
			c->side = 0;
		}
		else
		{
			c->side_y += c->delta_y;
			c->map_y += c->step_y;
			c->side = 1;
		}
		if (p->data.map[c->map_x][c->map_y] == '1')
			c->hit = 1;
	}
	if (c->side == 0)
		c->wall = (c->map_x - p->pos_x + (1 - c->step_x) / 2) / c->raydir_x;
	else
		c->wall = (c->map_y - p->pos_y + (1 - c->step_y) / 2) / c->raydir_y;
}

void		cal_ray(t_info *p, t_cal *c)
{
	if (c->raydir_x < 0)
	{
		c->step_x = -1;
		c->side_x = (p->pos_x - c->map_x) * c->delta_x;
	}
	else
	{
		c->step_x = 1;
		c->side_x = (c->map_x + 1.0 - p->pos_x) * c->delta_x;
	}
	if (c->raydir_y < 0)
	{
		c->step_y = -1;
		c->side_y = (p->pos_y - c->map_y) * c->delta_y;
	}
	else
	{
		c->step_y = 1;
		c->side_y = (c->map_y + 1.0 - p->pos_y) * c->delta_y;
	}
}

void		cal_base(t_info *p, t_cal *c, int x)
{
	c->camera_x = 2 * x / (double)p->data.win_w - 1;
	c->raydir_x = p->dir_x + p->plane_x * c->camera_x;
	c->raydir_y = p->dir_y + p->plane_y * c->camera_x;
	c->map_x = (int)p->pos_x;
	c->map_y = (int)p->pos_y;
	c->delta_x = fabs(1 / c->raydir_x);
	c->delta_y = fabs(1 / c->raydir_y);
	c->hit = 0;
}

void		calc_wa(t_info *p)
{
	int		x;

	x = 0;
	while (x < p->data.win_w)
	{
		cal_base(p, &p->cal, x);
		cal_ray(p, &p->cal);
		cal_dda(p, &p->cal);
		cal_wall(p, &p->cal);
		cal_in(p, &p->cal, &p->sp, x);
		x++;
	}
}
