/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shape.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ngerrets <ngerrets@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/16 13:11:37 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/02/21 19:19:52 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPE_H
# define SHAPE_H

# include "vec3.h"
# include "color.h"
# include "shape_masks.h"
# include <stdlib.h>

typedef enum e_shape_type
{
	SHAPE_NONE,
	SHAPE_PLANE,
	SHAPE_SQUARE,
	SHAPE_CIRCLE
}	t_shape_type;

typedef struct s_shape
{
	t_shape_type	type;
	t_v3			origin;
	t_color			color;
	void			*mask;
}					t_shape;

/* shape.c */
t_shape	*shape_create(t_shape_type type, t_v3 origin, t_color col, void *mask);
void	shape_free(void *shape);

/* shape_mask.c */
void	*shape_mask(t_shape_type type, void *data);

/* shape_debug.c */
void	shape_print(t_shape *shape);

#endif
