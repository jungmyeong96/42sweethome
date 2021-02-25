/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_press.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 04:39:21 by daekim            #+#    #+#             */
/*   Updated: 2021/02/26 00:02:23 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	cal_fd(int key, t_info *p)
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

void	cal_rl(int key, t_info *p)
{
	if (key == KEY_D)
	{
		if (!worldMap[(int)(p->posX + p->dirX * p->move)][(int)(p->posY)])
			p->posX += p->planeX * p->move;
		if (!worldMap[(int)(p->posX)][(int)(p->posY + p->dirY * p->move)])
			p->posY += p->planeY * p->move;
	}
	if (key == KEY_A)
	{
		if (!worldMap[(int)(p->posX - p->dirX * p->move)][(int)(p->posY)])
			p->posX -= p->planeX * p->move;
		if (!worldMap[(int)(p->posX)][(int)(p->posY - p->dirY * p->move)])
			p->posY -= p->planeY * p->move;
	}
}

void	cal_turn_rl(int key, t_info *p)
{
	if (key == KEY_E)
	{
		p->oldDirX = p->dirX;
		p->dirX = p->dirX * cos(-(p->rot)) - p->dirY * sin(-(p->rot));
		p->dirY = p->oldDirX * sin(-(p->rot)) + p->dirY * cos(-(p->rot));
		p->oldPlaneX = p->planeX;
		p->planeX = p->planeX * cos(-(p->rot)) - p->planeY * sin(-(p->rot));
		p->planeY = p->oldPlaneX * sin(-(p->rot)) + p->planeY *cos(-(p->rot));
	}
	if (key == KEY_Q)
	{
		p->oldDirX = p->dirX;
		p->dirX = p->dirX * cos(p->rot) - p->dirY * sin(p->rot);
		p->dirY = p->oldDirX * sin(p->rot) + p->dirY * cos(p->rot);
		p->oldPlaneX = p->planeX;
		p->planeX = p->planeX * cos(p->rot) - p->planeY * sin(p->rot);
		p->planeY = p->oldPlaneX * sin(p->rot) + p->planeY *cos(p->rot);
	}
}

int		key_press(int key, t_info *p)
{
	cal_fd(key, p);
	cal_rl(key, p);
	cal_turn_rl(key, p);
	if (key == KEY_ESC)
		exit(0);
	return (0);
}
