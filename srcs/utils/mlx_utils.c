/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:13:28 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/13 12:07:26 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	destroy_everything(t_mlx_backpack *mlx_bp)
{
	if (!mlx_bp->mlx_ptr)
		return ;
	if (mlx_bp->window_ptr)
	{
		mlx_destroy_window(mlx_bp->mlx_ptr, mlx_bp->window_ptr);
		mlx_bp->window_ptr = 0;
	}
	mlx_destroy_display(mlx_bp->mlx_ptr);
	free(mlx_bp->mlx_ptr);
	mlx_bp->mlx_ptr = 0;
}
