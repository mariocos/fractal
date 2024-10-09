#include "fractol.h"

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int				ret;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	ret = 0;
	if (n == 0)
		return (0);
	while (*str1 == *str2 && *str1 != '\0' && --n > 0)
	{
		str1++;
		str2++;
	}
	ret = *str1 - *str2;
	return (ret);
}


void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}
