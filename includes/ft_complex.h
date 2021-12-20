/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complex.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 10:21:07 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/20 14:46:15 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COMPLEX_H
# define FT_COMPLEX_H

# include <math.h>

typedef struct s_complex
{
	double	x;
	double	y;
}	t_complex;

t_complex	sum(t_complex, t_complex);
t_complex	minus(t_complex, t_complex);
t_complex	multiply(t_complex, t_complex);
t_complex	square(t_complex c);
double		modulus(t_complex c);

#endif
