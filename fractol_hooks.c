#include "fractol.h"

static void paint(t_data *data)
{
    double newZoom;
    int col;
    int fracY;

    newZoom = data->zoom;
    for (int y=0;y<HEIGHT;y++){
        fracY = y-(HEIGHT/2+((250+data->zoom)*data->y_offset));
        for (int x=0;x<WIDTH;x++){
            if (data->type == 2)
                col = julia_fractal(200, x-(WIDTH/2+((250+data->zoom)*data->x_offset)),fracY,data);
            else
                col = fractal(100, x-(WIDTH/2+((250+data->zoom)*data->x_offset)),fracY,data);
            my_mlx_pixel_put(data, x, y, col);
        }
    }
}
int render(t_data *data)
{
    paint(data);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
    return (0);
}
int move(int keycode, t_data *data)
{
    if (keycode == 97 || keycode == 65){
        data->x_offset += 0.3/pow(data->counter,1.5);
    }
    if (keycode == 68 || keycode == 100){
        data->x_offset -= 0.3/pow(data->counter,1.5);
    }
    if (keycode == 87 || keycode == 119){
        data->y_offset += 0.3/pow(data->counter,1.5);
    }
    if (keycode == 83 || keycode == 115){
        data->y_offset -= 0.3/pow(data->counter,1.5);
    }
    return (0);
}
int zoom(int event,int x, int y, t_data *data){
    if (event == 4){
        data->zoom += 100*data->counter;
        data->counter++;
    }
    else if (event == 5 && data->counter > 1){
        data->zoom -= 100*data->counter;
        data->counter--;
    }
    return (0);
}