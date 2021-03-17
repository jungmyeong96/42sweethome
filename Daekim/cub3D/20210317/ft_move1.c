/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:37:57 by daekim            #+#    #+#             */
/*   Updated: 2021/03/16 06:32:33 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		cal_f(t_info *p)
{
	if (p->key_w == 1)
	{
		if (p->data.map[(int)(p->pos_x + p->dir_x * p->move)][(int)(p->pos_y)]
				!= '1' && p->data.map[(int)(p->pos_x + p->dir_x
					* p->move)][(int)(p->pos_y)] != '2')
			p->pos_x += p->dir_x * p->move;
		else
		{
			p->pos_x -= p->dir_x * p->move * 10;
			p->hurt = 1;
		}
		if (p->data.map[(int)(p->pos_x)][(int)(p->pos_y + p->dir_y * p->move)]
				!= '1' && p->data.map[(int)(p->pos_x)]
				[(int)(p->pos_y + p->dir_y * p->move)] != '2')
			p->pos_y += p->dir_y * p->move;
		else
		{
			p->pos_y -= p->dir_y * p->move * 10;
			p->hurt = 1;
		}
	}
}

static void		cal_b(t_info *p)
{
	if (p->key_s == 1)
	{
		if (p->data.map[(int)(p->pos_x - p->dir_x * p->move)][(int)(p->pos_y)]
				!= '1' && p->data.map[(int)(p->pos_x - p->dir_x * p->move)]
				[(int)(p->pos_y)] != '2')
			p->pos_x -= p->dir_x * p->move;
		else
		{
			p->pos_x += p->dir_x * p->move * 10;
			p->hurt = 1;
		}
		if (p->data.map[(int)(p->pos_x)][(int)(p->pos_y - p->dir_y * p->move)]
				!= '1' && p->data.map[(int)(p->pos_x)]
				[(int)(p->pos_y - p->dir_y * p->move)] != '2')
			p->pos_y -= p->dir_y * p->move;
		else
		{
			p->pos_y += p->dir_y * p->move * 10;
			p->hurt = 1;
		}
	}
}

void			cal_turn_r(t_info *p)
{
	p->o_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(-(p->rot)) - p->dir_y * sin(-(p->rot));
	p->dir_y = p->o_dir_x * sin(-(p->rot)) + p->dir_y * cos(-(p->rot));
	p->o_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(-(p->rot)) - p->plane_y * sin(-(p->rot));
	p->plane_y = p->o_plane_x * sin(-(p->rot)) + p->plane_y *
		cos(-(p->rot));
}

void			cal_turn_l(t_info *p)
{
	p->o_dir_x = p->dir_x;
	p->dir_x = p->dir_x * cos(p->rot) - p->dir_y * sin(p->rot);
	p->dir_y = p->o_dir_x * sin(p->rot) + p->dir_y * cos(p->rot);
	p->o_plane_x = p->plane_x;
	p->plane_x = p->plane_x * cos(p->rot) - p->plane_y * sin(p->rot);
	p->plane_y = p->o_plane_x * sin(p->rot) + p->plane_y * cos(p->rot);
}

int				k_press(t_info *p)
{
	cal_f(p);
	cal_b(p);
	cal_r(p);
	cal_l(p);
	if (p->key_e == 1 || p->key_ar == 1)
		cal_turn_r(p);
	if (p->key_q == 1 || p->key_al == 1)
		cal_turn_l(p);
	cal_view(p);
	return (0);
}
