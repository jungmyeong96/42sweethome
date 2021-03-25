/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sp_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:32:06 by junghan           #+#    #+#             */
/*   Updated: 2021/03/25 05:13:28 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sp_get_offset(t_info *info, int i, int j, int *k)
{
	if (info->map[i][j] == '2')
	{
		info->sprite_arr[*k].x = i + 0.5;
		info->sprite_arr[*k].y = j + 0.5;
		info->sprite_arr[(*k)++].tex = 10; 
	}
	else if (info->map[i][j] == '3')
	{
		info->sprite_arr[*k].x = i + 0.5;
		info->sprite_arr[*k].y = j + 0.5;
		info->sprite_arr[(*k)++].tex = 11;
	}
	else if (info->map[i][j] == '4')
	{
		info->sprite_arr[*k].x = i + 0.5;
		info->sprite_arr[*k].y = j + 0.5;
		info->sprite_arr[(*k)++].tex = 12;
	}
	else if (info->map[i][j] == '5')
	{
		info->sprite_arr[*k].x = i + 0.5;
		info->sprite_arr[*k].y = j + 0.5;
		info->sprite_arr[(*k)++].tex = 13;
	}
}

void	count_item(char sp, t_info *info)
{
	if (sp == '2')
		info->sp2++;
	else if (sp == '3')
		info->sp3++;
	else if (sp == '4')
		info->sp4++;
	else if (sp == '5')
		info->sp5++;
}

void	sp_data(t_info *info, char **data)
{
	int		fd;
	int		n;

	n = 1;
	while (n < 5)
	{
		if (data == 0 || ft_check_extation(data[n], ".xpm") == 0)
			error_exit("[ERROR] no such path to xpm\n!");
		fd = open(data[n], O_RDONLY);
		if (fd == -1)
			error_exit("[ERROR] no such xpm!\n");
		close(fd);
		load_image(info, n + 9, data[n], &info->img);
		n++;
	}
}
