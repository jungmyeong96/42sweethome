/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:37:57 by daekim            #+#    #+#             */
/*   Updated: 2021/03/11 03:37:59 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		cal_fb(t_info *p)
{
	if (p->key_w == 1)
	{
		if (p->data.map[(int)(p->pos_x + p->dir_x * p->move)]
				[(int)(p->pos_y)] != '1')
			p->pos_x += p->dir_x * p->move;
		if (p->data.map[(int)(p->pos_x)]
				[(int)(p->pos_y + p->dir_y * p->move)] != '1')
			p->pos_y += p->dir_y * p->move;
	}
	if (p->key_s == 1)
	{
		if (p->data.map[(int)(p->pos_x - p->dir_x * p->move)]
				[(int)(p->pos_y)] != '1')
			p->pos_x -= p->dir_x * p->move;
		if (p->data.map[(int)(p->pos_x)]
				[(int)(p->pos_y - p->dir_y * p->move)] != '1')
			p->pos_y -= p->dir_y * p->move;
	}
}

static void		cal_rl(t_info *p)
{
	if (p->key_d == 1)
	{
		if (p->data.map[(int)(p->pos_x + p->plane_x * p->move)]
				[(int)(p->pos_y)] != '1')
			p->pos_x += p->plane_x * p->move;
		if (p->data.map[(int)(p->pos_x)]
				[(int)(p->pos_y + p->plane_y * p->move)] != '1')
			p->pos_y += p->plane_y * p->move;
	}
	if (p->key_a == 1)
	{
		if (p->data.map[(int)(p->pos_x - p->plane_x * p->move)]
				[(int)(p->pos_y)] != '1')
			p->pos_x -= p->plane_x * p->move;
		if (p->data.map[(int)(p->pos_x)]
				[(int)(p->pos_y - p->plane_y * p->move)] != '1')
			p->pos_y -= p->plane_y * p->move;
	}
}

void			cal_turn_r(t_info *p)
{
	if (p->key_e == 1 || p->key_ar == 1 || p->mou_lr > 0)
	{
		p->o_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-(p->rot)) - p->dir_y * sin(-(p->rot));
		p->dir_y = p->o_dir_x * sin(-(p->rot)) + p->dir_y * cos(-(p->rot));
		p->o_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(-(p->rot)) - p->plane_y * sin(-(p->rot));
		p->plane_y = p->o_plane_x * sin(-(p->rot)) + p->plane_y *
			cos(-(p->rot));
	}
}

void			cal_turn_l(t_info *p)
{
	if (p->key_q == 1 || p->key_al == 1 || p->mou_lr < 0)
	{
		p->o_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(p->rot) - p->dir_y * sin(p->rot);
		p->dir_y = p->o_dir_x * sin(p->rot) + p->dir_y * cos(p->rot);
		p->o_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(p->rot) - p->plane_y * sin(p->rot);
		p->plane_y = p->o_plane_x * sin(p->rot) + p->plane_y * cos(p->rot);
	}
}

int				k_press(t_info *p)
{
	cal_fb(p);
	cal_rl(p);
	cal_turn_r(p);
	cal_turn_l(p);
	return (0);
}
