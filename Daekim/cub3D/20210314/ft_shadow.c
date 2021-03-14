/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 23:28:59 by daekim            #+#    #+#             */
/*   Updated: 2021/03/14 20:21:20 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		s_shadow(t_info *p, t_spr *s)
{
	p->spr_h = s->dr_en_y - s->dr_st_y;
	if (p->spr_h < p->w_cent)
	{
		if (p->spr_h > p->w_cent * 0.8 && p->spr_h < p->w_cent)
			s->color3 = (s->color3 / 2) & 8355711;
		else if (p->spr_h > p->w_cent * 0.7 && p->spr_h < p->w_cent * 0.8)
			s->color3 = (((s->color3 / 2) & 8355711) / 2) & 8355711;
		else if (p->spr_h >= p->w_cent * 0.5 && p->spr_h < p->w_cent * 0.7)
			s->color3 = (((((s->color3) & 8355711) / 2) & 8355711) / 2)
				& 8355711;
		else if (p->spr_h >= p->w_cent * 0.3 && p->spr_h < p->w_cent * 0.5)
			s->color3 = (((((((s->color3) & 8355711) / 2) & 8355711) / 2)
						& 8355711) / 2) & 8355711;
		else
			s->color3 = 0;
	}
}

void		c_shadow(t_info *p, t_cal *c, int x, int y)
{
	if (y > p->d_cent * 0.92 && y < p->d_cent * 0.94)
		p->buf[y][x] = ((p->texture[6][p->twh[6].tex_w * c->fl_tex_y +
					c->fl_tex_x] / 2) & 6250335);
	else if (y >= p->d_cent * 0.94 && y < p->d_cent * 0.95)
		p->buf[y][x] = ((p->texture[6][p->twh[6].tex_w * c->fl_tex_y +
					c->fl_tex_x] / 2) & 8355711);
	else if (y >= p->d_cent * 0.95 && y < p->d_cent * 0.97)
		p->buf[y][x] = (((p->texture[6][p->twh[6].tex_w * c->fl_tex_y +
					c->fl_tex_x] / 2) & 8355711) / 2) & 8355711;
	else if (y >= p->d_cent * 0.97 && y < p->d_cent)
		p->buf[y][x] = (((((p->texture[6][p->twh[6].tex_w * c->fl_tex_y +
			c->fl_tex_x]) & 8355711) / 2) & 8355711) / 2) & 8355711;
}

void		f_shadow(t_info *p, t_cal *c, int x, int y)
{
	if (y > p->d_cent * 1.06 && y < p->d_cent * 1.08)
		p->buf[y][x] = ((p->texture[5][p->twh[5].tex_w * c->fl_tex_y +
					c->fl_tex_x] / 2) & 6250335);
	else if (y > p->d_cent * 1.05 && y <= p->d_cent * 1.06)
		p->buf[y][x] = ((p->texture[5][p->twh[5].tex_w * c->fl_tex_y +
					c->fl_tex_x] / 2) & 8355711);
	else if (y > p->d_cent * 1.03 && y <= p->d_cent * 1.05)
		p->buf[y][x] = (((p->texture[5][p->twh[5].tex_w * c->fl_tex_y +
						c->fl_tex_x] / 2) & 8355711) / 2) & 8355711;
	else if (y > p->d_cent && y <= p->d_cent * 1.03)
		p->buf[y][x] = (((((p->texture[5][p->twh[5].tex_w * c->fl_tex_y +
		c->fl_tex_x]) & 8355711) / 2) & 8355711) / 2) & 8355711;
}

void		w_shadow(t_info *p, t_cal *c)
{
	if (p->wall_h > p->w_cent * 0.8 && p->wall_h < p->w_cent)
		c->color = (c->color / 2) & 8355711;
	else if (p->wall_h > p->w_cent * 0.7 && p->wall_h < p->w_cent * 0.8)
		c->color = (((c->color / 2) & 8355711) / 2) & 8355711;
	else if (p->wall_h >= p->w_cent * 0.5 && p->wall_h < p->w_cent * 0.7)
		c->color = (((((c->color) & 8355711) / 2) & 8355711) / 2) & 8355711;
	else if (p->wall_h >= p->w_cent * 0.3 && p->wall_h < p->w_cent * 0.5)
		c->color = (((((((c->color) & 8355711) / 2) & 8355711) / 2)
					& 8355711) / 2) & 8355711;
	else
		c->color = 0;
}
