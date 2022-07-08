/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:36:28 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/08 11:14:32 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROGRAM_H
# define PROGRAM_H

# include "MLX42/MLX42.h"
# include "libft.h"
# include <stdlib.h>
# include "vec3.h"
# include "light.h"
# include "mat4.h"
# include "threads.h"
# include "config.h"

/**
**	Camera data
**	@param origin <t_v3> Origin point vector
**	@param direction <t_v3> Normal vector
**	@param view_matrix <t_mat4> Camera view matrix for rotation calculation
**	@param fov <float> Field of view
*/
typedef struct s_cam
{
	t_v3	origin;
	t_v3	direction;
	t_mat4	view_matrix;
	float	fov;
}			t_cam;

/**
**	Holds important data needed throughout the program
**	@param mlx <mlx_t*> Main MLX42 pointer
**	@param buffer <mlx_image_t*> MLX42-Image that holds the screen buffer
**	@param shuffled <int*> Array of shuffled ints up to nb of pixels
**	@param threads <t_threads> Thread data
**	@param camera <t_cam> Camera data
**	@param ambience <t_ambience> Ambient lighting data
**	@param lights <t_list*> Pointer to first element of all the lights
**	@param shapes <t_list*> Pointer to first element of all the shapes
*/
typedef struct s_program
{
	mlx_t		*mlx;
	mlx_image_t	*buffer;
	int			*shuffled;
	t_threads	threads;
	t_cam		camera;
	t_ambience	ambience;
	t_list		*lights;
	t_list		*shapes;
}				t_program;

/* program_init.c */
t_program		program_get(void);
void			program_init_mlx(t_program *program);
void			program_run(t_program *program);
void			program_terminate(t_program *program);

/* camera.c */
void			camera_calculate_matrix(t_cam *camera);

/* parse.c */
void			build_scene(t_program *program, char *file);

/* scene_draw.c */
void			clear_screen(mlx_image_t *img);
void			scene_draw(t_program *program);

/* anti_aliasing.c */
t_color			anti_aliasing(const t_program *program, double x, double y);
int				*shuffle(int pixels);

/* error.c */
_Noreturn void	rt_error(char *s1, char *s2);

/* texture.c */
mlx_texture_t	*load_texture(const char *fname);
t_color			texture_get_color(mlx_texture_t *tex, double x, double y);

#endif
