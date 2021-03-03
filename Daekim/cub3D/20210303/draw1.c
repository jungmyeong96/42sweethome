/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 23:17:47 by daekim            #+#    #+#             */
/*   Updated: 2021/03/03 02:48:21 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		draw(t_info *p)
{
	int		x;
	int		y;

	y = -1;
	while (++y < p->data.win_h)
	{
		x = -1;
		while (++x < p->data.win_w)
		{
			p->img.data[y * p->data.win_w + x] = p->buf[y][x];
			p->buf[y][x] = 0;
		}
	}
	mlx_put_image_to_window(p->mlx_p, p->win_p, p->img.img_p, 0, 0);
}
