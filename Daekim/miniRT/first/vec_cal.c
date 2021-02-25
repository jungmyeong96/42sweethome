#include "vector.h"

t_vec		vec_add(t_vec u, t_vec v)
{
	t_vec new_vec;

	new_vec.x = u.x + v.x;
	new_vec.y = u.y + v.y;
	new_vec.z = u.z + v.z;
	return (new_vec);
}

t_vec		vec_sub(t_vec u, t_vec v)
{
	t_vec new_vec;

	new_vec.x = u.x - v.x;
	new_vec.y = u.y - v.y;
	new_vec.z = u.z - v.z;
	return (new_vec);
}

t_vec		vec_multi(t_vec *u, t_vec *v)
{
	t_vec new_vec;

	new_vec.x = u->x * v->x;
	new_vec.y = u->y * v->y;
	new_vec.z = u->z * v->z;
	return (new_vec);
}

t_vec		vec_div(t_vec u, double t)
{
	t_vec new_vec;

	new_vec.x = u.x / t;
	new_vec.y = u.y / t;
	new_vec.z = u.z / t;
	return (new_vec);
}

t_vec		vec_multi2(t_vec v, double t)
{
	t_vec new_vec;

	new_vec.x = v.x * t;
	new_vec.y = v.y * t;
	new_vec.z = v.z * t;
	return (new_vec);
}
