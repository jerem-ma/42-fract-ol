/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:46:43 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/17 12:32:41 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPH_H
# define GRAPH_H

# include "mlx_utils.h"
# include "types.h"
# include "fractol.h"

void	draw_fractal(t_mlx_backpack *mlx_bp, t_fract_data *fract_data);
void	draw_julia_fractal(t_mlx_backpack *mlx_bp, t_fract_data *fract_data);

#endif
