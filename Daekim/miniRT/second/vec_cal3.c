/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_cal3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@struct.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/23 02:05:37 by daekim            #+#    #+#             */
/*   Updated: 2021/02/24 02:29:40 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec		v_at(t_ray r, double t)
{
	return (v_add(r.orig, v_mul2(t, r.dir)));
}

t_vec		v_random(void)
{
	t_vec ran;
	ran.x = random_double();
	ran.y = random_double();
	ran.z = random_double();
	return (ran);
}

t_vec		v_ran2(double min, double max)
{
	t_vec ran;
	ran.x = ran_dou2(min, max);
	ran.y = ran_dou2(min, max);
	ran.z = ran_dou2(min, max);
	return (ran);
}

t_vec		ran_unit_vec()
{
	double	a = ran_dou2(0, 2 * pi);
	double	z = ran_dou2(-1, 1);
	double	r = sqrt(1 - z * z);
	t_vec n_vec = {r * cos(a), r * sin(a), z};
	return (n_vec);
//	return (unit_vec(ran_unit_sp()));
}

t_vec		ran_unit_hemi(t_vec norm)
{
	t_vec	in_unit = ran_unit_sp();
	if (dot(in_unit, norm) > 0.0)
		return (in_unit);
	else
		return (v_mul2(-1.0, in_unit));
}
