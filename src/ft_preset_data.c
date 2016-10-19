#include "rt.h"

void ft_preset_data(t_data *data)
{
	data->cam = ft_create_point(30, 0, 15);
	data->screen.corner1 = ft_create_point(10, -15, 30);
	data->screen.corner2 = ft_create_point(10, 15, 30);
	data->screen.corner3 = ft_create_point(10, -15, 0);
}
