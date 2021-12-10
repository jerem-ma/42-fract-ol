/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_set.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:50:01 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/10 15:11:02 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef JULIA_SET_H
# define JULIA_SET_H

# include <stdlib.h>

# include "ft_complex.h"
# include "get_sequence_speed.h"
# include "shiny.h"

t_shiny	*get_julia_set(t_complex *pts, int length, t_complex c);
#endif
