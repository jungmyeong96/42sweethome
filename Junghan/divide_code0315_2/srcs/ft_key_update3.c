/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_update3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 07:38:10 by junghan           #+#    #+#             */
/*   Updated: 2021/03/14 20:04:15 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	look_up(t_info *info, t_keys *keys)
{
	info->pitch += 400 * keys->move_speed;
	if (info->pitch > info->win_hei * 2 / 5)
		info->pitch = info->win_hei * 2 / 5;
}

void	look_down(t_info *info, t_keys *keys)
{
	info->pitch -= 400 * keys->move_speed;
	if (info->pitch < -(info->win_hei * 2 / 5))
		info->pitch = -(info->win_hei * 2 / 5);
}

void	jump(t_info *info)
{
	info->pos_z = 200;
}

void	crouch(t_info *info)
{
	info->pos_z = -150;
}
