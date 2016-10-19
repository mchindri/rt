#include "rt.h"

int		get_length(char **tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
		i++;
	return (i);
}

void	count_elements(char *file, t_data *data)
{
	int		fd;
	char	*buf;
	char	**aux;
	int		len;

	data->nb_elem = 0;
	data->nb_lights = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Fail to open file\n");
	while (get_next_line(fd, &buf))
	{
		aux = ft_strsplit(buf, ' ');
		len = get_length(aux);
		if (len == 3)
			data->nb_lights++;
		else
			data->nb_elem++;
	}
	close(fd);
}

void	ft_set_element(char **element_param, t_data *data)
{
	int	length;
	static int light_idx = 0;
	static int elem_idx = 0;

	length = get_length(element_param);
	if (length == 3)
		setLight(element_param, data, light_idx++);
	else if (length == 5)
		setSphere(element_param, data, elem_idx++);
	else if (length == 9)
		setCone(element_param, data, elem_idx++);
	else if (length == 8)
		setCylinder(element_param, data, elem_idx++);
	else if (length == 10)
		setPlane(element_param, data, elem_idx++);
	else
		ft_error("Wrong input format");

}

int ft_read_data(char *file, t_data *data)
{
	int		fd;
	char	*line;
	char	**element_param;
	
	count_elements(file, data);
	data->elements = (t_element *)malloc(sizeof(t_element) * data->nb_elem);
	data->lights = (t_point *)malloc(sizeof(t_point) * data->nb_lights);
	if (data->elements == NULL || data->lights == NULL)
		ft_error("Fail at memory allocation");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		ft_error("Fail to open file\n");
	while(get_next_line(fd, &line))
	{
		element_param = ft_strsplit(line, ' ');
		ft_set_element(element_param, data);
	}
	close(fd);
	return (1);
}
