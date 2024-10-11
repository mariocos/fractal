/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:23:09 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/11 12:26:13 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_handler(t_fractol *f)
{
	mlx_destroy_image(f->mlx_connection, f->img.img_ptr);
	mlx_destroy_window(f->mlx_connection, f->mlx_window);
	mlx_destroy_display(f->mlx_connection);
	free(f->mlx_connection);
	exit(1);
	return (-1);
}

int	mouse_handler(int keysym, int x, int y, t_fractol *f)
{
	(void)x;
	(void)y;
	if (keysym == Button5)
		f->zoom *= 0.95;
	else if (keysym == Button4)
		f->zoom *= 1.05;
	fractol_render(f);
	return (-1);
}

int	key_handler(int keysym, t_fractol *f)
{
	if (keysym == XK_Escape)
		close_handler(f);
	else if (keysym == XK_Left)
		f->shift_sides += 0.5;
	else if (keysym == XK_Right)
		f->shift_sides -= 0.5;
	else if (keysym == XK_Up)
		f->shift_vert -= 0.5;
	else if (keysym == XK_Down)
		f->shift_vert += 0.5;
	fractol_render(f);
	return (-1);
}
