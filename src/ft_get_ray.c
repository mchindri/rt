#include "rt.h"

t_ray	ft_get_ray(t_point a, t_point b)
{
	t_ray ray;

	ft_memcpy(&(ray.a), &a, sizeof(a));
	ray.dir.a = b.x - a.x;
	ray.dir.b = b.y - a.y;
	ray.dir.g = b.z - a.z;
	ft_vect_normalize(&(ray.dir));
	return (ray);
}
