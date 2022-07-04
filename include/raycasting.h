/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 12:24:49 by ngerrets          #+#    #+#             */
/*   Updated: 2022/07/04 14:12:49 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "program.h"
# include "ray3.h"
# include "collision.h"
# include "color.h"
# include "material.h"

/**
**	Ray data accumulated over bounces
**	@param coll <t_collision> Last collision
**	@param color <t_color> Accumulated color so far
*/
typedef struct s_rdata
{
	t_collision	coll;
	t_color		color;
}	t_rdata;

typedef t_rdata (*t_rcastfunc)(t_program *, t_ray3 *, t_rdata);

t_collision	raycast_get_collision(t_list *shapes, const t_ray3 *ray);
t_color		raycast_calc_lighting(const t_program *program, t_collision coll);
t_rdata		raycast(const t_program *program, const t_ray3 *ray);
t_rdata		material_cast(const t_program *program, const t_ray3 *ray, t_rdata rdata);


#endif
