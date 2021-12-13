/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 11:13:53 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/13 11:34:02 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include <stdlib.h>

# include "mlx.h"

typedef struct s_mlx_backpack
{
	void	*mlx_ptr;
	void	*window_ptr;
}	t_mlx_backpack;

void	destroy_everything(t_mlx_backpack *mlx_bp);
#endif
