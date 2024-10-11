/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mariocos <mariocos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 12:23:28 by mariocos          #+#    #+#             */
/*   Updated: 2024/10/11 13:04:33 by mariocos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_atoi(char *str)
{
	int	i;
	int	nbr;

	i = 0;
	nbr = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			write(1, "please use a valid number for iter_numb\n", 41);
			exit(1);
		}
		nbr *= 10;
		nbr += str[i] - '0';
		if (nbr > 1500)
		{
			write(1, "iter nmb too large do not recomend\n", 36);
			exit(1);
		}
		i++;
	}
	return (nbr);
}

void	fart_check(char *s)
{
	int	i;
	int	flag;

	flag = 0;
	i = 0;
	if (s[0] == '-')
		i++;
	while (s[i] != '\0')
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
		{
			write(1, "please call julia with a valid number set\n", 43);
			exit(1);
		}
		if (s[i] == '.')
			flag++;
		i++;
	}
	if (flag > 1)
	{
		write(1, "please call julia with a valid number set\n", 43);
		exit(1);
	}
}

double	fart_loop(char *str, double nmb, int i)
{
	double	flag;

	flag = 10;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			flag = 0.1;
		else if (flag == 10)
		{
			nmb *= 10;
			nmb += str[i] - '0';
		}
		else if (flag != 10)
		{
			nmb += (str[i] - '0') * flag;
			flag *= 0.1;
		}
		i++;
	}
	return (nmb);
}

double	ft_fartoi(char *str)
{
	double	nmb;
	int		neg;
	int		i;

	fart_check(str);
	i = 0;
	nmb = 0;
	neg = 1;
	if (str[0] == '-')
	{
		neg = -1;
		i++;
	}
	nmb = fart_loop(str, nmb, i);
	return (nmb * neg);
}

void	parser(int argc, char **argv)
{
	if (argc < 2 || argc > 5)
		ft_call_error();
	if (ft_strncmp(argv[1], "mandelbrot", 10)
		&& ft_strncmp(argv[1], "julia", 5))
		ft_call_error();
	if (!ft_strncmp(argv[1], "julia", 5) && argc < 4)
		ft_call_error();
}
