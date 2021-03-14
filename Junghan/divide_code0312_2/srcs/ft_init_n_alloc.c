/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_n_alloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:09:50 by junghan           #+#    #+#             */
/*   Updated: 2021/03/12 02:51:16 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	start_dir2(t_info *info, char c)
{
	if (c == 'N')
	{
		info->dir_x = -1;
		info->dir_y = 0;
		info->plane_x = 0;
		info->plane_y = 0.66;
	}
	else if (c == 'W')
	{
		info->dir_x = 0;
		info->dir_y = -1;
		info->plane_x = -0.66;
		info->plane_y = 0;
	}
}

void	start_dir(t_info *info, char c, int x, int y)
{
	info->pos_x = x + 0.5;
	info->pos_y = y + 0.5;
	info->pitch = 0;
	if (c == 'E')
	{
		info->dir_x = 0;
		info->dir_y = 1;
		info->plane_x = 0.66;
		info->plane_y = 0;
	}
	else if (c == 'S')
	{
		info->dir_x = 1;
		info->dir_y = 0;
		info->plane_x = 0;
		info->plane_y = -0.66;
	}
	else
		start_dir2(info, c);
}

void	init_arr(t_info *info)
{
	info->sp_count = 0;
	info->is_save = 0;
}

void	init_keys(t_keys *keys, t_info *info)
{
	keys->key_a = 0;
	keys->key_w = 0;
	keys->key_s = 0;
	keys->key_d = 0;
	keys->key_left = 0;
	keys->key_right = 0;
	keys->key_p = 0;
	keys->key_r = 0;
	keys->key_f = 0;
	keys->key_up = 0;
	keys->key_down = 0;
	keys->key_esc = 0;
	keys->move_speed = 0.05;
	keys->rot_speed = 0.05;
	keys->zero_p = info->win_wid / 2;
	keys->zero_p2 = info->win_hei / 2; 
	keys->move_p = 0;
}

int	**alloc_arr(t_info *info)
{
	int	i;

	if (!(info->buf = (int **)calloc(info->win_hei, sizeof(int *))))
		error_exit("some error in malloc");
	if (!(info->z_buffer = (double *)calloc(info->win_wid, sizeof(double))))
		error_exit("some error in malloc");
	i = 0;
	while (i < info->win_hei)
	{
		if (!(info->buf[i] = (int *)calloc(info->win_wid, sizeof(int))))
			error_exit("some error in mallc");
		i++;
	}
	return (0);
}
