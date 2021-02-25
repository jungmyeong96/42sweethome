/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cal.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 02:36:47 by daekim            #+#    #+#             */
/*   Updated: 2021/02/26 04:56:25 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		cal_wall(t_info *p, t_cal *c)
{
	c->line_h = (int)(win_h / c->wall);

	c->draw_st = c->line_h * -1 / 2 + win_h / 2;
	if(c->draw_st < 0)
		c->draw_st = 0;
	c->draw_en = c->line_h / 2 + win_h / 2;
	if(c->draw_en >= win_h)
		c->draw_en = win_h - 1;

	c->tex_num = worldMap[c->mapX][c->mapY];
	
	if (c->side == 0)
		c->wall_x = p->posY + c->wall * c->rayDirY;
	else
		c->wall_x = p->posX + c->wall * c->rayDirX;
	c->wall_x -= floor(c->wall_x);

	c->tex_x = (int)(c->wall_x * (double)(tex_w));
	if (c->side == 0 && c->rayDirX > 0)
		c->tex_x = tex_w - c->tex_x - 1;
	if (c->side == 1 && c->rayDirY < 0)
		c->tex_x = tex_w - c->tex_x - 1;
/*
	if (worldMap[c->mapY][c->mapX] == 1)
		c->color = 0xFF0000;
	else if (worldMap[c->mapY][c->mapX] == 2)
		c->color = 0x00FF00;
	else if (worldMap[c->mapY][c->mapX] == 3)
		c->color = 0x0000FF;
	else if (worldMap[c->mapY][c->mapX] == 4)
		c->color = 0xFFFFFF;
	else
		c->color = 0xFFFF00;
	if (c->side == 1)
		c->color = c->color / 2;*/
}

void		cal_dda(t_info *p, t_cal *c)
{
	while (c->hit == 0)
	{
		if (c->sideX < c->sideY)
		{
			c->sideX += c->deltaX;
			c->mapX += c->stepX;
			c->side = 0;
		}
		else
		{
			c->sideY += c->deltaY;
			c->mapY += c->stepY;
			c->side = 1;
		}
		if (worldMap[c->mapX][c->mapY] > 0)
			c->hit = 1;
	}
	if (c->side == 0)
		c->wall = (c->mapX - p->posX + (1 - c->stepX) / 2) / c->rayDirX;
	else
		c->wall = (c->mapY - p->posY + (1 - c->stepY) / 2) / c->rayDirY;
}

void		cal_ray(t_info *p, t_cal *c)
{
	if (c->rayDirX < 0)
	{
		c->stepX = -1;
		c->sideX = (p->posX - c->mapX) * c->deltaX;
	}
	else
	{
		c->stepX = 1;
		c->sideX = (c->mapX + 1.0 - p->posX) * c->deltaX;
	}
	if (c->rayDirY < 0)
	{
		c->stepY = -1;
		c->sideY = (p->posY - c->mapY) * c->deltaY;
	}
	else
	{
		c->stepY = 1;
		c->sideY = (c->mapY + 1.0 - p->posY) * c->deltaY;
	}
}

void		cal_base(t_info *p, t_cal *c, int x)
{
	c->cameraX = 2 * x / (double)win_w - 1;
	c->rayDirX = p->dirX + p->planeX * c->cameraX;
	c->rayDirY = p->dirY + p->planeY * c->cameraX;
	c->mapX = (int)p->posX;
	c->mapY = (int)p->posY;
	c->deltaX = fabs(1 / c->rayDirX);
	c->deltaY = fabs(1 / c->rayDirY);
	c->hit = 0;
}

void		calc(t_info *p)
{
	int		x;
	t_cal	c;

	x = 0;
	while (x < win_w)
	{
		cal_base(p, &c, x);
		cal_ray(p, &c);
		cal_dda(p, &c);
		cal_wall(p, &c);
		cal_in(p, &c, x);
//		verLine(p, x, c.draw_st, c.draw_en, c.color);
		x++;
	}
}
