/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_calc_wall2.c                                    :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: junghan <junghan@student.42seoul.kr>	   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2021/03/08 12:13:07 by junghan		   #+#	#+#			 */
/*   Updated: 2021/03/12 09:10:08 by junghan          ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "cub3d.h"

void	jump_draw(t_wall *wall, t_info *info, int x)
{
	int		y;
	double	c;

	c = (wall->drawend + wall->drawstart) / 2;
	wall->distw = wall->perpwall_d;
	wall->distp = 0.0;

	if(wall->drawend < 0)
		wall->drawend = info->win_hei; //becomes < 0 when the integer overflows
	
	y = 0;
	while (y < wall->drawstart)
	  {
		wall->cur_d = (info->win_hei - (2.0 * info->pos_z)) / (info->win_hei - 2.0 * (y - info->pitch));

		wall->weight = (wall->cur_d - wall->distp) / (wall->distw - wall->distp);
		wall->cur_fx = wall->weight * wall->floor_xw + (1.0 - wall->weight) * info->pos_x;
		wall->cur_fy = wall->weight * wall->floor_yw + (1.0 - wall->weight) * info->pos_y;
		wall->floor_xt = (int)(wall->cur_fx * TEXWID) & (TEXWID - 1);
		wall->floor_yt = (int)(wall->cur_fy * TEXHEI) & (TEXHEI - 1);
		info->buf[y][x] = info->texture[6][TEXWID * wall->floor_yt + wall->floor_xt];
		if (y > c * 0.9 && y < c * 0.91)
			info->buf[y][x] = ((info->texture[6][TEXWID * wall->floor_yt + wall->floor_xt]) & 8355711);
		else if (y >= c * 0.91 && y < c * 0.92)
			info->buf[y][x] = ((info->texture[6][TEXWID * wall->floor_yt + wall->floor_xt] >> 1) & 8355711);
		else if (y >= c * 0.92 && y < c * 0.94)
			info->buf[y][x] = (((info->texture[6][TEXWID * wall->floor_yt + wall->floor_xt] >> 1) & 8355711) >> 1) & 8355711;
		else if (y >= c * 0.94 && y < c)
			info->buf[y][x] = (((((info->texture[6][TEXWID * wall->floor_yt + wall->floor_xt]) & 8355711) >> 1) & 8355711) >> 1) & 8355711;
		//info->buf[y][x] = info->texture[6][TEXWID * wall->floor_yt + wall->floor_xt];
		y++;
	  }
	  
	y = wall->drawend + 1;
	  while (y < info->win_hei)
	  {
		wall->cur_d = (info->win_hei + (2.0 * info->pos_z)) 
			/ (2.0 * (y - info->pitch) - info->win_hei);
		wall->weight = (wall->cur_d - wall->distp) / (wall->distw - wall->distp);
		wall->cur_fx = wall->weight * wall->floor_xw + (1.0 - wall->weight) * info->pos_x;
		wall->cur_fy = wall->weight * wall->floor_yw + (1.0 - wall->weight) * info->pos_y;
		wall->floor_xt = (int)(wall->cur_fx * TEXWID) & (TEXWID - 1);
		wall->floor_yt = (int)(wall->cur_fy * TEXHEI) & (TEXHEI - 1);

		info->buf[y][x] = (info->texture[5][TEXWID * wall->floor_yt + wall->floor_xt] >> 1)& 8355711;
		if (y > c * 1.09 && y < c * 1.1)
			info->buf[y][x] = ((info->texture[5][TEXWID * wall->floor_yt + wall->floor_xt]) & 8355711);
		else if (y > c * 1.08 && y <= c * 1.09)
			info->buf[y][x] = ((info->texture[5][TEXWID * wall->floor_yt + wall->floor_xt] >> 1) & 8355711);
		else if (y > c * 1.06 && y <= c * 1.08)
			info->buf[y][x] = (((info->texture[5][TEXWID * wall->floor_yt + wall->floor_xt] >> 1) & 8355711) >> 1) & 8355711;
		else if (y > c  && y <= c * 1.06)
			info->buf[y][x] = (((((info->texture[5][TEXWID * wall->floor_yt + wall->floor_xt]) & 8355711) >> 1) & 8355711) >> 1) & 8355711;

		y++;
	  }
}

void	check_news(t_wall *wall, t_info *info)
{
	if (wall->side == 1 && ((wall->raydir_x >= 0 && wall->raydir_y > 0)
				|| (wall->raydir_x < 0 && wall->raydir_y > 0)))
	{
		wall->color = info->texture[0][TEXHEI * wall->tex_y
			+ wall->tex_x];
//		wall->floor_xw = wall->map_x + wall->wall_tmp;
//		wall->floor_yw = wall->map_y;
	}
	if (wall->side == 1 && ((wall->raydir_x <= 0 && wall->raydir_y < 0)
				|| (wall->raydir_x > 0 && wall->raydir_y < 0)))
	{
		wall->color = info->texture[1][TEXHEI * wall->tex_y
			+ wall->tex_x];
//		wall->floor_xw = wall->map_x + wall->wall_tmp;
//		wall->floor_yw = wall->map_y + 1.0;
	}
	if (wall->side == 0 && ((wall->raydir_x < 0 && wall->raydir_y <= 0)
				|| (wall->raydir_x < 0 && wall->raydir_y > 0)))
	{
		wall->color = info->texture[2][TEXHEI * wall->tex_y
			+ wall->tex_x];
//		wall->floor_xw = wall->map_x + 1.0;
//		wall->floor_yw = wall->map_y + wall->wall_tmp;
	}
	if (wall->side == 0 && ((wall->raydir_x > 0 && wall->raydir_y >= 0)
				|| (wall->raydir_x > 0 && wall->raydir_y < 0)))
	{
		wall->color = info->texture[3][TEXHEI * wall->tex_y
			+ wall->tex_x];
//		wall->floor_xw = wall->map_x;
//		wall->floor_yw = wall->map_y + wall->wall_tmp;
	}
}

void	diff_wall_floor(t_wall *wall, t_info *info)
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

void	cal_in(t_wall *wall, t_info *info, int x)
{
	int	y;

	wall->step = 1.0 * TEXHEI / wall->line_hei;
	wall->tex_pos = (wall->drawstart - info->pitch -(info->pos_z 
				/ wall->perpwall_d) - info->win_hei / 2
			+ wall->line_hei / 2) * wall->step;
	y = wall->drawstart;
	while (y < wall->drawend)
	{
		wall->tex_y = (int)wall->tex_pos & (TEXHEI - 1);
		wall->tex_pos += wall->step;
		check_news(wall, info);
		info->buf[y][x] = wall->color;
		y++;
	}
}

void	put_in_wallbuf(t_wall *wall, t_info *info, int x)
{
	int	y;

	wall->tex_x = (int)(wall->wall_tmp * (double)TEXWID);
	if (wall->side == 0 && wall->raydir_x > 0)
		wall->tex_x = TEXWID - wall->tex_x - 1;
	if (wall->side == 1 && wall->raydir_y < 0)
		wall->tex_x = TEXWID - wall->tex_x - 1;
	cal_in(wall, info, x);
	diff_wall_floor(wall, info);
	jump_draw(wall, info, x);
	info->z_buffer[x] = wall->perpwall_d;
}
