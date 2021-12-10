/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:56:37 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/10 13:42:39 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_int_array	get_array(int width, int height)
{
	t_int_array	array;

	array.array = malloc(sizeof(int) * width * height);
	array.width = width;
	array.height = height;
	return (array);
}

int	*get_elem(int *array, int x, int y)
{
	if (x > array.width || y > array.height || x < 0 || y < 0)
		return (0);
	return (&array[y * array.width + x]);
}
