#ifndef FRACTOL_H
#define	FRACTOL_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"
#include "X11/X.h"
#include "X11/keysym.h"

//changeables
#define WIDTH 800
#define HEIGHT 800
#define ITER_NMB 42

#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define RED         0xFF0000  // RGB(255, 0, 0)
#define GREEN       0x00FF00  // RGB(0, 255, 0)
#define BLUE        0x0000FF  // RGB(0, 0, 255)

// Psychedelic colors
#define MAGENTA_BURST   0xFF00FF  // A vibrant magenta
#define LIME_SHOCK      0xCCFF00  // A blinding lime
#define NEON_ORANGE     0xFF6600  // A blazing neon orange
#define PSYCHEDELIC_PURPLE 0x660066  // A deep purple
#define AQUA_DREAM      0x33CCCC  // A bright turquoise
#define HOT_PINK        0xFF66B2  // As the name suggests!
#define ELECTRIC_BLUE   0x0066FF  // A radiant blue
#define LAVA_RED        0xFF3300  // A bright, molten red

//structs

typedef struct	s_complex
{
	double	x;
	double	y;
}				t_complex;


typedef struct s_img
{
	void	*img_ptr;
	void	*pixels;
	int		bpp;
	int		endian;
	int		line_len;
}				t_img;

typedef struct	s_fractol//missing hooks
{
	char	*name;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	int		escaped_value;
	int		iteration_limit;
	double	julia_x;
	double	julia_y;
	double	shift_sides;
	double	shift_vert;
	double	zoom;
}				t_fractol;




//libft utils
int	ft_strncmp(const char *s1, const char *s2, int n);
void	ft_putstr_fd(char *s, int fd);
//init file
void	fractol_init(t_fractol *fractol);
void	data_init(t_fractol *f, int iter);
void	events_init(t_fractol *f);
//error handling
void	free_error(void);
void	ft_call_error(void);
//math
t_complex ft_complex_sum(t_complex z, t_complex c);
t_complex	ft_complex_sqrd(t_complex z);
double	ft_squared_vector_norm(t_complex z);
//rendering
void	ft_pixel_put(int x, int y, t_img *img, int color);
void	fractol_render(t_fractol *f);
void	handle_pixel(int x, int y, t_fractol *s);
double	ft_scale(double new_max, double new_min, double max, double min, double value);
void	ft_mandel_julia(t_complex *z, t_complex *c, t_fractol *f);
//parsing
void	parser(int argc, char **argv);
double	ft_fartoi(char *str);
void	fart_check(char *s);
int	ft_atoi(char *str);
//key_handling
int	key_handler(int	keysym, t_fractol *f);
int	close_handler(t_fractol *f);
int	mouse_handler(int keysym, int x, int y, t_fractol *f);
//help
void	ft_help(void);








#endif
