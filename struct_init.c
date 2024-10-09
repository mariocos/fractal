#include "fractol.h"

void	data_init(t_fractol *f, int	iter)//ad macro and option to give a sparamater
{
	f->escaped_value = 4;
	f->iteration_limit = iter;
	f->zoom = 1;
	f->shift_sides = 0;
	f->shift_vert = 0;
}

void	events_init(t_fractol *f)
{
	mlx_hook(f->mlx_window,
			KeyPress,
			KeyPressMask,
			key_handler,
			f);
	mlx_hook(f->mlx_window,
			ButtonPress,
			ButtonPressMask,
			mouse_handler,
			f);
	mlx_hook(f->mlx_window,
			DestroyNotify,
			StructureNotifyMask,
			close_handler,
			f);
}


void	fractol_init(t_fractol *fractol)
{
	fractol->mlx_connection = mlx_init();
	if (!fractol->mlx_connection)
		free_error();//missing implementation
	fractol->mlx_window = mlx_new_window(fractol->mlx_connection, WIDTH, HEIGHT, fractol->name);
	if (!fractol->mlx_window)
	{
		mlx_destroy_display(fractol->mlx_connection);
		free (fractol->mlx_connection);
		free_error();//missing
	}
	fractol->img.img_ptr = mlx_new_image(fractol->mlx_connection, WIDTH, HEIGHT);
	if (!fractol->img.img_ptr)
	{
		mlx_destroy_window(fractol->mlx_connection, fractol->mlx_window);
		mlx_destroy_display(fractol->mlx_connection);
		free (fractol->mlx_connection);
		free_error();//missing		
	}
	fractol->img.pixels = mlx_get_data_addr(fractol->img.img_ptr, &fractol->img.bpp, &fractol->img.line_len, &fractol->img.endian);
	events_init(fractol);//needs implement
}
