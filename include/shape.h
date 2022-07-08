/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:11:37 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/08 11:19:50 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "ray3.h"
# include "shape_masks.h"
# include "vec3.h"
# include "objects.h"
# include "color.h"
# include "material.h"
# include "program.h"

//	Ugly but necessary to norm the typedef below
# define _C const

struct						s_shape;
typedef struct s_collision	(*t_collfunc)(_C struct s_shape *, _C t_ray3 *);
typedef t_v3				(*t_coordfunc)(_C struct s_collision *);

/**
**	@param id <char*> Letter identifier
**	@param type <t_object> Object enum
**	@param min_args <int> Minimum amount of arguments
**	@param max_args <int> Maximum amount of arguments
**	@param f <void(*f)(s_object, char **, void *)> Function to create object
*/
typedef struct s_object
{
	char			*id;
	t_object_type	type;
	int				min_args;
	int				max_args;
	void			(*f)(struct s_object, char **, t_program *);
}					t_object;

/**
**	Represents a default shape
**	@param union: contains the mask as a whole struct.
**	@param o <t_v3> Origin point vector of the shape.
**	@param n <t_v3> normal direction vector of the shape.
**	@param type <t_shape_type> Enumerator for the type of shape
**	@param material <t_material> Material data, such as reflectiveness
**	@param color <t_color> Color the shape has overall.
**	@param f Function used to check collision
*/
typedef struct s_shape
{
	union
	{
		t_mask_sphere	sp;
		t_mask_plane	pl;
		t_mask_cylinder	cy;
		t_mask_cone		co;
	};
	t_v3			o;
	t_object_type	type;
	t_color			color;
	t_material		material;
	mlx_texture_t	*texture;
	t_collfunc		f;
	t_coordfunc		cf;
}	t_shape;

/* shape.c */
void	build_sphere(t_object object, char **args, t_program *program);
void	build_plane(t_object object, char **args, t_program *program);
void	build_cylinder(t_object object, char **args, t_program *program);
void	build_cone(t_object object, char **args, t_program *program);

/* shape_debug.c */
void	shape_print(const t_shape *shape);

#endif
