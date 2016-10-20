#ifndef RT_H
# define RT_H

# include <mlx.h>
# include <math.h>
# include <libft.h>

# include <stdlib.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define WIN_LEN 500
# define WIN_WID 500

//
	#include <debug.h>
//

typedef struct	s_point
{
	double x;
	double y;
	double z;
}				t_point;

typedef struct	s_vector
{
	double a;
	double b;
	double g;
}				t_vector;

typedef struct	s_ray
{
	t_point		a;
	t_vector	dir;
}				t_ray;

typedef struct	s_element
{
	int			color;
	t_point		center;
	t_vector	norm;
	t_vector	dir;
	double		sin_alfa;
	double		cos_alfa;
	double		r;
	double		d;
	enum
	{
		CYLINDER,
		CONE,
		SPHERE,
		PLANE
	}			type;
}				t_element;

typedef struct	s_mlx
{
	void	*mlx;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct	s_data
{
	t_mlx		mlx_ptr;
	t_point		*lights;
	t_element	*elements;
	int			nb_elem;
	int			nb_lights;
	t_point		cam;
	struct
	{
		t_point corner1;
		t_point corner2;
		t_point corner3;
	}			screen;
}				t_data;


void	setLight(char **element_param, t_data *data, int index);
void	setSphere(char **element_param, t_data *data, int index);
void	setCone(char **element_param, t_data *data, int index);
void	setCylinder(char **element_param, t_data *data, int index);
void	setPlane(char **element_param, t_data *data, int index);

int		ft_read_data(char *file, t_data *data);
void	ft_draw_scene(t_data *data);
void	ft_preset_data(t_data *data);
int		ft_get_pixel_color(t_data *data, t_point win_pix);
double	ft_intersect(t_ray ray, t_element elem, t_point *point);
t_bool	ft_has_light(t_point point, int i_ref, t_data *data);
t_ray	ft_get_ray(t_point a, t_point b);
void	ft_validate_solution(t_point **sol, t_ray ray, int *n);

t_point		ft_point_sum(t_point a, t_point b);
t_point		ft_point_prod(double k, t_point a);
t_point		ft_create_point(double x, double y, double z);
double		*ft_solve_equation(double a, double b, double c, int *nb_sol);
double		ft_vect_norm(t_vector vect);
double		ft_vect_dot_prod(t_vector a, t_vector b);
t_vector 	ft_vect_scalar_prod(double k, t_vector a);
t_vector	ft_vect_prod(t_vector a, t_vector b);
t_vector	ft_vect_substract(t_vector a, t_vector b);
t_vector	ft_create_vector(t_point a, t_point b);
void		ft_vect_normalize(t_vector *a);
double		ft_distance(t_point a, t_point b);
double		ft_cos_btw_vectors(t_vector a, t_vector b);

int		get_color(char *color);
void	ft_usage();
void	ft_error(char *str);

int		mlx_pixel_put_to_image(void *img, int x, int y, int clr);

# endif
