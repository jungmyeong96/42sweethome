/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:20:25 by daekim            #+#    #+#             */
/*   Updated: 2021/02/24 20:50:27 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "mlx/mlx.h"
# include "struct.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>
# include <time.h>

# define pi 3.1415926535897932385

void		gradation(t_mlx *app, t_img *img);
void		base_img(t_img *img);
t_vec		ray_color(t_vec orig, t_vec dir);
void		write_color(t_mlx *app, t_vec c);
void		out_color(t_mlx *app, t_img *img, t_cam c);
void		sky(t_mlx *app, t_img *img, t_cam c);
t_vec		v_cre(double a, double b, double c);

t_vec		v_add(t_vec u, t_vec v);
t_vec		v_sub(t_vec u, t_vec v);
t_vec		v_mul(t_vec u, t_vec v);
t_vec		v_mul2(double t, t_vec v);
t_vec		v_div(double t, t_vec v);
double		v_len_squared(t_vec v);
double		v_len(t_vec v);
double		dot(t_vec u, t_vec v);
t_vec		cross(t_vec u, t_vec v);
t_vec		unit_vec(t_vec v);
t_vec		v_at(t_ray r, double t);
//t_vec		v_random(void);
//t_vec		v_ran2(double min, double max);
//t_vec		ran_unit_vec();
//t_vec		ran_unit_hemi();
//double		random_double(void);
//double		ran_dou2(double min, double max);

//t_vec		ran_unit_sp();

#endif
