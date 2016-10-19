#include "rt.h"

double	ft_vect_dot_prod(t_vector a, t_vector b)
{
	double sol;

	sol = a.a * b.a + a.b * b.b + a.g * b.g;
	return (sol);
}
