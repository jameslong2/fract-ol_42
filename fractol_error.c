#include "fractol.h"
#include <unistd.h>

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
		{
			return (-1);
		}
		i++;
	}
    if (s1[i] == s2[i] && s1[i] == 0)
        return (0);
    write(1, "Argumentos Invalidos\narg1* (mandelbort || julia) |
     if(arg1 == julia) arg2 (double value) arg3 (double value)");
	return (-1);
}

int error_check(char *arg){
    if (ft_strcmp("mandelbort",arg) == 0)
    {
        return (1);
    }else if (ft_strcmp("julia",arg) == 0)
    {
        return (2);
    }else
    {
        return (-1);
    }
}

void struct_init(t_data *img, double real, double imag, int type){
    img->x_offset = 0;
    img->y_offset = 0;
    img->zoom = 100;
    img->counter = 1;
    img->lastReal = real;
    img->lastImag = imag;
    img->type = type;
}

void init(t_data *img, void *mlx, void *mlx_win){
    img->mlx = mlx;
    img->mlx_win = mlx_win;
	img->img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length,
								&img->endian);
}

void hooks(t_data *data){
    mlx_do_key_autorepeaton(data->mlx);
    mlx_mouse_hook(data->mlx_win, &zoom, &img);
    mlx_hook(data->mlx_win, 2, 1L<<0, &move, &img);
    mlx_loop_hook(data->mlx,&render, &img);
    mlx_loop(mlx);
}