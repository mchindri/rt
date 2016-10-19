#include "rt.h"

int	mlx_pixel_put_to_image(void *img, int x, int y, int clr)
{
	char	*data;
	int		bpp;
	int		endian;
	int		sizeline;
	int		i;

	if (!(x >= 0 && y >= 0 && x <= WIN_WID &&
				y <= WIN_LEN))
		return (1);
	i = 0;
	data = mlx_get_data_addr(img, &bpp, &sizeline, &endian);
	if (endian == 0)
		while (i != bpp / 8)
		{
			data[y * sizeline + x * (bpp / 8) + i++] = 0x000000FF & clr;
			data[y * sizeline + x * (bpp / 8) + i++] = (0x0000FF00 & clr) >> 8;
			data[y * sizeline + x * (bpp / 8) + i++] = (0x00FF0000 & clr) >> 16;
			data[y * sizeline + x * (bpp / 8) + i++] = (0xFF000000 & clr) >> 24;
		}
	return (0);
}
