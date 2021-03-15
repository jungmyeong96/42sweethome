/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 07:30:38 by daekim            #+#    #+#             */
/*   Updated: 2021/03/13 06:50:41 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		view_up(t_info *p)
{
	p->pitch += 200 * p->move;
	if (p->pitch > p->data.win_h * 2 / 5)
		p->pitch = p->data.win_h * 2 / 5;
}

void		view_down(t_info *p)
{
	p->pitch -= 200 * p->move;
	if (p->pitch < -p->data.win_h * 2 / 5)
		p->pitch = -p->data.win_h * 2 / 5;
}

void		cal_view(t_info *p)
{
	if (p->key_jump == 1 && p->pos_z <= 0)
	{
		p->pos_z = 200;
		p->key_jump = 0;
	}
	if (p->key_sit == 1)
		p->pos_z = -150;
	if (p->key_up == 1)
		view_up(p);
	if (p->key_down == 1)
		view_down(p);
	if (p->pos_z > 0)
		p->pos_z = p->pos_z - 150 * p->move;
	if (p->pos_z < 0 && p->key_sit == 0)
		p->pos_z = 0;
}
