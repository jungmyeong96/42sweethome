/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_yorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 03:46:10 by junghan           #+#    #+#             */
/*   Updated: 2021/03/24 02:32:37 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_yorn(t_info *info, t_img *i, int n, char *path)
{
	int	y;
	int	x;

	y = -1;
	info->keys.yorn = 1;
	while (++y < i->img_height)
	{
		x = -1;
		while (++x < i->img_width)
		{
			if (info->texture[n][i->img_width * y + x] != -16777216)
				info->buf[y + (int)(info->win_hei * 0.125)]
					[x + (int)(info->win_wid * 0.125)] =
					info->texture[n][i->img_width * y + x];
		}
	}
	if (info->keys.key_o == 1)
		next_stage(info, path);
	free(info->texture[n]);
}

void	show_yorn(t_info *info, t_img *img, char *path)
{
	int		x;
	int		y;

	img->img = mlx_xpm_file_to_image(info->mlx,
			path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img,
			&img->bpp, &img->size_l, &img->endian);
	tex_wh(info, 8, img);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			info->texture[8][img->img_width * y + x] =
				img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
	if (info->keys.health <= 0)
		put_yorn(info, img, 8, "ex.cub");
	else if (info->level_up == 1)
		put_yorn(info, img, 8, info->stage);
}
