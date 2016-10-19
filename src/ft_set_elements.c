#include "rt.h"

void setLight(char **element_param, t_data *data, int index)
{
	data->lights[index].x = atof(element_param[0]);
	data->lights[index].y = atof(element_param[1]);
	data->lights[index].z = atof(element_param[2]);
}

void setSphere(char **element_param, t_data *data, int index)
{
	data->elements[index].center = ft_create_point(atof(element_param[0]),
		atof(element_param[1]), atof(element_param[2]));
	data->elements[index].r = atof(element_param[3]);
	data->elements[index].color = get_color(element_param[4]);
	data->elements[index].type = SPHERE;
}

void setCone(char **element_param, t_data *data, int index)
{
	t_point		p[2];
	double		r;
	double		h;
	double		l1;
	t_vector	dir;

	p[0] = ft_create_point(atof(element_param[0]), atof(element_param[1]),
			atof(element_param[2]));
	p[1] = ft_create_point(atof(element_param[3]), atof(element_param[4]),
			atof(element_param[5]));
	r = atof(element_param[6]);
	l1 = ft_distance(p[0], p[1]);
	h = sqrt(r * r + l1 * l1);
	data->elements[index].sin_alfa = r / h;
	data->elements[index].cos_alfa = l1 / h;
	data->elements[index].center = p[0];
	dir = ft_create_vector(p[0], p[1]);
	ft_vect_normalize(&dir);
	data->elements[index].dir = dir;
	data->elements[index].r = r;
	data->elements[index].d = atof(element_param[7]);
	data->elements[index].color = get_color(element_param[8]);
	data->elements[index].type = CONE;
}

void setCylinder(char **element_param, t_data *data, int index)
{
	t_point		point[2];

	point[0] = ft_create_point(atof(element_param[0]), atof(element_param[1]),
								atof(element_param[2]));
	point[1] = ft_create_point(atof(element_param[3]), atof(element_param[4]),
								atof(element_param[5]));
	data->elements[index].dir = ft_create_vector(point[0], point[1]);
	ft_vect_normalize(&(data->elements[index].dir));
	data->elements[index].center = point[0];
	data->elements[index].r = atof(element_param[6]);
	data->elements[index].color = get_color(element_param[7]);
	data->elements[index].type = CYLINDER;
}

/*
 *  norm is the normal vector of the plane
 *  the plane ecuation is ax + by + cz + d = 0 
 *	a,b,c are the dir parmas;
 *  d is the left parameter;
 */

void setPlane(char **element_param, t_data *data, int index)
{
	t_point		p[3];
	t_vector	vec[2];
	t_vector	dir;

	p[0] = ft_create_point(atof(element_param[0]), atof(element_param[1]),
							atof(element_param[2]));
	p[1] = ft_create_point(atof(element_param[3]), atof(element_param[4]),
							atof(element_param[5]));
	p[2] = ft_create_point(atof(element_param[6]), atof(element_param[7]),
							atof(element_param[8]));
	vec[0] = ft_create_vector(p[0], p[1]);
	vec[1] = ft_create_vector(p[0], p[2]);
	dir = ft_vect_prod(vec[0], vec[1]);
	ft_vect_normalize(&dir);
	data->elements[index].d = -(dir.a * p[0].x + dir.b * p[0].y + dir.g *
								p[0].z);
	data->elements[index].norm = dir;
	data->elements[index].color = get_color(element_param[9]);
	data->elements[index].type = PLANE;
}
