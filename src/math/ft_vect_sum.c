#include "rt.h"

t_vector ft_vect_sum(t_vector a, t_vector b)
{
	t_vector sum;

	sum.a = a.a + b.a;
	sum.b = a.b + b.b;
	sum.g = a.g + b.g;

	return sum;
}
