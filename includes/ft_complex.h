/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:21:07 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/10 10:34:00 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

typedef struct s_complex
{
	int	x;
	int	y;
}	t_complex;

t_complex	sum(t_complex, t_complex);
t_complex	multiply(t_complex, t_complex);

#endif
