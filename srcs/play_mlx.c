/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:36:26 by pingpanu          #+#    #+#             */
/*   Updated: 2022/06/27 22:09:24 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <math.h>

//#include <stdio.h>

typedef struct  s_data
{
    void    *img;
    char    *addr;
    int     bits_per_pixel;
    int     line_length;
    int     endian;
}               t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int     main(void)
{
    void        *mlx;
    void        *mlx_win;
    const float gradiant = 768.00 / 1024.00;
    t_data      img;
    int         xl; //x coordinate on screen
    int         xr;
    int         y; //y coordinate on screen


    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1024, 768, "Hello World!");
    img.img = mlx_new_image(mlx, 1024, 768);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    //printf("%f\n", gradiant);
    for(xl = 0; xl < 1024; xl++)
    {
        y = floor((gradiant * xl) + 0);
        xr = floor(1024.00 - xl);
        my_mlx_pixel_put(&img, xl, y, 0x00FF00);
        my_mlx_pixel_put(&img, xr, y, 0x00FF00);
        //printf("xl = %d, xr = %d, y = %d\n",(int)x.xl, (int)x.xr, y);
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
    //return (0);
}