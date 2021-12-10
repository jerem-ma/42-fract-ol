/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sequence_finite.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:52:17 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/10 12:33:00 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_complex.h"

int	get_sequence_speed(t_complex u0, t_complex c)
{
	t_complex	un;
	int			is_finite;
	int			n;

	n = 0;
	is_finite = 1;
	un = u0;
	while (n < 100 && is_finite)
	{
		un = sum(square(un), c);
		if (modulus(un) > 2)
			is_finite = 0;
		n++;
	}
	if (is_finite)
		n = -1;
	return (n);
}
