/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:59:35 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/13 17:33:01 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_floats.h"
#include <math.h>

double	parse_double(char *str)
{
	int		integer_part;
	int		float_part;
	char	*float_part_ptr;
	double	result;

	float_part_ptr = ft_strchr(str, '.') + 1;
	integer_part = ft_atoi(str);
	if (float_part_ptr == 0)
		return ((double) integer_part);
	float_part = ft_atoi(float_part_ptr);
	result = integer_part;
	result += float_part / pow(10, ft_strlen(float_part_ptr));
	return (result);
}

//int	set_int_mantissa(double *nbr, unsigned long int integer_part)
//{
//	int	i;
//	int	count;
//	int	digit;
//
//	i = 63;
//	count = 0;
//	while (i >= 0 && count < 52)
//	{
//		digit = 1 << i & integer_part;
//		if (digit || count)
//		{
//			*nbr |= (!!digit) << (51 - count);
//			count++;
//		}
//		i--;
//	}
//}
//
//int	set_float_mantissa(double *nbr, unsigned long int float_part, int shift)
//{
//	int	i;
//	int	count;
//	int	digit;
//
//	i = 63;
//	count = shift;
//	while (i >= 0 && count < 52)
//	{
//		digit = 1 << i & integer_part;
//		if (digit || count)
//		{
//			*nbr |= (!!digit) << (51 - count);
//			count++;
//		}
//		i--;
//	}
//}

int main()
{
	double ft_nbr;
	double nbr;
	char *str = "2424245.123612315";

	ft_nbr = parse_double(str);
	nbr = strtod(str, 0);
	printf("%f %f\n", ft_nbr, nbr);
}

int	is_float(char *str)
{
	int	i;
	int	part;

	i = 0;
	part = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
		{
			if (str[i] != '.' || part == 1)
				return (0);
			part = 1;
		}
		i++;
	}
	return (1);
}
