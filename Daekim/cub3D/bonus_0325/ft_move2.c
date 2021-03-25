/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:37:57 by daekim            #+#    #+#             */
/*   Updated: 2021/03/16 06:33:29 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		cal_r(t_info *p)
{
	if (p->key_d == 1)
	{
		if (p->data.map[(int)(p->pos_x + p->plane_x * p->move)][(int)(p->pos_y)]
			!= '1' && p->data.map[(int)(p->pos_x + p->plane_x * p->move)]
			[(int)(p->pos_y)] != '2')
			p->pos_x += p->plane_x * p->move;
		else
		{
			p->pos_x -= p->plane_x * p->move * 10;
			p->hurt = 1;
		}
		if (p->data.map[(int)(p->pos_x)][(int)(p->pos_y + p->plane_y * p->move)]
				!= '1' && p->data.map[(int)(p->pos_x)]
				[(int)(p->pos_y + p->plane_y * p->move)] != '2')
			p->pos_y += p->plane_y * p->move;
		else
		{
			p->pos_y -= p->plane_y * p->move * 10;
			p->hurt = 1;
		}
	}
}

void		cal_l(t_info *p)
{
	if (p->key_a == 1)
	{
		if (p->data.map[(int)(p->pos_x - p->plane_x * p->move)][(int)(p->pos_y)]
				!= '1' && p->data.map[(int)(p->pos_x - p->plane_x * p->move)]
				[(int)(p->pos_y)] != '2')
			p->pos_x -= p->plane_x * p->move;
		else
		{
			p->pos_x += p->plane_x * p->move * 10;
			p->hurt = 1;
		}
		if (p->data.map[(int)(p->pos_x)][(int)(p->pos_y - p->plane_y * p->move)]
				!= '1' && p->data.map[(int)(p->pos_x)]
				[(int)(p->pos_y - p->plane_y * p->move)] != '2')
			p->pos_y -= p->plane_y * p->move;
		else
		{
			p->pos_y += p->plane_y * p->move * 10;
			p->hurt = 1;
		}
	}
}
