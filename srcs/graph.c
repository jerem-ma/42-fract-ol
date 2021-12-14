/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:45:37 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/14 11:29:07 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

void	draw_fractal(t_mlx_backpack *mlx_bp, t_fract_data *fract_data)
{
	int		x;
	int		y;
	void	*image;
	char	*buffer;
	int		a;

	y = 0;
	image = mlx_new_image(mlx_bp->mlx_ptr, WIDTH, HEIGHT);
	buffer = mlx_get_data_addr(image, &a, &a, &a);
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			buffer[(y * WIDTH + x) * 4] = 127;
			buffer[(y * WIDTH + x) * 4 + 1] = 127;
			buffer[(y * WIDTH + x) * 4 + 2] = 127;
			buffer[(y * WIDTH + x) * 4 + 3] = 127;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx_bp->mlx_ptr, mlx_bp->window_ptr, image, 0, 0);
	(void) mlx_bp;
	(void) fract_data;
}
