/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:59:35 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/13 14:07:16 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_floats.h"

double	parse_double(char *str)
{
	(void) str;
	return (0.0);
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
