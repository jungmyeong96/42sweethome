/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:09:35 by junghan           #+#    #+#             */
/*   Updated: 2021/03/08 13:47:46 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	wallpoint(t_wall *wall, t_info *info, int x)
{
	wall->drawstart = -wall->line_hei / 2 + info->win_hei / 2;
	if (wall->drawstart < 0)
		wall->drawstart = 0;
	wall->drawend = wall->line_hei / 2 + info->win_hei / 2;
	if (wall->drawend >= info->win_hei)
		wall->drawend = info->win_hei - 1;
	wall->tex_num = info->map[wall->map_x][wall->map_y] - 1;
	if (wall->side == 0)
		wall->wall_tmp = info->pos_y + wall->perpwall_d
			* wall->raydir_y;
	else
		wall->wall_tmp = info->pos_x + wall->perpwall_d
			* wall->raydir_x;
	wall->wall_tmp -= floor((wall->wall_tmp));
}

void	work_dda(t_wall *wall, t_info *info, int x)
{
	while (wall->hit == 0)
	{
		if (wall->sidedist_x < wall->sidedist_y)
		{
			wall->sidedist_x += wall->deltadist_x;
			wall->map_x += wall->step_x;
			wall->side = 0;
		}
		else
		{
			wall->sidedist_y += wall->deltadist_y;
			wall->map_y += wall->step_y;
			wall->side = 1;
		}
		if (info->map[wall->map_x][wall->map_y] == '1')
			wall->hit = 1;
	}
	if (wall->side == 0)
		wall->perpwall_d = (wall->map_x - info->pos_x
				+ (1 - wall->step_x) / 2) / wall->raydir_x;
	else
		wall->perpwall_d = (wall->map_y - info->pos_y
				+ (1 - wall->step_y) / 2) / wall->raydir_y;
	wall->line_hei = (int)(info->win_hei / wall->perpwall_d);
}

void	set_wall_info(t_wall *wall, t_info *info, int x)
{
	wall->cam_x = 2 * x / (double)info->win_wid - 1;
	wall->raydir_x = info->dir_x + info->plane_x * wall->cam_x;
	wall->raydir_y = info->dir_y + info->plane_y * wall->cam_x;
	wall->map_x = (int)info->pos_x;
	wall->map_y = (int)info->pos_y;
	wall->deltadist_x = fabs(1 / wall->raydir_x);
	wall->deltadist_y = fabs(1 / wall->raydir_y);
	wall->hit = 0;
}

void	set_sidedist(t_wall *wall, t_info *info, int x)
{
	if (wall->raydir_x < 0)
	{
		wall->step_x = -1;
		wall->sidedist_x = (info->pos_x - wall->map_x)
			* wall->deltadist_x;
	}
	else
	{
		wall->step_x = 1;
		wall->sidedist_x = (wall->map_x + 1.0 - info->pos_x)
			* wall->deltadist_x;
	}
	if (wall->raydir_y < 0)
	{
		wall->step_y = -1;
		wall->sidedist_y = (info->pos_y - wall->map_y)
			* wall->deltadist_y;
	}
	else
	{
		wall->step_y = 1;
		wall->sidedist_y = (wall->map_y + 1.0 - info->pos_y)
			* wall->deltadist_y;
	}
}

void	calc_wall(t_info *info, int x)
{
	t_wall	wall;

	set_wall_info(&wall, info, x);
	set_sidedist(&wall, info, x);
	work_dda(&wall, info, x);
	wallpoint(&wall, info, x);
	put_in_wallbuf(&wall, info, x);
}
