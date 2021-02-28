/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal_s1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 06:54:31 by daekim            #+#    #+#             */
/*   Updated: 2021/02/27 09:28:01 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		sortSp(t_spr *s, int *ord, double *dist, int amount)
{
	int		i;

	i = 0;
	while (i < amount)
	{
		sprite[i].x = dist[i];
		sprite[i].y = ord[i];
		i++;
	}
	i = 0;
	while (i < amount)
	{
		dist[i] = sprite[amount - i - 1].x;
		ord[i] = sprite[amount - i -1].y;
		i++;
	}
}

void		sp_cal2(t_info *p, t_spr *s, int i)
{
	int		st;
	int		y;

	st = s->dr_stX;
	while (st < s->dr_enX)
	{
		s->tex_x = (int)(256 * (st - (-(s->sp_w) / 2 + s->screenX)) * tex_w
				/ s->sp_w) / 256;
		if (s->transY > 0 && st > 0 && st < win_w && s->transY < s->Zbuf[st])
		{
			y = s->dr_stY;
			while (y < s->dr_enY)
			{
				s->d = y * 256 - win_h * 128 + s->sp_h * 128;
				s->tex_y = ((s->d * tex_h) / s->sp_h) / 256;
				s->color3 = p->texture[s->sp_ord[i]][tex_w * s->tex_y + s->tex_x];
				if ((s->color3 & 0x00FFFFFF) != 0)
					p->buf[y][st] = s->color3;
				y++;
			}
		}
		st++;
	}
}

void		sp_cal1(t_info *p, t_spr *s, int i)
{
	s->spX = sprite[s->sp_ord[i]].x - p->posX;
	s->spY = sprite[s->sp_ord[i]].y - p->posY;

	s->mat = 1.0 / (p->planeX * p->dirY - p->dirX * p->planeY);
	s->transX = s->mat * (p->dirY * s->spX - p->dirX * s->spY);
	s->transY = s->mat * (-(p->planeY) * s->spX + p->planeX * s->spY);
	s->screenX = (int)((win_w / 2) * (1 + s->transX / s->transY));
	s->sp_h = abs((int)(win_h / s->transY));
 	s->dr_stY = -(s->sp_h) / 2 + win_h / 2; 
	if (s->dr_stY < 0)
		s->dr_stY = 0; 
	s->dr_enY = s->sp_h / 2 + win_h / 2;
	if (s->dr_enY >= win_h)
		s->dr_enY = win_h - 1;
	s->sp_w = abs((int)(win_h / s->transY));
	s->dr_stX = -(s->sp_w) / 2 + s->screenX;
	if (s->dr_stX < 0)
		s->dr_stX = 0;
	s->dr_enX = s->sp_w / 2 + s->screenX;
	if (s->dr_enX >= win_w)
		s->dr_enX = win_w - 1;
}
/*
void		sp_map(t_spr *sp)
{
	sp->s_map	sprite[num_sp] = {
		{20.5, 11.5, 10},
 		{18.5,4.5, 10},
		{10.0,4.5, 10},
		{10.0,12.5,10},
		{3.5, 6.5, 10},
		{3.5, 20.5,10},
		{3.5, 14.5,10},
		{14.5,20.5,10},
		{18.5, 10.5, 9},
		{18.5, 11.5, 9},
		{18.5, 12.5, 9},
		{21.5, 1.5, 8},
		{15.5, 1.5, 8},
		{16.0, 1.8, 8},
		{16.2, 1.2, 8},
		{3.5, 2.5, 8},
		{9.5, 15.5, 8},
		{10.0, 15.1,8},
		{10.5, 15.8,8},
	}
}
*/
void		calc_sp(t_info *p)
{
	int i;

//	sp_map(&p->sp);
	i = 0;
	while (i < num_sp)
	{
		p->sp.sp_ord[i] = i;
		p->sp.sp_dis[i] = ((p->posX - sprite[i].x) * (p->posX - sprite[i].x) + (p->posY - sprite[i].y) * (p->posX - sprite[i].y));
		i++;
	}
	sortSp(&p->sp, p->sp.sp_ord, p->sp.sp_dis, num_sp);
	i = 0;
	while (i < num_sp)
	{
		sp_cal1(p, &p->sp, i);
		sp_cal2(p, &p->sp, i);
		i++;
	}
}
