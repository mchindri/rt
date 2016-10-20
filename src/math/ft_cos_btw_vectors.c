#include "rt.h"

double	ft_cos_btw_vectors(t_vector a, t_vector b)
{
	return (ft_vect_dot_prod(a, b) / (ft_vect_norm(a) * ft_vect_norm(b)));
}
