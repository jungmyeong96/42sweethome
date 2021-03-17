/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_update2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:40:16 by junghan           #+#    #+#             */
/*   Updated: 2021/03/16 05:46:30 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	check_item(t_info *info, t_keys *keys)
{
	if (info->map[(int)(info->pos_x + info->dir_x * keys->move_speed)]
		[(int)(info->pos_y)] != '1'

}*/

void	key_up(t_info *info, t_keys *keys)
{
	if (info->map[(int)(info->pos_x + info->dir_x * keys->move_speed)]
		[(int)(info->pos_y)] != '1' && info->map[(int)(info->pos_x
		+ info->dir_x * keys->move_speed)][(int)(info->pos_y)] != '2')
		info->pos_x += info->dir_x * keys->move_speed;
	else
	{
		info->pos_x -= (info->dir_x * keys->move_speed) * 10;
		keys->hurt = 1;
	}
	if (info->map[(int)(info->pos_x)][(int)(info->pos_y + info->dir_y
		* keys->move_speed)] != '1' && info->map[(int)(info->pos_x)]
		[(int)(info->pos_y + info->dir_y * keys->move_speed)] != '2')
		info->pos_y += info->dir_y * keys->move_speed;
	else
	{
		info->pos_y -= (info->dir_y * keys->move_speed) * 10;
		keys->hurt = 1;
	}
	//check_item(info, keys);
}

void	key_down(t_info *info, t_keys *keys)
{
	if (info->map[(int)(info->pos_x - info->dir_x * keys->move_speed)]
		[(int)(info->pos_y)] != '1' && info->map[(int)(info->pos_x
		- info->dir_x * keys->move_speed)][(int)(info->pos_y)] != '2')
		info->pos_x -= info->dir_x * keys->move_speed;
	else
	{
		info->pos_x += (info->dir_x * keys->move_speed) * 10;
		keys->hurt = 1;
	}
	if (info->map[(int)(info->pos_x)][(int)(info->pos_y - info->dir_y
		* keys->move_speed)] != '1' && info->map[(int)(info->pos_x)]
		[(int)(info->pos_y - info->dir_y * keys->move_speed)] != '2')
		info->pos_y -= info->dir_y * keys->move_speed;
	else
	{
		info->pos_y += (info->dir_y * keys->move_speed) * 10;
		keys->hurt = 1;
	}


	//check_item(info, keys);
}

void	key_right(t_info *info, t_keys *keys)
{
	if (info->map[(int)(info->pos_x + info->plane_x * keys->move_speed)]
		[(int)(info->pos_y)] != '1' && info->map[(int)(info->pos_x
		+ info->plane_x * keys->move_speed)][(int)(info->pos_y)] != '2')
		info->pos_x += info->plane_x * keys->move_speed;
	else
	{
		info->pos_x -= (info->plane_x * keys->move_speed) * 10;
		keys->hurt = 1;
	}

	if (info->map[(int)(info->pos_x)][(int)(info->pos_y + info->plane_y
		* keys->move_speed)] != '1' && info->map[(int)(info->pos_x)]
		[(int)(info->pos_y + info->plane_y * keys->move_speed)] != '2')
		info->pos_y += info->plane_y * keys->move_speed;
	else
	{
		info->pos_y -= (info->plane_y * keys->move_speed) * 10;
		keys->hurt = 1;
	}

	//check_item(info, keys);
}

void	key_left(t_info *info, t_keys *keys)
{
	if (info->map[(int)(info->pos_x - info->plane_x * keys->move_speed)]
		[(int)(info->pos_y)] != '1' && info->map[(int)(info->pos_x
		- info->plane_x * keys->move_speed)][(int)(info->pos_y)] != '2')
		info->pos_x -= info->plane_x * keys->move_speed;
	else
	{
		info->pos_x += (info->plane_x * keys->move_speed) * 10;
		keys->hurt = 1;
	}

	if (info->map[(int)(info->pos_x)][(int)(info->pos_y - info->plane_y
		* keys->move_speed)] != '1' && info->map[(int)(info->pos_x)]
		[(int)(info->pos_y - info->plane_y * keys->move_speed)] != '2')
		info->pos_y -= info->plane_y * keys->move_speed;
	else
	{
		info->pos_y += (info->plane_y * keys->move_speed) * 10;
		keys->hurt = 1;
	}
	//check_item(info, keys);
}
