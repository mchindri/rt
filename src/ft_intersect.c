#include "rt.h"

static t_point *ft_intersect_cyl(t_ray ray, t_element elem, int *n,
					t_point win_pix)
{
	t_vector	aux[3];
	double		eq[3];
	double		*t;
	t_point		*sol;
	int			i;

	aux[0] = ft_vect_substract(ray.dir, ft_vect_scalar_prod(ft_vect_dot_prod(
				ray.dir, elem.dir), elem.dir));
	aux[2] = ft_create_vector(elem.center, ray.a);
	aux[1] = ft_vect_substract(aux[2], ft_vect_scalar_prod(ft_vect_dot_prod(
				aux[2], elem.dir), elem.dir));
	eq[0] = ft_vect_dot_prod(aux[0], aux[0]);
	eq[1] = 2 * ft_vect_dot_prod(aux[0], aux[1]);
	eq[2] = ft_vect_dot_prod(aux[1], aux[1]) - elem.r * elem.r;
	t = ft_solve_equation(eq[0], eq[1], eq[2], n);
	if (n == 0)
		return (NULL);
	sol = (t_point *)malloc(*n * sizeof(t_point));
	i = 0;
	while (i < *n)
	{
		sol[i].x = ray.a.x + t[i] * ray.dir.a;
		sol[i].y = ray.a.y + t[i] * ray.dir.b;
		sol[i].z = ray.a.z + t[i] * ray.dir.g;
		i++;
	}
	ft_validate_solution(&sol, ray, win_pix, n);
	return (sol);
}

static t_point *ft_intersect_cone(t_ray ray, t_element elem, int *n,
					t_point win_pix)
{
	double		eq[3];
	double		aux[4];
	t_vector	v[3];
	t_point		*sol;
	int			i;
	double		*t;

	aux[2] = elem.cos_alfa * elem.cos_alfa;
	aux[3] = elem.sin_alfa * elem.sin_alfa;
	v[2] = ft_create_vector(ray.a, elem.center);
	aux[0] = ft_vect_dot_prod(ray.dir, elem.dir);
	aux[1] = ft_vect_dot_prod(v[2], elem.dir);
	v[0] = ft_vect_substract(ray.dir, ft_vect_scalar_prod(aux[0], elem.dir));
	v[1] = ft_vect_substract(v[2], ft_vect_scalar_prod(aux[1], elem.dir));
	eq[0] = aux[2] * ft_vect_dot_prod(v[0], v[0]) - aux[3] * aux[0] * aux[0];
	eq[1] = 2 * aux[2] * ft_vect_dot_prod(v[0], v[1]) - 2 * aux[3] * aux[0] *
				aux[1];
	eq[2] = aux[2] * ft_vect_dot_prod(v[1], v[1]) - aux[3] * aux[1] * aux[1];
	t = ft_solve_equation(eq[0], eq[1], eq[2], n);
	if (*n == 0)
		return (NULL);
	i = 0;
	sol = (t_point *)malloc(*n * sizeof(t_point));
	while (i < *n)
	{
		sol[i].x = ray.a.x + t[i] * ray.dir.a;
		sol[i].y = ray.a.y + t[i] * ray.dir.b;
		sol[i].z = ray.a.z + t[i] * ray.dir.g;
		i++;
	}
	ft_validate_solution(&sol, ray, win_pix, n);
	return (sol);
}
static t_point *ft_intersect_plane(t_ray ray, t_element elem, int *n,
					t_point win_pix)
{
	double	t;
	double	aux1;
	double	aux2;
	t_point	*inter;

	aux1 = elem.d + elem.norm.a * ray.a.x + elem.norm.b * ray.a.y + elem.norm.g
			* ray.a.z;
	aux2 = ray.dir.a * elem.norm.a + ray.dir.b * elem.norm.b + ray.dir.g *
			elem.norm.g;
	t = -aux1 / aux2;
	if (t < 0)
	{
		*n = 0;
		return (NULL);
	}
	else
		*n = 1;
	inter = (t_point *)malloc(sizeof(t_point));
	inter->x = ray.a.x + t * ray.dir.a;
	inter->y = ray.a.y + t * ray.dir.b;
	inter->z = ray.a.z + t * ray.dir.g;
	ft_validate_solution(&inter, ray, win_pix, n);
	return(inter);
}

static t_point *ft_intersect_sphere(t_ray ray, t_element elem, int *n,
					t_point win_pix)
{
	double	*t;
	double	ec[3];
	t_point	*inter;
	double	sol[3];
	int		i;
	t_vector	aux;
	
	ec[0] = ft_vect_dot_prod(ray.dir, ray.dir);
	aux = ft_create_vector(ray.a, elem.center);
	ec[1] = 2 * ft_vect_dot_prod(ray.dir, aux);
	ec[2] = ft_vect_dot_prod(aux, aux) - (elem.r * elem.r);
	t = ft_solve_equation(ec[0], ec[1], ec[2], n);
	if (*n == 0)
		return (NULL);	
	inter = (t_point *)malloc(*n * sizeof(t_point));
	i = 0;
	while (i < *n)
	{
		sol[0] = ray.a.x + t[i] * ray.dir.a;
		sol[1] = ray.a.y + t[i] * ray.dir.b;
		sol[2] = ray.a.z + t[i] * ray.dir.g;
		inter[i] = ft_create_point(sol[0], sol[1], sol[2]);
		i++;
	}
	ft_validate_solution(&inter, ray, win_pix, n);
	return (inter);
}

/*
 * this function return de nearest intersection to the begin of the ray
 * with the elemenet
 */

double ft_intersect(t_ray ray, t_element elem, t_point *point, t_point win_pix)
{
	t_point *inter;
	int		nb_inter;
	float	d1;
	float	d2;

	if (elem.type == CYLINDER)
		inter = ft_intersect_cyl(ray, elem, &nb_inter, win_pix);
	else if (elem.type == CONE)
		inter = ft_intersect_cone(ray, elem, &nb_inter, win_pix);
	else if (elem.type == PLANE)
		inter = ft_intersect_plane(ray, elem, &nb_inter, win_pix);
	else if (elem.type == SPHERE)
		inter = ft_intersect_sphere(ray, elem, &nb_inter, win_pix);
	else
		ft_error("different element type\n");
	if (nb_inter == 0)
		return -1;
	else if (nb_inter == 1)
	{
		*point = *inter;
		return (ft_distance(ray.a, *inter));
	}
	d1 = ft_distance(ray.a, inter[0]);
	d2 = ft_distance(ray.a, inter[1]);
	if (d1 < d2)
	{
		*point = inter[0];
		return (d1);
	}
	*point = inter[1];
	return (d2);
}
