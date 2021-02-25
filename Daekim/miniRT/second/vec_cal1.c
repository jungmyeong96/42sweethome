/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 23:38:30 by daekim            #+#    #+#             */
/*   Updated: 2021/02/22 23:46:54 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		v_add(t_vec u, t_vec v)
{
	t_vec	n_vec;

	n_vec.x = u.x + v.x;
	n_vec.y = u.y + v.y;
	n_vec.z = u.z + v.z;
	return (n_vec);
}

t_vec		v_sub(t_vec u, t_vec v)
{
	t_vec n_vec;

	n_vec.x = u.x - v.x;
	n_vec.y = u.y - v.y;
	n_vec.z = u.z - v.z;
	return (n_vec);
}

t_vec		v_mul(t_vec u, t_vec v)
{
	t_vec n_vec;

	n_vec.x = u.x * v.x;
	n_vec.y = u.y * v.y;
	n_vec.z = u.z * v.z;
	return (n_vec);
}

t_vec		v_mul2(double t, t_vec v)
{
	t_vec n_vec;

	n_vec.x = v.x * t;
	n_vec.y = v.y * t;
	n_vec.z = v.z * t;
	return (n_vec);
}

t_vec		v_div(double t, t_vec v)
{
	t_vec n_vec;

	n_vec.x = v.x / t;
	n_vec.y = v.y / t;
	n_vec.z = v.z / t;
	return (n_vec);
}
