#include "rt.h"

t_point ft_point_sum(t_point a, t_point b)
{
	t_point sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	sum.z = a.z + b.z;

	return sum;
}
