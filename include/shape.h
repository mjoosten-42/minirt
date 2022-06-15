/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:11:37 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/15 15:41:35 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "vec3.h"
# include "color.h"
# include "material.h"
# include "shape_masks.h"
# include "ray3.h"

typedef struct s_shape	t_shape;
typedef struct s_collision	(*t_collfunc)(const t_shape *, const t_ray3 *);

/**
**	Represents a default shape
**	@param union: contains the mask as a whole struct.
**	@param type <t_shape_type> Enumerator for the type of shape (like circle)
**	@param o <t_v3> Origin point vector of the shape. Usually the center
**	@param n <t_v3> normal direction vector of the shape.
**	@param color <t_color> Color the shape has overall.
**	@param f Function used to check collision
*/
struct s_shape
{
	union
	{
		t_mask_sphere	sp;
		t_mask_cylinder	cy;
		t_mask_cone		co;
	};
	t_shape_type	type;
	t_v3			o;
	t_v3			n;
	t_color			color;
	t_material		material;
	t_collfunc		f;
};

/* shape_debug.c */
void	shape_print(t_shape *shape);

/* shape.c */
void	build_sphere(char **args, void *ptr);
void	build_plane(char **args, void *ptr);
void	build_cylinder(char **args, void *ptr);
void	build_circle(char **args, void *ptr);
void	build_cone(char **args, void *ptr);

#endif
