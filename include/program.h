/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   program.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:36:28 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/17 17:41:49 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include "../lib/mlx/mlx.h"
# include <stdlib.h>

typedef struct s_img
{
    void    *mlx_img;
    void    *addr;
}           t_img;

typedef struct s_program
{
    void    *mlx;
    void    *window;
    t_img   *buffer;
}           t_program;

#endif
