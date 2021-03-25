/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 05:53:47 by junghan           #+#    #+#             */
/*   Updated: 2021/03/19 06:37:42 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	mouse_move_ud(t_info *info)
{
	if (info->mou_ud > 0)
	{
		look_down(info, &info->keys);
		mlx_mouse_move(info->win, info->win_wid / 2, info->win_hei / 2);
	}
	if (info->mou_ud < 0)
	{
		look_up(info, &info->keys);
		mlx_mouse_move(info->win, info->win_wid / 2, info->win_hei / 2);
	}
}

int		mouse_move(int x, int y, t_info *info)
{
	if (info->keys.key_p == 0)
		mlx_mouse_show();
	if (info->keys.key_p == 1)
	{
		mlx_mouse_hide();
		info->mou_lr = (x - info->keys.zero_p) / 15;
		info->mou_ud = (y - info->keys.zero_p2) / 15;
		if (info->mou_lr < 0)
		{
			turn_left(info, &info->keys);
			mlx_mouse_move(info->win, info->win_wid / 2, info->win_hei / 2);
		}
		if (info->mou_lr > 0)
		{
			turn_right(info, &info->keys);
			mlx_mouse_move(info->win, info->win_wid / 2, info->win_hei / 2);
		}
		mouse_move_ud(info);
	}
	return (0);
}
