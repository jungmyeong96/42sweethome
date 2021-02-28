/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 04:15:19 by daekim            #+#    #+#             */
/*   Updated: 2021/02/26 04:38:46 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		cal_in(t_info *p, t_cal *c, int x)
{
	int y;

	c->step = 1.0 * tex_h / c->line_h;
	c->tex_pos = (c->draw_st - win_h / 2 + c->line_h / 2) * c->step;
	y = c->draw_st;
	while (y < c->draw_en)
	{
		c->tex_y = (int)c->tex_pos & (tex_h - 1);
		c->tex_pos += c->step;
		c->color = p->texture[c->tex_num][tex_h * c->tex_y + c->tex_x];
		if (c->side == 1)
			c->color = (c->color >> 1) & 8355711;
		p->buf[y][x] = c->color;
		y++;
	}
}

void		verLine(t_info *p, int x, int y1, int y2, int color)
{
	int		y;

	y = y1;
	while (y <= y2)
	{
		mlx_pixel_put(p->mlx_p, p->win_p, x, y, color);
		y++;
	}
}
