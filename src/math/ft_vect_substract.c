#include "rt.h"

t_vector	ft_vect_substract(t_vector a, t_vector b)
{
	t_vector	sol;

	sol.a = a.a - b.a;
	sol.b = a.b - b.b;
	sol.g = a.g - a.g;
	return (sol);
}
