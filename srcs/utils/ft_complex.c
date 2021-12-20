/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:35:44 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/20 14:45:35 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

t_complex	sum(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.x = c1.x + c2.x;
	result.y = c1.y + c2.y;
	return (result);
}

t_complex	minus(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.x = c1.x - c2.x;
	result.y = c1.y - c2.y;
	return (result);
}

t_complex	multiply(t_complex c1, t_complex c2)
{
	t_complex	result;

	result.x = c1.x * c2.x - c1.y * c2.y;
	result.y = c1.x * c2.y + c1.y * c2.x;
	return (result);
}

t_complex	square(t_complex c)
{
	return (multiply(c, c));
}

double	modulus(t_complex c)
{
	return (sqrt(pow(c.x, 2) + pow(c.y, 2)));
}
