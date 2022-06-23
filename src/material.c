/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:22:16 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/23 15:52:01 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include <stdio.h>

void	material_print(const t_material *material)
{
	printf("|  MATERIAL:\n");
	printf("|  |   name: %s\n", material->name);
	printf("|  |   reflection: %f\n", material->reflection);
	printf("|  |   refraction: %f\n", material->refraction);
	printf("|  |   refractive index: %f\n", material->index);
	printf("|  |   shine: %f\n", material->shine);
}
