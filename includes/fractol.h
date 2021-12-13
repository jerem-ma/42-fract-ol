/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:28:49 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/13 14:05:21 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 1024
# define HEIGHT 768
# define TITLE "fract-ol"

# include <stdio.h>
# include <stdlib.h>

# include "mlx.h"
# include "libft.h"

# include "keycodes.h"
# include "mlx_utils.h"
# include "ft_complex.h"
# include "ft_floats.h"

typedef enum e_fractal_type
{
	mandelbrot,
	julia
}	t_fractal_type;

typedef struct s_fract_data
{
	t_fractal_type	type;
	t_complex		c;
}	t_fract_data;

int			start_fractol(int ac, char **av);

#endif
