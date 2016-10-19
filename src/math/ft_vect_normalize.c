#include "rt.h"

void	ft_vect_normalize(t_vector *a)
{
	double norm;

	norm = ft_vect_norm(*a);
	a->a /= norm;
	a->b /= norm;
	a->g /= norm;
}
