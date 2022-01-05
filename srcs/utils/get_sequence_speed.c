/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sequence_speed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:52:17 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/05 15:40:29 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

int	get_sequence_speed(t_complex u0, t_complex c, int is_mega_mandelbrot)
{
	t_complex	un;
	int			is_finite;
	int			n;

	n = 0;
	is_finite = 1;
	un = u0;
	while (n < MAX_SPEED && is_finite)
	{
		un = sum(square(un), c);
		if (is_mega_mandelbrot)
			un = square(un);
		if (modulus(un) > 2)
			is_finite = 0;
		n++;
	}
	if (is_finite)
		n = -1;
	return (n);
}
