/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:02:59 by junghan           #+#    #+#             */
/*   Updated: 2021/03/18 01:59:30 by junghan          ###   ########.fr       */
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
		{
			info->img.data[y * info->win_wid + x] = info->buf[y][x];
			info->buf[y][x] = 0;
		}
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img.img, 0, 0);
}

void	map_background(t_info *info, t_map *map)
{
	int	i;
	int j;

	j = 0;
	while (j < info->win_hei / 6)
	{
		i = 0;
		while (i < info->win_wid / 3)
		{
			info->minimap[j][i] = map->grid_color;
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
		{
//			if (info->map[j / ((info->win_hei / 6) / 5) + (int)info->pos_x][i / ((info->win_wid / 3) / 7) + (int)info->pos_y] == '1')
//				info->minimap[j][i] = 0xFF0000;
//			else if (info->map[j / ((info->win_hei / 6) / 5) + (int)info->pos_x][i / ((info->win_wid / 3) / 7) + (int)info->pos_y] == '2')
//				info->minimap[j][i] = 0x00FF00;
//			else if (info->map[j / ((info->win_hei / 6) / 5) + (int)info->pos_x][i / ((info->win_wid / 3) / 7) + (int)info->pos_y] == '0')
//				info->minimap[j][i] = 0x0000FF;
			info->minimap[j][i] =  0xFD93F9;
		}
}

void	get_minimap(t_info *info)
{
	int	i;
	int j;
	int tmp_px;
	int	tmp_py;

	j = 0;
	while (j < info->win_hei / 6 - 1)
	{
		i = 0;
		while (i < info->win_wid / 3) //protect need
		{
//			printf("posx%d posy%d\n", (int)info->pos_x, (int)info->pos_y);
			if ((int)info->pos_x > 1)
				tmp_px = (int)info->pos_x - 2;
			else
				tmp_px = (int)floor(info->pos_x);
			if ((int)info->pos_y > 2)
				tmp_py = (int)info->pos_y - 3;
			else 
				tmp_py = (int)floor(info->pos_y);
			
			if (info->map[j / ((info->win_hei / 6) / 5) + tmp_px][i / ((info->win_wid / 3) / 7) + tmp_py] != '\0')
			{
				if (info->map[j / ((info->win_hei / 6) / 5) + tmp_px][i / ((info->win_wid / 3) / 7) + tmp_py] == '1')
					info->minimap[j][i] = 0xFF0000;
				else if (info->map[j / ((info->win_hei / 6) / 5) + tmp_px][i / ((info->win_wid / 3) / 7) + tmp_py] == '2')
					info->minimap[j][i] = 0x00FF00;
				else if (info->map[j / ((info->win_hei / 6) / 5) + tmp_px][i / ((info->win_wid / 3) / 7) + tmp_py] == '0')
					info->minimap[j][i] = 0x0000FF;
				get_pos(info, j, i);
			}
			else
				break;
			i++;
		}
		j++;
	}
}

void	rend_minimap(t_info *info, t_map *map)
{
	int	i;
	int j;
	int k;

	map_background(info, map);
	get_minimap(info);
//	printf("--rend-\n");
	j = 0;
	while (j < info->win_hei / 6)
	{
		i = info->win_wid * 2 / 3;
		k = 0;
		while (i < info->win_wid)
		{
			info->buf[j][i] = info->minimap[j][k];
			k++;
			i++;
		}
		j++;
	}
}

void	init_minimap(t_info *info, t_map *map)
{
//	mlx_pixel_put(info->mlx, info->win, info->pos_x, info->pos_y, 	map->init_color);
	rend_minimap(info, map);
}

void	map_calc(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->win_hei)
	{
	//	calc_floor(info, &info->floor, y);
		y++;
	}
	x = 0;
	while (x < info->win_wid)
	{
		calc_wall(info, x);
		x++;
	}
	calc_sprite(info);
	pop_up(info);
	init_minimap(info, &info->hud_map);
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
	printf("map init\n");
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
