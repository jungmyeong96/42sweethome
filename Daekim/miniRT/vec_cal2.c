/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:48:01 by daekim            #+#    #+#             */
/*   Updated: 2021/02/23 00:44:22 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		v_len_squared(t_vec v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double		v_len(t_vec v)
{
	return (sqrt(v_len_squared(v)));
}

double		dot(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

t_vec		cross(t_vec u, t_vec v)
{
	t_vec	n_vec;

	n_vec.x = u.y * v.z - u.z * v.y;
	n_vec.y = u.z * v.x - u.x * v.z;
	n_vec.z = u.x * v.y - u.y * v.x;
	return (n_vec);
}

t_vec		unit_vec(t_vec v)
{
	t_vec	n_vec;

	n_vec = v_div(v_len(v), v);
	return (n_vec);
}
