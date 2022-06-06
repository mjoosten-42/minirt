/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:54:38 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/06 11:36:52 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

typedef enum e_material_type
{
	MATERIAL_DEFAULT,
	MATERIAL_MIRROR
}	t_material_type;

/**
**	data to define behaviour of impacting rays
**	@param reflection	<float> percentage (0.0 - 1.0)
**	@param shine	<float> shine for the phong model, less is more shiny!
*/
typedef struct s_material
{
	t_material_type	type;
	float			reflection;
	float			shine;
}	t_material;

#endif
