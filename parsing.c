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
		printf("checking %c\n", s[i]);
		if ((s[i] < '0' || s[i] > '9') && s[i] != '.')
		{
			printf("hey\n");
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

double	ft_fartoi(char *str)
{
	double	nmb;
	int	i;
	double	flag;

	fart_check(str);
	i = 0;
	flag = 10;
	nmb = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
			flag = 0.1;
		if (flag == 10)
		{
			nmb *= 10;
			nmb += str[i] - '0';
		}
		if (flag != 10)
		{
			nmb += (str[i] - '0') * flag;
			flag *= 0.1;
		}
		i++;
	}
	return (nmb);
}



void	parser(int argc, char **argv)
{
	if (argc < 2 || argc > 5)
		ft_call_error();
	if (ft_strncmp(argv[1], "mandelbrot", 10) && ft_strncmp(argv[1], "julia", 5))
		ft_call_error();
	if (!ft_strncmp(argv[1], "julia", 5) && argc < 4)
		ft_call_error();
}
