#include "rt.h"

t_vector	ft_vect_scalar_prod(double k, t_vector a)
{
	t_vector prod;

	prod.a = a.a * k;
	prod.b = a.b * k;
	prod.g = a.g * k;
	return prod;
}
