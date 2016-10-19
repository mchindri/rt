#include "rt.h"

static t_point	ft_get_iterator(t_point a, t_point b, int nb_iter)
{
	t_point iter;
	iter.x = (b.x - a.x) / nb_iter;
	iter.y = (b.y - a.y) / nb_iter;
	iter.z = (b.z - a.z) / nb_iter;
	return iter;
}

void			ft_draw_scene(t_data *data)
{
	int		i;
	int		j;
	t_point	w_step;
	t_point	l_step;
	t_point	screen_iter;
	
	w_step = ft_get_iterator(data->screen.corner1, data->screen.corner2,
								WIN_WID);
	l_step = ft_get_iterator(data->screen.corner1, data->screen.corner3,
								WIN_LEN);
	i = 0;
	while (i < WIN_LEN)
	{
		j = 0;
		screen_iter = ft_point_sum(data->screen.corner1, ft_point_prod(i,
									l_step));
		while (j < WIN_WID)
		{
			int color;
			color = ft_get_pixel_color(data, screen_iter);
			//mlx_pixel_put(data->mlx_ptr.mlx, data->mlx_ptr.win, j, i, color);
			mlx_pixel_put_to_image(data->mlx_ptr.img, j, i, color);
			screen_iter = ft_point_sum(screen_iter, w_step);	
			j++;
		}
		i++;
	}
}
