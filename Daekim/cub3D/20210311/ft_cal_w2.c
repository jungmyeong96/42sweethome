/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:53:52 by daekim            #+#    #+#             */
/*   Updated: 2021/03/07 22:15:20 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		check_news(t_info *p, t_cal *c)
{
	if (c->side == 1 && ((c->raydir_x >= 0 && c->raydir_y > 0)
				|| (c->raydir_x < 0 && c->raydir_y > 0)))
		c->color = p->texture[0][p->twh[0].tex_h * c->tex_y + c->tex_x];
	if (c->side == 1 && ((c->raydir_x <= 0 && c->raydir_y < 0)
				|| (c->raydir_x > 0 && c->raydir_y < 0)))
		c->color = p->texture[1][p->twh[1].tex_h * c->tex_y + c->tex_x];
	if (c->side == 0 && ((c->raydir_x < 0 && c->raydir_y <= 0)
				|| (c->raydir_x < 0 && c->raydir_y > 0)))
		c->color = p->texture[2][p->twh[2].tex_h * c->tex_y + c->tex_x];
	if (c->side == 0 && ((c->raydir_x > 0 && c->raydir_y >= 0)
				|| (c->raydir_x > 0 && c->raydir_y < 0)))
		c->color = p->texture[3][p->twh[3].tex_h * c->tex_y + c->tex_x];
}

void		cal_in(t_info *p, t_cal *c, t_spr *sp, int x)
{
	int y;

	c->step = 1.0 * p->twh[0].tex_h / c->line_h;
	c->tex_pos = (c->draw_st - p->data.win_h / 2 + c->line_h / 2) * c->step;
	y = c->draw_st;
	while (y < c->draw_en)
	{
		c->tex_y = (int)c->tex_pos & (p->twh[0].tex_h - 1);
		c->tex_pos += c->step;
		check_news(p, c);
		p->buf[y][x] = c->color;
		y++;
	}
	sp->zbuf[x] = c->wall;
}
