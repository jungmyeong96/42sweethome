/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 20:53:52 by daekim            #+#    #+#             */
/*   Updated: 2021/03/04 04:01:22 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		check_news(t_info *p, t_cal *c)
{
	if (c->side == 1 && ((c->raydir_x >= 0 && c->raydir_y > 0)
			   	|| (c->raydir_x < 0 && c->raydir_y > 0)))
		c->color = p->texture[0][tex_h * c->tex_y + c->tex_x];

	if (c->side == 1 && ((c->raydir_x <= 0 && c->raydir_y < 0)
			   	|| (c->raydir_x > 0 && c->raydir_y < 0)))
		c->color = p->texture[1][tex_h * c->tex_y + c->tex_x];

	if (c->side == 0 && ((c->raydir_x < 0 && c->raydir_y <= 0)
			   	|| (c->raydir_x < 0 && c->raydir_y > 0)))
		c->color = p->texture[2][tex_h * c->tex_y + c->tex_x];

	if (c->side == 0 && ((c->raydir_x > 0 && c->raydir_y >= 0)
			   	|| (c->raydir_x > 0 && c->raydir_y < 0)))
		c->color = p->texture[3][tex_h * c->tex_y + c->tex_x];
}

void		cal_in(t_info *p, t_cal *c, t_spr *sp, int x)
{
	int y;

	c->step = 1.0 * tex_h / c->line_h;
	c->tex_pos = (c->draw_st - p->data.win_h / 2 + c->line_h / 2) * c->step;
	y = c->draw_st;
	while (y < c->draw_en)
	{
		c->tex_y = (int)c->tex_pos & (tex_h - 1);
		c->tex_pos += c->step;
//		c->color = p->texture[c->tex_n][tex_h * c->tex_y + c->tex_x];

		check_news(p, c);
/*		if (c->side == 1 && ((c->raydir_x > 0 && c->raydir_y >0)
				   	|| (c->raydir_x < 0 && c->raydir_y > 0)))
			c->color = p->texture[0][tex_h * c->tex_y + c->tex_x];*/
		p->buf[y][x] = c->color;
		y++;
	}
	sp->zbuf[x] = c->wall;
}

void		verline(t_info *p, int x, int st, int en)
{
	int		y;

	y = st;
	if (p->cal.f_rgb == 1)
		while (y <= en)
		{
			mlx_pixel_put(p->mlx_p, p->win_p, x, y, p->cal.color_f);
			y++;
		}
	y = st;
	if (p->cal.c_rgb == 1)
		while (y <= en)
		{
			mlx_pixel_put(p->mlx_p, p->win_p, x, y, p->cal.color_c);
			y++;
		}
}
