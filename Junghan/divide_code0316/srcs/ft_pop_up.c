/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_up.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 20:59:05 by junghan           #+#    #+#             */
/*   Updated: 2021/03/16 06:54:29 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	show_hp(t_info *info, t_img *img, char *path)
{
	int		x;
	int		y;

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

void	check_hurt(t_info *info, t_keys *keys)
{
	t_img imgg;

	if (keys->hurt)
	{
		keys->health--;
		keys->hurt = 0;
	}
	if (keys->health == 5)
		show_hp(info, &imgg, "../textures/hp5.xpm");
	else if (keys->health == 4)
		show_hp(info, &imgg, "../textures/hp4.xpm");
	else if (keys->health == 3)
		show_hp(info, &imgg, "../textures/hp3.xpm");
	else if (keys->health == 2)
		show_hp(info, &imgg, "../textures/hp2.xpm");
	else if (keys->health == 1)
		show_hp(info, &imgg, "../textures/hp1.xpm");
	else if (keys->health == 0)
		error_exit("Game Over!!!! GG\n");
}

void	pop_up(t_info *info)
{
	check_hurt(info, &info->keys);
//	show_map(info, &info->img);
}
