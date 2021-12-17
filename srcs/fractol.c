/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:09:51 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/17 18:19:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_fract_data(t_fract_data *data, char **av);
static int	key_hook(int keycode, t_mlx_backpack *mlx_bp);
static int	mouse_hook(int button, int x, int y, void **params);

int	start_fractol(char **av)
{
	t_mlx_backpack	mlx_bp;
	t_fract_data	fract_data;
	void			*hook_params[2];

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
	hook_params[0] = &mlx_bp;
	hook_params[1] = &fract_data;
	mlx_key_hook(mlx_bp.window_ptr, key_hook, &mlx_bp);
	mlx_mouse_hook(mlx_bp.window_ptr, mouse_hook, hook_params);
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
	data->min = (t_complex){.x = -2, .y = -2};
	data->max = (t_complex){.x = 2, .y = 2};
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

static int	mouse_hook(int button, int xx, int yy, void **params)
{
	t_mlx_backpack	*mlx_bp;
	t_fract_data	*data;
	double			len;
	double			n_len;
	t_complex		mouse;

	mouse.x = xx;
	mouse.y = yy;
	mlx_bp = params[0];
	data = params[1];
	if (button == ZOOM_IN_KEY || button == ZOOM_OUT_KEY)
	{
		len = data->max.x - data->min.x;
		if (button == ZOOM_IN_KEY)
			n_len = len / 2;
		else
			n_len = len * 2;
		data->min.x += mouse.x / WIDTH * (len - n_len);
		data->min.y += mouse.y / HEIGHT * (len - n_len);
		data->max.x -= (1 - mouse.x / WIDTH) * (len - n_len);
		data->max.y -= (1 - mouse.y / HEIGHT) * (len - n_len);
		draw_fractal(mlx_bp, data);
	}
	return (0);
}
