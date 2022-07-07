/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:09:03 by mjoosten          #+#    #+#             */
/*   Updated: 2022/07/07 14:42:40 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "parse.h"

int	table_entry(const char *table, int tablesize, char *s, int objectsize)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(s);
	while (i < tablesize)
	{
		if (ft_strncmp(s, *(char **)&table[i * objectsize], len) == 0)
			return (i);
		i++;
	}
	rt_error(s, "not an identifier");
}

t_object	get_object(char *str)
{
	static const t_object	table[] = {
	{"A", OBJECT_AMBIENCE, 3, 3, build_ambience},
	{"C", OBJECT_CAMERA, 4, 4, build_camera},
	{"L", OBJECT_LIGHT, 4, 4, build_light},
	{"sp", OBJECT_SPHERE, 4, 6, build_sphere},
	{"pl", OBJECT_PLANE, 4, 6, build_plane},
	{"cy", OBJECT_CYLINDER, 6, 8, build_cylinder},
	{"co", OBJECT_CONE, 6, 8, build_cone}
	};

	return (table[table_entry(
				(const char *)table,
				sizeof(table) / sizeof(*table),
				str,
				sizeof(t_object))]);
}
