#include "rt.h"

int get_color(char *color)
{
	if (ft_strcmp(color, "red") == 0)
		return (0xff0000);
	if (ft_strcmp(color, "blue") == 0)
		return (0x0000ff);
	if (ft_strcmp(color, "green") == 0)
		return (0x00ff00);
	if (ft_strcmp(color, "yellow") == 0)
		return (0xffff00);
	if (ft_strcmp(color, "cyan") == 0)
		return (0x00ffff);
	if (ft_strcmp(color, "magenta") == 0)
		return (0xff00ff);
	if (ft_strcmp(color, "orange") == 0)
		return (0xff6600);
	if (ft_strcmp(color, "violet") == 0)
		return (0x660066);
	if (ft_strcmp(color, "gray") == 0)
		return (0x666666);
	if (ft_strcmp(color, "turquoise") == 0)
		return (0x01c5cd);
	if (ft_strcmp(color, "white") == 0)
		return (0xffffff);
	if (ft_strcmp(color, "black") == 0)
		return (0x000000);
	ft_error("wrong color");
	return (-1);
}
