#include "rt.h"

t_mlx draw_window()
{
	int		i;
	int		j;
	t_mlx	mlx_ptr;
	mlx_ptr.mlx = mlx_init();
	mlx_ptr.win = mlx_new_window(mlx_ptr.mlx, 500, 500, "test");	
	i = 225;
	while (i < 275)
	{
		j = 225;
		while (j < 275)
		{
			mlx_pixel_put(mlx_ptr.mlx, mlx_ptr.win, i, j, 0xff0000);
			j++;
		}
		i++;
	}
	return mlx_ptr;
}

int		ft_key_hook(int key, void *var)
{
	//
	(void)var;
	ft_putnbr(key);ft_putstr("\n");
	//
	if (key == 65307)
		exit(0);
	return (0);
}

/*void testSphere(t_data *data)
{
	t_ray ray;
	t_element sphere = data->elements[0];
	t_point inter;
	t_point p1, p2;
	double dist;

	POINT(sphere.center)
	NBF(sphere.r)
	p1 = ft_create_point(10, 0, 0);
	p2 = ft_create_point(9, 0, 0);
	ray = ft_get_ray(p1, p2);
	POINT(ray.a)
	VECT(ray.dir)
	dist = ft_intersect(ray, sphere, &inter);
	NBF(dist)
	POINT(inter)
	EXIT
}
*/
int main(int argc, char **argv)
{	
	void	*var = NULL;
	t_data	data;
	
	if (argc != 2)
		ft_usage();
	ft_read_data(argv[1], &data);
	//testSphere(&data);
	ft_preset_data(&data);
	data.mlx_ptr.mlx = mlx_init();
	data.mlx_ptr.win = mlx_new_window(data.mlx_ptr.mlx, WIN_WID, WIN_LEN,
										argv[1]);
	data.mlx_ptr.img = mlx_new_image(data.mlx_ptr.mlx, WIN_WID, WIN_LEN);
	ft_draw_scene(&data);
	mlx_put_image_to_window(data.mlx_ptr.mlx, data.mlx_ptr.win,
								data.mlx_ptr.img, 0, 0);
//	mlx_destroy_image(data.mlx_ptr.mlx, data.mlx_ptr.img);
	mlx_key_hook(data.mlx_ptr.win, ft_key_hook, &var);
	mlx_loop(data.mlx_ptr.mlx);
	return 0;
}
