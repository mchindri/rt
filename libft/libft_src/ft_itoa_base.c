/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchindri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 11:43:26 by mchindri          #+#    #+#             */
/*   Updated: 2016/03/02 11:43:29 by mchindri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_convert(char *str, int size, unsigned n, int base)
{
	str[size--] = '\0';
	if (n == 0)
		str[size] = '0';
	else
	{
		while (n > 0)
		{
			if (n % base > 9)
				str[size--] = n % base - 10 + 'A';
			else
				str[size--] = n % base + '0';
			n /= base;
		}
	}
}

int		ft_calc_size(unsigned n, int base, char sign)
{
	int size;

	size = 0;
	if (sign == '-' || n == 0)
		size++;
	while (n > 0)
	{
		n /= base;
		size++;
	}
	return (size);
}

char	*ft_itoa_base(int value, int base)
{
	unsigned	n;
	char		sign;
	char		*str;
	int			size;

	if (base > 16 || base < 2)
		return (NULL);
	sign = '+';
	if (value < 0)
	{
		n = value * (-1);
		if (base == 10)
			sign = '-';
	}
	else
		n = value;
	size = ft_calc_size(n, base, sign);
	str = (char *)malloc(sizeof(char) * (size + 1));
	ft_convert(str, size, n, base);
	if (sign == '-')
		str[0] = sign;
	return (str);
}
