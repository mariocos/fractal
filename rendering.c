/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:23:31 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/11 13:05:27 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
//this is really dumb but since i cant use more than 4 params it had to be done
double	ft_scale(int flag, double max, double min, double value)
{
	if (flag == 1)
		return ((+2 - -2) * (value - min) / (max - min) + -2);
	if (flag == 2)
		return ((-2 - +2) * (value - min) / (max - min) + +2);
	if (flag == 3)
		return ((MAGENTA_BURST - PSYCHEDELIC_PURPLE)
			* (value - min) / (max - min) + PSYCHEDELIC_PURPLE);
	return (-1);
}

void	ft_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels + offset) = color;
}

void	ft_mandel_julia(t_complex *z, t_complex *c, t_fractol *f)
{
	if (!ft_strncmp(f->name, "mandelbrot", 10))
	{
		c->x = z->x;
		c->y = z->y;
	}
	else
	{
		c->x = f->julia_x;
		c->y = f->julia_y;
	}
}

void	handle_pixel(int x, int y, t_fractol *s)
{
	t_complex	z;
	t_complex	c;
	int			i;
	int			color;

	i = 0;
	z.x = ((ft_scale(1, WIDTH, 0, x) * s->zoom) + s->shift_sides);
	z.y = ((ft_scale(2, HEIGHT, 0, y) * s->zoom) + s->shift_vert);
	ft_mandel_julia(&z, &c, s);
	while (i < s->iteration_limit)
	{
		z = ft_complex_sum(ft_complex_sqrd(z), c);
		if ((z.x * z.x) + (z.y * z.y) > s->escaped_value)
		{
			color = ft_scale(3, s->iteration_limit, 0, i);
			ft_pixel_put(x, y, &s->img, color);
			return ;
		}
		++i;
	}
	ft_pixel_put(x, y, &s->img, BLACK);
}

void	fractol_render(t_fractol *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
			handle_pixel(x, y, f);
	}
	mlx_put_image_to_window(f->mlx_connection,
		f->mlx_window, f->img.img_ptr, 0, 0);
}
