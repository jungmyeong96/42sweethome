/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daekim <daekim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 22:05:06 by daekim            #+#    #+#             */
/*   Updated: 2021/02/25 18:32:04 by daekim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
/*
double		hit_sp(t_sp s, t_ray r)
{
	t_vec	oc = v_sub(r.orig, s.center);
	double	a = v_len_squared(r.dir);
	double	half_b = dot(oc, r.dir);
	double	c = v_len_squared(oc) - s.radius * s.radius;
	double	discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1);
	else
		return ((-half_b - sqrt(discriminant)) / a);
}

t_vec		ran_unit_sp(void)
{
	while (1)
	{
		t_vec	p = v_ran2(-1.0, 1.0);
		if (v_len_squared(p) > 1)
			continue;
		return p;
	}
}

t_vec		ray_color(t_ray r, t_hittable world, int depth)
{
	t_hit_re rec;
	t_vec color = {1, 1, 1};
	if (depth <= 0)
	{
		return (v_mul2(0, color));
	}
//	double t = hit(r, 0, INFINITY, rec, world.sp[0]);
	double 	t = hit_sp(world.sp[0], r);
	if (t > 0)
	{

		rec.norm = unit_vec(v_sub(v_at(r, t), world.sp[0].center));
		return (v_mul2(0.5, v_add(color, rec.norm)));
	}
//	t = hit(r, 0, INFINITY, rec, world.sp[1]);
	t = hit_sp(world.sp[1], r);
	if (t > 0)
	{
		rec.norm = unit_vec(v_sub(v_at(r, t), world.sp[1].center));
		return (v_mul2(0.5, v_add(color, rec.norm)));
	}
	t_vec	unit_dir = unit_vec(r.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	t_vec	col1 = {1.0, 1.0, 1.0};
	t_vec	col2 = {0.5, 0.7, 1.0};
	t_vec	n_vec = v_add(v_mul2((1.0 - t), col1), v_mul2(t, col2));
	return (n_vec);
}

double		clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

void		write_color(t_mlx *app, t_vec c, int p)
{
	double r = c.x;
	double g = c.y;
	double b = c.z;

	double scale = 1.0 / p;
	r = scale * r;
	g = scale * g;
	b = scale * b;

	int ir = 256 * clamp(r, 0.0, 0.999);
	int ig = 256 * clamp(g, 0.0, 0.999);
	int ib = 256 * clamp(b, 0.0, 0.999);
	
	app->color.x = ir * 256 * 256;
	app->color.y = ig * 256;
	app->color.z = ib;
	app->p_color = app->color.x + app->color.y + app->color.z;
}
*/
int			esc_key(int key, t_mlx app)
{
	if (key == 53)
		exit(0);
	return (0);
}

void		start(t_mlx *app, t_img *img)
{
	t_cam	cam;
//	gradation(app, img);
	sky(app, img, cam);
}

int			main()
{
	t_mlx	app;
	t_img	img;

	base_img(&img);
	app.mlx_p = mlx_init();
	app.win_p = mlx_new_window(app.mlx_p, img.img_w, img.img_h, "third miniRT");
	mlx_key_hook(app.win_p, esc_key, app.mlx_p);
	app.img_p = mlx_new_image(app.mlx_p, img.img_w, img.img_h);
	app.data = (int *)mlx_get_data_addr(app.img_p, &app.bpp, &app.size_l, &app.endian);

	start(&app, &img);
	/*
	//image
	double	rate = 1;
	int		img_w = 500;
	int		img_h = img_w / rate;
	int		sample_p = 3;
	int		max_depth = 10;

	app.mlx_p = mlx_init();
	app.win_p = mlx_new_window(app.mlx_p, img_w, img_h, "second miniRT");
	mlx_key_hook(app.win_p, esc_key, app.mlx_p);
	app.img_p = mlx_new_image(app.mlx_p, img_w, img_h);
	app.data = (int *)mlx_get_data_addr(app.img_p, &app.bpp, &app.size_l, &app.endian);


	//world
	t_hittable	world;
	world.sp[1].center.x = 0;
	world.sp[1].center.y = -100.5;
	world.sp[1].center.z = -1.0;
	world.sp[1].radius = 100;

	world.sp[0].center.x = 0;
	world.sp[0].center.y = 0;
	world.sp[0].center.z = -1;
	world.sp[0].radius = 0.5;

	world.sp[2].center.x = -1;
	world.sp[2].center.y = 0;
	world.sp[2].center.z = -1;
	world.sp[2].radius = 0.5;

	world.sp[3].center.x = 1;
	world.sp[3].center.y = 0;
	world.sp[3].center.z = -1;
	world.sp[3].radius = 0.5;

	world.sp[4].center.x = 0.8;
	world.sp[4].center.y = 0.8;
	world.sp[4].center.z = 0.0;
//	world.sp[4].radius;

	world.sp[5].center.x = 0.7;
	world.sp[5].center.y = 0.3;
	world.sp[5].center.z = 0.3;
//	world.sp[5].radius;

	world.sp[6].center.x = 0.8;
	world.sp[6].center.y = 0.8;
	world.sp[6].center.z = 0.8;
//	world.sp[6].radius;

	world.sp[7].center.x = 0.8;
	world.sp[7].center.y = 0.6;
	world.sp[7].center.z = 0.2;
//	world.sp[7].radius;


	//camera
	double	view_h = 2.0;
	double	view_w = rate * view_h;
	double	focal_len = 1; 

	t_vec	origin = {0, 0, 0};
	t_vec	horizontal = {view_w, 0, 0};
	t_vec	vertical = {0, view_h, 0};
	t_vec	focal = {0, 0, focal_len};
	t_vec	lower_left_corner = v_sub(v_sub(v_sub(origin, v_div(2, horizontal)), v_div(2, vertical)), focal);

	int j = 0;
	while (j < img_h - 1)
	{
		int i = 0;
		while (i < img_w)
		{
			t_vec pixel_color = {0, 0, 0};
			int s = 0;
			while (s < sample_p)
			{
				double u = (i + random_double()) / (img_w - 1);
				double v = (img_h - 1 - j + random_double()) / (img_h - 1);
				t_ray r;
			    r.orig = origin;
				r.dir = v_sub(v_add(v_add(lower_left_corner, v_mul2(u, horizontal)), v_mul2(v, vertical)), origin);
				pixel_color = v_add(pixel_color, ray_color(r, world, max_depth));
				s++;
			}
			write_color(&app, pixel_color, sample_p);
			mlx_pixel_put(app.mlx_p, app.win_p, i, j, app.p_color);
			app.data[j * img_w + i] = app.p_color;
			i++;
		}
		j++;
	}*/
	mlx_put_image_to_window(app.mlx_p, app.win_p, app.img_p, 0, 0);
	mlx_loop(app.mlx_p);
	return (0);
}
