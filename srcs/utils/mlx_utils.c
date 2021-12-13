/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:13:28 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/13 11:19:44 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	destroy_everything(void **mlx_ptr, void **window_ptr)
{
	if (*window_ptr)
	{
		mlx_destroy_window(*mlx_ptr, *window_ptr);
		free(*window_ptr);
		*window_ptr = 0;
	}
	if (*mlx_ptr)
	{
		mlx_destroy_display(*mlx_ptr);
		free(*mlx_ptr);
		*mlx_ptr = 0;
	}
}
