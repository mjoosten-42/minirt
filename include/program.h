/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   program.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:36:28 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/23 10:58:25 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "list.h"
# include <stdlib.h>

# define WINDOW_W 1024
# define WINDOW_H 1024
# define WINDOW_TITLE "WINDOW TITLE"
# define WINDOW_RESIZE 0

// typedef struct s_img
// {
//     void    *mlx_img;
//     void    *addr;
// }           t_img;

/**
**	Holds important data needed throughout the program
**	@param mlx <t_mlx*> Main MLX42 pointer
**	@param buffer <t_mlx_image*> MLX42-Image that holds the screen buffer
**	@param shapes <t_list*> Pointer to first element of all the shapes
*/
typedef struct s_program
{
	t_mlx		*mlx;
	t_mlx_image	*buffer;
	t_list		*shapes;
}				t_program;

/* program_init.c */
t_program	*program_get(void);
void		program_run(t_program *program);
void		program_terminate(t_program *program);

#endif
