/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:11:37 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/03/01 12:39:47 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "vec3.h"
# include "color.h"
# include "ray3.h"
# include "shape_masks.h"
# include <stdlib.h>

/**
**	Represents a default shape
**	@param type <t_shape_type> Enumerator for the type of shape (like circle)
**	@param origin <t_v3> Origin point vector of the shape. Usually the center
**	@param color <t_color> Color the shape has overall.
**	@param mask <void*> Pointer to the shape's collision data, it's mask.
*/
typedef struct s_shape
{
	t_shape_type	type;
	t_v3			origin;
	t_color			color;
	void			*mask;
}					t_shape;

typedef int (*t_collfunc)(const t_shape *, const t_ray3 *);

/* shape.c */
t_shape	*shape_create(t_shape_type type, t_v3 origin, t_color col, void *mask);
void	shape_free(void *shape);
void	*shape_get_coll_func(t_shape_type type);

/* shape_mask.c */
void	*shape_mask(t_shape_type type, void *data);

/* shape_debug.c */
void	shape_print(t_shape *shape);

/* shape_sphere.c */
t_mask_sphere	shape_sphere_mask(double radius);
int				shape_sphere_collision(const t_shape *sphere, const t_ray3 *ray);

#endif
