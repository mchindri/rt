#include "rt.h"

/*
 *	ft_intersect must return the closer intersection
 *  distance >= 0 ??
 *
 * scalar prod with -1 on the ray make the ray start on the window pixel
 */
t_point		ft_intersect_elem(t_data *data, t_ray ray, int *ref, double *dis)
{
	int		i;
	double	dis_aux;
	t_point	inter;
	t_point	inter_aux;

	i = 0;
	*dis = -1;
	ft_bzero(&inter, sizeof(inter));
	while (i < data->nb_elem)
	{
		dis_aux = ft_intersect(ray, data->elements[i], &inter_aux);
		if (dis_aux >= 0)
		{
			if (*dis < 0)
			{
				*ref = i;
				*dis = dis_aux;
				inter = inter_aux;
			}
			else if (dis_aux < *dis)
			{
				*ref = i;
				*dis = dis_aux;
				inter = inter_aux;
			}
		}
		i++;
	}
	return (inter);	
}

void		ft_intersect_light(t_data *data, t_ray ray, int *ref, double *dis)
{
	int			i;
	double		dis_aux;
	t_vector	aux;

	i = 0;
	*dis = -1;
	*ref = -1;
	while (i < data->nb_lights)
	{	
		aux = ft_create_vector(ray.a, data->lights[i]);
		if (ft_cos_btw_vectors(aux, ray.dir) == 1)
		{
			dis_aux = ft_distance(data->lights[i], ray.a);
			if (*dis < 0)
			{
				*ref = i;
				*dis = dis_aux;
			}
			else if (dis_aux < *dis)
			{
				*ref = i;
				*dis = dis_aux;
			}
		}
		i++;
	}
}

int			ft_get_pixel_color(t_data *data, t_point win_pixel)
{
	t_ray	ray;
	t_point	inter;
	double	dist[2];
	int		i[2];

	ray = ft_get_ray(data->cam, win_pixel);
	ray.a = win_pixel;
	inter = ft_intersect_elem(data, ray, i, dist);
	ft_intersect_light(data, ray, i + 1, dist + 1);
	if ((dist[0] < dist[1] || dist[1] == -1) && dist[0] > -1)
	{
	//if (dist[0] > -1)
		if (ft_has_light(inter, i[0], data))
			return (data->elements[i[0]].color);
	}
	else if (dist[1] > 0)
		return (0x00ffffff);
	return (0x000000);
}
