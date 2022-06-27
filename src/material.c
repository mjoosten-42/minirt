/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 14:22:16 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/27 12:56:46 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "config.h"
#include "libft.h"
#include <math.h>

t_material	parse_material(char *str)
{
	const static t_material	table[] = {
	{"water", 0.2, 0.5, 1.3, DEFAULT_PHONG},
	{"mirror", 0.9, 0.0, 1.0, INFINITY},
	{"glass", 0.0, 0.9, 1.5, INFINITY},
	{"metal", 0.5, 0.1, 2.0, 2.0}
	};
	int						tablesize;
	int						len;
	int						i;

	if (!str)
		return ((t_material){NULL, 0, 0, 1, INFINITY});
	i = 0;
	len = ft_strlen(str);
	tablesize = sizeof(table) / sizeof(*table);
	while (i < tablesize)
	{
		if (ft_strncmp(str, table[i].name, len) == 0)
			return (table[i]);
		i++;
	}
	return ((t_material){NULL, 0, 0, 1, DEFAULT_PHONG});
}

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
