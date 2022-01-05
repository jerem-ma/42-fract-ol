/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:50:55 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/05 15:57:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "set.h"

static void	fill_set(t_shiny *set, t_complex *pts, int length,
				t_fract_data *data);

t_shiny	*get_set(t_complex *pts, int length, t_fract_data *data)
{
	t_shiny	*set;

	set = malloc(sizeof(*set) * length);
	if (!set)
		return (0);
	fill_set(set, pts, length, data);
	return (set);
}

static void	fill_set(t_shiny *set, t_complex *pts, int length,
		t_fract_data *data)
{
	int			i;
	t_shiny		julie;
	t_complex	z0;

	z0 = (t_complex){.x = 0, .y = 0};
	i = 0;
	while (i < length)
	{
		julie.nbr = pts[i];
		if (data->type == mandelbrot)
			julie.value = get_sequence_speed(z0, pts[i], 0);
		else if (data->type == julia)
			julie.value = get_sequence_speed(pts[i], data->c, 0);
		else if (data->type == mega_mandelbrot)
			julie.value = get_sequence_speed(z0, pts[i], 1);
		set[i] = julie;
		i++;
	}
}
