/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   material.h                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/02 11:54:38 by ngerrets      #+#    #+#                 */
/*   Updated: 2022/07/05 17:46:04 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_H
# define MATERIAL_H

/**
**	data to define behaviour of impacting rays
**	@param name	<char *> identifier
**	@param reflection	<float> percentage (0.0 - 1.0)
**	@param refraction	<float> percentage (0.0 - 1.0)
**	@param index	<float> how much light bends when refracting
**	@param shine	<float> shine percentage for the phong model
**	@param specular_index	<float> size of specular, less is bigger
**	@param checkerboard	<int> checkerboard texture or not
*/
typedef struct s_material
{
	char	*name;
	float	reflection;
	float	refraction;
	float	index;
	float	shine;
	float	specular_index;
	int		checkerboard;
}	t_material;

t_material	parse_material(char *str);
void		material_print(const t_material *material);

#endif
