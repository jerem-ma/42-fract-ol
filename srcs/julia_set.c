/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:50:55 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/15 17:58:57 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia_set.h"

static void	fill_julia_set(t_shiny *set, t_complex *pts, int length,
				t_complex c);

t_shiny	*get_julia_set(t_complex *pts, int length, t_complex c)
{
	t_shiny	*julia_set;

	julia_set = malloc(sizeof(*julia_set) * length);
	if (!julia_set)
		return (0);
	fill_julia_set(julia_set, pts, length, c);
	return (julia_set);
}

static void	fill_julia_set(t_shiny *set, t_complex *pts, int length,
		t_complex c)
{
	int		i;
	t_shiny	julie;

	i = 0;
	while (i < length)
	{
		julie.nbr = pts[i];
		julie.value = get_sequence_speed(pts[i], c);
		set[i] = julie;
		i++;
	}
}
