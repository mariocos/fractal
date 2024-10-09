#include "fractol.h"

void	free_error(void)
{
	perror("malloc problems :(\n");
	exit(1);
}

void	ft_call_error(void)
{
	write (1, "please call as follows,\n./fractol mandelbrot iter_nmb\n./fractol julia nmb nmb iter_nmb\n", 88);
	exit (1);
}
