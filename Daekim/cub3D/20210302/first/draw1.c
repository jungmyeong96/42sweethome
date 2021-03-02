/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 18:59:04 by daekim            #+#    #+#             */
/*   Updated: 2021/02/26 06:14:56 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		draw(t_info *p)
{
	int x;
	int y;

	y = -1;
	while (++y < win_h)
	{
		x = -1;
		while (++x < win_w)
		{
			p->img.data[y * win_w + x] = p->buf[y][x];
		}
	}
	mlx_put_image_to_window(p->mlx_p, p->win_p, p->img.img_p, 0, 0);
}
