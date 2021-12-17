/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:09:51 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/17 12:46:32 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fract_data(t_fract_data *data, char **av);
static int	key_hook(int keycode, t_mlx_backpack *mlx_bp);

int	start_fractol(char **av)
{
	t_mlx_backpack	mlx_bp;
	t_fract_data	fract_data;

	mlx_bp.mlx_ptr = mlx_init();
	if (!mlx_bp.mlx_ptr)
		return (1);
	mlx_bp.window_ptr = mlx_new_window(mlx_bp.mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!mlx_bp.window_ptr)
	{
		destroy_everything(&mlx_bp);
		return (2);
	}
	init_fract_data(&fract_data, av);
	draw_fractal(&mlx_bp, &fract_data);
	mlx_key_hook(mlx_bp.window_ptr, key_hook, &mlx_bp);
	mlx_loop(mlx_bp.mlx_ptr);
	destroy_everything(&mlx_bp);
	return (0);
}

static void	init_fract_data(t_fract_data *data, char **av)
{
	if (!ft_strncmp(av[1], "mandelbrot", 11))
		data->type = mandelbrot;
	else if (!ft_strncmp(av[1], "julia", 6))
	{
		data->type = julia;
		data->c.x = parse_double(av[2]);
		data->c.y = parse_double(av[3]);
	}
	data->min = -2;
	data->max = 2;
}

static int	key_hook(int keycode, t_mlx_backpack *mlx_bp)
{
	if (keycode == ECHAP_KEY)
	{
		printf("Exiting program...\n");
		mlx_loop_end(mlx_bp->mlx_ptr);
	}
	return (0);
}
