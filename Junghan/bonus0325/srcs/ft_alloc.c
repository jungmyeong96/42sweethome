/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_alloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 11:09:50 by junghan           #+#    #+#             */
/*   Updated: 2021/03/24 05:50:18 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		**alloc_mini(t_info *info)
{
	int i;

	if (!(info->minimap = (int **)ft_calloc((int)(info->win_hei
		/ 6), sizeof(int *))))
		error_exit("some error in malloc");
	i = 0;
	while (i < info->win_hei / 6)
	{
		if (!(info->minimap[i] = (int *)ft_calloc((int)(info->win_wid
						/ 3), sizeof(int))))
			error_exit("some error in mallc");
		i++;
	}
	return (0);
}

int		**alloc_arr(t_info *info)
{
	int	i;

	if (!(info->buf = (int **)ft_calloc(info->win_hei, sizeof(int *))))
		error_exit("some error in malloc");
	if (!(info->z_buffer = (double *)ft_calloc(info->win_wid, sizeof(double))))
		error_exit("some error in malloc");
	i = 0;
	while (i < info->win_hei)
	{
		if (!(info->buf[i] = (int *)ft_calloc(info->win_wid, sizeof(int))))
			error_exit("some error in mallc");
		i++;
	}
	return (0);
}
