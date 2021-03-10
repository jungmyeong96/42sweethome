/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junghan <junghan@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:44:55 by junghan           #+#    #+#             */
/*   Updated: 2021/03/11 01:57:09 by junghan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_key_press(int key_num, t_keys *keys)
{
	if (key_num == K_W)
		keys->key_w = 1;
	if (key_num == K_S)
		keys->key_s = 1;
	if (key_num == K_D)
		keys->key_d = 1;
	if (key_num == K_A)
		keys->key_a = 1;
	if (key_num == K_E)
		keys->key_e = 1;
	if (key_num == K_Q)
		keys->key_q = 1;
	if (key_num == K_ESC)
		exit(0);
	if (key_num == K_P && keys->key_p == 0)
		keys->key_p = 1;
	else if (key_num == K_P && keys->key_p == 1)
		keys->key_p = 0;
	printf("p%d\n kn%d\n", keys->key_p, key_num);
	return (0);
}

int	ft_key_release2(int key_num, t_keys *keys)
{
	if (key_num == K_E)
	{
		keys->key_e = 0;
		keys->key_eq = 0;
	}
	if (key_num == K_Q)
	{
		keys->key_q = 0;
		keys->key_qe = 0;
	}
	if (key_num == K_ESC)
		exit(0);
	return (0);
}

int	ft_key_release(int key_num, t_keys *keys)
{
	if (key_num == K_W)
	{
		keys->key_w = 0;
		keys->key_ws = 0;
	}
	if (key_num == K_S)
	{
		keys->key_s = 0;
		keys->key_sw = 0;
	}
	if (key_num == K_D)
	{
		keys->key_d = 0;
		keys->key_da = 0;
	}
	if (key_num == K_A)
	{
		keys->key_a = 0;
		keys->key_ad = 0;
	}
	ft_key_release2(key_num, keys);
	return (0);
}

int	ft_click_exit(int keys, t_info *info)
{
	exit(0);
	return (0);
}
