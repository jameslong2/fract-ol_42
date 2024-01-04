#include "mlx.h"
#include <math.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
    void    *mlx;
    void    *mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
    double     zoom;
    int     iszoom;
    double     x_offset;
    double     y_offset;
    double center_x;
    double center_y;
    int counter;
    double lastReal;
    double lastImag;
}				t_data;

typedef struct s_color{
    int red;
    int green;
    int blue;
} t_color;

#define WIDTH 800
#define HEIGHT 600

int	numlen(const char *n);
const char	*skip(const char *str);
double	double_part(const char *str);
double	ft_atod(const char *str);
int render(t_data *data);
int move(int keycode, t_data *data);
int zoom(int event,int x, int y, t_data *data);
int error_check(char *arg);
void struct_init(t_data *img, double real, double imag, int type);
void init(t_data *img, void *mlx, void *mlx_win);
void hooks(t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int fractal(int iter, int x, int y, t_data *data);
int julia_fractal(int iter, int x, int y, t_data *data);