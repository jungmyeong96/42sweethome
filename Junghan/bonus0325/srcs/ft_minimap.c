/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minimap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:02:59 by junghan           #+#    #+#             */
/*   Updated: 2021/03/24 05:40:31 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_background(t_info *info)
{
	int	i;
	int j;

	j = 0;
	while (j < info->win_hei / 6)
	{
		i = 0;
		while (i < info->win_wid / 3)
		{
			info->minimap[j][i] = 0x111111 + info->buf[j]
			[i + info->win_wid * 2 / 3];
			i++;
		}
		j++;
	}
}

void	get_pos(t_info *info, int j, int i)
{
	if (j >= 2 * ((info->win_hei / 6) / 5)
			&& j <= 3 * ((info->win_hei / 6) / 5))
		if (i >= 3 * ((info->win_wid / 3) / 7)
				&& i <= 4 * ((info->win_wid / 3) / 7))
			info->minimap[j][i] = 0xFD93F999;
}

void	wall_minimap(t_info *info, int j, int i)
{
	if ((j / (int)((info->win_hei / 6) / 5) + (int)info->pos_x >= 2) &&
			(int)(j / ((info->win_hei / 6) / 5) + info->pos_x - 2)
			< info->map_lines)
	{
		if (i / (int)((info->win_wid / 3) / 7) + (int)info->pos_y >= 3 &&
				(int)(i / ((info->win_wid / 3) / 7) + info->pos_y - 3)
				< (int)ft_strlen(info->map[(int)(j / ((info->win_hei / 6) / 5)
				+ info->pos_x - 2)]))
		{
			if (info->map[(int)(j / ((info->win_hei / 6) / 5)
					+ info->pos_x - 2)][(int)(i / ((info->win_wid / 3) / 7)
					+ info->pos_y - 3)] == '1')
				info->minimap[j][i] = 0xFF0000;
			else if (info->map[(j / ((info->win_hei / 6) / 5)
					+ (int)info->pos_x) - 2][i / (int)((info->win_wid / 3) / 7)
					+ (int)info->pos_y - 3] == '2')
				info->minimap[j][i] = 0x00FF00;
			else if (info->map[j / (int)((info->win_hei / 6) / 5)
					+ (int)info->pos_x - 2][i / (int)((info->win_wid / 3) / 7)
					+ (int)info->pos_y - 3] == '0')
				info->minimap[j][i] = 0x111111 + info->buf[j]
					[i + (int)(info->win_wid * 2 / 3)];
		}
	}
}

void	get_minimap(t_info *info)
{
	int	i;
	int j;

	j = -1;
	while (++j < (int)(info->win_hei / 6))
	{
		i = -1;
		while (++i < (int)(info->win_wid / 3))
		{
			wall_minimap(info, j, i);
			get_pos(info, j, i);
		}
	}
}

void	rend_minimap(t_info *info)
{
	int	i;
	int j;
	int k;

	map_background(info);
	get_minimap(info);
	j = 0;
	while (j < info->win_hei / 6)
	{
		i = info->win_wid * 2 / 3;
		k = 0;
		while (i < info->win_wid && k < (int)(info->win_wid / 3))
		{
			info->buf[j][i] = info->minimap[j][k];
			info->minimap[j][k] = 0;
			k++;
			i++;
		}
		j++;
	}
}
