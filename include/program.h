/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   program.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:36:28 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 15:10:53 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include <stdlib.h>

# define WINDOW_W 1024
# define WINDOW_H 1024
# define WINDOW_TITLE "WINDOW TITLE"
# define WINDOW_RESIZE false

// typedef struct s_img
// {
//     void    *mlx_img;
//     void    *addr;
// }           t_img;

typedef struct s_program
{
	t_mlx		*mlx;
	t_mlx_image	*buffer;
}           	t_program;

/* program_init.c */
t_program	*program_get(void);
void		program_terminate(t_program *program);


#endif
