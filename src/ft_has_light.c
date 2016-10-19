#include "rt.h"

t_bool	ft_has_light(t_point point, t_data *data)
{
	int		i;
	int		j;
	t_ray	ray;
	t_point	inter;
	double	dis;

	i = 0;
	while (i < data->nb_lights)
	{
		ray = ft_get_ray(point, data->lights[i]);
		j = 0;
		while (j < data->nb_elem)
		{
			dis = ft_intersect(ray, data->elements[j], &inter, ray.a);
			if (dis != -1)
				if (dis < ft_distance(point, data->lights[i]))
					return (0);
			j++;
		}
		i++;
	}
	return (1);
}
