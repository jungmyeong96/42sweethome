/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shadow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 23:28:59 by daekim            #+#    #+#             */
/*   Updated: 2021/03/15 18:41:03 by daekim           ###   ########.fr       */
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
	if (y > p->data.win_h / 2 * 0.92 + p->pos_z * 0.08 + p->pitch &&
			y < p->data.win_h / 2 * 0.94 + p->pos_z * 0.08 + p->pitch)
		p->buf[y][x] = ((p->texture[6][p->twh[6].tex_w * c->fl_tex_y +
					c->fl_tex_x] / 2) & 6250335);
	else if (y >= p->data.win_h / 2 * 0.94 + p->pos_z * 0.08 + p->pitch &&
			y < p->data.win_h / 2 * 0.95 + p->pos_z * 0.08 + p->pitch)
		p->buf[y][x] = ((p->texture[6][p->twh[6].tex_w * c->fl_tex_y +
					c->fl_tex_x] / 2) & 8355711);
	else if (y >= p->data.win_h / 2 * 0.95 + p->pos_z * 0.08 + p->pitch &&
			y < p->data.win_h / 2 * 0.97 + p->pos_z * 0.08 + p->pitch)
		p->buf[y][x] = (((p->texture[6][p->twh[6].tex_w * c->fl_tex_y +
					c->fl_tex_x] / 2) & 8355711) / 2) & 8355711;
	else if (y >= p->data.win_h / 2 * 0.97 + p->pos_z * 0.08 + p->pitch)
		p->buf[y][x] = (((((p->texture[6][p->twh[6].tex_w * c->fl_tex_y +
			c->fl_tex_x]) & 8355711) / 2) & 8355711) / 2) & 8355711;
}

void		f_shadow(t_info *p, t_cal *c, int x, int y)
{
	if (y > p->data.win_h / 2 * 1.06 + p->pos_z * 0.08 + p->pitch &&
			y < p->data.win_h / 2 * 1.08 + p->pos_z * 0.08 + p->pitch)
		p->buf[y][x] = ((p->texture[5][p->twh[5].tex_w * c->fl_tex_y +
					c->fl_tex_x] / 2) & 6250335);
	else if (y > p->data.win_h / 2 * 1.05 + p->pos_z * 0.08 + p->pitch &&
			y <= p->data.win_h / 2 * 1.06 + p->pos_z * 0.08 + p->pitch)
		p->buf[y][x] = ((p->texture[5][p->twh[5].tex_w * c->fl_tex_y +
					c->fl_tex_x] / 2) & 8355711);
	else if (y > p->data.win_h / 2 * 1.03 + p->pos_z * 0.08 + p->pitch &&
			y <= p->data.win_h / 2 * 1.05 + p->pos_z * 0.08 + p->pitch)
		p->buf[y][x] = (((p->texture[5][p->twh[5].tex_w * c->fl_tex_y +
						c->fl_tex_x] / 2) & 8355711) / 2) & 8355711;
	else if (y <= p->data.win_h / 2 * 1.03 + p->pos_z * 0.08 + p->pitch)
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
