/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/10 02:33:37 by daekim            #+#    #+#             */
/*   Updated: 2021/03/11 03:37:05 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		mouse_move(int x, int y, t_info *p)
{
	if (p->key_p == 1)
	{
		p->mou_lr = (x - p->zero_p) / 15;
		if (p->mou_lr > 0)
		{
			cal_turn_l(p);
			mlx_mouse_move(p->win_p, p->data.win_w / 2, p->data.win_h / 2);
		}
		if (p->mou_lr < 0)
		{
			cal_turn_r(p);
			mlx_mouse_move(p->win_p, p->data.win_w / 2, p->data.win_h / 2);
		}
	}
	return (0);
}
