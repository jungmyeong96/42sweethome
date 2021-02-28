/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   press.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 19:37:57 by daekim            #+#    #+#             */
/*   Updated: 2021/03/01 04:57:42 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void		cal_fb(int key, t_info *p)
{
	if (key == KEY_W)
	{
		if (!worldMap[(int)(p->posX + p->dirX * p->move)][(int)(p->posY)])
			p->posX += p->dirX * p->move;
		if (!worldMap[(int)(p->posX)][(int)(p->posY + p->dirY * p->move)])
			p->posY += p->dirY * p->move;
	}
	if (key == KEY_S)
	{
		if (!worldMap[(int)(p->posX - p->dirX * p->move)][(int)(p->posY)])
			p->posX -= p->dirX * p->move;
		if (!worldMap[(int)(p->posX)][(int)(p->posY - p->dirY * p->move)])
			p->posY -= p->dirY * p->move;
	}
}

static void		cal_rl(int key, t_info *p)
{
	if (key == KEY_D)
	{
		if (!worldMap[(int)(p->posX + p->planeX * p->move)][(int)(p->posY)])
			p->posX += p->planeX * p->move;
		if (!worldMap[(int)(p->posX)][(int)(p->posY + p->planeY * p->move)])
			p->posY += p->planeY * p->move;
	}
	if (key == KEY_A)
	{
		if (!worldMap[(int)(p->posX - p->planeX * p->move)][(int)(p->posY)])
			p->posX -= p->planeX * p->move;
		if (!worldMap[(int)(p->posX)][(int)(p->posY - p->planeY * p->move)])
			p->posY -= p->planeY * p->move;
	}
}

static void		cal_turn_rl(int key, t_info *p)
{
	if (key == KEY_RT || key == KEY_E)
	{
		p->o_dirX = p->dirX;
		p->dirX = p->dirX * cos(-(p->rot)) - p->dirY * sin(-(p->rot));
		p->dirY = p->o_dirX * sin(-(p->rot)) + p->dirY * cos(-(p->rot));
		p->o_planeX = p->planeX;
		p->planeX = p->planeX * cos(-(p->rot)) - p->planeY * sin(-(p->rot));
		p->planeY = p->o_planeX * sin(-(p->rot)) + p->planeY * cos(-(p->rot));
	}
	if (key == KEY_LT || key == KEY_Q)
	{
		p->o_dirX = p->dirX;
		p->dirX = p->dirX * cos(p->rot) - p->dirY * sin(p->rot);
		p->dirY = p->o_dirX * sin(p->rot) + p->dirY * cos(p->rot);
		p->o_planeX = p->planeX;
		p->planeX = p->planeX * cos(p->rot) - p->planeY * sin(p->rot);
		p->planeY = p->o_planeX * sin(p->rot) + p->planeY * cos(p->rot);
	}
}
#include <stdio.h>
int			k_press(int	key, t_info *p)
{
	cal_fb(key, p);
	cal_rl(key, p);
	cal_turn_rl(key, p);
//	printf("%d\n", key);
	if (key == KEY_ESC)
		exit(0);
	return (0);
}
