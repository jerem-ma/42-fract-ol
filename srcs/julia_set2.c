/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:50:55 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/20 16:04:22 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "julia_set.h"

static void	fill_julia_set(t_shiny *set, t_complex *pts, int length,
				t_complex c);
static void	fill_inverse_image(t_complex *result, t_complex z_n, t_complex c);

#include <stdio.h>

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
	int			i;
	t_shiny		julie;
	t_complex	result[2];

	i = 0;
	set[0] = 
	while (i < length)
	{
//		julie.nbr = pts[i];
//		julie.value = get_sequence_speed(pts[i], c);
//		set[i] = julie;
//		i++;
		
	}
	fill_inverse_image(result, (t_complex) {.x = -1, .y = 0}, c);
	printf("S = {(%f ; %f); (%f ; %f)}\n", result[0].x, result[0].y, result[1].x, result[1].y);
}

static void	get_base(t_shiny *set, t_complex c)
{
	t_complex	
}

static void	fill_inverse_image(t_complex *result, t_complex z_n, t_complex c)
{
	t_complex	z_base;
	double		s_x[2];
	double		s_y[2];

	z_base = minus(z_n, c);
	if (z_base.y == 0)
	{
		result[0] = (t_complex) {.x = 0, .y = -z_base.x};
		result[1] = (t_complex) {.x = 0, .y = z_base.x};
	}
	else
	{
		s_x[0] = -(z_n.x + sqrt(pow(z_n.x, 2) + pow(z_n.y, 2))) / 2;
		s_x[1] = s_x[0];
		s_y[0] = s_x[0] + z_n.x;
		s_y[1] = -s_y[0];
		if (z_base.y < 0)
		{
			if (s_x[0] * s_y[0] < 0)
				printf("Pouet !\n");
			result[0] = (t_complex) {.x = s_x[0], .y = s_y[0]};
			result[1] = (t_complex) {.x = s_x[1], .y = s_y[1]};
		}
		else
		{
			if (s_x[0] * s_y[0] > 0)
				printf("Pouet 2 !\n");
			result[0] = (t_complex) {.x = s_x[0], .y = s_y[1]};
			result[1] = (t_complex) {.x = s_x[1], .y = s_y[0]};
		}
	}
}
