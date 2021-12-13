/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:28:49 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/13 12:09:37 by jmaia            ###   ########.fr       */
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

# include "mlx_utils.h"

int			start_fractol(int ac, char **av);
static int	key_hook(int keycode, t_mlx_backpack *mlx_bp);

#endif
