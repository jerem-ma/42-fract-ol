/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:09:51 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/13 12:12:14 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	start_fractol(int ac, char **av)
{
	t_mlx_backpack	mlx_bp;

	(void) ac;
	(void) av;
	mlx_bp.mlx_ptr = mlx_init();
	if (!mlx_bp.mlx_ptr)
		return (1);
	mlx_bp.window_ptr = mlx_new_window(mlx_bp.mlx_ptr, WIDTH, HEIGHT, TITLE);
	if (!mlx_bp.window_ptr)
	{
		destroy_everything(&mlx_bp);
		return (2);
	}
	mlx_key_hook(mlx_bp.window_ptr, key_hook, &mlx_bp);
	mlx_loop(mlx_bp.mlx_ptr);
	destroy_everything(&mlx_bp);
	return (0);
}

static int	key_hook(int keycode, t_mlx_backpack *mlx_bp)
{
	if (keycode == 65307)
	{
		printf("Exiting program...\n");
		mlx_loop_end(mlx_bp->mlx_ptr);
	}
	return (0);
}
