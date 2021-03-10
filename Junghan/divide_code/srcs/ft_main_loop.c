/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:02:59 by junghan           #+#    #+#             */
/*   Updated: 2021/03/11 02:11:22 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_draw(t_info *info)
{
	int	y;
	int	x;

	y = -1;
	while (++y < info->win_hei)
	{
		x = -1;
		while (++x < info->win_wid)
			info->img.data[y * info->win_wid + x] = info->buf[y][x];
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	map_calc(t_info *info)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	while (y < info->win_hei)
	{
		calc_floor(info, y);
		y++;
	}
	x = 0;
	while (x < info->win_wid)
	{
		calc_wall(info, x);
		x++;
	}
	calc_sprite(info);
}

int	main_loop(t_info *info)
{
	map_calc(info);
	map_draw(info);
	save_bmp(info);
	key_updapt(info, &info->keys);
//	ft_movement(info);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;
	char	*tmp;

	info.mlx = mlx_init();
	init_arr(&info);
	arg_protect(&info, argc, argv);
	open_mapfile(&info, argv[1]);
	get_file(&info);
	alloc_arr(&info);
	parse_map(&info);
	init_keys(&info.keys, &info);
	info.win = mlx_new_window(info.mlx, info.win_wid, info.win_hei, "mlx");
	info.img.img = mlx_new_image(info.mlx, info.win_wid, info.win_hei);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp,
			&info.img.size_l, &info.img.endian);
	mlx_hook(info.win, 2, 0, &ft_key_press, &info.keys);
	mlx_hook(info.win, 3, 0, &ft_key_release, &info.keys);
	mlx_hook(info.win, 17, 0, &ft_click_exit, &info.keys);
	mlx_hook(info.win, 6, 0, &mouse_move, &info);
	mlx_loop_hook(info.mlx, &main_loop, &info);
	mlx_loop(info.mlx);
	return (0);
}
