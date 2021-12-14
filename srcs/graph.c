/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:45:37 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/14 16:04:14 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

#include "shiny.h"
#include "julia_set.h"

static void	fill_pts(t_complex *pts, t_fract_data *data, int width, int height);

void	draw_fractal(t_mlx_backpack *mlx_bp, t_fract_data *fract_data)
{
	int		x;
	int		y;
	void	*image;
	int		*buffer;
	int		a;
	t_shiny	*set;
	t_complex	pts[SIZE * SIZE];

	fill_pts(pts, fract_data, SIZE, SIZE);
	set = get_julia_set(pts, SIZE * SIZE, fract_data->c);
	y = 0;
	image = mlx_new_image(mlx_bp->mlx_ptr, SIZE, SIZE);
	buffer = (int *) mlx_get_data_addr(image, &a, &a, &a);
	while (y < SIZE)
	{
		x = 0;
		while (x < SIZE)
		{
//			printf("%f\n", set[y * SIZE + x].value == -1 ? 0 : (set[y * SIZE + x].value - 50) / 100.0 * 255); 
			buffer[(y * SIZE + x)] = (((int) (set[y * SIZE + x].value == -1 ? 0 : (set[y * SIZE + x].value - 50) / 100.0 * 255)) << 4) + ((int) (set[y * SIZE + x].value == -1 ? 0 : (set[y * SIZE + x].value - 50) / 100.0 * 255) << 2) + set[y * SIZE + x].value == -1 ? 0 : (set[y * SIZE + x].value - 50) / 100.0 * 255;
//			buffer[(y * SIZE + x) * 4 + 1] = set[y * SIZE + x].value == -1 ? 0 : (set[y * SIZE + x].value - 50) / 100.0 * 255; 
//			buffer[(y * SIZE + x) * 4 + 2] = set[y * SIZE + x].value == -1 ? 0 : (set[y * SIZE + x].value - 50) / 100.0 * 255; 
//			buffer[(y * SIZE + x) * 4 + 3] = set[y * SIZE + x].value == -1 ? 0 : (set[y * SIZE + x].value - 50) / 100.0 * 255; 
			x++;
		}
		y++;
	}
	printf("%f %f\n", fract_data->c.x, fract_data->c.y);
	mlx_put_image_to_window(mlx_bp->mlx_ptr, mlx_bp->window_ptr, image, 0, 0);
	(void) mlx_bp;
	(void) fract_data;
}

static void	fill_pts(t_complex *pts, t_fract_data *data, int width, int height)
{
	int			x;
	int			y;
	t_complex	point;

	y = 0;
	while (y < height)
	{
		x = 0;
		point.y = (1.0 * y / height * (data->max - data->min)) + data->min;
		while (x < width)
		{
			point.x = (1.0 * x / width * (data->max - data->min)) + data->min;
			pts[y * width + x] = point;
			x++;
		}
		y++;
	}
}
