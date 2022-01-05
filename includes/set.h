/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:50:01 by jmaia             #+#    #+#             */
/*   Updated: 2022/01/05 13:38:05 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_H
# define SET_H

# include <stdlib.h>

# include "ft_complex.h"
# include "get_sequence_speed.h"
# include "shiny.h"
# include "types.h"

t_shiny	*get_set(t_complex *pts, int length, t_fract_data *data);
#endif
