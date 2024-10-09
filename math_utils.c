#include "fractol.h"

t_complex ft_complex_sum(t_complex z, t_complex c)
{
	t_complex	sum;

	sum.x = z.x + c.x;
	sum.y = z.y + c.y;
	return (sum);
}

// x'2 +ai'2 +2xai
t_complex	ft_complex_sqrd(t_complex z)
{
	t_complex	ret;

	ret.x = (z.x * z.x) - (z.y * z.y);
	ret.y = 2 * z.x * z.y;
	return (ret);
}

double	ft_squared_vector_norm(t_complex z)
{
	double	ret;

	ret = (z.x * z.x) + (z.y + z.y);
	return (ret);
}
