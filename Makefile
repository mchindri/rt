SRC = 	main.c\
		src/ft_draw_scene.c\
		src/ft_error.c\
		src/ft_get_pixel_color.c\
		src/ft_get_ray.c\
		src/ft_has_light.c\
		src/ft_intersect.c\
		src/ft_preset_data.c\
		src/ft_read_data.c\
		src/ft_set_elements.c\
		src/ft_usage.c\
		src/ft_validate_solution.c\
		src/get_color.c\
		src/math/ft_create_point.c\
		src/math/ft_create_vector.c\
		src/math/ft_solve_equation.c\
		src/math/ft_vect_dot_prod.c\
		src/math/ft_vect_normalize.c\
		src/math/ft_vect_norm.c\
		src/math/ft_vect_prod.c\
		src/math/ft_vect_scalar_prod.c\
		src/math/ft_vect_substract.c\
		src/math/ft_vect_sum.c\
		src/math/ft_point_sum.c\
		src/math/ft_point_prod.c\
		src/math/ft_distance.c\
		src/math/ft_cos_btw_vectors.c\
		src/mlx_pixel_put_to_image.c

FLAGS = -Wall -Wextra -Werror	
NAME = rt
INCLUDES = -I includes -I libft/includes
LIBRARYS = -lmlx -lXext -lX11 -lm -L libft -lft

###
DEBUG = -I debug
###

all: $(NAME)

$(NAME): mlx
	@make -C libft
	@gcc $(SRC) -o $(NAME) $(FLAGS) $(LIBRARYS) $(INCLUDES) $(DEBUG)

mlx:
#	@echo "Libraria minilibx este creat pe linux."
#	make -C minilibx

clean:
	@rm -f $(NAME)

fclean: clean
	@make -C libft fclean
#	@echo "minilibx nu se sterge pe linux"
#	make -C minilibx clean

re: clean all

test: re
	./rt input_files/scene1.txt


