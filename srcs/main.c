/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:47:02 by jmaia             #+#    #+#             */
/*   Updated: 2021/12/13 14:00:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	main(int ac, char **av)
{
	int	err;

	if (!are_args_valid(ac, av))
	{
		print_help();
		return (1);
	}
	err = start_fractol(ac, av);
	if (err)
		print_err();
	return (err);
}

static int	are_args_valid(int ac, char **av)
{
	if (ac < 2)
		return (0);
	if (!ft_strncmp(av[1], "mandelbrot", 11))
		return (1);
	if (!ft_strncmp(av[1], "julia", 6))
	{
		if (ac < 4)
			return (0);
		if (!is_float(av[2]) || !is_float(av[3]))
			return (0);
		return (1);
	}
	return (0);
}

static void	print_help(void)
{
	ft_putendl_fd("--- Available parameters ---", 2);
	ft_putendl_fd("• mandelbrot", 2);
	ft_putendl_fd("• julia Re(C) Im(C)", 2);
	ft_putendl_fd("----------------------------", 2);
}

static void	print_err(void)
{
	ft_putendl_fd("An error has occured while using mlx !", 2);
}
