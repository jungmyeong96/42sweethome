#include "test.h"

typedef struct	s_ray
{
	t_vec	orig;
	t_vec	dir;
}				t_ray;

typedef struct	s_sphere
{
	t_vec	center;
	double	radius;
}				t_sphere;

typedef struct	s_hit_record
{
	t_vec	p;
	t_vec	norm;
	double	t;
	int		front_face;
}				t_hit_record;

typedef struct	s_hit_list
{
	t_sphere	sp[2];
}				t_hit_list;



t_vec		vec_cross(t_vec u, t_vec v)
{
	t_vec new_vec;
	new_vec.x = u.y * v.z - u.z * v.y;
	new_vec.y = u.z * v.x - u.x * v.z;
	new_vec.z = u.x * v.y - u.y * v.x;
	return (new_vec);
}

t_vec		vec_at(t_ray r, double t)
{
	return (vec_add(r.orig, vec_multi2(r.dir, t)));
}

void		set_face_norm(t_vec dir, t_vec norm, t_vec out_norm, int front_face)
{
	front_face = vec_dot(dir, out_norm);
	if (front_face < 0)
		norm = out_norm;
	else
		norm = vec_multi2(out_norm, -1);
}

int			hit(t_ray r, double t_min, double t_max, t_hit_record rec, t_sphere s)
{
	t_vec oc = vec_sub(r.orig, s.center);
	double a = vec_len_pow(r.dir);
	double half_b = vec_dot(oc, r.dir);
	double c = vec_len_pow(oc) - s.radius * s.radius;
	double discriminant = half_b * half_b - a * c;

	if (discriminant > 0)
	{
		double root = sqrt(discriminant);
		double temp = (-half_b - root) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = vec_at(r, rec.t);
			t_vec out_norm = vec_div(vec_sub(rec.p, s.center), s.radius);
			set_face_norm(r.dir, rec.norm, out_norm, rec.front_face);
			return (1);
		}
		temp = (-half_b + root) / a;
		if (temp < t_max && temp > t_min)
		{
			rec.t = temp;
			rec.p = vec_at(r, rec.t);
			t_vec out_norm = vec_div(vec_sub(rec.p, s.center), s.radius);
			set_face_norm(r.dir, rec.norm, out_norm, rec.front_face);
			return (1);
		}
	}
	return (0);
}

int			hittable_list(t_ray r, double t_min, double t_max, t_hit_record rec, t_hit_list world)
{
	t_hit_record temp_rec;
	int		hit_anything = 0;
	double	closest_far = t_max;
	int		i = 0;

	while (i < 2)
	{
		if (hit(r, t_min, t_max, temp_rec, world.sp[i]))
		{
			hit_anything = 1;
			closest_far = temp_rec.t;
			rec = temp_rec;
		}
	}
	return (hit_anything);
}

double		hit_sphere(t_sphere s, t_ray r)
{
	t_vec oc = vec_sub(r.orig, s.center);
	double a = vec_dot(r.dir, r.dir);
	double half_b = vec_dot(oc, r.dir);
	double c = vec_len_pow(oc) - s.radius * s.radius;
	double discriminant = half_b * half_b - a * c;
	if (discriminant < 0)
		return (-1.0);
	else
		return ((-half_b - sqrt(discriminant)) / a);
}

t_vec		ray_color(t_ray r, t_hit_list world)
{
	double	t = hit_sphere(world.sp[0], r);
	if (t > 0.0)
	{
		t_vec n = vec_unit(vec_sub(vec_at(r, t), world.sp[0].center));
		t_vec color;
		color.x = n.x + 1;
		color.y = n.y + 1;
		color.z = n.z + 1;
		return (vec_multi2(color, 0.5));
	}

	t = hit_sphere(world.sp[1], r);
	if (t > 0.0)
	{
		t_vec n = vec_unit(vec_sub(vec_at(r, t), world.sp[1].center));
		t_vec color;
		color.x = n.x + 1;
		color.y = n.y + 1;
		color.z = n.z + 1;
		return (vec_multi2(color, 0.5));
	}
	t_vec unit_dir = vec_unit(r.dir);
	t = 0.5 * (unit_dir.y + 1.0);
	t_vec 	a = vec_create(1.0);
	t_vec	b; b.x = 0.5; b.y = 0.7, b.z = 1.0;
	return (vec_add(vec_multi2(a, 1.0 - t), vec_multi2(b, t)));
}

