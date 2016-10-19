#include "rt.h"

t_point	ft_point_prod(double k, t_point a)
{
	t_point prod;

	prod.x = a.x * k;
	prod.y = a.y * k;
	prod.z = a.z * k;
	return prod;
}
