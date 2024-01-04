#include "fractol.h"

int	main(int argc, char **argv)
{
	void	*mlx;
    void	*mlx_win;
	t_data	img;
    int     error;

    if (argc > 1 && argc < 5)
    {
        error = error_check(argv[1]);
        if (error == 0 || (error == 2 && argc < 4))
            return (0);
        else if (error == 1)
            struct_init(&img,0,0,error);
        else
            struct_init(&img, ft_atod(argv[2]), ft_atod(argv[3]),error);
    }
    init(&img, mlx_init(), mlx_new_window(mlx, WIDTH, HEIGHT, "Fractal de Jaume Carrion"));
    hooks(&img);
    return (0);
}