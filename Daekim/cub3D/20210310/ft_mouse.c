/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 02:33:37 by daekim            #+#    #+#             */
/*   Updated: 2021/03/10 05:48:20 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		mouse_move(int x, int y, t_info *p)
{
	printf("x : %d\ny : %d\nwin_w : %d\n", x, y, p->data.win_h);

	p->mou_lr = x - p->zero_p; //+ p->move_p;
	printf("lr : %d\np->zero_p : %d\np->move_p : %d\n", p->mou_lr, p->zero_p, p->move_p);
	printf("dir_x : %lf\no_dir_x : %lf\n", p->dir_x, p->o_dir_x); 
	if (p->mou_lr < 0)
	{
		p->o_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-(0.002)) - p->dir_y * sin(-(0.002));
		p->dir_y = p->o_dir_x * sin(-(0.002)) + p->dir_y * cos(-(0.002));
		p->o_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(-(0.002)) - p->plane_y * sin(-(0.002));
		p->plane_y = p->o_plane_x * sin(-(0.002)) + p->plane_y *
			cos(-(0.002));
/*		p->move_p++;
		if(x - p->zero_p + p->move_p == p->zero_p)
		{
			p->move_p = 0;*/
			p->zero_p = x;
//		}
	}
	if (p->mou_lr > 0)
	{
		p->o_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(0.002) - p->dir_y * sin(0.002);
		p->dir_y = p->o_dir_x * sin(0.002) + p->dir_y * cos(0.002);
		p->o_plane_x = p->plane_x;
		p->plane_x = p->plane_x * cos(0.002) - p->plane_y * sin(0.002);
		p->plane_y = p->o_plane_x * sin(0.002) + p->plane_y * cos(0.002);
/*		p->move_p--;
		if(x - p->zero_p + p->move_p == p->zero_p)
		{
			p->move_p = 0;*/
			p->zero_p = x;
//		}
	}
	printf("OK\n");
	return (0);
}
