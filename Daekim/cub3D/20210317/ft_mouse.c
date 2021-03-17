/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 02:33:37 by daekim            #+#    #+#             */
/*   Updated: 2021/03/14 20:25:39 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	up_down(int y, t_info *p)
{
	p->mou_ud = (y - p->zero_h) / 15;
	if (p->mou_ud < 0)
	{
		view_up(p);
		mlx_mouse_move(p->win_p, p->data.win_w / 2, p->data.win_h / 2);
	}
	if (p->mou_ud > 0)
	{
		view_down(p);
		mlx_mouse_move(p->win_p, p->data.win_w / 2, p->data.win_h / 2);
	}
}

int		mouse_move(int x, int y, t_info *p)
{
	if (p->key_p == 0)
		mlx_mouse_show();
	if (p->key_p == 1)
	{
		p->mou_lr = (x - p->zero_w) / 15;
		mlx_mouse_hide();
		if (p->mou_lr > 0)
		{
			cal_turn_r(p);
			mlx_mouse_move(p->win_p, p->data.win_w / 2, p->data.win_h / 2);
		}
		if (p->mou_lr < 0)
		{
			cal_turn_l(p);
			mlx_mouse_move(p->win_p, p->data.win_w / 2, p->data.win_h / 2);
		}
		up_down(y, p);
	}
	return (0);
}
