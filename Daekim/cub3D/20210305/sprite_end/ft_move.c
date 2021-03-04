/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:37:57 by daekim            #+#    #+#             */
/*   Updated: 2021/03/01 21:27:57 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		cal_fb(t_info *p)
{
	if (p->key_w == 1)
	{
		if (!worldMap[(int)(p->posX + p->dirX * p->move)][(int)(p->posY)])
			p->posX += p->dirX * p->move;
		if (!worldMap[(int)(p->posX)][(int)(p->posY + p->dirY * p->move)])
			p->posY += p->dirY * p->move;
	}
	if (p->key_s == 1)
	{
		if (!worldMap[(int)(p->posX - p->dirX * p->move)][(int)(p->posY)])
			p->posX -= p->dirX * p->move;
		if (!worldMap[(int)(p->posX)][(int)(p->posY - p->dirY * p->move)])
			p->posY -= p->dirY * p->move;
	}
}

static void		cal_rl(t_info *p)
{
	if (p->key_d == 1)
	{
	if (!worldMap[(int)(p->posX + p->planeX * p->move)][(int)(p->posY)])
		p->posX += p->planeX * p->move;
	if (!worldMap[(int)(p->posX)][(int)(p->posY + p->planeY * p->move)])
		p->posY += p->planeY * p->move;
	}
	if (p->key_a == 1)
	{
		if (!worldMap[(int)(p->posX - p->planeX * p->move)][(int)(p->posY)])
			p->posX -= p->planeX * p->move;
		if (!worldMap[(int)(p->posX)][(int)(p->posY - p->planeY * p->move)])
			p->posY -= p->planeY * p->move;
	}
}

static void		cal_turn_rl(t_info *p)
{
	if (p->key_e == 1 || p->key_ar == 1)
	{
		p->o_dirX = p->dirX;
		p->dirX = p->dirX * cos(-(p->rot)) - p->dirY * sin(-(p->rot));
		p->dirY = p->o_dirX * sin(-(p->rot)) + p->dirY * cos(-(p->rot));
		p->o_planeX = p->planeX;
		p->planeX = p->planeX * cos(-(p->rot)) - p->planeY * sin(-(p->rot));
		p->planeY = p->o_planeX * sin(-(p->rot)) + p->planeY * cos(-(p->rot));
	}
	if (p->key_q == 1 || p->key_al == 1)
	{
		p->o_dirX = p->dirX;
		p->dirX = p->dirX * cos(p->rot) - p->dirY * sin(p->rot);
		p->dirY = p->o_dirX * sin(p->rot) + p->dirY * cos(p->rot);
		p->o_planeX = p->planeX;
		p->planeX = p->planeX * cos(p->rot) - p->planeY * sin(p->rot);
		p->planeY = p->o_planeX * sin(p->rot) + p->planeY * cos(p->rot);
	}
}

int			k_press(t_info *p)
{
	cal_fb(p);
	cal_rl(p);
	cal_turn_rl(p);
	return (0);
}
