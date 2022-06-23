/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pingpanu <pingpanu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:36:10 by pingpanu          #+#    #+#             */
/*   Updated: 2022/06/23 15:48:12 by pingpanu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

/*struct to generate matrix of **int*/
typedef struct  s_map
{
    int     length;
    int     width;
    int     **plane;
}               t_map;
#endif
