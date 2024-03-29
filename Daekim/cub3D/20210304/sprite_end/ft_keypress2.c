/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoulkr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 21:15:22 by daekim            #+#    #+#             */
/*   Updated: 2021/03/01 21:50:20 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	key_save(int *in_key, char *save_key, int i, char j)
{
	(*in_key) = i;
	(*save_key) = j;
}

void	key_press_qe(int key, t_info *p)
{
	if (key == KEY_Q)
	{
		if (p->key_e == 1)
		{
			p->key_qe = 'e';
			p->key_e = 0;
		}
		p->key_q = 1;
	}
	if (key == KEY_E)
	{
		if (p->key_q == 1)
		{
			p->key_qe = 'q';
			p->key_q = 0;
		}
		p->key_e = 1;
	}
}

int		key_press_A(int key, t_info *p)
{
	if (key == KEY_LT)
	{
		if (p->key_ar == 1)
		{
			p->key_A = '>';
			p->key_ar = 0;
		}
		p->key_al = 1;
	}
	if (key == KEY_RT)
	{
		if (p->key_al == 1)
		{
			p->key_A = '<';
			p->key_al = 0;
		}
		p->key_ar = 1;
	}
	key_press_qe(key, p);
	return (0);
}

void	key_release_qe(int key, t_info *p)
{
	if (key == KEY_Q)
	{
		if (p->key_qe == 'e')
			key_save(&(p->key_e), &(p->key_qe), 1, 0);
		else if (p->key_qe == 'q')
			key_save(&(p->key_q), &(p->key_qe), 0, 0);
		p->key_q = 0;
	}
	if (key == KEY_E)
	{
		if (p->key_qe == 'q')
			key_save(&(p->key_q), &(p->key_qe), 1, 0);
		else if (p->key_qe == 'e')
			key_save(&(p->key_e), &(p->key_qe), 0, 0);
		p->key_e = 0;
	}
}

int		key_release_A(int key, t_info *p)
{
	if (key == KEY_LT)
	{
		if (p->key_A == '>')
			key_save(&(p->key_ar), &(p->key_A), 1, 0);
		else if (p->key_A == '<')
			key_save(&(p->key_al), &(p->key_A), 0, 0);
		p->key_al = 0;
	}
	if (key == KEY_RT)
	{
		if (p->key_A == '<')
			key_save(&(p->key_al), &(p->key_A), 1, 0);
		else if (p->key_A == '>')
			key_save(&(p->key_ar), &(p->key_A), 0, 0);
		p->key_ar = 0;
	}
	key_release_qe(key, p);
	return (0);
}
