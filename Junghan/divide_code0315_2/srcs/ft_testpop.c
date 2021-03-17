/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_testpop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 02:59:07 by junghan           #+#    #+#             */
/*   Updated: 2021/03/16 05:11:25 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pop_up_draw(t_info *info)
{
	int	y;
	int	x;

	printf("dddd\n");
	y = -1;
	while (++y < info->win_hei)
	{
		x = -1;
		while (++x < info->win_wid)
		{
			info->img.data[y * info->win_wid + x] = info->buf[y][x];
			info->buf[y][x] = 0;
			printf("x %d y %d\n", x, y);
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	put_in_buf(t_info *info, t_img *img)
{
	int	y;
	int	x;
	int	z;


	z = 0;
	y = 0;
	printf("hei%d\n", info->win_hei);
	while (z < img->img_height+ info->win_hei / 2)
	{
		y = info->win_hei / 2 + z;
		x = 0;
		printf("imgwid %d imghei %d \n", img->img_width , img->img_height);
		
		while (x < img->img_width && z < img->img_height)
		{
			info->buf[y][x] = info->texture[7][img->img_width * z + x];
			x++;
		}
		z++;
		printf("z%d y%d x%d\n", z, y, x);
	}
	pop_up_draw(info);

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
		printf("i %dj %d\n",i, j);
	}
}
*/

void	show_hp(t_info *info)
{
	int		x;
	int		y;
	char	*path;
	t_img	imgg;

	path = "../textures/scouge3.xpm";
	imgg.img = mlx_xpm_file_to_image(info->mlx,
			path, &imgg.img_width, &imgg.img_height);
	imgg.data = (int *)mlx_get_data_addr(imgg.img,
			&imgg.bpp, &imgg.size_l, &imgg.endian);
	y = -1;
	while (++y < imgg.img_height)
	{
		x = -1;
		while (++x < imgg.img_width)
			info->texture[7][imgg.img_width * y + x] =
				imgg.data[imgg.img_width * y + x];
	}
	//printf("x %d y %d\n", x, y);
	put_in_buf(info, &imgg);
	mlx_destroy_image(info->mlx, imgg.img);
}

int	pop_lup(t_info *info)
{
	show_hp(info);
//	show_map(info, &info->img);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	info.mlx = mlx_init();
	info.win_wid = 640;
	info.win_hei = 480;
	alloc_arr(&info);
	info.win = mlx_new_window(info.mlx, info.win_wid, info.win_hei, "mlx");
	info.img.img = mlx_new_image(info.mlx, info.win_wid, info.win_hei);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp,
			&info.img.size_l, &info.img.endian);
	mlx_loop_hook(info.mlx, &pop_lup, &info);
	mlx_loop(info.mlx);
	return (0);
}
