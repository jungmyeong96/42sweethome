/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:53:52 by daekim            #+#    #+#             */
/*   Updated: 2021/03/06 05:08:17 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		check_news(t_info *p, t_cal *c)
{
	if (c->side == 1 && ((c->raydir_x >= 0 && c->raydir_y > 0)
				|| (c->raydir_x < 0 && c->raydir_y > 0)))
		c->color = p->texture[0][TEX_H * c->tex_y + c->tex_x];
	if (c->side == 1 && ((c->raydir_x <= 0 && c->raydir_y < 0)
				|| (c->raydir_x > 0 && c->raydir_y < 0)))
		c->color = p->texture[1][TEX_H * c->tex_y + c->tex_x];
	if (c->side == 0 && ((c->raydir_x < 0 && c->raydir_y <= 0)
				|| (c->raydir_x < 0 && c->raydir_y > 0)))
		c->color = p->texture[2][TEX_H * c->tex_y + c->tex_x];
	if (c->side == 0 && ((c->raydir_x > 0 && c->raydir_y >= 0)
				|| (c->raydir_x > 0 && c->raydir_y < 0)))
		c->color = p->texture[3][TEX_H * c->tex_y + c->tex_x];
}

void		cal_in(t_info *p, t_cal *c, t_spr *sp, int x)
{
	int y;

	c->step = 1.0 * TEX_H / c->line_h;
	c->tex_pos = (c->draw_st - p->data.win_h / 2 + c->line_h / 2) * c->step;
	y = c->draw_st;
	while (y < c->draw_en)
	{
		c->tex_y = (int)c->tex_pos & (TEX_H - 1);
		c->tex_pos += c->step;
		check_news(p, c);
		p->buf[y][x] = c->color;
		y++;
	}
	sp->zbuf[x] = c->wall;
}
