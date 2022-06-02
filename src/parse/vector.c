/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:09:47 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/02 16:29:38 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "../lib/libft/include/libft.h"
#include "parse.h"
#include "log.h"
#include <math.h>

int	nb_of_char(char *str, char c);

t_v3	parse_vector_norm(char *str)
{
	t_v3	vector;
	double	len;

	vector = parse_vector(str);
	len = vec3_length(vector);
	/*
	if (fabs(len - 1) > __DBL_EPSILON__)
	{
		LOG_ERR("Vector is not normalized");
		exit(EXIT_FAILURE);
	}
	*/
	vec3_normalize(&vector);
	return (vector);
}

t_v3	parse_vector(char *str)
{
	t_v3	vector;
	char	**strs;

	if (nb_of_char(str, ',') != 2)
	{
		LOG_ERR("Only two comma's per vector allowed");
		exit(EXIT_FAILURE);
	}
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

int	nb_of_char(char *str, char c)
{
	int	amount;

	amount = 0;
	while (*str)
	{
		if (*str == c)
			amount++;
		str++;
	}
	return (amount);
}
