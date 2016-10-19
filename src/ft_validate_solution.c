#include "rt.h"

void	ft_validate_solution(t_point **sol, t_ray ray, t_point win_pix, int *n)
{
	int			i;
	t_vector	aux;
	double		cos_alfa;

	i = 0;
	return ;
	while (i < *n)
	{
		aux = ft_create_vector(win_pix, (*sol)[i]);
		cos_alfa = ft_vect_dot_prod(ray.dir, aux) /
				(ft_vect_norm(ray.dir) * ft_vect_norm(aux));
		if (cos_alfa < 0)
		{
			if (i == 0 && *n == 2)
				ft_memcpy(&((*sol)[0]), &((*sol)[1]), sizeof(t_point));
			(*n)--;
			i--;
		}
		i++;
	}
	if (*n == 0)
		*sol = NULL;
}
