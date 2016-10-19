#include "rt.h"

t_vector ft_create_vector(t_point a, t_point b)
{
	t_vector vec;

	vec.a = b.x - a.x;
	vec.b = b.y - a.y;
	vec.g = b.z - a.z;
	return vec;
}
