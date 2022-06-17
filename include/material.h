/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 11:54:38 by ngerrets          #+#    #+#             */
/*   Updated: 2022/06/17 14:24:29 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

/**
**	data to define behaviour of impacting rays
**	@param name	<char *> "glass" "mirror" "diffuse"
**	@param reflection	<float> percentage (0.0 - 1.0)
**	@param refraction	<float> percentage (0.0 - 1.0)
**	@param index	<float> the angle at which light passes through an object
**	@param shine	<float> shine for the phong model, less is more shiny!
*/
typedef struct s_material
{
	char	*name;
	float	reflection;
	float	refraction;
	float	index;
	float	shine;
}	t_material;

void	material_print(const t_material *material);

#endif
