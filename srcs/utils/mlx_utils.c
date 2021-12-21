/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:13:28 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/21 16:12:53 by jmaia            ###   ########.fr       */
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

t_img	*zoom(t_mlx_backpack *mlx_bp, t_img *image, double factor)
{
	t_img		*new_image;
	int			n_width;
	int			n_height;
	t_complex	tmp;
	int			*img_bytes;
	int			*old_img_bytes;

	n_width = (int) image->width * factor;
	n_height = (int) image->height * factor;
	new_image = mlx_new_image(mlx_bp->mlx_ptr, n_width, n_height);
	if (!new_image)
		return (0);
	img_bytes = (int *) mlx_get_data_addr(new_image, (int *) &tmp, (int *) &tmp, (int *) &tmp);
	old_img_bytes = (int *) mlx_get_data_addr(image, (int *) &tmp, (int *) &tmp, (int *) &tmp);
	tmp = (t_complex) {.x = 0, .y = 0};
	while (tmp.y < n_height)
	{
		tmp.x = 0;
		while (tmp.x < n_width)
		{
			img_bytes[(int) (tmp.y * n_width + tmp.x)] = old_img_bytes[(int) ((int) (tmp.y / factor) * image->width + tmp.x / factor)];
			tmp.x++;
		}
		tmp.y++;
	}
	return (new_image);
}
