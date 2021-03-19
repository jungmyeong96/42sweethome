/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 07:30:38 by daekim            #+#    #+#             */
/*   Updated: 2021/03/13 04:57:16 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void		key_perf2(int key, t_info *p)
{
	if (key == KEY_AU)
	{
		if (p->key_down == 1)
		{
			p->key_ud = ']';
			p->key_down = 0;
		}
		p->key_up = 1;
	}
	if (key == KEY_AD)
	{
		if (p->key_up == 1)
		{
			p->key_ud = '[';
			p->key_up = 0;
		}
		p->key_down = 1;
	}
}

int			key_perf(int key, t_info *p)
{
	if (key == KEY_SPACE && p->pos_z <= 0)
		p->key_jump = 1;
	if (key == KEY_C)
		p->key_sit = 1;
	key_perf2(key, p);
	return (0);
}

int			key_release_ud(int key, t_info *p)
{
	if (key == KEY_AU)
	{
		if (p->key_ud == ']')
			key_save(&(p->key_down), &(p->key_ud), 1, 0);
		else if (p->key_ud == '[')
			key_save(&(p->key_up), &(p->key_ud), 0, 0);
		p->key_up = 0;
	}
	if (key == KEY_AD)
	{
		if (p->key_ud == '[')
			key_save(&(p->key_up), &(p->key_ud), 1, 0);
		else if (p->key_ud == ']')
			key_save(&(p->key_down), &(p->key_ud), 0, 0);
		p->key_down = 0;
	}
	if (key == KEY_C)
		p->key_sit = 0;
	return (0);
}
