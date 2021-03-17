/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:59:05 by junghan           #+#    #+#             */
/*   Updated: 2021/03/16 05:39:47 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
/*
void	pop_up_draw(t_info *info)
{
	int	y;
	int	x;

	y = -1;
	while (++y < info->win_hei)
	{
		x = -1;
		while (++x < info->win_wid)
		{
			info->img.data[y * info->win_wid + x] = info->buf[y][x];
			info->buf[y][x] = 0;
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}
*/

void	put_in_buf(t_info *info, t_img *img)
{
	int	y;
	int	x;
	int	z;


	z = 0;
	y = 0;
	while (y < img->img_height + info->win_hei / 2)
	{
		y = info->win_hei * 0.02 + z;
		x = 0;
		while (x < img->img_width && z < img->img_height)
		{
			if (info->texture[7][img->img_width * z + x] != -16777216)
				info->buf[y][x] = info->texture[7][img->img_width * z + x];
			x++;
		}
		z++;
	}
}

/*
void	put_in_buf(t_info *info, t_img *img)
{
	int	y;
	int	x;
	int	i;
	int	j;

	y = 0;
	i = 0;
	while (y < info->win_hei)
	{
		x = 0;
		j = 0;
		while (x < info->win_wid)
		{
			if (y > info->win_hei - img->img_height * 2 && y < info->win_hei - img->img_height)
				if (x >= info->win_wid / 2 - img->img_width / 2 && x <= info->win_wid / 2 + img->img_width / 2)
				{
					info->buf[y][x] = info->texture[7][img->img_width * i + j];
					j++;
				}
				x++;
		}
		y++;
		if (j > info->win_wid - img->img_width / 2)
			i++;
	}
}*/

void	show_hp(t_info *info, t_img *img)
{
	int		x;
	int		y;
	char	*path;

	path = "../textures/hp256_64.xpm";
	img->img = mlx_xpm_file_to_image(info->mlx,
			path, &img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img,
			&img->bpp, &img->size_l, &img->endian);
	y = -1;
	while (++y < img->img_height)
	{
		x = -1;
		while (++x < img->img_width)
			info->texture[7][img->img_width * y + x] =
				img->data[img->img_width * y + x];
	}
	mlx_destroy_image(info->mlx, img->img);
	put_in_buf(info, img);
}

void	pop_up(t_info *info)
{
	t_img imgg;

	show_hp(info, &imgg);
//	show_map(info, &info->img);
}
