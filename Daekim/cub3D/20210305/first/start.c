/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seou.kr           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 05:14:19 by daekim            #+#    #+#             */
/*   Updated: 2021/02/26 06:43:00 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		main_loop(t_info *p)
{
	calc(p);
	draw(p);
//	mlx_put_image_to_window(p->mlx_p, p->win_p, p->img.img_p, 0, 0);
	return (0);
}

void	info(t_info *p)
{
	p->posX = 22;
	p->posY = 11.5;
	p->dirX = -1.0;
	p->dirY = 0.0;
	p->planeX = 0.0;
	p->planeY = 0.66;

	p->move = 0.05;
	p->rot = 0.05;

//	color_wall(p);
	tex_wall(p);
}

int		main()
{
	t_info	p;

	p.mlx_p = mlx_init();
	info(&p);
	p.win_p = mlx_new_window(p.mlx_p, win_w, win_h, "first cub");
//	p.img_p = mlx_xpm_file_to_image(p.mlx_p, , &img.img_w, &img.img_h);
	p.img.img_p = mlx_new_image(p.mlx_p, win_w, win_h);
	p.img.data = (int *)mlx_get_data_addr(p.img.img_p, &p.img.bpp, 
			&p.img.size_l, &p.img.endian);

	mlx_loop_hook(p.mlx_p, &main_loop, &p);
	mlx_hook(p.win_p, X_EVENT_KEY_PRESS, 0, &key_press, &p);
//	mlx_put_image_to_window(p.mlx_p, img.img_p, img.img_p, 50, 50);
	mlx_loop(p.mlx_p);
//	return (0);
}
