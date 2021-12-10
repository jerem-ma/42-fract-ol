/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:50:01 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/10 15:03:22 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA_SET_H
# define JULIA_SET_H

# include <stdlib.h>

# include "ft_complex.h"
# include "get_sequence_speed.h"

typedef struct s_shiny
{
	t_complex	nbr;
	int			value;
}	t_shiny;

t_shiny	*get_julia_set(t_complex *pts, int length, t_complex c);
#endif
