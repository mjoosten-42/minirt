/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   program.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/17 17:36:28 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/03 10:42:30 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include "../lib/MLX42/include/MLX42/MLX42.h"
# include "list.h"
# include <stdlib.h>
# include "vec3.h"

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
**	Camera data
**	@param origin <t_v3> Origin point vector
**	@param direction <t_v3> Normal vector
**	@param up <t_v3> Normal vector that points up from direction
**	@param fov <float> Field of view
*/
typedef struct s_cam
{
	t_v3	origin;
	t_v3	direction;
	t_v3	up;
	float	fov;
}			t_cam;

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
	t_cam		camera;
}				t_program;

/* program_init.c */
t_program	*program_get(void);
void		program_run(t_program *program);
void		program_terminate(t_program *program);

/* scene_draw.c */
void		scene_draw(t_program *program);

#endif
