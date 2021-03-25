/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fc_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 07:51:14 by junghan           #+#    #+#             */
/*   Updated: 2021/03/25 02:43:32 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ceil_in_buf(t_wall *wall, t_info *info, int x, int y)
{
	wall->cur_d = (info->win_hei - (2.0 * info->pos_z))
		/ (info->win_hei - 2.0 * (y - info->pitch));
	wall->weight = (wall->cur_d - wall->distp)
		/ (wall->distw - wall->distp);
	wall->cur_fx = wall->weight * wall->floor_xw
		+ (1.0 - wall->weight) * info->pos_x;
	wall->cur_fy = wall->weight * wall->floor_yw
		+ (1.0 - wall->weight) * info->pos_y;
	wall->floor_xt = (int)(wall->cur_fx
			* info->texwh[6].tex_w) & (info->texwh[6].tex_w - 1);
	wall->floor_yt = (int)(wall->cur_fy
			* info->texwh[6].tex_h) & (info->texwh[6].tex_h - 1);
	info->buf[y][x] = info->texture[6][info->texwh[6].tex_w * wall->floor_yt
		+ wall->floor_xt];
}

void	floor_in_buf(t_wall *wall, t_info *info, int x, int y)
{
	wall->cur_d = (info->win_hei + (2.0 * info->pos_z))
		/ (2.0 * (y - info->pitch) - info->win_hei);
	wall->weight = (wall->cur_d - wall->distp)
		/ (wall->distw - wall->distp);
	wall->cur_fx = wall->weight * wall->floor_xw
		+ (1.0 - wall->weight) * info->pos_x;
	wall->cur_fy = wall->weight * wall->floor_yw
		+ (1.0 - wall->weight) * info->pos_y;
	wall->floor_xt = (int)(wall->cur_fx
			* info->texwh[5].tex_w) & (info->texwh[5].tex_w - 1);
	wall->floor_yt = (int)(wall->cur_fy
			* info->texwh[5].tex_h) & (info->texwh[5].tex_h - 1);
	info->buf[y][x] = (info->texture[5][info->texwh[5].tex_w * wall->floor_yt
			+ wall->floor_xt] >> 1) & 8355711;
}

void	fc_draw(t_wall *wall, t_info *info, int x)
{
	int	y;

	info->floor_h = wall->drawend - info->win_hei / 2;
	info->ceil_h = info->win_hei / 2 - wall->drawstart;
	wall->distw = wall->perpwall_d;
	wall->distp = 0.0;
	if (wall->drawend < 0)
		wall->drawend = info->win_hei;
	y = 0;
	while (y < wall->drawstart)
	{
		ceil_in_buf(wall, info, x, y);
		ceiling_shadow(wall, info, x, y);
		y++;
	}
	y = wall->drawend + 1;
	while (y < info->win_hei)
	{
		floor_in_buf(wall, info, x, y);
		floor_shadow(wall, info, x, y);
		y++;
	}
}

void	diff_wall_floor(t_wall *wall)
{
	if (wall->side == 1 && ((wall->raydir_x >= 0 && wall->raydir_y > 0)
				|| (wall->raydir_x < 0 && wall->raydir_y > 0)))
	{
		wall->floor_xw = wall->map_x + wall->wall_tmp;
		wall->floor_yw = wall->map_y;
	}
	if (wall->side == 1 && ((wall->raydir_x <= 0 && wall->raydir_y < 0)
				|| (wall->raydir_x > 0 && wall->raydir_y < 0)))
	{
		wall->floor_xw = wall->map_x + wall->wall_tmp;
		wall->floor_yw = wall->map_y + 1.0;
	}
	if (wall->side == 0 && ((wall->raydir_x < 0 && wall->raydir_y <= 0)
				|| (wall->raydir_x < 0 && wall->raydir_y > 0)))
	{
		wall->floor_xw = wall->map_x + 1.0;
		wall->floor_yw = wall->map_y + wall->wall_tmp;
	}
	if (wall->side == 0 && ((wall->raydir_x > 0 && wall->raydir_y >= 0)
				|| (wall->raydir_x > 0 && wall->raydir_y < 0)))
	{
		wall->floor_xw = wall->map_x;
		wall->floor_yw = wall->map_y + wall->wall_tmp;
	}
}
