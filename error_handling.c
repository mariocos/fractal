/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:23:05 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/11 12:25:30 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	free_error(void)
{
	perror("malloc problems :(\n");
	exit(1);
}

void	ft_call_error(void)
{
	write (1, "please call as follows,\n", 25);
	write (1, "./fractol mandelbrot iter_nmb\n", 31);
	write (1, "./fractol julia nmb nmb iter_nmb\n", 34);
	exit (1);
}
