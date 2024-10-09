#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	fract;
	int	iter;

	iter = ITER_NMB;
	parser(argc, argv);
	if (!ft_strncmp(argv[1], "mandelbrot", 10) && argc == 3)
		iter = ft_atoi(argv[2]);
	if (!ft_strncmp(argv[1], "julia", 5) && argc == 5)
		iter = ft_atoi(argv[3]);
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
