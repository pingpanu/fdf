/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:28:37 by pingpanu          #+#    #+#             */
/*   Updated: 2022/06/23 15:58:53 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"

/* Main working sequence
* 1) read fdf file (refer to gnl)
* 2) get height & width of matrix
* 3) build the matrix of **int
* 4) write number in matrix **int
* 5) draw the line with Bresenham algorithm
* 6) display the model
* 7) if user pan camera, redraw Bresenham algorithm
* 8) if nothing happened, end
*/

t_map   createmap(int fd);

int     main(int argc, char **argv)
{
    int     fd;
    t_map   map;

    if (argc != 2)
        return (0);
    fd = open(argv[1], O_RDONLY);
    map = createmap(fd);
    if (!map)
    {
        free(map);
        return (1);
    }
    build_frame(map);
    show_frame(map);
    return (0);
}

t_map   createmap(int fd)
{
    t_map   plane;
    char    **read_fdf;
    int     i;

    if (fd < 0)
        return (NULL);
    i = 0;
    map_init(plane);
    return (plane);   
}