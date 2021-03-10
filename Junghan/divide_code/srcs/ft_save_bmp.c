/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_save_bmp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:55:21 by junghan           #+#    #+#             */
/*   Updated: 2021/03/08 13:39:20 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	image_bmp(t_info *info, t_save *s)
{
	int	i;
	int	j;
	int	x;
	int	y;

	j = -1;
	while (++j < info->win_hei)
	{
		i = -1;
		while (++i < info->win_wid)
		{
			x = i;
			y = info->win_hei - 1 - j;
			s->color_b = info->img.data[y * info->win_wid + x];
			write(s->fd_b, &s->color_b, 3);
		}
		i = -1;
		while (++i < (4 - (info->win_wid * 3) % 4) % 4)
			write(s->fd_b, &s->pad, 1);
	}
}

static void	header_set(unsigned char *header, int bit)
{
	header[0] = (unsigned char)(bit);
	header[1] = (unsigned char)(bit >> 8);
	header[2] = (unsigned char)(bit >> 16);
	header[3] = (unsigned char)(bit >> 24);
}

static void	header_bmp(t_info *info, t_save *s)
{
	int	i;

	i = 0;
	while (i < 14)
		s->header[i++] = 0;
	s->header[0] = 'B';
	s->header[1] = 'M';
	s->header[10] = 54;
	i = 0;
	while (i < 40)
		s->data[i++] = 0;
	s->data[0] = 40;
	s->data[12] = 1;
	s->data[14] = 24;
	i = 0;
	while (i < 3)
		s->pad[i++] = 0;
	header_set(&s->header[2], s->size_b);
	header_set(&s->data[4], info->win_wid);
	header_set(&s->data[8], info->win_hei);
	write(s->fd_b, s->header, 14);
	write(s->fd_b, s->data, 40);
}

void		save_bmp(t_info *info)
{
	if (info->is_save == 1)
	{
		info->save.size_b = 54 + 3 * info->win_wid * info->win_hei;
		if ((info->save.fd_b = open("save.bmp", O_CREAT
						| O_WRONLY, S_IRWXU)) < 0)
			error_exit("Error : create bmp fail!");
		header_bmp(info, &info->save);
		image_bmp(info, &info->save);
		close(info->save.fd_b);
		info->is_save = 0;
	}
}
