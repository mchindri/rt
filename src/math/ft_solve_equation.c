#include "rt.h"

/*
 *	solve the equations but only raturnate positive solutionsi(not now)
 *
 */

double	*ft_solve_equation(double a, double b, double c, int *nb_sol)
{
	double	*sol;
	double	delta;

	if (a == 0)
	{
		if (b != 0)
		{
			*nb_sol = 1;
			sol = (double *)malloc(sizeof(double));
			*sol = -c / b;
			if (*sol < 0)
			{
				*nb_sol = 0;
				return (NULL);
			}
			return (sol);
		}
		else
		{
			*nb_sol = 0;
			return (NULL);
		}
	}
	delta = b * b - 4 * a * c;
	if (delta < 0)
	{
		*nb_sol = 0;
		return (NULL);
	}
	if (delta == 0)
	{
		*nb_sol = 1;
		sol = (double *)malloc(sizeof(double));
		*sol = -b / (2 * a);
		if (*sol < 0)
		{
			*nb_sol = 0;
			return (NULL);
		}
		return (sol);
	}
	*nb_sol = 2;
	sol = (double *)malloc(2 * sizeof(double));
	sol[0] = (-b + sqrt(delta)) / (2 * a);
	sol[1] = (-b - sqrt(delta)) / (2 * a);
	return (sol);
}