void		write_color(t_mlx *app, t_vec c)
{
	int		ir = 255.999 * c.x;
	int		ig = 255.999 * c.y;
	int		ib = 255.999 * c.z;

	app->color.x = ir * 256 * 256;
	app->color.y = ig * 256;
	app->color.z = ib;
	app->int_color = app->color.x + app->color.y + app->color.z;
}
/*
double		clamp(double x, double min, double max)
{
	if (x < min)
		return (min);
	if (x > max)
		return (max);
	return (x);
}

void		write_color(t_mlx *app, t_vec c, int sample_c)
{
//	int r = c.x;
//	int g = c.y;
//	int b = c.z;
	int	r = 256 * clamp(c.x, 0.0, 0.999);
	int	g = 256 * clamp(c.y, 0.0, 0.999);
	int	b = 256 * clamp(c.z, 0.0, 0.999);

	double scale = 1.0 / sample_c;
	r *= scale;
	g *= scale;
	b *= scale;

//	r = 256 * clamp(r, 0.0, 0.999);
//	g = 256 * clamp(g, 0.0, 0.999);
//	b = 256 * clamp(b, 0.0, 0.999);

	app->color.x = r * 256 * 256;
	app->color.y = g * 256;
	app->color.z = b;
	app->int_color = app->color.x + app->color.y + app->color.z;
}
*/
int		esc_key(int key, t_mlx *data)
{
	if (key == 53)
		exit(0);
	return (0);
}

int			main(void)
{
	//image
	double	aspect_ratio = 1.0;
	int		img_w = 500;
	int		img_h = img_w / aspect_ratio;
	int		sample_pixel = 100;

	//start mlx
	t_mlx	*app;

	if (!(app = (t_mlx *)malloc(sizeof(t_mlx))))
		return (-1);
	app->mlx_p = mlx_init();
	app->win_p = mlx_new_window(app->mlx_p, 500, 500, "test");
	mlx_key_hook(app->win_p, esc_key, 0);
	app->img_p = mlx_new_image(app->mlx_p, img_w, img_h);
	app->data = (int *)mlx_get_data_addr(app->img_p, &app->bpp, &app->size_l, &app->endian);

	//world
	t_hit_list world;
	world.sp[0].center.x = 0;
	world.sp[0].center.y = 0;
	world.sp[0].center.z = -1;
	world.sp[0].radius = 0.5;
	world.sp[1].center.x = 0;
	world.sp[1].center.y = -100.5;
	world.sp[1].center.z = -1;
	world.sp[1].radius = 100;

	//camera
	double	view_h = 2.0;
	double	view_w = aspect_ratio * view_h;
	double	focal_length = 1.0;;

	t_vec	origin = {0, 0, 0};
	t_vec	horizontal = {view_w, 0, 0};
	t_vec	vertical = {0, view_h, 0};
	t_vec	any = {0, 0, focal_length};
	t_vec	lower_left_corner  = vec_sub(origin, vec_add(vec_add(vec_div(horizontal, 2), vec_div(vertical, 2)), any));

	int		j = 0;
	while (j < img_h)
	{
		int	i = 0;
/*		while (i < img_w)
		{
			t_vec pixel_color = {0, 0, 0};
			int s = 0;
			while (s < sample_pixel)
			{
				double u = (i + (rand() / RAND_MAX)) / (img_w - 1);
				double v = (img_h - 1 - j + (rand() / RAND_MAX)) / (img_h - 1);
				t_ray r;
				r.orig = origin;
				r.dir = vec_add(lower_left_corner, vec_add(vec_multi2(horizontal, u), vec_sub(vec_multi2(vertical, v), origin)));
				t_vec pixel_color = ray_color(r, world);
				s++;
			}
			write_color(app, pixel_color, sample_pixel);
			mlx_pixel_put(app->mlx_p, app->win_p, i, j, app->int_color);
			app->data[j * img_w + i] = app->int_color;
			i++;
		}*/
		while (i < img_w)
		{
			double u = (double)i / (img_w - 1);
			double v = (img_h - (double)j - 1) / (img_h - 1);
			t_ray r;
			r.orig = origin;
			r.dir = vec_add(lower_left_corner, vec_add(vec_multi2(horizontal, u), vec_multi2(vec_sub(vertical, origin), v)));
			t_vec pixel_color = ray_color(r, world);
			write_color(app, pixel_color);
			mlx_pixel_put(app->mlx_p, app->win_p, i, j, app->int_color);
			app->data[j * img_w + i] = app->int_color;
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(app->mlx_p, app->win_p, app->img_p, 0, 0);
	mlx_loop(app->mlx_p);
	return (0);
}
