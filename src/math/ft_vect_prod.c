#include "rt.h"

t_vector ft_vect_prod(t_vector a, t_vector b)
{
	t_vector c;

	c.a = a.b * b.g - a.g * b.b;
	c.b = a.g * b.a - a.a * b.g;
	c.g = a.a * b.b - a.b * b.a;
	return (c);
}
