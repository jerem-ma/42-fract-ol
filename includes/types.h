/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:53:33 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/05 15:04:24 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "ft_complex.h"

typedef enum e_fractal_type
{
	mandelbrot,
	julia
}	t_fractal_type;

typedef struct s_fract_data
{
	t_fractal_type	type;
	t_complex		c;
	t_complex		min;
	t_complex		max;
	int				color_shift;
}	t_fract_data;

#endif
