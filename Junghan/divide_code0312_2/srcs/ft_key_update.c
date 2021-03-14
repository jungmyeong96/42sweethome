/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_update.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:31:17 by junghan           #+#    #+#             */
/*   Updated: 2021/03/12 07:27:47 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void		turn_right(t_info *info, t_keys *keys)
{
	double old_d_x;
	double old_p_x;

	old_d_x = info->dir_x;
	info->dir_x = info->dir_x * cos(-keys->rot_speed)
		- info->dir_y * sin(-keys->rot_speed);
	info->dir_y = old_d_x * sin(-keys->rot_speed)
		+ info->dir_y * cos(-keys->rot_speed);
	old_p_x = info->plane_x;
	info->plane_x = info->plane_x * cos(-keys->rot_speed)
		- info->plane_y * sin(-keys->rot_speed);
	info->plane_y = old_p_x * sin(-keys->rot_speed)
		+ info->plane_y * cos(-keys->rot_speed);
}

void		turn_left(t_info *info, t_keys *keys)
{
	double old_d_x;
	double old_p_x;

	old_d_x = info->dir_x;
	info->dir_x = info->dir_x * cos(keys->rot_speed)
		- info->dir_y * sin(keys->rot_speed);
	info->dir_y = old_d_x * sin(keys->rot_speed)
		+ info->dir_y * cos(keys->rot_speed);
	old_p_x = info->plane_x;
	info->plane_x = info->plane_x * cos(keys->rot_speed)
		- info->plane_y * sin(keys->rot_speed);
	info->plane_y = old_p_x * sin(keys->rot_speed)
		+ info->plane_y * cos(keys->rot_speed);
}

void	key_updapt3(t_info *info, t_keys *keys)
{
	if (keys->key_r)
		look_up(info, keys);
	if (keys->key_f)
		look_down(info, keys);
	if (keys->key_up)
	{
		if (info->pos_z == 0)
			jump(info, keys);
		keys->key_up = 0;
	}
	if (keys->key_down)
		crouch(info, keys);
    if (info->pos_z > 0)
		info->pos_z = ft_max(0, info->pos_z - 150 * keys->move_speed);
    if (info->pos_z < 0)
		info->pos_z = ft_min(0, info->pos_z + 100 * keys->move_speed);
}

void	key_updapt2(t_info *info, t_keys *keys)
{
	if (keys->key_a && !keys->key_d)
	{
		keys->key_ad = 1;
		key_left(info, keys);
	}
	if (keys->key_a && keys->key_d && keys->key_ad)
		key_right(info, keys);
	if (keys->key_right && !keys->key_left)
	{
		keys->key_eq = 1;
		turn_right(info, keys);
	}
	if (keys->key_right && keys->key_left && keys->key_eq)
		turn_left(info, keys);
	if (keys->key_left && !keys->key_right)
	{
		keys->key_qe = 1;
		turn_left(info, keys);
	}
	if (keys->key_left && keys->key_right && keys->key_qe)
		turn_right(info, keys);
	if (keys->key_esc)
		exit(0);
	key_updapt3(info, keys);
}

void	key_updapt(t_info *info, t_keys *keys)
{
	if (keys->key_w && !keys->key_s)
	{
		keys->key_ws = 1;
		key_up(info, keys);
	}
	if (keys->key_w && keys->key_s && keys->key_ws)
		key_down(info, keys);
	if (keys->key_s && !keys->key_w)
	{
		keys->key_sw = 1;
		key_down(info, keys);
	}
	if (keys->key_s && keys->key_w && keys->key_sw)
		key_up(info, keys);
	if (keys->key_d && !keys->key_a)
	{
		keys->key_da = 1;
		key_right(info, keys);
	}
	if (keys->key_d && keys->key_a && keys->key_da)
		key_left(info, keys);
	key_updapt2(info, keys);
}
