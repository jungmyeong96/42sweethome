/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_wall2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:26:15 by junghan           #+#    #+#             */
/*   Updated: 2021/03/24 02:48:33 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_news(t_wall *wall, t_info *info)
{
	if (wall->side == 1 && ((wall->raydir_x >= 0 && wall->raydir_y > 0)
				|| (wall->raydir_x < 0 && wall->raydir_y > 0)))
	{
		wall->color = info->texture[0][info->texwh[0].tex_h * wall->tex_y
			+ wall->tex_x];
	}
	if (wall->side == 1 && ((wall->raydir_x <= 0 && wall->raydir_y < 0)
				|| (wall->raydir_x > 0 && wall->raydir_y < 0)))
	{
		wall->color = info->texture[1][info->texwh[1].tex_h * wall->tex_y
			+ wall->tex_x];
	}
	if (wall->side == 0 && ((wall->raydir_x < 0 && wall->raydir_y <= 0)
				|| (wall->raydir_x < 0 && wall->raydir_y > 0)))
	{
		wall->color = info->texture[2][info->texwh[2].tex_h * wall->tex_y
			+ wall->tex_x];
	}
	if (wall->side == 0 && ((wall->raydir_x > 0 && wall->raydir_y >= 0)
				|| (wall->raydir_x > 0 && wall->raydir_y < 0)))
	{
		wall->color = info->texture[3][info->texwh[3].tex_h * wall->tex_y
			+ wall->tex_x];
	}
}

void	cal_in(t_wall *wall, t_info *info, int x)
{
	int	y;

	wall->step = 1.0 * info->texwh[0].tex_h / wall->line_hei;
	wall->tex_pos = (wall->drawstart - info->pitch - (info->pos_z
				/ wall->perpwall_d) - info->win_hei / 2
			+ wall->line_hei / 2) * wall->step;
	y = wall->drawstart;
	while (y < wall->drawend)
	{
		wall->tex_y = (int)wall->tex_pos & (info->texwh[0].tex_h - 1);
		wall->tex_pos += wall->step;
		check_news(wall, info);
		info->wall_h = wall->drawend - wall->drawstart;
		if (info->wall_h < info->win_mid)
		{
			wall_shadow(info, wall, y);
		}
		info->buf[y][x] = wall->color;
		y++;
	}
}

void	put_in_wallbuf(t_wall *wall, t_info *info, int x)
{
	wall->tex_x = (int)(wall->wall_tmp * (double)info->texwh[0].tex_w);
	if (wall->side == 0 && wall->raydir_x > 0)
		wall->tex_x = info->texwh[0].tex_w - wall->tex_x - 1;
	if (wall->side == 1 && wall->raydir_y < 0)
		wall->tex_x = info->texwh[0].tex_w - wall->tex_x - 1;
	cal_in(wall, info, x);
	diff_wall_floor(wall);
	fc_draw(wall, info, x);
	info->z_buffer[x] = wall->perpwall_d;
}
