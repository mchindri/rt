#include "rt.h"

double	ft_distance(t_point a, t_point b)
{
	double x;
	double y;
	double z;

	x = b.x - a.x;
	y = b.y - a.y;
	z = b.z - a.z;
	return (sqrt(x * x + y * y + z * z));
}
