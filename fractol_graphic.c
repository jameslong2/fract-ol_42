#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

static t_color interpolateColor(t_color startColor, t_color middleColor, t_color endColor, float t) {
    t_color result;
    float oneMinusT = 1.0 - t;

    result.red = (int)(oneMinusT * oneMinusT * startColor.red + 4 * oneMinusT * t * middleColor.red + t * t * endColor.red);
    result.green = (int)(oneMinusT * oneMinusT * startColor.green + 4 * oneMinusT * t * middleColor.green + t * t * endColor.green);
    result.blue = (int)(oneMinusT * oneMinusT * startColor.blue + 4 * oneMinusT * t * middleColor.blue + t * t * endColor.blue);

    return result;
}

int fractal(int iter, int x, int y, t_data *data)
{
    double count;
    double real;
    double imag;
    double tempx;

    count = 0;
    real = (double)(x)/(double)(250+data->zoom);
    imag = (double)(y)/(double)(250+data->zoom);
    while (count < iter)
    { 
        tempx = real * real - imag * imag+(double)(x)/(double)(250+data->zoom); 
        imag = 2 * real * imag+(double)(y)/(double)(250+data->zoom); 
        real = tempx; 
        count++;
        if (real * real + imag * imag > 40)
        {
            t_color interpolatedColor = interpolateColor({0, 0, 255},{0, 255, 0},{255, 0, 0}, count / (iter));
            return ((interpolatedColor.red << 16) | (interpolatedColor.green << 8) | interpolatedColor.blue);
        }
    }
    return (0);
}

int julia_fractal(int iter, int x, int y, t_data *data)
{
    double real;
    double imag;
    double tempx;
    int color;
    
    color = 0;
    real = (double)(x)/(double)(250+data->zoom);
    imag = (double)(y)/(double)(250+data->zoom);
    while (color < iter)
    { 
        tempx = pow(real,2) - pow(imag,2) + data->lastReal; 
        imag = 2 * real * imag +  data->lastImag; 
        real = tempx; 
        color++;
        if (real * real + imag * imag > 50){
            t_color interpolatedColor = interpolateColor({0, 0, 255},{0, 255, 0},{255, 0, 0}, (double)color/iter);
            return ((interpolatedColor.red << 16) | (interpolatedColor.green << 8) | interpolatedColor.blue);
        }else if (real * real + imag * imag < 0)
            return (0);
    }
    return (0);
}