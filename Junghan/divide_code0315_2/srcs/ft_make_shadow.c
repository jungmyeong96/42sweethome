/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_shadow.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:35:07 by junghan           #+#    #+#             */
/*   Updated: 2021/03/15 19:01:20 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wall_shadow(t_info *info, t_wall *wall, int y)
{
	int i;

	i = y;
	if (info->wall_h > info->win_mid * 0.8 && info->wall_h < info->win_mid)
		wall->color = (wall->color / 2) & 8355711;
	else if (info->wall_h > info->win_mid * 0.7 && info->wall_h < info->win_mid * 0.8)
		wall->color = (((wall->color / 2) & 8355711) / 2) & 8355711;
	else if (info->wall_h >= info->win_mid * 0.5 && info->wall_h < info->win_mid * 0.7)
		wall->color = (((((wall->color) & 8355711) / 2) & 8355711) / 2) & 8355711;
	else if (info->wall_h >= info->win_mid * 0.3 && info->wall_h < info->win_mid * 0.5)
		wall->color = (((((((wall->color) & 8355711) / 2) & 8355711) / 2)
					& 8355711) / 2) & 8355711;
	else
		wall->color = 0;
}

void	sprite_shadow(t_info *info, t_sprite *sprite)
{
	if (info->sp_h < info->win_mid)
	{
		if (info->sp_h > info->win_mid * 0.8 && info->sp_h < info->win_mid)
			sprite->color = (sprite->color / 2) & 8355711;
		else if (info->sp_h > info->win_mid * 0.7 && info->sp_h < info->win_mid * 0.8)
			sprite->color = (((sprite->color / 2) & 8355711) / 2) & 8355711;
		else if (info->sp_h >= info->win_mid * 0.5 && info->sp_h < info->win_mid * 0.7)
			sprite->color = (((((sprite->color) & 8355711) / 2) & 8355711) / 2)
				& 8355711;
		else if (info->sp_h >= info->win_mid * 0.3 && info->sp_h < info->win_mid * 0.5)
			sprite->color = (((((((sprite->color) & 8355711) / 2) & 8355711) / 2) 
						& 8355711) / 2) & 8355711;
		else
			sprite->color = 0;
	}
}

void	ceiling_shadow(t_wall *wall, t_info *info, int x, int y)
{
	//	double	mid;

 	if (y > info->win_hei / 2 * 0.92 + info->pos_z * 0.08 + info->pitch &&
			y < info->win_hei / 2  + info->pos_z * 0.08 + info->pitch)
			info->buf[y][x] = 0;
	wall->tmp = 0;
}

void	floor_shadow(t_wall *wall, t_info *info, int x, int y)
{
	//double	mid;
	if (y > info->win_hei / 2 + info->pos_z * 0.08 + info->pitch &&
			y < info->win_hei / 2 * 1.08 + info->pos_z * 0.08 + info->pitch)
		info->buf[y][x] = 0;
	wall->tmp = 0;

}
