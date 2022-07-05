/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   material.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mjoosten <mjoosten@student.42.fr>            +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/06/17 14:22:16 by mjoosten      #+#    #+#                 */
/*   Updated: 2022/07/05 19:07:39 by ngerrets      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "material.h"
#include "config.h"
#include "libft.h"
#include <math.h>
#include <stdio.h>

t_material	parse_material(char *str)
{
	static const t_material	table[] = {
	{"default", 0, 0, 1, 1.0, DEFAULT_PHONG, 0},
	{"clouds", 0, 0.6, 1.5, 0.0, DEFAULT_PHONG, 0},
	{"water", 0.2, 0.5, 1.3, 1.0, DEFAULT_PHONG, 0},
	{"mirror", 0.9, 0.0, 1.0, 1.0, DEFAULT_PHONG, 0},
	{"planet", 0.0, 0.0, 1.0, 0.2, 2.0, 0},
	{"glass", 0.0, 0.9, 1.5, 4.0, 4.0, 0},
	{"star", 0.0, 0.4, 1.0, 0.8, 2.0, 0},
	{"shine", 0.0, 0.0, 1.0, 2.6, 2.2, 0},
	{"metal", 0.4, 0.0, 2.0, 1.2, 16.0, 0},
	{"checkerboard", 0.0, 0.0, 1.0, 1.0, DEFAULT_PHONG, 1}
	};
	int						tablesize;
	int						len;
	int						i;

	if (!str)
		return (table[0]);
	i = 0;
	len = ft_strlen(str);
	tablesize = sizeof(table) / sizeof(*table);
	while (i < tablesize)
	{
		if (ft_strncmp(str, table[i].name, len) == 0)
			return (table[i]);
		i++;
	}
	return (table[0]);
}

void	material_print(const t_material *material)
{
	printf("|  MATERIAL:\n");
	printf("|  |   name: %s\n", material->name);
	printf("|  |   reflection: %.3f\n", material->reflection);
	printf("|  |   refraction: %.3f\n", material->refraction);
	printf("|  |   refractive index: %.3f\n", material->index);
	printf("|  |   shine: %.3f\n", material->shine);
	printf("|  |   checkerboard: %d\n", material->checkerboard);
}
