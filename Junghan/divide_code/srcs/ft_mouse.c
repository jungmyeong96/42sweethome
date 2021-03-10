/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 05:53:47 by junghan           #+#    #+#             */
/*   Updated: 2021/03/11 02:09:38 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		mouse_move(int x, int y, t_info *info)
{
	
	double old_d_x;
	double old_p_x;
	printf("wid%d \n key_p%d\n", info->win_wid, info->keys.key_p);
	if (info->keys.key_p == 1)
	{
	printf("x : %d\ny : %d\nwin_w : %d\n", x, y, info->win_wid);

	info->mou_lr = (x - info->keys.zero_p) / 15;
	printf("lr : %d\np->zero_p : %d\np->move_p : %d\ninfo->mou_lr : %d\n", info->mou_lr, info->keys.zero_p, info->keys.move_p, info->mou_lr);
	printf("dir_x : %lf\no_dir_x : %lf\n", info->dir_x, old_d_x); 
	if (info->mou_lr < 0)
	{
	old_d_x = info->dir_x;
	info->dir_x = info->dir_x * cos(info->keys.rot_speed)
		- info->dir_y * sin(info->keys.rot_speed);
	info->dir_y = old_d_x * sin(info->keys.rot_speed)
		+ info->dir_y * cos(info->keys.rot_speed);
	old_p_x = info->plane_x;
	info->plane_x = info->plane_x * cos(info->keys.rot_speed)
		- info->plane_y * sin(info->keys.rot_speed);
	info->plane_y = old_p_x * sin(info->keys.rot_speed)
		+ info->plane_y * cos(info->keys.rot_speed);
	mlx_mouse_move(info->win, info->win_wid / 2, info->win_hei / 2);
	/*		info->keys.move_p++;
		if(x - info->keys.zero_p + info->keys.move_p == info->keys.zero_p)
			info->keys.move_p = 0;*/
	}
	if (info->mou_lr > 0)
	{
	old_d_x = info->dir_x;
	info->dir_x = info->dir_x * cos(-info->keys.rot_speed)
		- info->dir_y * sin(-info->keys.rot_speed);
	info->dir_y = old_d_x * sin(-info->keys.rot_speed)
		+ info->dir_y * cos(-info->keys.rot_speed);
	old_p_x = info->plane_x;
	info->plane_x = info->plane_x * cos(-info->keys.rot_speed)
		- info->plane_y * sin(-info->keys.rot_speed);
	info->plane_y = old_p_x * sin(-info->keys.rot_speed)
		+ info->plane_y * cos(-info->keys.rot_speed);
	mlx_mouse_move(info->win, info->win_wid / 2, info->win_hei / 2);
/*
		info->keys.move_p--;
		if(x - info->keys.zero_p + info->keys.move_p == info->keys.zero_p)
			info->keys.move_p = 0;
			*/
	}
	printf("OK\n");
	}
	if (info->keys.key_p == 0)
		mlx_mouse_show();

	return (0);
}
