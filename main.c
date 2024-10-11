/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:23:18 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/11 12:55:23 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_help(void)
{
	write(1, "how to call program,\n", 22);
	write(1, "./fractol mandelbrot iter_numb(optional)\n", 42);
	write(1, "./fractol julia nmb1 nmb2 iter_numb(optional)\n", 47);
	write(1, "dont know cool julia sets?\n", 28);
	write(1, "try the following:", 18);
	write(1, "1(-0.8, 0.156) 2(-0.835, -0.2321)\n", 35);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_fractol	fract;
	int			iter;

	if (argc == 2 && !ft_strncmp(argv[1], "help", 4))
		ft_help();
	iter = ITER_NMB;
	parser(argc, argv);
	if (!ft_strncmp(argv[1], "mandelbrot", 10) && argc == 3)
		iter = ft_atoi(argv[2]);
	if (!ft_strncmp(argv[1], "julia", 5) && argc == 5)
		iter = ft_atoi(argv[4]);
	if (!ft_strncmp(argv[1], "julia", 5))
	{
		fract.julia_x = ft_fartoi(argv[2]);
		fract.julia_y = ft_fartoi(argv[3]);
	}
	fract.name = argv[1];
	data_init(&fract, iter);
	fractol_init(&fract);
	fractol_render(&fract);
	mlx_loop(fract.mlx_connection);
}
