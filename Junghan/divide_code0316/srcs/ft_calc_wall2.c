/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_wall2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:26:15 by junghan           #+#    #+#             */
/*   Updated: 2021/03/16 04:28:55 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_news(t_wall *wall, t_info *info)
{
	if (wall->side == 1 && ((wall->raydir_x >= 0 && wall->raydir_y > 0)
				|| (wall->raydir_x < 0 && wall->raydir_y > 0)))
	{
		wall->color = info->texture[0][TEXHEI * wall->tex_y
			+ wall->tex_x];
	}
	if (wall->side == 1 && ((wall->raydir_x <= 0 && wall->raydir_y < 0)
				|| (wall->raydir_x > 0 && wall->raydir_y < 0)))
	{
		wall->color = info->texture[1][TEXHEI * wall->tex_y
			+ wall->tex_x];
	}
	if (wall->side == 0 && ((wall->raydir_x < 0 && wall->raydir_y <= 0)
				|| (wall->raydir_x < 0 && wall->raydir_y > 0)))
	{
		wall->color = info->texture[2][TEXHEI * wall->tex_y
			+ wall->tex_x];
	}
	if (wall->side == 0 && ((wall->raydir_x > 0 && wall->raydir_y >= 0)
				|| (wall->raydir_x > 0 && wall->raydir_y < 0)))
	{
		wall->color = info->texture[3][TEXHEI * wall->tex_y
			+ wall->tex_x];
	}
}

void	cal_in(t_wall *wall, t_info *info, int x)
{
	int	y;

	wall->step = 1.0 * TEXHEI / wall->line_hei;
	wall->tex_pos = (wall->drawstart - info->pitch - (info->pos_z
				/ wall->perpwall_d) - info->win_hei / 2
			+ wall->line_hei / 2) * wall->step;
	y = wall->drawstart;
	while (y < wall->drawend)
	{
		wall->tex_y = (int)wall->tex_pos & (TEXHEI - 1);
		wall->tex_pos += wall->step;
		check_news(wall, info);
		info->wall_h = wall->drawend - wall->drawstart;
//		printf("wall_h %d win_mid %f\n",info->wall_h, info->win_mid);
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
	wall->tex_x = (int)(wall->wall_tmp * (double)TEXWID);
	if (wall->side == 0 && wall->raydir_x > 0)
		wall->tex_x = TEXWID - wall->tex_x - 1;
	if (wall->side == 1 && wall->raydir_y < 0)
		wall->tex_x = TEXWID - wall->tex_x - 1;
	cal_in(wall, info, x);
	diff_wall_floor(wall);
	fc_draw(wall, info, x);
	info->z_buffer[x] = wall->perpwall_d;
}
