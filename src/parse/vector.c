/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:09:47 by mjoosten          #+#    #+#             */
/*   Updated: 2022/05/30 15:27:54 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "../lib/libft/include/libft.h"
#include "parse.h"
#include "log.h"

#define EPSILON 0.1

double	dabs(double a);

t_v3	parse_vector_norm(char *str)
{
	t_v3	vector;
	double	len;

	vector = parse_vector(str);
	len = vec3_length(vector) - 1;
	if (dabs(len) < EPSILON)
		return (vector);
	LOG_ERR("Vector is not normalized");
	exit(EXIT_FAILURE);
}

t_v3	parse_vector(char *str)
{
	t_v3	vector;
	char	**strs;

	strs = ft_split(str, ',');
	if (!strs)
	{
		LOG_ERR("Split allocation failed");
		exit(EXIT_FAILURE);
	}
	if (ft_argsize(strs) != 3)
	{
		LOG_ERR("Incorrect amount of doubles");
		exit(EXIT_FAILURE);
	}
	vector.x = atod(strs[0]);
	vector.y = atod(strs[1]);
	vector.z = atod(strs[2]);
	return (vector);
}

double	dabs(double a)
{
	if (a > 0)
		return (a);
	return (-a);
}
