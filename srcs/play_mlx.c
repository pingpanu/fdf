/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:36:26 by pingpanu          #+#    #+#             */
/*   Updated: 2022/06/27 14:35:02 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

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
    void    *mlx;
    void    *mlx_win;
    t_data  img;
    int     x;
    int     y;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1024, 768, "Hello World!");
    img.img = mlx_new_image(mlx, 1024,768);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
    for (y = 0; y < 51; y++)
    {
        if (y == 0 || y == 50)
        {
            for (x = 0; x < 51; x++)
                my_mlx_pixel_put(&img, x, y, 0x00FF00);
        }
        else
        {
            for (x = 0; x < 51; x++)
            {
                if (x == 0 || x == 50)
                    my_mlx_pixel_put(&img, x, y, 0x00FF00);
            }
        }
    }
    mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}