/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:45:37 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/02 19:30:42 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graph.h"

#include "shiny.h"
#include "julia_set.h"

static void	fill_pts(t_complex pts[], t_fract_data *data, int width,
				int height);
static int	get_color(int speed);
static void	clean_set_and_image(void *set, void *image, void *mlx_ptr);

void	draw_fractal(t_mlx_backpack *mlx_bp, t_fract_data *fract_data)
{
	if (fract_data->type == mandelbrot)
		;
	else if (fract_data->type == julia)
		draw_julia_fractal(mlx_bp, fract_data);
}

void	draw_julia_fractal(t_mlx_backpack *mlx_bp, t_fract_data *fract_data)
{
	t_complex	screen;
	void		*image;
	int			*buffer;
	t_shiny		*set;
	t_complex	pts[SIZE * SIZE];

	fill_pts(pts, fract_data, SIZE, SIZE);
	set = get_julia_set(pts, SIZE * SIZE, fract_data->c);
	screen.y = 0;
	image = mlx_new_image(mlx_bp->mlx_ptr, SIZE, SIZE);
	buffer = (int *)mlx_get_data_addr(image, (int *)&screen.x,
			(int *)&screen.x, (int *)&screen.x);
	while (screen.y < SIZE)
	{
		screen.x = 0;
		while (screen.x < SIZE)
		{
			buffer[(int)(screen.y * SIZE + screen.x)] = get_color(
					set[(int)(screen.y * SIZE + screen.x)].value);
			screen.x++;
		}
		screen.y++;
	}
	mlx_put_image_to_window(mlx_bp->mlx_ptr, mlx_bp->window_ptr, image, 0, 0);
	clean_set_and_image(set, image, mlx_bp->mlx_ptr);
}

static void	clean_set_and_image(void *set, void *image, void *mlx_ptr)
{
	free(set);
	mlx_destroy_image(mlx_ptr, image);
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
		point.y = ((data->max.y - data->min.y) * y / height) + data->min.y;
		while (x < width)
		{
			point.x = ((data->max.x - data->min.x) * x / width) + data->min.x;
			pts[y * width + x] = point;
			x++;
		}
		y++;
	}
}

static int	get_color(int speed)
{
	int	color;

	if (speed == -1)
		return (0xFF000000);
	color = 0;
	if (speed % 60 < 20)
	{
		color += (int)(255 - speed % 60 / 20.0 * 255) << 16;
		color += (int)(speed % 60 / 20.0 * 255) << 8;
	}
	else if (speed % 60 < 40)
	{
		color += (int)(255 - speed % 60 / 20.0 * 255) << 8;
		color += (int)((speed - 20) % 60 / 20.0 * 255);
	}
	else
	{
		color += (int)(255 - speed % 60 / 20.0 * 255);
		color += (int)((speed - 40) % 60 / 20.0 * 255) << 16;
	}
	return (color);
}
