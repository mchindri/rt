#include "rt.h"

double ft_vect_norm(t_vector vect)
{
	return (sqrt(vect.a * vect.a + vect.b * vect.b + vect.g * vect.g));
}
