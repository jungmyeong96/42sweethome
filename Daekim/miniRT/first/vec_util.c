/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seou.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:25:20 by daekim            #+#    #+#             */
/*   Updated: 2021/02/20 23:06:20 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

double		vec_dot(t_vec u, t_vec v)
{
	return (u.x * v.x + u.y * v.y + u.z * v.z);
}

double		vec_len_pow(t_vec v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double		vec_len(t_vec new_vec)
{
	return (sqrt(vec_len_pow(new_vec)));
}

t_vec		vec_unit(t_vec v)
{
	return (vec_div(v, vec_len(v)));
}

t_vec		vec_create(double n)
{
	t_vec new_vec;

	new_vec.x = n;
	new_vec.y = n;
	new_vec.z = n;
	return (new_vec);
}
