/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_butpress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 02:14:29 by daekim            #+#    #+#             */
/*   Updated: 2021/03/14 20:22:18 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	key_press_ws(int key, t_info *p)
{
	if (key == KEY_W)
	{
		if (p->key_s == 1)
		{
			p->key_ws = 's';
			p->key_s = 0;
		}
		p->key_w = 1;
	}
	if (key == KEY_S)
	{
		if (p->key_w == 1)
		{
			p->key_ws = 'w';
			p->key_w = 0;
		}
		p->key_s = 1;
	}
}

int		butpress(int key, t_info *p)
{
	p->click = key;
	exit(0);
	return (0);
}
