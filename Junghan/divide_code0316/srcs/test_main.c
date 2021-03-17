/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:02:59 by junghan           #+#    #+#             */
/*   Updated: 2021/03/17 00:09:39 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_info *info, t_map *map)
{
	int	draw_position;
	int	i;

	i = 0;
	while (i < map->row_c)
	{
		draw_position = 0;
		while (draw_position <= info->win_wid)
		{
			mlx_pixel_put(info->mlx, info->win, draw_position, i * (info->win_hei / map->row_c), map->grid_color);
			draw_position++;
		}
		i++;
	}
	i = 0;
	while (i < map->col_c)
	{
		draw_position = 0;
		while (draw_position <= info->win_wid)
		{
			mlx_pixel_put(info->mlx, info->win, i * (info->win_wid / map->col_c), draw_position, map->grid_color);
			draw_position++;
		}
		i++;
	}
}

void	init_player(t_info *info, t_map *map)
{
	mlx_pixel_put(info->mlx, info->win, info->pos_x, info->pos_y, map->init_color);
}

int	pop_map(t_info *info)
{
	init_player(info, &info->hud_map);
	draw_map(info, &info->hud_map);
//	key_updapt(info, &info->keys);
	return (0);
}

int	main(int argc, char **argv)
{
	t_info	info;

	info.mlx = mlx_init();
	init_arr(&info);
	arg_protect(&info, argc, argv);
	open_mapfile(&info, argv[1]);
	get_file(&info);
	alloc_arr(&info);
	parse_map(&info);
	init_keys(&info.keys, &info);
	info.hud_map.init_color = 0xFF0000;
	info.hud_map.grid_color = 0x0000FF;
	info.hud_map.row_c = 10;
	info.hud_map.col_c = 10;
	info.win = mlx_new_window(info.mlx, info.win_wid, info.win_hei, "mlx");
	info.img.img = mlx_new_image(info.mlx, info.win_wid, info.win_hei);
	info.img.data = (int *)mlx_get_data_addr(info.img.img, &info.img.bpp,
			&info.img.size_l, &info.img.endian);
//	mlx_hook(info.win, 2, 0, &ft_key_press, &info.keys);
//	mlx_hook(info.win, 3, 0, &ft_key_release, &info.keys);
//
//mlx_hook(info.win, 17, 0, &ft_click_exit, &info.keys);
	mlx_loop_hook(info.mlx, &pop_map, &info);
	mlx_loop(info.mlx);
	return (0);
}
