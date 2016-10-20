#include "rt.h"

t_ray	ft_get_element_ray(t_point p, t_element elem)
{
	t_ray	ray;
	double	aux;
	double	x;
	double	y;
	double	z;

	if (elem.type == PLANE)
	{
		ray.dir = elem.norm;
		ray.a = p;
	}
	else if(elem.type == SPHERE)
	{
		ray = ft_get_ray(elem.center, p);
		ray.a = p;
		ray.dir = ft_vect_scalar_prod(-1, ray.dir);
	}
	else if (elem.type == CYLINDER || elem.type == CONE)
	{
		aux = ft_vect_dot_prod(ft_create_vector(elem.center, p), elem.dir);
		x = elem.center.x + aux * elem.dir.a;
		y = elem.center.y + aux * elem.dir.b;
		z = elem.center.z + aux * elem.dir.g;
		ray = ft_get_ray(ft_create_point(x, y, z), p);
		ray.a = p;
		ray.dir = ft_vect_scalar_prod(-1, ray.dir);
	}
	return (ray);
}

t_bool	ft_has_light(t_point point, int i_ref, t_data *data)
{
	int		i;
	int		j;
	t_ray	ray;
	t_ray	ref_ray;
	t_point	inter;
	double	dis;
	double	light_dis;

	i = 0;
	while (i < data->nb_lights)
	{
		ref_ray = ft_get_element_ray(point, data->elements[i_ref]);
		ray = ft_get_ray(point, data->lights[i]);
		light_dis = ft_distance(point, data->lights[i]);
		if (ft_cos_btw_vectors(ref_ray.dir, ray.dir) > 0)
			return (0);
		j = 0;
		while (j < data->nb_elem)
		{
			if (j != i_ref)
			{
				dis = ft_intersect(ray, data->elements[j], &inter);
				if (dis != -1)
					if (dis < light_dis)
						return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
