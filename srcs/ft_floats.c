/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:59:35 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/14 12:51:56 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_floats.h"
#include <math.h>

#include <stdio.h>

double	parse_double(char *str)
{
	int		integer_part;
	int		float_part;
	char	*float_part_ptr;
	double	result;

	float_part_ptr = ft_strchr(str, '.') + 1;
	integer_part = ft_atoi(str + (str[0] == '-'));
	if (float_part_ptr == (void *)1)
		return ((double) integer_part);
	float_part = ft_atoi(float_part_ptr);
	result = integer_part;
	result += float_part / pow(10, ft_strlen(float_part_ptr));
	return (result * (-2 * (str[0] == '-') + 1));
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
			if (!((str[i] == '.' && part == 0) || (str[i] == '-' && i == 0)))
				return (0);
			if (str[i] == '.')
				part = 1;
		}
		i++;
	}
	return (1);
}
