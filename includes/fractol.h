/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:28:49 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/14 11:57:41 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define SIZE 400
# define WIDTH SIZE
# define HEIGHT SIZE
# define TITLE "fract-ol"

# include <stdio.h>
# include <stdlib.h>

# include "mlx.h"
# include "libft.h"

# include "keycodes.h"
# include "mlx_utils.h"
# include "ft_complex.h"
# include "ft_floats.h"
# include "graph.h"
# include "types.h"

int			start_fractol(int ac, char **av);

#endif
