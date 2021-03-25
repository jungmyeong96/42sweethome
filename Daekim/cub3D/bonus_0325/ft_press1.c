/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:14:51 by daekim            #+#    #+#             */
/*   Updated: 2021/03/13 05:22:22 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	key_press_ad(int key, t_info *p)
{
	if (key == KEY_A)
	{
		if (p->key_d == 1)
		{
			p->key_ad = 'd';
			p->key_d = 0;
		}
		p->key_a = 1;
	}
	if (key == KEY_D)
	{
		if (p->key_a == 1)
		{
			p->key_ad = 'a';
			p->key_a = 0;
		}
		p->key_d = 1;
	}
	if (key == KEY_P && p->key_p == 0)
		p->key_p = 1;
	else if (key == KEY_P && p->key_p == 1)
		p->key_p = 0;
}

int		key_press(int key, t_info *p)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_O)
		p->key_o = 1;
	key_press_ws(key, p);
	key_press_ad(key, p);
	key_press_aa(key, p);
	key_perf(key, p);
	return (0);
}

void	key_release_ad(int key, t_info *p)
{
	if (key == KEY_A)
	{
		if (p->key_ad == 'd')
			key_save(&(p->key_d), &(p->key_ad), 1, 0);
		else if (p->key_ad == 'a')
			key_save(&(p->key_a), &(p->key_ad), 0, 0);
		p->key_a = 0;
	}
	if (key == KEY_D)
	{
		if (p->key_ad == 'a')
			key_save(&(p->key_a), &(p->key_ad), 1, 0);
		else if (p->key_ad == 'd')
			key_save(&(p->key_d), &(p->key_ad), 0, 0);
		p->key_d = 0;
	}
}

int		key_release(int key, t_info *p)
{
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_W)
	{
		if (p->key_ws == 's')
			key_save(&(p->key_s), &(p->key_ws), 1, 0);
		else if (p->key_ws == 'w')
			key_save(&(p->key_w), &(p->key_ws), 0, 0);
		p->key_w = 0;
	}
	if (key == KEY_S)
	{
		if (p->key_ws == 'w')
			key_save(&(p->key_w), &(p->key_ws), 1, 0);
		else if (p->key_ws == 's')
			key_save(&(p->key_s), &(p->key_ws), 0, 0);
		p->key_s = 0;
	}
	if (key == KEY_O)
		p->key_o = 0;
	key_release_ad(key, p);
	key_release_aa(key, p);
	key_release_ud(key, p);
	return (0);
}

int		ft_press(t_info *p)
{
	mlx_hook(p->win_p, X_KEY_PRESS, 0, &key_press, p);
	if (p->yorn == 0)
	{
		mlx_hook(p->win_p, X_KEY_RELEASE, 0, &key_release, p);
		mlx_hook(p->win_p, X_KEY_EXIT, 0, &butpress, &p);
	}
	return (0);
}
