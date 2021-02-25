/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 13:17:45 by daekim            #+#    #+#             */
/*   Updated: 2021/02/20 21:32:39 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	VECTOR_H
# define VECTOR_H

# include "test.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

typedef struct	s_vec	t_vec;
t_vec			vec_add(t_vec u, t_vec v);
t_vec			vec_sub(t_vec u, t_vec v);
t_vec			vec_multi(t_vec *u, t_vec *v);
t_vec			vec_div(t_vec u, double t);
t_vec			vec_multi2(t_vec v, double t);
double			vec_dot(t_vec u, t_vec v);
t_vec			vec_cross(t_vec u, t_vec v);
double			vec_len_pow(t_vec v);
double			vec_len(t_vec new_vec);
t_vec			vec_unit(t_vec v);
t_vec			vec_create(double n);

#endif
