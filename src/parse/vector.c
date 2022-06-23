/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjoosten <mjoosten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:09:47 by mjoosten          #+#    #+#             */
/*   Updated: 2022/06/23 16:02:29 by mjoosten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec3.h"
#include "libft.h"
#include "parse.h"
#include <math.h>
#include "program.h"

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
	vector = vec3_norm(vector);
	return (vector);
}

t_v3	parse_vector(char *str)
{
	t_v3	vector;
	char	**strs;

	if (nb_of_char(str, ',') != 2)
		rt_error(str, "vector incorrectly formatted");
	strs = ft_split(str, ',');
	if (!strs)
		rt_error(NULL, "Split allocation failed");
	if (ft_argsize(strs) != 3)
		rt_error(str, "vector incorrectly formatted");
	vector.x = atod(strs[0]);
	vector.y = atod(strs[1]);
	vector.z = atod(strs[2]);
	ft_free_array(strs);
	return (vector);
}
