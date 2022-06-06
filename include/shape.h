/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:11:37 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/06 11:57:11 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "vec3.h"
# include "color.h"
# include "material.h"
# include "shape_masks.h"

/**
**	Represents a default shape
**	@param union: contains the mask as a whole struct.
**	@param type <t_shape_type> Enumerator for the type of shape (like circle)
**	@param origin <t_v3> Origin point vector of the shape. Usually the center
**	@param color <t_color> Color the shape has overall.
*/
typedef struct s_shape
{
	union
	{
		t_mask_sphere	sp;
		t_mask_plane	pl;
		t_mask_cylinder	cy;
		t_mask_square	sq;
		t_mask_triangle	tr;
		t_mask_circle	ci;
	};
	t_shape_type	type;
	t_v3			origin;
	t_color			color;
	t_material		material;
}					t_shape;

/* shape_debug.c */
void	shape_print(t_shape *shape);

/* shape.c */
void	build_sphere(char **args, void *ptr);
void	build_plane(char **args, void *ptr);
void	build_cylinder(char **args, void *ptr);

#endif
