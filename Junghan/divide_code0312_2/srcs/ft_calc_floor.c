/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:07:16 by junghan           #+#    #+#             */
/*   Updated: 2021/03/12 08:19:05 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_fc(t_info *info, t_floor *floor, int y, int x)
{
	if (info->fcrgb.f_rgb != 1)
	{
		info->fcrgb.color_f = info->texture[5][TEXWID
			* floor->tex_y + floor->tex_x];
		info->buf[y][x] = info->fcrgb.color_f;
	}
	else if (info->fcrgb.f_rgb == 1)
		info->buf[y][x] = info->fcrgb.color_f;
	if (info->fcrgb.c_rgb != 1)
	{
		info->fcrgb.color_c = info->texture[6][TEXWID
			* floor->tex_y + floor->tex_x];
		info->buf[info->win_hei - y - 1][x] = info->fcrgb.color_c;
	}
	else if (info->fcrgb.c_rgb == 1)
		info->buf[info->win_hei - y - 1][x] = info->fcrgb.color_c;
}

void	set_floor_info(t_floor *floor, t_info *info, int y)
{
	double cam_z;
	info->pitch = 0;
	if (y > info->win_hei / 2 + info->pitch)
	{
		info->point = y - info->win_hei / 2 - info->pitch;
		cam_z = 0.5 * info->win_hei + info->pos_z;
		//info->pos_z = 0.5 * info->win_hei + info->pos_z;

	}
	else
	{
		info->point = info->win_hei / 2 - y + info->pitch;
		cam_z = 0.5 * info->win_hei - info->pos_z;
		//info->pos_z = 0.5 * info->win_hei - info->pos_z;

	}
	floor->ray_dirx1 = info->dir_x - info->plane_x;
	floor->ray_diry1 = info->dir_y - info->plane_y;
	floor->ray_dirx2 = info->dir_x + info->plane_x;
	floor->ray_diry2 = info->dir_y + info->plane_y;
	floor->row_dist = cam_z / info->point;
	floor->floorstep_x = floor->row_dist * (floor->ray_dirx2
			- floor->ray_dirx1) / info->win_wid;
	floor->floorstep_y = floor->row_dist * (floor->ray_diry2
			- floor->ray_diry1) / info->win_wid;
	floor->floor_x = info->pos_x + floor->row_dist * floor->ray_dirx1;
	floor->floor_y = info->pos_y + floor->row_dist * floor->ray_diry1;
}

void	calc_floor(t_info *info, t_floor *floor,int y)
{
	int		x;

	set_floor_info(floor, info, y);
	x = -1;
	while (++x < info->win_wid)
	{
		floor->cell_x = (int)(floor->floor_x);
		floor->cell_y = (int)(floor->floor_y);
		floor->tex_x = (int)(TEXWID * (floor->floor_x
					- floor->cell_x)) & (TEXWID - 1);
		floor->tex_y = (int)(TEXHEI * (floor->floor_y
					- floor->cell_y)) & (TEXHEI - 1);
		floor->floor_x += floor->floorstep_x;
		floor->floor_y += floor->floorstep_y;
		//floor.check_pat = (int)(floor.cell_x + floor.cell_y) & 1;
		put_fc(info, floor, y, x);
	}
}
