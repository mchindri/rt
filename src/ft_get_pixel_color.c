#include "rt.h"

/*
 *	ft_intersect must return the closer intersection
 *  distance >= 0 ??
 *
 * scalar prod with -1 on the ray make the ray start on the window pixel
 */

int	ft_get_pixel_color(t_data *data, t_point win_pixel)
{
	t_ray	ray;
	int		i;
	double	min_dis;
	t_point	intersection[2];
	double	distance;
	int		i_ref;

	ray = ft_get_ray(win_pixel, data->cam);
	ray.dir = ft_vect_scalar_prod(-1, ray.dir);
	i = 0;
	min_dis = -1;
	while (i < data->nb_elem)
	{
		distance = ft_intersect(ray, data->elements[i], &(intersection[1]), 
							win_pixel);
		if (distance >= 0)
		{
			if (min_dis < 0)
			{
				i_ref = i;
				min_dis = distance;
				intersection[0] = intersection[1];
			}
			else if (distance < min_dis)
			{
				i_ref = i;
				min_dis = distance;
				intersection[0] = intersection[1];
			}
		}
		i++;
	}
	if (min_dis > 0)
	//if (ft_has_light(intersection[0], data))
		return data->elements[i_ref].color;
	return 0x000000;
}
